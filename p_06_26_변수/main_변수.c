#pragma region static

#include <stdio.h>

void simpleFunc();

int main()
{
	/*
	main
	: simpleFunc 함수 3번 호출. 인자x
	3번 호출이면 반복문 써라 걍 쓰지말고

	simpleFunc 함수
	- num1. 0으로 선동초(??) ( 단, num1은 static 변수 )
	- num2. 0으로 선동초(???) ( 선언과 동시에 초기화 ㅋㅋ )
	- num1, num2 1씩 증가
	- num1, num2 출력
	*/
	int i;
	for (i = 0; i < 3; i++)
		simpleFunc();

	return 0;
}

void simpleFunc()
{
	static int num1 = 0;
	// 호출이 되지 않아도 static은 선언이 됨 ( 어차피 근데 여기 안에서만 노니까 딱히 상관없음 )
	int num2 = 0;
	num1++;
	num2++;
	printf("num1: %d, num2 : %d \n", num1, num2);
}



#pragma endregion


#pragma region factorial 재귀함수 (기초)
#include <stdio.h>

int fac(int value);

int main()
{
	int num;
	printf("input: ");
	scanf_s("%d", &num);
	if (num < 0) return -1;
	printf("%d! : %d ", num, fac(num));

	return 0;
}

int fac(int value)
{
	if (value == 0) return 1;
	return value * fac(value - 1);
}


#pragma endregion





#pragma region 1번과 2번
#include <stdio.h>

void gugudan(int n1, int n2);

int main()
{
	// 16진수
	/*
	int num = 0;
	printf("input: ");
	scanf_s("%d", &num);
	printf("16진수화: %x", num);
	*/



	// 2번
	// 변수 4개로 해야함
	int num1 = 0, num2 = 0, i, j;

	printf("input 2 numbers: ");
	scanf_s("%d %d", &num1, &num2);

	// 함수 아닐 때
	// 1. 3,5 일 때 ( 일단 5,3 제외하고 틀 만들어놓기 )
	// 2. 이제 5,3 일 경우도 넣어야지 -> swap말고는 없나? 있나봄 ㄷㄷ
	i = (num1 < num2 ? num1 : num2);
	for (; i < 10; i++)
	{
		if (i >= num1 && i >= num2) break;

		for (j = 1; j < 10; j++) printf("%d x %d = %d \n", i, j, i * j);

		printf("\n");



		// 함수 구현으로 했을 때 -> 함수 아니여도 됨
		// int num1 = 0, num2 = 0;
		// gugudan(num1, num2);


		return 0;
	}




	void gugudan(int n1, int n2)
	{
		int temp, j = 0;

		if (n1 > n2)
		{
			temp = n1;
			n1 = n2;
			n2 = temp;
		}
		for (; n1 < 10; n1++)
		{
			if (n1 > n2) break;
			for (j = 1; j < 10; j++)
				printf("%d x %d = %d \n", n1, j, n1 * j);
			printf("\n");
		}
	}





#pragma endregion






#pragma region 3번 문제 못풀음 -> while로 푸셈
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

//int GCD(int v1, int v2)
//{
//	// int i, gcd;
//	int result;
//	// 여기 밑에 4줄?	 일단 뽑아나보자
//
//	// 너무 더러운데 이게 맞나
//	// 다른 조건 result <= v1 > v2 ? v1+1 : v2+1
//	result = v1 > v2 ? v1 : v2;
//	for (; result <= v1 || result <= v2; result--)
//		if (v1 % result == 0 && v2 % result == 0) return result;
//}

// while
int GCD(int v1, int v2)
{
	// int i, gcd; // 더러워 !
	// 여기 밑에 4줄?	 일단 뽑아나보자
	// result = v1 > v2 ? v1 : v2;
	int result;
	result = v1;
	while (result)
	{
		if (v1 % result == 0 && v2 % result == 0) return result;
		result--;
	}
	return 0;

	// 강사님 버전
	//int result = v1 < v2 ? v1 : v2;
	//while (v1 % result != 0 || v2 % result != 0)
	//	result--;
	//return result;


}

//int GCD(int n1, int n2)
//{
//	int result;
//
//	while (n2 != 0) {
//		result = n1 % n2;
//		n1 = n2;
//		n2 = result;
//	}
//	return n1;
//}




#pragma endregion



#pragma region 4번 반복문에서 상수를 쓰지 않는다네
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	3500원을 가지고 맥콜(500원), 코카콜라(700원), 쿠우(400원)을 사려한다.
	잔돈을 안 남기고 이 세가지 물건을 하나 이상 반드시 구매하려면
	어떻게 구매를 진행해야 하는가?
	여러가지 경우의 수가 있을텐데 제시해보셈

	ex
	현재 소유금액 3500원
	맥콜 1개, 코카콜라 2개, 쿠 우 4개
	맥콜 2개, 코카콜라 3개, 쿠 우 1개
	맥콜 4개, 코카콜라 1개, 쿠 우 2개

	어떻게 구입할래요?
	*/
	// A Z 힌트

	// 결정적 힌트가 A Z 라면 왜 이게 결정적인지부터 천천히 생각해보셈
	// AZ가 printf에서 장난치는 문제였는데
	// 그럼 여기에도?

	// printf("맥콜 %d개, 코카콜라 %d개, 쿠 우 %d개 \n", );

	// 124 231 412 이게 가로 세로 다 나오네
	// 그럼 저 값을 어떻게 찾아야하나??

	// 500		1400	1600
	// 1000		2100	400
	// 2000		700		800

	// 1		2		4
	// 2		3		1
	// 4		1		2

	// A돌리고 Z돌리고?

	int basic = 0, x, y, z;
	int mac = 500, coke = 700, coou = 400;
	printf("현재 당신이 소유하고 있는 금액 : ");
	scanf_s("%d", &basic);
	// 원 단위가 아니라 개수로 돌려라
	for (x = 1; x <= basic / mac; x++)
		for (y = 1; y <= basic / coke; y++)
			for (z = 1; z <= basic / coou; z++)
			{
				if (basic == (x * mac) + (y * coke) + (z * coou))
					printf("맥	콜 %d개,  코카콜라 %d개,  쿠	우 %d개 \n", x, y, z);
			}


	return 0;
}


