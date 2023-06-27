#include <stdio.h>

#define H (60*60)
#define M 60

int gcd(int v1, int v2);
int isPrime(int n);
void secondToHMS(int sec);
int square_re(int num);

int main()
{
	//	1. 16진수
	//	2. 3 5 입력하면 3단 ~5단까지 출력 !, 곱하기는 9까지 다 출력
	//	3. GCD 함수로
	//	4. 밀키스, 콜라, 레몬티
	//	5. 양수를 입력하면 1부터 입력한 양수까지의 소수를 출력
	//	6. 초 입력하면 h m s 입력
	//	7. 입력한 수의 2의 k승수(보다 작거나 같게)
	//	8. 7번을 재귀함수로



	//	1. 16진수 -ch
	/*int num;
	printf("input: ");
	scanf_s("%d", &num);

	printf("%x", &num);
	// o는 8진수, x는 16진수
	*/


	// 2. 3 5 입력하면 3단 ~ 5단까지 출력 ! , 곱하기는 9까지 다 출력
	/*int v1, v2, i, j;
	printf("2. input: ");
	scanf_s("%d %d", &v1, &v2);

	i = v1 < v2 ? v1 : v2;
	for (; i < 10; i++)
	{
		if (i > v1 && i > v2) break;
		for (j = 1; j < 10; j++)
		{
			printf("%d x %d = %d \n", i, j, i * j);
		}
		puts("");
	}*/
	int v1, v2, i, j;
	scanf_s("%d %d", &v1, &v2);
	i = v1 < v2 ? v1 : v2;
	for (; i < 10; i++) // 구구단이니까 조건 !!
	{
		if (i > v1 && i > v2) break; // 조건을 잘 생각해야지. 언제!! break 해야돼?
		for (j = 1; j < 10; j++)
			printf("%d x %d = %d \n", i, j, i * j);
		printf("\n");
	}



	// 3. GCD 함수로
	/*int v1, v2;
	printf("3. input: ");
	scanf_s("%d %d", &v1, &v2);

	printf("gcd: %d\n", gcd(v1, v2));*/


	//	4. 밀키스, 콜라, 레몬티 ( 함수 아님 )
	int basic, mil = 500, coke = 700, remon = 400;
	int x, y, z;
	printf("4. input: ");
	scanf_s("%d", &basic);

	for (x = 1; x < basic / mil; x++)
		for (y = 1; y < basic / coke; y++)
			for (z = 1; z < basic / remon; z++)
			{
				if (basic == (x * mil) + (y * coke) + (z * remon))
					printf("밀키스 %d, 콜라 %d, 레몬에이드 %d \n", x, y, z);
			}


	//	5. 양수를 입력하면 1부터 입력한 양수까지의 소수를 출력 (함수)
	int num, i, cnt = 0;
	printf("5. input: ");
	scanf_s("%d", &num);

	for (i = 2; i < num + 1; i++)
	{
		if (isPrime(i))
		{
			printf("%5d ", i);
			cnt++;
		}
		else continue;
		if (cnt % 5 == 0) printf("\n");
	}


	//	6. 초 입력하면 h m s 입력
	int sec;
	printf("6. input: ");
	scanf_s("%d", &sec);

	secondToHMS(sec);


	//	7. 입력한 수의 2의 k승수(보다 작거나 같게) ( 곱하기 와 나누기 둘 다 한 번 씩 )
	int num, i, cnt = 0;
	printf("7. input: ");
	scanf_s("%d", &num);

	// 나누기 변수 2개
	for (cnt = 0; num > 1; cnt++)
		num /= 2;
	printf("2의 k승 : %d \n", cnt);

	// 곱하기 변수 3개
	// for문 시작에서 i = 2로 시작하면 1024 기준 11승이 나와버림
	for (i = 1; i < num; cnt++)
		i *= 2;
	printf("2의 k승 : %d \n", cnt);


	//	8. 7번을 재귀함수로
	/*int num;
	printf("8. input: ");
	scanf_s("%d", &num);

	printf("%d", square_re(num));*/

	return 0;
}

// 3번
int gcd(int v1, int v2)
{
	int result;
	// 조건과 while문이라는 것 !
	result = v1 < v2 ? v1 : v2; // result에 삼항 연산자
	while (v1 % result != 0 || v2 % result != 0) // or조건과 != 라는 것 !
		result--;
	return result;
}

// 5번
int isPrime(int n)
{
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0) return 0;
	return 1;
}


// 6번
void secondToHMS(int sec)
{
	int h, m, s;
	h = sec / H;
	m = (sec % H) / M;
	s = sec % M;

	printf("h: %d, m: %d, s: %d \n", h, m, s);
}


int square_re(int num)
{
	if (num == 0) return 1;
	return 2 * square_re(num - 1);
}