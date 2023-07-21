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

	// new
	int oper_arr[5];
	int recv_tot, recv_len, str_len;

	// argment count 인자의 개수가 3개인 것을 세는 것
	// HellServer.exe 111
	// HellServer.exe -> 1개, 111 -> 2개
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
	// inet_addr, inet_pton 둘 다 ip주소를 세팅하는 역할을 하지만 사용방법이 다르다
	// servAddr.sin_addr.s_addr = inet_addr(argv[1]);
	inet_pton(AF_INET, argv[1], &servAddr.sin_addr);
	servAddr.sin_port = htons(atoi(argv[2]));

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		errorHandling("connect() error");
	else
		printf("Connected....................\n");

	while (1)
	{
		fputs("Operand count: ", stdout);
		fgets(oper_arr[0], sizeof(int), stdin);

		str_len = send(hSocket, oper_arr[0], sizeof(int), 0);

		recv_tot = 0;
		while (recv_tot < str_len)
		{
			recv_len = recv(hSocket, oper_arr[0], sizeof(int), 0); // -1 ?
			if (recv_len == -1) errorHandling("recv() error");
			recv_tot += recv_len;
		}

		printf("Message From server : %d \n", oper_arr[0]);
	}

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