
#pragma region �������� -> ����� �������ϱ� ( ���� ���� )
// start
// #include "header.h"
#include <stdio.h>

int record[5][5];
void writeRecord();
void writeSumRecord();
void showAllRecord();

int main()
{
	/*
	�������� ���α׷� �ۼ�
	4�����̰� �л��� �� ����̴� !
	�� �׻���� �� ���� ������ �Է¹޴´�.
	������ ���� ����
	�̸� ������ ���� �迭�� ������ ���·� �� ���� ����.

	������ ���� �� ���¿���
	�� � �͵� ������ �ȵ� -> ���ʿ� ���� �ʿ䰡 ����
	No Touch Zone��
	*/

	writeRecord();		// �Է�
	writeSumRecord();	// ���� ���ϴ� �Լ� ( 9ĭ )
	showAllRecord();	// ���� ������


	return 0;
}
void writeRecord()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		printf("%d��° �л��� ���� �Է� \n", i + 1);
		for (j = 0; j < 4; j++)
		{
			printf("���� %d: ", j + 1);
			scanf_s("%d", &record[i][j]);
		}
	}
}


/*
	0,4		1,4		2,4		3,4
	4,4
	4,0		4,1		4,2		4,3
*/
void writeSumRecord()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			record[i][4] += record[i][j]; // ������ �հ�
			record[4][j] += record[i][j]; // �� �հ�
		}
		record[4][4] += record[i][4]; // �� �հ� // ���� ~
	}
}

void showAllRecord()
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%3d ", record[i][j]);
		printf("\n");
	}
}




#pragma endregion


#pragma region ����� �������ϱ� 2��° ����
// start
// #include "header.h"
#include <stdio.h>

int record[5][5];
void writeRecord();
void writeSumRecord();
void showAllRecord();

int main()
{
	/*
	�������� ���α׷� �ۼ�
	4�����̰� �л��� �� ����̴� !
	�� �׻���� �� ���� ������ �Է¹޴´�.
	������ ���� ����
	�̸� ������ ���� �迭�� ������ ���·� �� ���� ����.

	������ ���� �� ���¿���
	�� � �͵� ������ �ȵ� -> ���ʿ� ���� �ʿ䰡 ����
	*/

	writeRecord();		// �Է�
	writeSumRecord();	// ���� ���ϴ� �Լ� ( 9ĭ )
	showAllRecord();	// ���� ������

	return 0;
}
void writeRecord()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		printf("%d��° �л��� ���� �Է� \n", i + 1);
		for (j = 0; j < 4; j++)
		{
			printf("���� %d: ", j + 1);
			scanf_s("%d", &record[i][j]);
			record[i][4] += record[i][j];
		}
	}
}


/*
	0,4		1,4		2,4		3,4
	4,4
	4,0		4,1		4,2		4,3
*/
// record[i][4] += record[i][j]; // ������ �հ�
void writeSumRecord()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			record[4][j] += record[i][j]; // �� �հ�
		record[4][4] += record[i][4]; // �� �հ� // ���� ~
	}
}

void showAllRecord()
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%3d ", record[i][j]);
		printf("\n");
	}
}


#pragma endregion


#pragma region ���� ������ �⺻ ����
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*

	*/
	double num = 3.14;
	double* ptr = &num;
	double** dptr = &ptr;

	printf("%p \n", ptr);
	printf("%p \n", *dptr);

	printf("%g \n", num);
	printf("%g \n", **dptr);

	double* ptr2;
	ptr2 = *dptr;
	*ptr2 = 10.99;

	printf("%g \n", num);
	printf("%g \n", **dptr);

	return 0;
}

#pragma endregion


#pragma region �������� -> ���� �������� Ȱ�� 
// start
// #include "header.h"
#include <stdio.h>


void MaxAndMin(int* arr, int len, int** maxPtr, int** minPtr);

int main()
{
	/* ��������
	������ ���� �ΰ��� int�� ������ ������ ���̰� 5�� int�� �迭�� �����Ѵ�.

	�׸��� MaxAndMin�̶� �̸��� �Լ��� ����
	ȣ���ϸ鼭 �� ������ ������ ���� ������ ����
	��� ������ ��� ���������� ������ ����
	�Լ� ȣ���� �Ϸ�Ǹ�, ������ ���� maxPtr���� ���� ū ���� �����
	�迭����� �ּ� ��!!!��,
	minPtr���� ���� ���� ���� ����� �迭 ����� �ּ� ��!!!!�� �����.

	���� 5�� ( ���� ���� )
	�Լ� 6��
	*/
	int* maxPtr;
	int* minPtr;
	int arr[5];
	int i, len;
	len = sizeof(arr) / sizeof(int);

	// �迭�� �� �Է�
	for (i = 0; i < len; i++)
	{
		printf("���� �Է� %d : ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	// �Լ� ȣ��
	MaxAndMin(arr, len, &maxPtr, &minPtr);

	printf("�ִ�: %d, �ּ�: %d", *maxPtr, *minPtr);

	return 0;
}
// ������ ������ �ּҰ��� �޴� ���������� dM??Ptr
void MaxAndMin(int* arr, int len, int** dMaxPtr, int** dMinPtr)
{
	int i;
	// 1�ٷ�
	*dMinPtr = *dMaxPtr = &arr[0]; // �ּҰ��� arr�� �ּҰ����� ���� 

	// �ּҰ��� �����ϴ� �ݺ����� ����� ��?
	for (i = 1; i < len; i++)
	{
		if (**dMaxPtr < arr[i]) *dMaxPtr = &arr[i]; // +1 ����
		if (**dMinPtr > arr[i]) *dMinPtr = &arr[i];
	}
}


#pragma endregion


#pragma region ����ü ����
// start
// #include "header.h"
#include <stdio.h>
#include <math.h>
struct point {
	int xpos;
	int ypos;
};

int main()
{
	/* ����
	point�� ����ü ����
	- ����� ������ xpos ����
	- ����� ������ ypos ����

	main�Լ�����
	- point�� ���� pos1, pos2 ����
	- �Ǽ� ���� �׸� distance ����
	- "point 1 pos: " ���, �� fputs ���
	- pos1�� x��ǥ, y��ǥ �Է� �ޱ�
	- "point 2 pos: " ���, �� fputs ���
	- pos1�� x��ǥ, y��ǥ �Է� �ޱ�

	- distance ���ϱ�.
	->(x��ǥ������ �� x x��ǥ������ �� ) + (y��ǥ������ �� x y��ǥ������ �� )�� ����
		��Ʈ�� �����
	-> sqrt�Լ� ���. �Ҽ� math.h
	- "�� ���� �Ÿ��� ���Դϴ�." ��� pritnf ���
	*/


	struct point pos1;
	struct point pos2;
	double distance;

	fputs("point 1 pos: ", stdout);
	scanf_s("%d %d", &pos1.xpos, &pos1.ypos);

	fputs("point 2 pos: ", stdout);
	scanf_s("%d %d", &pos2.xpos, &pos2.ypos);

	distance = sqrt((pos1.xpos - pos2.xpos) * (pos1.xpos - pos2.xpos) + (pos1.ypos - pos2.ypos) * (pos1.ypos - pos2.ypos));

	// printf("%d", ~(pos1.xpos - pos2.xpos)+1);
	printf("�� ���� �Ÿ��� %.1f�Դϴ�.", distance);

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





