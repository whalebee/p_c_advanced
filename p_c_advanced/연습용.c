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

	for�� ����� �� 2���� !! ( �⺻�� 3���� ���� )
	*/

	int math[2][3];
	int rotateMath[3][2];
	int i, j;

	printf("--- math[2x3] --- \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			math[i][j] = i + j;
			printf("%d ", math[i][j]);
			rotateMath[j][(i + 1) % 2] = math[i][j];
		}
		printf("\n");
	}
	
	printf("--- rotateMath[3x2] --- \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%d ", rotateMath[i][j]);
		printf("\n");
	}





	return 0;
}