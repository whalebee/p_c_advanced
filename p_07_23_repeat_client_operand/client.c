#include <stdio.h>
#include <stdlib.h>
#include <ws2tcpip.h>
#include <winsock2.h>

#define BUF 1024
#define INT 4

void errorHandling(char* message);

int main(int argc, char* argv[])
{
	// definition
	WSADATA wsadata;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	SSIZE_T recvLen, strLen;

	int i, j;
	char result[INT]; // define to char because of second parameter of recv function -> char* buf 
	char arr[BUF]; // array
	int count, forgetchar; // count, getchar
	int temp; // scanf_s


	// parameter check
	if (argc != 3)
	{
		printf("Usage: %s <IP> <PORT> \n", argv[0]);
		exit(1);
	}

	// init
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		errorHandling("WSAstartup() error");

	// socket
	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET)
		errorHandling("socket() error");

	// memset init
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	inet_pton(AF_INET, argv[1], &servAddr.sin_addr); // <ws2tcpip.h>
	servAddr.sin_port = htons(atoi(argv[2]));

	// connect
	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		errorHandling("connect() error");
	else
		printf("connected......................\n");


	// input
	while (1)
	{
		// count
		printf("operand count ( input 0 to quit ): ");
		scanf_s("%c", &arr[0], (unsigned int)sizeof(int));
		count = atoi(&arr[0]);
		if (count == 0) break;
		printf("받은 카운트는 : %d \n", count);


		// scanf_s
		j = 1;
		for (i = 1; i < count * INT; i += INT)
		{
			printf("operand %d :", j++);
			scanf_s("%d", (int*)&arr[i]);
			forgetchar = getchar();
			/*scanf_s("%d", &temp);
			arr[i + 0] = temp;
			arr[i + 1] = temp >> 8;
			arr[i + 2] = temp >> 16;
			arr[i + 3] = temp >> 24;*/
		}
		
		// i = 0부터 시작하는게 좋다.
		for (i = 1; i < count * INT; i += INT)
			printf("입력된 값들: %d \n", *((int*)(arr + i)));

		// arr[i] -> 참조값
		// (int*) -> 포인터
		// 결과: *((int*)&(arr[i])) 엉망이네ㅋㅋ
		
		// (arr+i) -> 주소값
		// (int*) -> 포인터
		// *(  ) -> 참조값
		// 결과 *((int*)(arr + i))


		// operator
		printf("operator: ");
		scanf_s("%c", &arr[count * INT + 2], (unsigned char)sizeof(char));
		forgetchar = getchar();


		// send & recv
		strLen = send(hSocket, arr, sizeof(int) * count + 3, 0);
		if (strLen == -1) errorHandling("send() error");
		printf("클라에서 보내는바이트는? %d \n", (int)strLen);


		recvLen = recv(hSocket, result, sizeof(result), 0);
		if (recvLen == -1) errorHandling("recv() error");
		printf("클라에서 받은바이트는? %d \n", (int)recvLen);

		// result
		printf("Result from server : %d \n", *((int*)result));


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