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
	int i, j, k;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 2; j++)
		{
			arrB[i][j] = arrA[j][i];
		}
	


	// ��� ���� -> �ƴ϶��?
	// ��� A
	printf("arrA: \n");
	for (i = 0, k = 0; i < 2; i++)
	{
		if (j < 4)
		{
			for (j = 0; j < 4; j++)
				printf("%3d", arrA[i][j]);
			printf("\n");
		}
		else
		{
			if (k == 0) printf("arrB: \n");
			for (k = 0; k < 4; k++)
				printf("%3d", arrB[k][i]);
			printf("\n");
		}
		
	}


	return 0;
}
