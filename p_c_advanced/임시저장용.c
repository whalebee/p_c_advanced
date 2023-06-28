// start
// #include "header.h"
#include <stdio.h>

void line_up(double* max, double* mid, double* min);
void swap(double* n1, double* n2);

int main()
{
	/*
	main함수에서 실수 값을 세 개 입력 받아서 line_up함수를 호출 하고 난 뒤,
	정렬된 값을 출력 ( 최대값, 중간값, 최소값)

	line_up 함수에서는 swap함수를 호출해서 세 변수의 값을 크기 별로 정렬하도록 구현

	swap 함수는 두 실수를 바꾸는 함수로 구현

	출력은 메인에서
	예)
	실수값 세 개 입력 : 4.7 11.2 -8.1
	정렬된 값 출력 : 11.2 4.7 -8.1
	*/
	/*
	메인 5
	라인 3
	스왑3
	*/

	// 선언
	double max = 0, mid = 0, min = 0;

	// 입력
	printf("실수 값 세 개 입력 : ");
	scanf_s("%lf %lf %lf", &max, &mid, &min);

	// line_up 정렬된 값을 출력하는 함수
	line_up(&max, &mid, &min);

	// 확인
	printf("정렬된 값 출력 : %.1lf %.1lf %.1lf", max, mid, min);
	return 0;
}

// 주소값을 매개변수로 받음
// 총 3줄, 판단은 line_up에서
// swap 함수 호출 ( 매개변수를 2개씩 넣어야한다면 비교를 좀 해야할 듯 )
// printf("값이 바뀌었나 ? %lf %lf %lf", *max, *mid, *min);
void line_up(double* max, double* mid, double* min)
{
	/*if (*max < *mid)		swap(max, mid);
	if (*mid < *min)		swap(mid, min);
	if (*max < *mid)		swap(max, mid);*/

	// 정답
	if (*max < *mid)	swap(max, mid);
	if (*max < *min)	swap(max, min);
	if (*mid < *min)	swap(mid, min);
}

void swap(double* n1, double* n2)
{
	double temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
// 두 실수를 바꾸는 함수로 구현 -> 매개변수가 2개
// 총 3줄
//  주소값을 받아옴
// 주소값이 들어왔고 두 실수 자리 변경 -> 비교하지말고 바로 바꿔