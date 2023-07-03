// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	������ 2���� �迭 int math[2][3]�� �׸� ���� ����
	��+���� ������ ������ �Ŀ� ��� -> math[1][2]�� ���� 3
	math[2][3] �迭�� ���ο� 2���� �迭 rotateMath[3][2]�� ��ȯ�Ͽ�,
	�����ϰ� ���

	��, 2���� ��� math[2][3]�� ������, �ðԹ������� ȸ���� ���·� ��ȯ�Ͽ� ����

	hint: index�� �ٲ㼭 Ǯ��
	*/

	int math[2][3];
	int rotateMath[3][2];
	int i, j;

	// �Է�
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			math[i][j] = i + j;

	
	// ó�� -> ó���� �������� �� ��
	/*for (i = 0; i < 3; i++)
	{
		rotateMath[i][0] = math[1][i];
		rotateMath[i][1] = math[0][i];
	}*/

	/* �� �ε����� �׸� ������ ������ ã�ƺ� ��
	i j    j i				i j	   j i
	0,0 -> 1 0				0,1 -> 0 0
	1,0 -> 1 1				1,1 -> 0 1
	2,0 -> 1 2				2,1 -> 0,2
	*/

	// ��Ģ ã�� �ڿ� ����
	for (i = 0; i < 3; i++)
		for (j = 0; j < 2; j++)
			rotateMath[i][j] = math[(j + 1) % 2][i];

	// ��� -> �̰Ÿ� ��� ���ľ��ϳ�?
	printf("--- math[2x3] --- \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%3d ", math[i][j]);
		printf("\n");

	}
		

	printf("--- rotateMath[3x2] --- \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%3d ", rotateMath[i][j]);
		printf("\n");
	}

	return 0;
}
