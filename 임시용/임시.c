// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	�迭 A�� �迭 B ����
	�迭 A�� ����� ���ÿ� �׸���� �ʱ�ȭ
	�� �Ŀ� �迭 B�� �׸���� �ʱ�ȭ�� �ϵ�, �ݵ�� !!
	�迭 A�� ����� ���� �̿��ؼ� �ʱ�ȭ ����.
	*/

	int arrA[2][4] = { 1,2,3,4,5,6,7,8 };
	int arrB[4][2];
	int i, j;

	printf("arrA: \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			arrB[j][i] = arrA[i][j];
			printf("%4d", arrA[i][j]);
		}
		printf("\n\n");
	}

	printf("arrB: \n");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
				printf("%4d", arrB[i][j]);
			printf("\n");
		}

	return 0;
}
