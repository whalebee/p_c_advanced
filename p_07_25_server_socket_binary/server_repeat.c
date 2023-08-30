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
	chkRecvLen = recv(hClntSock, recvBuf, sizeof(recvBuf)-1, 0); // sizeof(recvBuf) -1 에서 -1이 없으니까 널 문자 입력할 때 버퍼 오버런 경고 창 떴었어
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
	// fread 할 때 count는 readBuf의 크기만큼 하는게 좋다.
	// fread 할 때 0 보다 크든, 0이 아니든 상관없었다.
	// send할 때 fread에서 긁어온 만큼 씩 옮겨야한다.


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