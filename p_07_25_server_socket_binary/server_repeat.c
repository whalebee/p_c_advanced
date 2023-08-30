#include <stdio.h>
#include <stdlib.h>
#include <ws2tcpip.h>
#include <winSock2.h>

#define BUF 1024

void errorHandling(char* message);

int main(int argc, char* argv[])
{
	// basic def
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAddr;
	SOCKADDR_IN clntAddr;

	// argc check
	if (argc != 2)
	{
		printf("Usage : %s <PORT> \n", argv[0]);
		exit(1);
	}

	// WSAstartup
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) == -1)
		errorHandling("WSAStartup() error");


	// socket
	hServSock= socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == -1) errorHandling("socket() error");

	// memset init
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(atoi(argv[1]));


	// bind
	if (bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == -1)
		errorHandling("bind() error");

	// listen
	if (listen(hServSock, 5) == SOCKET_ERROR) errorHandling("listen() error");





	// new def
	int szClntAddr;

	char recvBuf[BUF];
	char readBuf[BUF];

	SIZE_T chkRecvLen, chkFrLen;

	

	// for, size, accept
	szClntAddr = sizeof(clntAddr);
	hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);
	if (hClntSock == INVALID_SOCKET) errorHandling("accept() error");


	// file name read
	chkRecvLen = recv(hClntSock, recvBuf, sizeof(recvBuf)-1, 0); // sizeof(recvBuf) -1 ���� -1�� �����ϱ� �� ���� �Է��� �� ���� ������ ��� â ������
	if (chkRecvLen == -1) errorHandling("recv() error");
	printf("chkRecvLen : %d \n", (int)chkRecvLen);
	recvBuf[chkRecvLen] = '\0';

	printf("recv file name : %s \n", recvBuf);



	// file open 
	FILE* readfp;
	errno_t chkFp;
	chkFp = fopen_s(&readfp, recvBuf, "rb");
	if (chkFp != 0) return -1;

	while ((chkFrLen = fread(readBuf, sizeof(char), sizeof(readBuf), readfp)) != 0)
	{
		send(hClntSock, readBuf, chkFrLen, 0);
	}
	// fread �� �� count�� readBuf�� ũ�⸸ŭ �ϴ°� ����.
	// fread �� �� 0 ���� ũ��, 0�� �ƴϵ� ���������.
	// send�� �� fread���� �ܾ�� ��ŭ �� �Űܾ��Ѵ�.


	fclose(readfp);



	closesocket(hClntSock);
	closesocket(hServSock);
	WSACleanup();

	return 0;
}



void errorHandling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}