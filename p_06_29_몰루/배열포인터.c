
#pragma region 포인터 배열 기본
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*

	*/
	int arr[3] = { 10,11,12 };
	printf("%p \n", arr); // 상수 형태의 포인터 ( 주소 값을 바꿀 수 없다 )
	printf("%p \n", &arr[0]);
	printf("%p \n", &arr[1]);
	printf("%p \n", &arr[2]);



	return 0;
}



#pragma endregion


#pragma region 포인터 연산 연습문제 1번
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	// 연습문제 1번
	/*
	길이가 5인 int형 배열 arr을 선언하고 이를 1 2 3 4 5로 초기화 한 다음,
	이 배열의 첫 번째 요소를 가리키는 포인터 변수 ptr을 선언
	그 다음 포인터 변수 ptr에 저장된 값을 증가시키는 형태의 연산을 기반으로
	배열 요소에 접근하면서 모든 배열 요소의 값을 2씩 증가 시키고
	정상적으로 증가가 이뤄졌는지 확인하는 예제를 작성
	*/

	// 피드백
	/*
	for (i = 0; i < len; i++)
		ptr[i] += 2; // -> 이것도 2번 방법이라서 1번은 ++ 써야될 것 같음 -> 맞음
	*/


	// 1번

	// 선언
	int arr[5] = { 1,2,3,4,5 };
	int i, len;
	int* ptr = arr;
	// while (arr[len] != '\0') len++; // NULL값이 없어서 못 씀
	len = sizeof(arr) / sizeof(int);
	// printf("%d", len);

	// 처리
	for (i = 0; i < len; i++)
		*(ptr++) += 2;

	// 확인
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);




	return 0;
}



#pragma endregion


#pragma region 포인터 연산 연습문제 2번
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* 연습문제 2번
	1번 문제에서는 포인터 변수 ptr에 저장된 값을 변경시켜가면서 배열 요소에 접근하라고 했다.
	그런데 이번에는 포인터 변수 ptr에 저장된 값을 변경하는게 아니라,
	ptr을 대상으로 덧셈 연산을 하여
	그 결과로 반환되는 주소 값을 통해서 -> ?
	모든 배열 요소에 접근하여
	값을 2씩 증가 시키는 예제를 작성 !
	*/

	// 2번

	// 선언
	int arr[5] = { 1,2,3,4,5 };
	int i, len;
	int* ptr = arr;

	len = sizeof(arr) / sizeof(int);

	// 처리
	for (i = 0; i < len; i++)
		printf("%d ", ptr[i] + 2);

	// 원래 값 확인
	/*for (i = 0; i < len; i++)
		printf("%d ", arr[i]);*/



	return 0;
}



#pragma endregion


#pragma region 포인터 연산 연습문제 3번
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* 연습문제 3번
	길이가 5인 int형 배열 arr을 선언하고,
	이를 1 2 3 4 5로 초기화 한다음, 이 배열의 마지막 요소를 가리키는 포인터 변수 ptr 선언
	그 다음 포인터 변수 ptr에 저장된 값을 감소시키는 형태의 연산을 기반으로
	모든 배열요소에 접근하여, 배열에 저장된 모든 정수를 더하여,
	그 결과를 출력하는 프로그램을 작성.
	*/

	int arr[5] = { 1,2,3,4,5 };
	int i, len, sum = 0;

	len = sizeof(arr) / sizeof(int);

	int* ptr = &arr[len - 1];

	// 처리
	for (i = 0; i < len; i++)
		sum += *(ptr--);

	// 확인
	printf("sum: %d \n", sum);

	return 0;
}



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion




#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion





