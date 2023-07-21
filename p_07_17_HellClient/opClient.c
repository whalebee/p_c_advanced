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

	int strLen;

	// new
	// ī��Ʈ�� ���� 4����Ʈ?
	// �ڷ����� �� �´� ��? -> �ƴ� ����ü���� ����

	int recv_tot, recv_len, str_len;
	int i;

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

	char count;
	char arr[100];
	while (1)
	{
		fputs("Operand count: ", stdout);
		scanf_s("%c", &count, (unsigned int)sizeof(char));
		// fgets(, sizeof(int), stdin);

		// �ϴ� ���������� ������� �غ���, ���!!���� �����α���
		arr[0] = count;

		
		

		for (i = 1; i < 100; i++)
		{
			printf("Operand %d :", i);
			scanf_s("%c", &arr[i], (unsigned int)sizeof(char));
			printf("%c ", &arr[i]);
		}



		// str_len = send(hSocket, &oper_arr[0], sizeof(int), 0);
		// if (str_len == -1) errorHandling("send() error");

		/*for (i = 1; i < 4; i++)
		{
			printf("Operand %d: \n", i);
			fgets(&oper_arr[i], sizeof(int), stdin);
		}
			
		fputs("Operator: ", stdout);
		fgets(&oper_arr[4], sizeof(int), stdin);*/

		
		
		// send
		/*for (i = 1; i < 5; i++)
		{
			printf("�����ϴ�. \n");
			str_len = send(hSocket, &oper_arr[i], sizeof(int), 0);
			if (str_len == -1) errorHandling("send() error");
			printf("�޽��ϴ�. \n");
			printf("�迭: %d \n", oper_arr[i]);
			recv(hSocket, &oper_arr[0], sizeof(int), 0);
		}*/


		//recv_tot = 0;
		//while (recv_tot < str_len)
		//{
		//	recv_len = recv(hSocket, &oper_arr[0], sizeof(int), 0); // -1 ?
		//	if (recv_len == -1) errorHandling("recv() error");
		//	recv_tot += recv_len;
		//}

		// printf("Message From server : %d \n", oper_arr[0]);
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