#include <stdio.h>
#include <stdlib.h>
#include <ws2tcpip.h>
#include <winsock2.h>

#define BUF 1024
#define INT 4
#define BACKLOG 5
#define CHAR 1

void errorHandling(char* message);
int cal(unsigned char* arr, int cnt, char oper);

int main(int argc, char* argv[])
{
	// definition
	WSADATA wsadata;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAddr, clntAddr;

	int szClntAddr;

	// parameter check
	if (argc != 2)
	{
		printf("Usage : %s <PORT> \n", argv[0]);
		exit(1);
	}

	// init
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		errorHandling("WSAstartup() error");

	// socket()
	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET)
		errorHandling("socket() error");


	// memset init
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(atoi(argv[1]));

	// bind()
	if( bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR )
		errorHandling("bind() error");

	// listen()
	if (listen(hServSock, BACKLOG) == SOCKET_ERROR)
		errorHandling("listen() error");
	else
		printf("�Է� ��� �� ..... \n");


	// accept()
	int rep;
	SSIZE_T strLen, recvLen, recvTot, sendLen;
	char arr[BUF];
	int count;
	int result;
	int i, j; // for operand values check

	for (rep = 0; rep < BACKLOG; rep++)
	{
		// size
		szClntAddr = sizeof(clntAddr);

		// accept
		hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);
		if (hClntSock == INVALID_SOCKET) errorHandling("accept() error");


		// recv, write
		while ((strLen = recv(hClntSock, arr, CHAR, 0) != 0))
		{
			if (strLen == SOCKET_ERROR) errorHandling("recv() error");
			printf("�������� ���� ����Ʈ �� : %d \n", (int)strLen);

			// �ٲ㼭 �޾ƾ��� �θ�
			count = atoi(&arr[0]);
			printf("���� ī��Ʈ �� : %d \n", count);

			recvTot = 1; // ī��Ʈ �ϳ� �޾����ϱ� 1�� ����.
			recvLen = 1; // ��������
			while (recvTot < count*INT + 2)
			{
				recvLen = recv(hClntSock, &arr[recvTot], BUF - 1, 0);
				if (recvLen == SOCKET_ERROR) errorHandling("recv() error");
				printf("�������� ���� ����Ʈ �� : %d\n", (int)recvLen);
				recvTot += recvLen;
			}
			
			// check operands
			j = 1;
			for (i = 1; i < count * INT; i += INT)
			{
				printf("���� operand %d :", j++);
				printf("%d \n", *((int*)(arr + i)));
			}

			// operator check
			printf("operator : %c \n", arr[count * INT + 2]);

			// call calculator
			// arr�� ù��° �ּҰ��� ��� ������ cal �Լ� �ȿ��� i = 1 ���� ������ ��
			// �ٸ� ������Ʈ���� &arr[1] �̷��� �־��� ������ cal�Լ� �ȿ��� i = 0���� �����ص� �ƾ��ٴ� ��.
			result = cal(arr, count, arr[count * INT + 2]);
			printf("������� : %d \n", result);

			sendLen = send(hClntSock, &result, sizeof(result), 0);
			if (sendLen == SOCKET_ERROR) errorHandling("send() error");
			printf("������ ����Ʈ��? %d \n", (int)sendLen);

		}

		// close() -> client
		closesocket(hClntSock);
	}

	

	// close() -> server
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


int cal(unsigned char* arr, int cnt, char oper)
{
	int i, result = 0;

	// check
	for (i = 1; i < cnt * INT; i += INT)
		printf("�Է��� �� %d : %d \n", i + 1, *((int*)(arr + i)));

	for (i = 1; i < cnt * INT; i += INT)
	{
		if (oper == '+')				result += *((int*)(arr + i));
		else if ( oper == '-')		result -= *((int*)(arr + i));
		else if (oper == '*')
		{
			if (i == 1) result = 1;
			result *= *((int*)(arr + i));
		}

	}
	

	return result;
}