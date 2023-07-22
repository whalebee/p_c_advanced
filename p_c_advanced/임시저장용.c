#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define BUF 1024
#define INT 4
#define ETC 2

void errorHandling(char* message);


int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	int strLen;

	// new
	int i, cnt, j, forGetchar;
	int result = 0;
	char temp;
	char arr[BUF];

	// new
	// 카운트를 굳이 4바이트?
	// 자료형이 안 맞는 건? -> 아니 구조체말고 뭐지

	SSIZE_T recv_tot, recv_len, str_len;

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


	int test;


	while (1)
	{
		printf("operand count( input 0 to quit ): ");
		scanf_s("%c", &temp, (unsigned char)sizeof(char));
		cnt = atoi(&temp);


		if (cnt == 0) break;

		arr[0] = temp;
		j = 1;
		for (i = 1; i < cnt * 4; i += 4)
		{
			printf("operand %d : ", j++);
			// fgets((int*)& arr[i + 1], 4, stdin);
			scanf_s("%u", (unsigned int*)&arr[i]);
			forGetchar = getchar();
			// forGetchar = 0;
		}



		// int tp[BUF];
		for (i = 1; i < cnt * 4; i += 4)
		{
			printf("입력한 값들: %d \n", (int)arr[i]);
		}


		printf("cnt는 %d \n", cnt);

		printf("operator: ");
		scanf_s("%c", (char*)&arr[cnt * 4], (unsigned char)sizeof(char));
		forGetchar = getchar();
		// printf("%c", arr[cnt]);

		// printf("연산자는 : %c \n", arr[cnt* INT]);
		// printf("보낼 값은 : %c \n", arr[0]);

		str_len = send(hSocket, &arr, (sizeof(int) * cnt) + 2, 0);
		printf("클라에서 보내는바이트는? %d \n", (int)str_len);
		if (str_len == -1) errorHandling("send() error");

		recv_len = recv(hSocket, &result, sizeof(int), 0);
		printf("클라에서 받은바이트는? %d \n", (int)recv_len);
		if (recv_len == -1) errorHandling("recv() error");
		printf("Result From server : %d \n", result);

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