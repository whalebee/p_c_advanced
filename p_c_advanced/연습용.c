// start
// #include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>


int main()
{
	/*

	*/
	int i;
	char count = 0;
	char arr[100];
	while (1)
	{
		fputs("Operand count: ", stdout);
		gets(&arr[0], sizeof(char), stdin);

		// �ϴ� ���������� ������� �غ���, ���!!���� �����α���
		// arr[0] = count;
	

		for (i = 0; i < 3; i++)
		{
			printf("Operand %d :", i + 1);
			// gets(&arr[i+1], sizeof(char), stdin);

			scanf_s("%d", (int*) & arr[i*4 + 1], (unsigned int)sizeof(char));
			getchar();
			printf("%c ", arr[i]);
		}
		

		break;
	}


	return 0;
}
