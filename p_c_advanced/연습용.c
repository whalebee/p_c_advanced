// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* �̰� ����
	num1. 10���� ������
	num2. 20���� ������
	num3. 30���� ������
	���̰� 3�� ������ ������ �迭 arr. num1�� �ּ�, num2�� �ּ�, num3�� �ּҷ� ������
	arr�� Ȱ���ؼ� ��ü ��� ���
	*/
	int num1 = 10, num2 = 20, num3 = 30, i, len;
	int* arr[3] = { &num1, &num2, &num3 };
	len = (sizeof(arr)/2) / sizeof(int);

	for (i = 0; i < len; i++)
		printf("%d ", *(arr[i]));

	return 0;
}
