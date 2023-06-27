// start
// #include "header.h"
#include <stdio.h>

int main()
{
	// 아직 못한
	int arr[5] = { 0, };
	int i, arrLen, max, min, sum;
	arrLen = sizeof(arr) / sizeof(int);

	// 입력 for문
	printf("input 5 numbes: ");
	for (i = 0; i < arrLen; i++)
		scanf_s("%d", &arr[i]);

	// 처리 for문
	max = arr[0];
	min = arr[0];
	sum = 0; 
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