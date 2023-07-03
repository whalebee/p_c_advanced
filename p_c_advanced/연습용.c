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
	*/

	int math[2][3];
	int rotateMath[3][2];
	int i, j;

	// 입력
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			math[i][j] = i + j;

	
	// 처리 -> 처음엔 수동으로 할 것
	/*for (i = 0; i < 3; i++)
	{
		rotateMath[i][0] = math[1][i];
		rotateMath[i][1] = math[0][i];
	}*/

	/* 꼭 인덱스로 그린 다음에 패턴을 찾아볼 것
	i j    j i				i j	   j i
	0,0 -> 1 0				0,1 -> 0 0
	1,0 -> 1 1				1,1 -> 0 1
	2,0 -> 1 2				2,1 -> 0,2
	*/

	// 규칙 찾고난 뒤에 적용
	for (i = 0; i < 3; i++)
		for (j = 0; j < 2; j++)
			rotateMath[i][j] = math[(j + 1) % 2][i];

	// 출력 -> 이거를 어떻게 합쳐야하나?
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
