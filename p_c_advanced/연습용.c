// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	���̰� 10�� �迭�� �����ϰ� �� 10���� ������ �Է� �޴´�
	��, �Է� ���� ���ڰ� Ȧ���̸� �迭�� �տ������� ä��������,
	¦���̸� �ڿ������� ä�������� ������ ���Ѵ�.
	���� ����ڰ� [1,2,3,4,5,6,7,8,9,10]�� �Է��ߴٸ�,
	�迭���� [ 1,3,5,7,9,10,8,6,4,2 ] �� ������ ���� main �Լ��� �����ؾ��Ѵ�.
	main 12��
	*/

	int arr[10];
	int i, temp, len, backCnt = 0, frontCnt = 0;
	len = sizeof(arr) / sizeof(int);

	// �Է� & ó��
	printf("�� 10���� ���� �Է� \n");
	for (i = 0; i < len; i++)
	{
		printf("%d��° �Է�: ", i + 1);
		scanf_s("%d", &temp);

		if (temp % 2 == 0)
		{
			arr[len - 1 - backCnt] = temp;
			backCnt++;
		}
		else
		{
			arr[frontCnt] = temp;
			frontCnt++;
		}
	}

	/


	// ���
	printf("�迭 ����� ��� : ");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	return 0;
}