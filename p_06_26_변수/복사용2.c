// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	10���� ���·� ������ �ϳ� �Է� ���� ����,
	�̸� 2������ ��ȯ�ؼ� ����ϴ� ���α׷� �ۼ�

	����: main�Լ����� �ۼ�
	if (num % 2 == 1) arr[0] = 1; -> �̷��� ����
	*/

	// ����
	int arr[100];
	int i, num;
	printf("10���� ���� �Է� : ");
	scanf_s("%d", &num);

	// ó��
	for (i = 0; num > 0; i++)
	{
		arr[i] = num % 2;
		num /= 2;
	}

	// ���
	for (i--; i >= 0; i--)
		printf("%d", arr[i]);


	return 0;
}
