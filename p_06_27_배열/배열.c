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





#pragma region



#pragma endregion





#pragma region



#pragma endregion





#pragma region



#pragma endregion





#pragma region








#pragma region



#pragma endregion





#pragma region



#pragma endregion
#pragma endregion