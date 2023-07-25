#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define BUF 1024

void errorHandling(char* message);

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	char message[30];
	int strLen;

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



	// new def
	SSIZE_T ckCntWrLen, ckStrWrLen;
	
	size_t sendCnt;


	char fileName[BUF];
	char temp[BUF];

	// file name scanf_s
	printf("Input file name: ");
	fgets(fileName, BUF, stdin);
	// scanf_s("%s", fileName, (unsigned char)sizeof(fileName));

	// file name cnt
	sendCnt = strlen(fileName);
	printf("sendCnt : %zd \n", sendCnt);

	// send cnt
	ckCntWrLen = send(hSocket, (char*)&sendCnt, sizeof(int), 0);

	// send str
	ckStrWrLen = send(hSocket, fileName, (int)sendCnt, 0);


	

	// recv cnt



	// create jpg
	FILE* fp;
	errno_t ckError;
	ckError = fopen_s(&fp, "bb.jpg", "wb");
	if (ckError != 0) return -1;

	

	// recv str
	while (recv(hSocket, temp, sizeof(char), 0) != 0)
		fwrite(temp, sizeof(char), sizeof(char), fp);


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