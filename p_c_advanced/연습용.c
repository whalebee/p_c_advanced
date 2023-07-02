// start
// #include "header.h"
#include <stdio.h>
#include "연습용.h"

#define FIVE 5 // 상수는 define이나 const로 해놓는게 좋다 ! tip 좋았다
				// 근데 이거 for문 조건식에서 왜 안 써지지 -> 5; 이걸로 정의해놔서ㅋㅋ

int main()
{
	/*
	main 함수는 정수형 배열 5개를 선언해서 72, 88, 95, 64, 100으로 초기화
	print_graph 함수를 호출해서 아래 결과처럼 출력 !
	점수는 오른쪽 정렬하고 각 점수를 5로 나눈 몫 만큼의 *을 출력

	조건: 함수는 포인터 함수로 해야하고 이 함수는 딱 한 번만 호출할 수 있다.
	매개변수 제한? X, 함수안에서 지역변수 2개제한, 매개변수도 2개로 제한
	*/

	// 선언
	int arr[5] = { 72, 88, 95, 64, 100 };
	int i, len;
	len = sizeof(arr) / sizeof(int);

	// 호출
	printf_graph(arr, len);

	return 0;
}

