#pragma region �迭�� �հ�� ���
// start
// #include "header.h"
#include <stdio.h>


int main()
{
	/*
	������ �� 3���� �Է¹޾Ƽ� �迭�� ����
	�հ�� ��� ��� ( ����� �Ҽ��� 1�ڸ����� )
	*/

	int arr[3] = { 0 };
	int arrLen, i, sum = 0;

	arrLen = sizeof(arr) / sizeof(int);

	for (i = 0; i < arrLen; i++)
	{
		printf("input: ");
		scanf_s("%d", &arr[i]); // �Է�
		sum += arr[i]; // ó��
	}
	printf("sum: %d, avg: %.1f", sum, (double)sum / (double)arrLen);

	return 0;
}
#pragma endregion



#pragma region �迭�� �ִ밪, �ּҰ� ( ���� ���� )
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	int arr[5] = { 0, };
	int i, arrLen, max, min, sum = 0;
	arrLen = sizeof(arr) / sizeof(int);

	// �Է� for��
	printf("input 5 numbes: ");
	for (i = 0; i < arrLen; i++)
		scanf_s("%d", &arr[i]);

	// ó�� for��
	max = arr[0];
	min = arr[0];
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

#pragma endregion



#pragma region �迭�� �ִ밪 �ּҰ� sum�� min max ��ģ��
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	int arr[5] = { 0, };
	int i, arrLen, max, min, sum;

	arrLen = sizeof(arr) / sizeof(int);

	// �Է� for��
	printf("input 5 numbes: ");
	for (i = 0; i < arrLen; i++)
		scanf_s("%d", &arr[i]);

	// ó�� for��
	min = max = sum = arr[0];
	// i = 0 �̸� arr[0]�� arr[0]�� ���ϸ鼭 �����ϱ� ������
	// i = 1 �� �ٲ� ��
	for (i = 1; i < arrLen; i++)
	{
		// ���׿����ڴ� if�� else ���� ���� �� ���� �� !! ( �� ���̸� �������� �ƴ϶� )
		if (max < arr[i]) max = arr[i];
		else if (min > arr[i]) min = arr[i]; // else if ¿����
		sum += arr[i];
	}

	// ���
	printf("Max: %d \n", max);
	printf("Min: %d \n", min);
	printf("Sum: %d \n", sum);

	return 0;
}
#pragma endregion



