#include <stdio.h>

int GCD(int v1, int v2);

int main()
{
	// 두 개의 정수 입력받아서 최대 공약수를 구하는 프로그램 작성
	// 6과 9를 입력하면 3이 나와야함.
	// 12 : 1 2 3 4 6 12
	// 16 : 1 2 4 8 16
	// 나눴을 때 0 이라고함 -> 힌트네

	int v1, v2;
	printf("두 개의 정수 입력 : ");
	scanf_s("%d %d", &v1, &v2);

	printf("gcd : %d \n", GCD(v1, v2));


	return 0;
}

int GCD(int v1, int v2)
{
	// int i, gcd;
	int result;
	// 여기 밑에 4줄?	 일단 뽑아나보자

	// 너무 더러운데 이게 맞나
	// 다른 조건 result <= v1 > v2 ? v1+1 : v2+1
	result = v1 > v2 ? v1 : v2;
	/*for (; result <= v1 || result <= v2; result--)
		if (v1 % result == 0 && v2 % result == 0) return result;*/
	for (result = 1; result < 1 || result < v2; result++)
		if (v1 % result == 0 && v2 % result == 0) return result;

}