#pragma endregion



#pragma region 5번 드디어 풀었다
// start
// #include "header.h"
#include <stdio.h>

int isPrime(int num);

int main()
{
	/*
	5. 양수를 하나 입력 받아 1부터 그 수까지의 소수를 출력
	1과 자기자신밖에 없는 녀석
	이걸 어떻게 구할까
	*/

	int num, i, cnt = 0;
	printf("양수 입력 : ");
	scanf_s("%d", &num);

	// 소수냐 아니냐만 반환을 해서 소수면 i를 출력하고 아니면 넘기고?
	// for (i = 2; i < num+1; i++) // 쌤은 이렇게 씀
	for (i = 2; i < num; i++)
	{
		if (isPrime(i) == 1)
		{
			printf("%3d ", i);
			cnt++;
		}
		else continue;
		if (cnt % 5 == 0) printf("\n");
	}
	return 0;
}

// True False ?
int isPrime(int num)
{
	int i;
	// if (num <= 1) return 0; 함수를 다른 곳에서 여러번 쓴다면 여기서 쓰는게 나을 듯
	for (i = 2; i <= num; i++)
		if (num % i == 0 && i != num) return 0;
	// num을 i로 나눴을 때 나머지가 0이라는 건 나눌 수 있는 약수가 있다는 뜻
	// 근데 이렇게만 해버리면 위에 반복문의 i값(매개변수)과 여기 i값이 같아질 때
	// num % i == 0 이 조건에서 무조건 0이 나오니까  모두 return 0으로 나오는 거였음
	return 1;

	// if (num % i == 0) return 0; // 쌤은 이렇게 함
}

#pragma endregion



#pragma region 6번
// start
// #include "header.h"
#include <stdio.h>

#define H (60*60)
#define M 60

void secondToHMS(int sec);

int main()
{
	/*
	초(second)를 입력 받은 후에 이를 [시, 분, 초]의 형태로 출력하는 프로그램 작성

	ex) 초(second) 입력: 3615
		[h:1, m:0, s:15]

	keypoint: 몫과 나머지를 모두 이용한 풀이
	*/
	int sec;
	printf("초(second) 입력: ");
	scanf_s("%d", &sec);
	secondToHMS(sec);

	return 0;
}

void secondToHMS(int sec)
{
	int h, m;
	h = sec / H;
	m = (sec % H) / M;
	sec = sec % M;
	printf("[h:%d, m:%d, s:%d]", h, m, sec);
}

#pragma endregion




#pragma region 7번 숫자n승 구해보기
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	숫자 n을 입력받고 다음 공식이 성립하는 k의 최대값을 계산해서 출력하는 프로그램 작성

	2의 k승 <= n

	실행 예 상수 256 입력했을 때
	공식을 만족하는 k의 최대값은 8
	*/

	int num, i, cnt = 1;
	printf("input: ");
	scanf_s("%d", &num);

	// for문으로 ( 나누기로 풀었으니까 )
	// 변수 2개?? -> i를 이용해야할 듯 -> ㄴㄴ
	for (i = 2; (num / i) != 1; )
		num = num / i;
	printf("k: %d", num);

	//*  ( 곱하기로 풀어보기 )
	/*for (i = 2; i < num; cnt++)
		i = i*2;
	printf("k: %d", cnt);*/


	// 시작지점 생각들
	// 256 % 2 == 0 까지
	/*
	i = 2;
	while (num / i != 1)
	{
		num = num / i;
		cnt++;
	}
	printf("%d ", cnt);
	*/


	return 0;
}





#pragma endregion




#pragma region 8번 n승 구하기 ( 재귀함수 )
// start
// #include "header.h"
#include <stdio.h>

int squre_re(int num);

int main()
{
	/*
	 2의 n승을 구하는 함수!!!를 재귀적으로 구현.
	 그에 따른 적절한 main 함수도 구현

	 실행 예 정수 8입력하면 2의8승은 256

	*/
	int num;
	printf("input: ");
	scanf_s("%d", &num);

	printf("2의 %d승은: %d \n", num, squre_re(num));

	return 0;
}

int squre_re(int num)
{
	if (num == 0) return 1;
	// 예를들어 8승이다
	// 2 * 2 * 2 * 2 * 이런식으로 나와야함
	return 2 * squre_re(num - 1);
}




#pragma endregion


