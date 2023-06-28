// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	num1.100으로 선동초
	num2.100으로 선동초
	정수형 포인터변수 pnum선언

	pnum을 num1의 주소로 초기화
	pnum을 활용해서 num1의 값 30 증가 << 30으로 만들라는게 아니라

	pnum을 num2의 주소로 초기화
	pnum을 활용해서 num1의 값 30 감소 << 30으로 만들라는게 아니라

	num1, num2 출력
	*/

	int num1 = 100, num2 = 100;
	int* pnum;

	pnum = &num1;
	*pnum += 30;
	
	pnum = &num2;
	*pnum -= 30;

	printf("num1: %d, num2: %d \n", num1, num2 );

	return 0;
}
