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



#pragma region �������� 1��, �迭�� ����
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	// Good time ���� ����� ���ÿ� Good time ���� �ʱ�ȭ�� ���� ���
	// ���� 3��, �ڵ� 6��

	char arr[] = { 'G','o','o','d',' ','t','i','m','e' };
	int i, arrLen;
	arrLen = sizeof(arr) / sizeof(char);

	// �Է� for��

	// ó�� for��

	// ���
	for (i = 0; i < arrLen; i++)
		printf("%c", arr[i]);

	return 0;
}

#pragma endregion





#pragma region �����ε� ���߿��� while������ ���ڿ� ���� ���� ����� �ִ� !
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	���̰� 50�� char �迭 str ����
	������ ���� idx ����

	"���ڿ� �Է�: " ���
	str�� ����ڷκ��� ���ڿ� �Է� �ޱ�. ( ���Ĺ��� s ��� )
	"�Է¹��� ���ڿ� : ��"��� ( ���Ĺ��� s ��� )

	"���� ���� ���: " ���
	�� ���ھ� ���. ( ���Ĺ��� c ��� )
	*/

	//���ڿ� ����� ���� while�� �Ѵٰ� ��
	/*for (idx = 0; idx < len - 1; idx++)
	{
		printf("%c", str[idx]);
	}*/
	// �� ���� ? �� ������ -> ���̸� �߸��ᳪ��
	// �� 50���� �� ������ �ȵ��� -> ���鳪���� �������� !

	char str[50];
	int idx = 0;
	printf("���ڿ� �Է�: ");
	scanf_s("%s", str, (unsigned int)sizeof(str));
	printf("�Է� ���� ���ڿ�: %s \n", str);

	printf("���� ���� ���: ");
	while (str[idx] != '\0') idx++;
	// ���ڿ��� ���̸� �� �� �ִ� �ݺ��� ( ���߿� )
	printf("%d", idx);

	return 0;
}


#pragma endregion





#pragma region �������� 2��
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	 1. �ϳ��� ���ܾ �Է� �޾�
	 �Է� ���� ���ܾ��� ���̸� ����Ͽ� ����ϴ� ���α׷�
	 input: Array �ϸ� ����: 5

	 2. ���ܾ� �Է¹��� ���� char �迭�� ����
	 ���ܾ �������� ������, �ι��ڴ� �����ϸ� �ȵ�, Ȯ�� ���
	*/

	char arr[50];
	int i, temp, cnt = 4, idx = 0;

	printf("input: ");
	scanf_s("%s", arr, (unsigned int)sizeof(arr));
	while (arr[idx] != '\0') idx++;
	printf("����: %d \n", idx);


	/*printf("������ ���ܾ�: ");
	for (i = idx-1; i >= 0; i--)
		printf("%c", arr[i]);*/
		// ��¶����� �ƴ϶� ������� �ٲ����

	for (i = 0; i < idx; i++, cnt--)
	{
		temp = arr[i];
		arr[i] = arr[cnt];
		arr[cnt] = temp;
		if (arr[i] == arr[cnt]) break;
	}
	printf("������ ���ܾ�: %s \n", arr);

	// idx�� ���ϴ� ���
	/*for (i = 0; i < idx; i++, idx--)
	{
		temp = arr[i];
		arr[i] = arr[idx - 1];
		arr[idx - 1] = temp;
	}
	printf("������ ���ܾ�: %s \n", arr);*/

	return 0;
}



#pragma endregion





#pragma region �������� 3��
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	���ܾ �Է� ���� �� ���� ���ܾ �����ϴ� ���� �߿���
	�ƽ�Ű �ڵ� ���� ���� ū ���ڸ� ã�Ƽ� ����ϴ� ���α׷� �ۼ�

	input: LOVE
	output: V << �갡 �ƽ�Ű �ڵ� ���� ���� ŭ
	*/

	char arr[50];
	int i, max, idx = 0;

	// �Է�
	printf("input: ");
	scanf_s("%s", arr, (unsigned int)sizeof(arr));

	// ó��
	while (arr[idx] != '\0') idx++;
	max = arr[0];
	for (i = 1; i < idx; i++)
		if (max < arr[i]) max = arr[i];

	// ���
	printf("MAX ASCII: %c", max);

	// Ȯ��
	/*for(i = 0; i < idx; i++)
		printf("%d ", arr[i]);*/


	return 0;
}



