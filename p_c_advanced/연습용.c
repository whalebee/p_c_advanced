// start
// #include "header.h"
#include <stdio.h>

int main()
{
	// ���� ����
	int arr[5] = { 0, };
	int i, arrLen, max, min, sum;
	arrLen = sizeof(arr) / sizeof(int);

	// �Է� for��
	printf("input 5 numbes: ");
	for (i = 0; i < arrLen; i++)
		scanf_s("%d", &arr[i]);

	// ó�� for��
	max = arr[0];
	min = arr[0];
	sum = 0; 
	for (i = 0; i < arrLen; i++)
	{
		// ���׿����ڴ� if�� else ���� ���� �� ���� �� !! ( �� ���̸� �������� �ƴ϶� )
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
		sum += arr[i];
	}

	// ���
	printf("Max: %d \n", max);
	printf("Min: %d \n", min);
	printf("Sum: %d \n", sum);


	return 0;
}