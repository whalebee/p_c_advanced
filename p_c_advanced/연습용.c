// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	������ ���̰� 9, ������ ���̰� 3�� int�� 2���� �迭 �����ϰ�
	������ �߿� 2,3,4���� �����ض�

	Ȯ���ϱ� ���� ���
	*/

	int gugudan[3][9];
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 9; j++)
			gugudan[i][j] = (i + 2) * (j + 1); // ���� �켱���� ����

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 9; j++)
			printf("%3d ", gugudan[i][j]);
		printf("\n");
	}
	
	
	return 0;
}
