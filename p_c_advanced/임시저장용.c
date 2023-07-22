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
	// ī��Ʈ�� ���� 4����Ʈ?
	// �ڷ����� �� �´� ��? -> �ƴ� ����ü���� ����

	SSIZE_T recv_tot, recv_len, str_len;

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
			printf("�Է��� ����: %d \n", (int)arr[i]);
		}


		printf("cnt�� %d \n", cnt);

		printf("operator: ");
		scanf_s("%c", (char*)&arr[cnt * 4], (unsigned char)sizeof(char));
		forGetchar = getchar();
		// printf("%c", arr[cnt]);

		// printf("�����ڴ� : %c \n", arr[cnt* INT]);
		// printf("���� ���� : %c \n", arr[0]);

		str_len = send(hSocket, &arr, (sizeof(int) * cnt) + 2, 0);
		printf("Ŭ�󿡼� �����¹���Ʈ��? %d \n", (int)str_len);
		if (str_len == -1) errorHandling("send() error");

		recv_len = recv(hSocket, &result, sizeof(int), 0);
		printf("Ŭ�󿡼� ��������Ʈ��? %d \n", (int)recv_len);
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