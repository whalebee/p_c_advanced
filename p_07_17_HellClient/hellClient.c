#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>

void errorHandling(char* message);

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	char message[30];
	int strLen;

	// argment count ������ ������ 3���� ���� ���� ��
	// HellServer.exe 111
	// HellServer.exe -> 1��, 111 -> 2��
	if (argc != 3) {
		printf("Usage : %s <IP> <port> \n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		errorHandling("WSAStartup() error!");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET)
		errorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	// inet_addr, inet_pton �� �� ip�ּҸ� �����ϴ� ������ ������ ������� �ٸ���
	// servAddr.sin_addr.s_addr = inet_addr(argv[1]);
	inet_pton(AF_INET, argv[1], &servAddr.sin_addr);
	servAddr.sin_port = htons(atoi(argv[2]));

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		errorHandling("connect() error");

	strLen = recv(hSocket, message, sizeof(message) - 1, 0);
	if (strLen == -1)
		errorHandling("read() error");

	printf("Message From server : %s \n", message);

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