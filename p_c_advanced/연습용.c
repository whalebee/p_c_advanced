// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* 이건 예제
	num1. 10으로 선동초
	num2. 20으로 선동초
	num3. 30으로 선동초
	길이가 3인 정수형 포인터 배열 arr. num1의 주소, num2의 주소, num3의 주소로 선동초
	arr을 활용해서 전체 요소 출력
	*/
	int num1 = 10, num2 = 20, num3 = 30, i, len;
	int* arr[3] = { &num1, &num2, &num3 };
	len = (sizeof(arr)/2) / sizeof(int);

	for (i = 0; i < len; i++)
		printf("%d ", *(arr[i]));

	return 0;
}
