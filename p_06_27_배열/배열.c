#pragma region 배열의 합계와 평균
// start
// #include "header.h"
#include <stdio.h>


int main()
{
	/*
	정수형 값 3개를 입력받아서 배열에 저장
	합계와 평균 출력 ( 평균은 소수점 1자리까지 )
	*/

	int arr[3] = { 0 };
	int arrLen, i, sum = 0;

	arrLen = sizeof(arr) / sizeof(int);

	for (i = 0; i < arrLen; i++)
	{
		printf("input: ");
		scanf_s("%d", &arr[i]); // 입력
		sum += arr[i]; // 처리
	}
	printf("sum: %d, avg: %.1f", sum, (double)sum / (double)arrLen);

	return 0;
}
#pragma endregion



#pragma region 배열의 최대값, 최소값 ( 정렬 ㄴㄴ )
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	int arr[5] = { 0, };
	int i, arrLen, max, min, sum = 0;
	arrLen = sizeof(arr) / sizeof(int);

	// 입력 for문
	printf("input 5 numbes: ");
	for (i = 0; i < arrLen; i++)
		scanf_s("%d", &arr[i]);

	// 처리 for문
	max = arr[0];
	min = arr[0];
	for (i = 0; i < arrLen; i++)
	{
		// 삼항연산자는 if와 else 같이 써질 때 쓰는 것 !! ( 한 줄이면 무조건이 아니라 )
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
		sum += arr[i];
	}

	// 출력
	printf("Max: %d \n", max);
	printf("Min: %d \n", min);
	printf("Sum: %d \n", sum);

	return 0;
}

#pragma endregion



#pragma region 배열의 최대값 최소값 sum과 min max 합친거
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	int arr[5] = { 0, };
	int i, arrLen, max, min, sum;

	arrLen = sizeof(arr) / sizeof(int);

	// 입력 for문
	printf("input 5 numbes: ");
	for (i = 0; i < arrLen; i++)
		scanf_s("%d", &arr[i]);

	// 처리 for문
	min = max = sum = arr[0];
	// i = 0 이면 arr[0]과 arr[0]을 비교하면서 시작하기 때문에
	// i = 1 로 바꾼 것
	for (i = 1; i < arrLen; i++)
	{
		// 삼항연산자는 if와 else 같이 써질 때 쓰는 것 !! ( 한 줄이면 무조건이 아니라 )
		if (max < arr[i]) max = arr[i];
		else if (min > arr[i]) min = arr[i]; // else if 쩔었다
		sum += arr[i];
	}

	// 출력
	printf("Max: %d \n", max);
	printf("Min: %d \n", min);
	printf("Sum: %d \n", sum);

	return 0;
}
#pragma endregion



