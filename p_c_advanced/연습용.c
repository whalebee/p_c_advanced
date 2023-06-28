// start
// #include "header.h"
#include <stdio.h>

void rotate(int* n1, int* n2, int* n3);

int main()
{
	// 선언
	int num1 = 1, num2 = 2, num3 = 3;
	char enter = '\n';

	// 처리
	while (enter == '\n')
	{
		printf("%d:%d:%d\n", num1, num2, num3);
		scanf_s("%c", &enter, (unsigned int)sizeof(enter));
		rotate(&num1, &num2, &num3);
	}

	return 0;
}

void rotate(int* n1, int* n2, int* n3)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = *n3;
	*n3 = temp;
}