#pragma endregion





#pragma region ������ �⺻
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	num1.100���� ������
	num2.100���� ������
	������ �����ͺ��� pnum����

	pnum�� num1�� �ּҷ� �ʱ�ȭ
	pnum�� Ȱ���ؼ� num1�� �� 30 ���� << 30���� �����°� �ƴ϶�

	pnum�� num2�� �ּҷ� �ʱ�ȭ
	pnum�� Ȱ���ؼ� num1�� �� 30 ���� << 30���� �����°� �ƴ϶�

	num1, num2 ���
	*/

	int num1 = 100, num2 = 100;
	int* pnum;

	pnum = &num1;
	*pnum += 30;

	pnum = &num2;
	*pnum -= 30;

	printf("num1: %d, num2: %d \n", num1, num2);

	return 0;
}




#pragma endregion





#pragma region ������ �������� 2�� ( swap ) ( 1���� �׸��̿��� )
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* �������� 2��
	1. int�� ���� num1�� num2�� ����� ���ÿ� ���� 10�� 20���� �ʱ�ȭ
	2. int�� ������ ���� ptr1�� ptr2�� �����Ͽ� ���� num1�� num2�� ����Ű������
	3. ptr1�� ptr2�� �̿��ؼ� num1�� ���� 10 ���� ��Ű�� num2�� ���� 10 ���ҽ�Ű��
	4. �� ������ ���� ptr1�� ptr2�� ����Ű�� ����� ���� �ٲ��� (����. &num1 &num2 ���� )
	5. ���������� pt1�� pt2�� ����Ű�� ������ ����� ���� �������.
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


#pragma endregion





#pragma region �߰����� ������ �Լ� �������� 1��
// start
// #include "header.h"
#include <stdio.h>
	// �� �� ���� �� !
	//int* ptr = NULL;
	//int* ptr2 = 0;

void setValue10(int* n1, int* n2, int* n3);

int main()
{
	// ���� ���� 1��
	/*
	main()�Լ����� ������ 3���� int �� ������ ���� ��� 10���� �����ϴ�
	setValue10()�Լ��� �ۼ��Ͻð�,
	num1, 2, 3�� 10, 20, 30���� �������ϸ鼭 ����
	*/

	int num1 = 10, num2 = 20, num3 = 30;

	printf("before : %3d, %3d, %3d \n", num1, num2, num3);
	setValue10(&num1, &num2, &num3);
	printf("after  : %3d, %3d, %3d \n", num1, num2, num3);

	return 0;
}

void setValue10(int* n1, int* n2, int* n3)
{
	*n1 = *n2 = *n3 = 10;
}


#pragma endregion





#pragma region ������ �߰� ���� 2��
// start
// #include "header.h"
#include <stdio.h>

void enterValue(int* mod, int* rem);

int main()
{
	/*
	4�� �������� �� ��� �������� ���ϴ� �Լ��� �����Ϸ� �մϴ�.
	main�Լ������� ������ �Լ� ȣ�� �� ��� ���� ����մϴ�.
	��� �������� ����ϴ� ������ main���� �����մϴ�. (mod, rem)
	���� ��� ������ ��µ� main���� �մϴ�.
	��� �Է��� �߰� �Լ����� �������� !

	����
	���� 3��
	�Լ� 5��

	��)
	��� �Է� : 14
	�� : 3, ������ :2
	*/

	int mod = 0, rem = 0;

	enterValue(&mod, &rem);
	printf("�� : %d, ������ : %d \n", mod, rem);

	return 0;
}

void enterValue(int* mod, int* rem)
{
	int num;
	printf("��� �Է� : ");
	scanf_s("%d", &num);
	*mod = num / 4;
	*rem = num % 4;
}


#pragma endregion





#pragma region








#pragma region



#pragma endregion





#pragma region



#pragma endregion
#pragma endregion