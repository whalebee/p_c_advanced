// start
// #include "header.h"
#include <stdio.h>

typedef struct score {
	int kor, eng, mat;
	int total;
}SCORE;

int main()
{
	// 더블 포인터
	//int a = 5;
	//int* p = &a;
	//int** pp = &p;


	//printf("%p \n",	p);		// a의 주소값
	//printf("%d	\n",	*p);		// 5
	//printf("%p	\n",	*pp);		// a의 주소값
	//printf("%p	\n",	pp);		// p의 주소값
	//printf("%d	\n",	**pp);	// 5



	/*
	 2차원 포인터 배열
	int arr[4][3] = { 1,2,3,4,5,6,7,8,9,10,11 }; // 알아서 3열씩 짤라서 배열에 입력됨
	 int* p[3] = arr;  -> 이렇게 해버리면 1차원 포인터 배열
	int(*p)[3] = arr;  // -> 이렇게 해야 2차원 포인터 배열 [3] 이와같이 열을 표시해주고 괄호로 감싸줘야해 !
	printf("%d \n", *p[1]);				// 4
	printf("%d \n", *(p[1] + 2));		// 6
	printf("%d \n", *(p[3] + 2));		// 0
	*/



	// 구조체 포인터
	SCORE s[3] = {
		{70, 70, 70},
		{80, 80, 80},
		{90, 90, 90}
	};

	// 1차원 배열 일 때
	// s.total = s.kor + s.eng + s.mat;

	SCORE* pS = &s;

	// 1차원 포인터 구조체
	// pS->total = pS->kor + pS->eng + pS->mat;
	// 
	// printf("%d \n", pS->total); 

	// 2차원 포인터 구조체 배열
	// 포인터 변수가 아닌 구조체 변수로 선언하기
	s[0].total = s[0].kor + s[0].eng + s[0].mat;
	s[1].total = s[1].kor + s[1].eng;
	s[2].total = s[2].kor;

	// 주소의 위치에 따른 표현
	(pS + 0)->total = (pS + 0)->kor + (pS + 0)->eng + (pS + 0)->mat;
	(pS + 1)->total = (pS + 1)->kor + (pS + 1)->eng;
	(pS + 2)->total = (pS + 2)->kor;

	// 인덱스로 표현 -> 변수화가 되기 때문에 -> 가 아닌 . 으로 멤버 선택
	pS[0].total = pS[0].kor + pS[0].eng + pS[0].mat;
	pS[1].total = pS[1].kor + pS[1].eng;
	pS[2].total = pS[2].kor;

	printf("2차원 포인터 구조체 배열 0: %d \n", pS[0].total);
	printf("2차원 포인터 구조체 배열 1: %d \n", pS[1].total);
	printf("2차원 포인터 구조체 배열 2: %d \n", pS[2].total);


	return 0;
}


