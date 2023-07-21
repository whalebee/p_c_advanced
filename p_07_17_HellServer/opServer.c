#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

void errorHandling(char* message);

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAddr, clntAddr;


	int szClntAddr;
	char message[] = "Hell World!";


	// new
	int i, j;
	int oper;
	SSIZE_T str_len;

	// argment count 인자의 개수가 2개인 것을 세는 것
	// HellServer.exe 111
	// HellServer.exe -> 1개, 111 -> 2개
	// argv[0] -> HellServer.exe
	// argv[1] -> 111
	// 이런식으로 된다 ! 서버라면 argv[2]가 port
	if (argc != 2) {
		printf("Usage : %s <port> \n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		errorHandling("WSAStartup() error");

	hServSock = socket(PF_INET, SOCK_STREAM, 0);

	if (hServSock == INVALID_SOCKET)
		errorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(atoi(argv[1]));

	if (bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		errorHandling("bind() error");

	if (listen(hServSock, 5) == SOCKET_ERROR)
		errorHandling("listen() error");

	// int count = 0;
	for (i = 0; i < 5; i++)
	{
	szClntAddr = sizeof(clntAddr);
	hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);

	if (hClntSock == INVALID_SOCKET) errorHandling("accept() error");

	//// count
	//while(recv(hClntSock, count, sizeof(int), 0) == 0)
	//	printf("count: %d", count);

	//// parameter
	//for(j = 0; j < count; j++)
	//{
	//	str_len = recv(hClntSock, &oper_arr[j], sizeof(int), 0);
	//	send(hClntSock, oper_arr[j], str_len, 0);
	//}
	
	// calculator
	

	closesocket(hClntSock);
	}

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