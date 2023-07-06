
#pragma region ������ �迭 ���� �⺻ ����
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*

	*/
	int arr1[3][2]; // �� ��ŭ �ö󰡴±��� ~
	int arr2[2][3];

	printf("arr: %p \n", arr1);				// 000 000 17B68FF878
	printf("arr+1: %p \n", arr1 + 1);		// 000 000 17B68FF880			8�̳�
	printf("arr+2: %p \n", arr1 + 2);		// 000 000 17B68FF888			16�̳פ���

	printf("arr2: %p \n", arr2);			// 000 000 17B68FF8A8
	printf("arr2+1: %p \n", arr2 + 1);		// 000 000 17B68FF8B4			12
	return 0;
}

// 0 1 2 3 4 5 6 7 8 9 a b c d e f





#pragma endregion


#pragma region �迭 ������ ����
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	2�� 2�� �迭 arr1. 1,2,3,4 ������
	3�� 2�� �迭 arr2. 1,2,3,4,5,6 ������
	4�� 2�� �迭 arr3. 1,2,3,4,5,6,7,8 ������

	������ ������ ������ ũ�Ⱑ 2�� ���� ptr ����
	ptr�� arr1�� ������ �ʱ�ȭ
	ptr�� ������ ��ü ��� ���

	ptr�� arr2�� ������ �ʱ�ȭ
	ptr�� ������ ��ü ��� ���

	ptr�� arr3�� ������ �ʱ�ȭ
	ptr�� ������ ��ü ��� ���
	*/
	int i, j;
	int arr1[2][2] = { 1,2,3,4 };
	int arr2[3][2] = { 1,2,3,4,5,6 };
	int arr3[4][2] = { 1,2,3,4,5,6,7,8 };

	int(*ptr)[2];

	ptr = arr1;
	printf("* * Show 2, 2, arr1 * *\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%2d ", ptr[i][j]);
		printf("\n");
	}

	ptr = arr2;
	printf("* * Show 3, 2, arr2 * *\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%2d ", ptr[i][j]);
		printf("\n");
	}

	ptr = arr3;
	printf("* * Show 4, 2, arr3 * *\n");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%2d ", ptr[i][j]);
		printf("\n");
	}


	return 0;
}


#pragma endregion


#pragma region ����� ���� ����
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	num1.10, num2.20, 3�� 30, 4�� 40���� ������

	2�� 4��. arr2d. 1,2,3,4,5,6,7,8 ������

	whoA. num1�� �ּ�, num2�� �ּ�, num3�� �ּ�, num4�� �ּҷ� ������
	whoB. �� �迭(2��4��)�� ������

	whoA�� ����ؼ� ��ü ��� ���
	whoB�� ����ؼ� ��ü ��� ���
	*/
	int i, j;
	int num1 = 10, num2 = 20, num3 = 30, num4 = 40;
	int arr2d[2][4] = { 1,2,3,4,5,6,7,8 };

	// whoA
	int* whoA[4] = { &num1, &num2, &num3, &num4 };
	// �ּҴϱ� ������, 4���ϱ� �迭 -> ������ �迭

	// whoB
	int(*whoB)[4] = arr2d;
	// 2���� �迭�� ������ �� �ִ� ������ -> �迭 ������

	// whoA ��� ���
	printf("--- whoA ---\n");
	for (i = 0; i < 4; i++)
		printf("%d ", *whoA[i]);
	printf("\n");

	// whoB ��� ���
	printf("--- whoB ---\n");
	for (i = 0; i < 2; i++)
		for (j = 0; j < 4; j++)
			printf("%d ", whoB[i][j]);
	printf("\n");

	return 0;
}




#pragma endregion


#pragma region  �迭 �������� ���̿� �Ű����� ����
// start
// #include "header.h"
#include <stdio.h>

#define ARR_COL 4

void showArr2DStyle(int(*arr)[4], int row);
int sum2DArr(int(*arr)[4], int row);

int main()
{
	/*
	2��4�� arr1. 1,2,3,4,5,6,7,8 ������
	3��4�� arr2. 1,1,1,1,3,3,3,3,5,5,5,5 ������

	showArr2DStyle�Լ� ȣ��. ���� arr1, ���
	showArr2DStyle�Լ� ȣ��. ���� arr2, ���

	arr1�� �� ���. sum2DArr�Լ� Ȱ��. ���� arr1, ���
	arr2�� �� ���. sum2DArr�Լ� Ȱ��. ���� arr2, ���

	showArr2DStyle �Լ�
	- ���޹��� ��ü ����� �� ���

	sum2DArr �Լ�
	- ���޹��� ��ü ����� �� ��ȯ!!!!!
	*/

	int arr1[2][4] = { 1,2,3,4,5,6,7,8 };
	int arr2[3][4] = { 1,1,1,1,3,3,3,3,5,5,5,5 };
	// int test[5][2];

	int row1, row2;
	row1 = sizeof(arr1) / sizeof(*arr1); // *arr1 �̷��� �ϸ� ���� ũ�Ⱑ ����
	row2 = sizeof(arr2) / sizeof(*arr2);
	// row2 = sizeof(arr2) / sizeof(arr2[0]);
	/*
	printf("%zd \n", sizeof(*arr1));
	printf("%zd \n", sizeof(*arr2));
	printf("%zd \n", sizeof(*test));
	*/
	/*printf("%zd \n", sizeof(*(test + 0)));
	printf("%zd \n", sizeof(*(test + 1)));*/

	// printf("%d\n\n", row1);
	// printf("%d\n\n", row2);
	// ������� ���ڿ� � ���� ��� ����� ���� ������
	// ���� ���ڷ� �ְ� ���� define -> �ᵵ ��
	showArr2DStyle(arr1, row1);
	showArr2DStyle(arr2, row2);

	printf("arr1�� �� : %d \n", sum2DArr(arr1, row1));
	printf("arr2�� �� : %d \n", sum2DArr(arr2, row2));

	return 0;
}

void showArr2DStyle(int(*arr)[4], int row)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < ARR_COL; j++)
			printf("%d ", arr[i][j]);
	printf("\n");
}

int sum2DArr(int(*arr)[4], int row)
{
	int i, j, result = 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < ARR_COL; j++)
			result += arr[i][j];
	return result;
}



#pragma endregion


#pragma region �Լ��� �Ű����� ����
// start
// #include "header.h"
#include <stdio.h>

typedef struct point
{
	int xPos;
	int yPos;
}Point;

Point getCurrentPosition();
void showPosition(Point curPos);

int main()
{
	/*
	point ����ü ����. �� �̸��� Point�� ����

	main�Լ�
	- point�� ���� curPos. getCurrentPosition�� �������� ������ ������
	- showPosition�Լ� ȣ��. ���ڴ� �˾Ƽ�!

	getCurrentPosition�Լ�
	- ����ڷκ��� x��ǥ, y��ǥ�� �޾Ƽ� ��ȯ!!�ϴ� �Լ�

	showPosition�Լ�
	- ���� ���� ��ǥ ����ϴ� �Լ�
	*/

	/*Point curPos = getCurrentPosition();
	showPosition(&curPos);*/
	showPosition(getCurrentPosition());

	return 0;
}

Point getCurrentPosition()
{
	Point pos = { 0, };
	printf("input current pos: ");
	scanf_s("%d %d", &pos.xPos, &pos.yPos);

	// ����ü ��ü�� �Ѱ������
	return pos;
}

void showPosition(Point curPos)
{
	printf("[%d %d] \n", curPos.xPos, curPos.yPos);
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





