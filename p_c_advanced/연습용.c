// start
// #include "header.h"
#include <stdio.h>

void rotate(char* en, int* n1, int* n2, int* n3);

int main()
{
	/*
	main함수는 정수 1,2,3을 차례대로 출력한다.
	엔터가 입력시 roate함수를 호출하고 그 결과를 받아서 출력
	단, 엔터 이외의 값이 들어오면 프로그램을 종료 !
	rotate함수는 아래와 같이 1:2:3을 차례대로 섞어주는 함수이다.
	*/
	int num1 = 1, num2 = 2, num3 = 3;
	char enter = '\n';
	
	printf("%d:%d:%d\n", num1, num2, num3);

	while (enter == '\n')
	{
		scanf_s("%c", &enter, (unsigned int)sizeof(enter));
		rotate(&enter, &num1, &num2, &num3);
		printf("%d:%d:%d", num1, num2, num3);
	}

	return 0;
}

void rotate(char* en, int* n1, int* n2, int* n3)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = *n3;
	*n3 = temp;
}


