// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	10진수 형태로 정수를 하나 입력 받은 다음,
	이를 2진수로 변환해서 출력하는 프로그램 작성

	조건: main함수에서 작성
	if (num % 2 == 1) arr[0] = 1; -> 이런거 금지
	*/

	// 선언
	int arr[100];
	int i, num;
	printf("10진수 정수 입력 : ");
	scanf_s("%d", &num);

	// 처리
	for (i = 0; num > 0; i++)
	{
		arr[i] = num % 2;
		num /= 2;
	}

	// 출력
	for (i--; i >= 0; i--)
		printf("%d", arr[i]);


	return 0;
}
