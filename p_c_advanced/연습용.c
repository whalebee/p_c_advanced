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

	printf("num1: %d, num2: %d \n", num1, num2 );

	return 0;
}
