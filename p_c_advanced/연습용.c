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