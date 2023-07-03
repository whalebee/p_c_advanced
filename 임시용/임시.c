// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	배열 A와 배열 B 선언
	배열 A는 선언과 동시에 그림대로 초기화
	그 후에 배열 B는 그림대로 초기화를 하되, 반드시 !!
	배열 A에 저장된 값을 이용해서 초기화 진행.
	*/

	int arrA[2][4] = { 1,2,3,4,5,6,7,8 };
	int arrB[4][2];
	int i, j, k;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 2; j++)
		{
			arrB[i][j] = arrA[j][i];
		}
	


	// 출력 합쳐 -> 아니라면?
	// 출력 A
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
