// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	정수형 2차원 배열 int math[2][3]의 항목 값을 각각
	행+열의 값으로 설정한 후에 출력 -> math[1][2]의 값은 3
	math[2][3] 배열을 새로운 2차원 배열 rotateMath[3][2]로 변환하여,
	저장하고 출력

	즉, 2차원 행렬 math[2][3]을 오른쪽, 시게방향으로 회전한 형태로 변환하여 저장

	hint: index로 바꿔서 풀기

	for문 덩어리는 총 2개로 !! ( 기본은 3개가 맞음 )
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