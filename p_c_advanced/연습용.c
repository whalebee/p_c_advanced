// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	가로의 길이가 9, 세로의 길이가 3인 int형 2차원 배열 선언하고
	구구단 중에 2,3,4단을 저장해라

	확인하기 위한 출력
	*/

	int gugudan[3][9];
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 9; j++)
			gugudan[i][j] = (i + 2) * (j + 1); // 연산 우선순위 생각

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 9; j++)
			printf("%3d ", gugudan[i][j]);
		printf("\n");
	}
	
	
	return 0;
}
