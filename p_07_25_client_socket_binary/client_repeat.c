#include <stdio.h>
#include <stdlib.h>
#include <ws2tcpip.h>
#include <winSock2.h>

#define NAME 50

void errorHandling(char* message);

int main(int argc, char* argv[])
{
	// basic def
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN serv_addr;

	// argc check
	if (argc != 3)
	{
		printf("Usage : %s <IP> <PORT> \n", argv[0]);
		exit(1);
	}
	
	// WSAstartup
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0 )
		errorHandling("WSAStartup() error");
	

	// socket
	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET) errorHandling("socket() error");

	// memset init
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	// serv_addr.sin_addr.s_addr = inet_addr(argv[1]); -> �̰� �ƴ��ݾ�
	inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
	serv_addr.sin_port = htons(atoi(argv[2]));

	// connect
	if(connect(hSocket, (SOCKADDR*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR)
		errorHandling("connect() error");

	
	// new def
	char name[NAME];
	char recvBuf[NAME];

	int chkSendLen, chkRecvLen;


	// file name
	printf("Input file name : ");
	fgets(name, NAME, stdin);
	// scanf_s("%s", name, (unsigned int)sizeof(name));


	// send file name cnt -> �̰��������� �غ���


	// send file name str
	chkSendLen = send(hSocket, name, (int)strlen(name), 0);
	printf("chkSendLen : %d \n", chkSendLen);
	// scanf_s ���� ���⼭ 0���� ������� �ʴ´ٰ� �����


	// create FILE
	FILE* writeFp;
	errno_t chkFp;
	chkFp = fopen_s(&writeFp, name, "wb");
	if (chkFp != 0) return -1;

	// recv file str
	while ((chkRecvLen = recv(hSocket, recvBuf, sizeof(char), 0)) != 0)
		fwrite(recvBuf, sizeof(char), sizeof(char), writeFp);
		
		
	closesocket(hSocket);
	WSACleanup();




	return 0;
}



void errorHandling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}