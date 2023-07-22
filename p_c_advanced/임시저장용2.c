#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define BACKLOG 10
#define BUF 1024
#define INT 4
#define CHAR 1


void errorHandling(char* message);
int calculator(unsigned char* arr, int cnt, char oper);


int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAddr, clntAddr;


	int szClntAddr;

	// new
	int rep, i, j, oper, cnt, tmp, result;
	unsigned char tmp_arr[BUF];
	SSIZE_T str_len, recv_tot, recv_len, send_len;

	// argment count ������ ������ 2���� ���� ���� ��
	// HellServer.exe 111
	// HellServer.exe -> 1��, 111 -> 2��
	// argv[0] -> HellServer.exe
	// argv[1] -> 111
	// �̷������� �ȴ� ! ������� argv[2]�� port
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

	if (listen(hServSock, BACKLOG) == SOCKET_ERROR)
		errorHandling("listen() error");



	printf("�Է� �����..... \n");

	for (rep = 0; rep < BACKLOG; rep++)
	{
		szClntAddr = sizeof(clntAddr);
		hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);

		if (hClntSock == INVALID_SOCKET) errorHandling("accept() error");
		else printf("Connected client : %d \n", rep + 1);

		// ó�� ����
		while ((str_len = recv(hClntSock, tmp_arr, CHAR, 0) != 0))
		{

			if (str_len == -1) errorHandling("first recv() error !");
			cnt = atoi(&tmp_arr[0]);


			recv_tot = 0;
			recv_len = 1;
			while (recv_tot < (cnt * INT + 1))
			{
				recv_len = recv(hClntSock, &tmp_arr[recv_len], BUF - 1, 0);
				printf("���� ����Ʈ�� : %d \n", (int)recv_len);
				if (recv_len == -1) errorHandling("second recv() error !");
				recv_tot += recv_len;
			}

			printf("���� ���� \n");
			j = 1;
			for (i = 1; i < cnt * INT; i += INT)
			{
				printf("operand %d : ", j++);
				printf("%d \n", (int)tmp_arr[i]); // �̰� �� ������?
			}
			printf("�����ڰ� ���ñ�? : %c \n", tmp_arr[cnt * INT]);

			result = calculator(&tmp_arr[1], cnt, tmp_arr[cnt * INT]);
			printf("����� ! ���� !!! : %d", result);

			send_len = send(hClntSock, &result, sizeof(result), 0);
			if (send_len == -1) errorHandling("send() error");
			printf("������ ����Ʈ��? %d \n", (int)send_len);

		}

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

int calculator(unsigned char* arr, int cnt, char oper)
{
	int i, result = 0;

	for (i = 0; i < cnt * 4; i += 4)
		printf("����.. %d \n", arr[i]);

	// printf("cal�ȿ��� �����ڴ� ���ϱ�? %c \n", oper);

	for (i = 0; i < cnt * INT; i += 4)
	{
		if (oper == '+')
			result += arr[i];
		else if (oper == '-')
			result -= arr[i];
		else if (oper == '*')
		{
			if (i == 0) result = 1;
			result *= arr[i];
		}

	}
	return result;


}