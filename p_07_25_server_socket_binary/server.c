#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define BUF 1024

void errorHandling(char* message);

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAddr;
	SOCKADDR_IN clntAddr;


	int szClntAddr;
	char message[] = "Hell World!";

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

	if (listen(hServSock, 5) == SOCKET_ERROR)
		errorHandling("listen() error");

	szClntAddr = sizeof(clntAddr);
	hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);
	if (hClntSock == INVALID_SOCKET)
		errorHandling("accept() error");

	// new def
	SSIZE_T ck_cnt_r_len, ck_name_r_len;

	int cnt_r;
	char name[BUF];

	char temp[5];
	// size_t ck_fr_len, ck_fw_len;


	cnt_r = 0;
	// receive cnt
	ck_cnt_r_len = recv(hClntSock, (char*)& cnt_r, sizeof(int), 0);

	// receive name str
	ck_name_r_len = recv(hClntSock, name, cnt_r, 0);
	name[cnt_r] = '\0';
	// check
	printf("name : %s \n", name);




	// file create
	FILE* src, *des;
	
	size_t fileSize;

	errno_t src_err;
	errno_t des_err;
	src_err = fopen_s(&src, "aa.jpg", "rb");
	des_err = fopen_s(&des, "b.jpg", "wb");
	if (src_err != 0 || des_err != 0) return -1;
		
	// fread
	while ((fileSize = fread(temp, sizeof(char), sizeof(temp), src)) > 0)
	{
		// fwrite(temp, sizeof(char), fileSize, des); //test

		// ������
		send(hClntSock, temp, fileSize, 0);
	}
		

	fclose(src);
	fclose(des);


	

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