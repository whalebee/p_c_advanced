// start
// #include "header.h"
#include <stdio.h>

typedef struct
{
	int w500;
	int w100;
	int w50;
	int w10;
}Money;

void init(Money* price);
void save(Money* price, int won, int count);
int total(Money* price);

int main()
{

	/*
	동전 금액과 개수를 입력 받아서 전체 금액을 계산하는 프로그램 작성

	1. 동전 금액별 구조체 한 개 생성
	2. main 함수에서 "동전의 금액, 개수"를 계속 입력 받고 "총 저금액"출력
		단, 0이 입력되면 지금까지 받은 총 저금액 출력
	3. main함수에서 초기화 함수(init)호출
	4. save함수에서 동전 별 수량 카운트
	5. total함수에서 총 저금액 계산 후 값 반환


	힌트
	잔뜩 들고 있는 놈을 초기화하기 -> init 함수
	save: main함수는 동전 별 개수를 모르니까 save가 챙기는 것
	500원이네? -> 500원을 10개 올려야지 이런식
	*/
	int won, count = 0;
	Money price;
	init(&price); // 잔뜩 들고 있는 놈을 초기화
	while(1)
	{
		printf("동전의 금액과 개수: ");
		scanf_s("%d", &won);
		if (won == 0) break;
		scanf_s("%d", &count);
		save(&price, won, count);
	}

	printf("총 저금액: %d원\n", total(&price));

	return 0;
}

void init(Money* price)
{
	price->w500 = price->w100 = price->w50 = price->w10 = 0;
}


void save(Money* price, int won, int count)
{
	// 구조체 전체를 받아서 가격별로 축적해주기?
	// 이 값의 개수를 계속 더해주기
	if (won == 500) price->w500 += count;
	else if (won == 100) price->w100 += count;
	else if (won == 50) price->w50 += count;
	else if (won == 10) price->w10 += count;
}


int total(Money* price)
{
	return (price->w500 * 500) + (price->w100 * 100) + (price->w50 * 50) + (price->w10 * 10);
}

