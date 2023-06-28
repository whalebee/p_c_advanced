// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* 연습문제 2번
	1. int형 변수 num1과 num2를 선언과 동시에 각각 10과 20으로 초기화
	2. int형 포인터 변수 ptr1과 ptr2를 선언하여 각각 num1과 num2를 가리키게하자
	3. ptr1과 ptr2를 이용해서 num1의 값을 10 증가 시키고 num2의 값을 10 감소시키자
	4. 두 포인터 변수 ptr1과 ptr2가 가리키는 대상을 서로 바꾸자 (조건. &num1 &num2 금지 )
	5. 마지막으로 pt1과 pt2가 가리키는 변수에 저장된 값을 출력하자.	
	*/

	// 1 ~ 2
	int num1 = 10, num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int* temp;

	// 3
	*ptr1 += 10; // num1 == 20
	*ptr2 -= 10; // num2 == 10

	// 4
	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
	
	// 5
	printf("ptr1: %d \nptr2: %d ", *ptr1, *ptr2);


	return 0;
}