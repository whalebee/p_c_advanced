#include <stdio.h>



int main()
{
	int num1 = 0, num2 = 0, i, j;

	printf("input 2 numbers: ");
	scanf_s("%d %d", &num1, &num2);

	// ㅋㅋ test1
	// 함수 아닐 때
	// 1. 3,5 일 때 ( 일단 5,3 제외하고 틀 만들어놓기 )
	// 2. 이제 5,3 일 경우도 넣어야지 -> swap말고는 없나? 있나봄 ㄷㄷ
	// swap 없앴음
	for (i = (num1 < num2 ? num1 : num2); i < num1+1 || i < num2+1; i++)
	{
		if (i > (num1 > num2 ? num1 : num2)) break;
		for (j = 1; j < 10; j++) printf("%d x %d = %d \n", i, j, i * j);
		printf("\n");
	}


	return 0;
}


