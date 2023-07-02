#pragma region 연습문제 1번, 배열과 문자
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	// Good time 으로 선언과 동시에 Good time 으로 초기화후 내용 출력
	// 변수 3개, 코드 6줄

	char arr[] = { 'G','o','o','d',' ','t','i','m','e' };
	int i, arrLen;
	arrLen = sizeof(arr) / sizeof(char);

	// 입력 for문

	// 처리 for문

	// 출력
	for (i = 0; i < arrLen; i++)
		printf("%c", arr[i]);

	return 0;
}

#pragma endregion





#pragma region 예제인데 개중요한 while문으로 문자열 길이 보는 방법이 있다 !
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	길이가 50인 char 배열 str 선언
	정수형 변수 idx 선언

	"문자열 입력: " 출력
	str에 사용자로부터 문자열 입력 받기. ( 서식문자 s 사용 )
	"입력받은 문자열 : 땡"출력 ( 서식문자 s 사용 )

	"문자 단위 출력: " 출력
	한 문자씩 출력. ( 서식문자 c 사용 )
	*/

	//문자열 출력은 보통 while로 한다고 함
	/*for (idx = 0; idx < len - 1; idx++)
	{
		printf("%c", str[idx]);
	}*/
	// 왜 끝에 ? 가 나오지 -> 길이를 잘못줬나봄
	// 아 50까지 다 찍으면 안되지 -> 공백나오면 끝내야함 !

	char str[50];
	int idx = 0;
	printf("문자열 입력: ");
	scanf_s("%s", str, (unsigned int)sizeof(str));
	printf("입력 받은 문자열: %s \n", str);

	printf("문자 단위 출력: ");
	while (str[idx] != '\0') idx++;
	// 문자열의 길이를 알 수 있는 반복문 ( 개중요 )
	printf("%d", idx);

	return 0;
}


#pragma endregion





#pragma region 연습문제 2번
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	 1. 하나의 영단어를 입력 받아
	 입력 받은 영단어의 길이를 계산하여 출력하는 프로그램
	 input: Array 하면 길이: 5

	 2. 영단어 입력받은 것을 char 배열에 저장
	 영단어를 역순으로 뒤집고, 널문자는 변경하면 안됨, 확인 출력
	*/

	char arr[50];
	int i, temp, idx = 0;

	printf("input: ");
	scanf_s("%s", arr, (unsigned int)sizeof(arr));
	while (arr[idx] != '\0') idx++;
	printf("길이: %d \n", idx);


	/*printf("뒤집힌 영단어: ");
	for (i = idx-1; i >= 0; i--)
		printf("%c", arr[i]);*/
	// 출력때만이 아니라 저장까지 바꿔야함

	// 조건  i < idx/2 이렇게하고 if문 없애도 됨
	// 아니면 arr[--idx]로 해도 됨
	for (i = 0; i < idx; i++)
	{
		temp = arr[i];
		arr[i] = arr[idx - 1 - i];
		arr[idx - 1 - i] = temp;
		if (arr[i] == arr[idx - 1 - i]) break;
	}
	printf("뒤집힌 영단어: %s \n", arr);

	// idx가 변하는 방법
	/*for (i = 0; i < idx/2; i++, idx--)
	{
		temp = arr[i];
		arr[i] = arr[idx - 1];
		arr[idx - 1] = temp;
	}
	printf("뒤집힌 영단어: %s \n", arr);*/

	return 0;
}



#pragma endregion





#pragma region 연습문제 3번
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	영단어를 입력 받은 후 받은 영단어를 구성하는 문자 중에서
	아스키 코드 값이 가장 큰 문자를 찾아서 출력하는 프로그램 작성

	input: LOVE
	output: V << 얘가 아스키 코드 값이 가장 큼
	*/

	char arr[50];
	int i, idx = 0;
	char max; // int max;  아니다 !!

	// 입력
	printf("input: ");
	scanf_s("%s", arr, (unsigned int)sizeof(arr));

	// 처리
	while (arr[idx] != '\0') idx++;
	max = arr[0];
	for (i = 1; i < idx; i++)
		if (max < arr[i]) max = arr[i];

	// 출력
	printf("MAX ASCII: %c", max);

	// 확인
	/*for(i = 0; i < idx; i++)
		printf("%d ", arr[i]);*/


	return 0;
}



#pragma endregion





#pragma region 포인터 기본
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	num1.100으로 선동초
	num2.100으로 선동초
	정수형 포인터변수 pnum선언

	pnum을 num1의 주소로 초기화
	pnum을 활용해서 num1의 값 30 증가 << 30으로 만들라는게 아니라

	pnum을 num2의 주소로 초기화
	pnum을 활용해서 num1의 값 30 감소 << 30으로 만들라는게 아니라

	num1, num2 출력
	*/

	int num1 = 100, num2 = 100;
	int* pnum;

	pnum = &num1;
	*pnum += 30;

	pnum = &num2;
	*pnum -= 30;

	printf("num1: %d, num2: %d \n", num1, num2);

	return 0;
}




#pragma endregion





#pragma region 포인터 연습문제 2번 ( swap ) ( 1번은 그림이였음 )
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/* 연습문제 2번
	1. int형 변수 num1과 num2를 선언과 동시에 각각 10과 20으로 초기화
	2. int형 포인터 변수 ptr1과 ptr2를 선언하여 각각 num1과 num2를 가리키게하자
	3. ptr1과 ptr2를 이용해서 num1의 값을 10 증가 시키고 num2의 값을 10 감소시키자
	4. 두 포인터 변수 ptr1과 ptr2가 가리키는 대상을 서로 바꾸자 (조건. &num1 &num2 금지 )
	5. 마지막으로 pt1과 pt2가 가리키는 변수에 저장된 값을 출력하자.
	*/

	// 1 ~ 2
	int num1 = 10, num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int* temp;

	// 3
	*ptr1 += 10; // num1 == 20
	*ptr2 -= 10; // num2 == 10

	// 4
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;

	// 5
	printf("ptr1: %d \nptr2: %d ", *ptr1, *ptr2);


	return 0;
}


#pragma endregion





#pragma region 추가예제 포인터 함수 연습문제 1번
// start
// #include "header.h"
#include <stdio.h>
	// 둘 다 같은 말 !
	//int* ptr = NULL;
	//int* ptr2 = 0;

void setValue10(int* n1, int* n2, int* n3);

int main()
{
	// 연습 문제 1번
	/*
	main()함수에서 정의한 3개의 int 형 변수의 값을 모두 10으로 변경하는
	setValue10()함수를 작성하시고,
	num1, 2, 3은 10, 20, 30으로 선동초하면서 시작
	*/

	int num1 = 10, num2 = 20, num3 = 30;

	printf("before : %3d, %3d, %3d \n", num1, num2, num3);
	setValue10(&num1, &num2, &num3);
	printf("after  : %3d, %3d, %3d \n", num1, num2, num3);

	return 0;
}

void setValue10(int* n1, int* n2, int* n3)
{
	*n1 = *n2 = *n3 = 10;
}


#pragma endregion





#pragma region 포인터 추가 예제 2번
// start
// #include "header.h"
#include <stdio.h>

void enterValue(int* mod, int* rem);

int main()
{
	/*
	4로 나누었을 때 몫과 나머지를 구하는 함수를 구현하려 합니다.
	main함수에서는 적절한 함수 호출 후 결과 값을 출력합니다.
	몫과 나머지를 담당하는 변수는 main에서 선언합니다. (mod, rem)
	최종 몫과 나머지 출력도 main에서 합니다.
	양수 입력을 추가 함수에서 받으세요 !

	조건
	메인 3줄
	함수 5줄

	예)
	양수 입력 : 14
	몫 : 3, 나머지 :2
	*/

	int mod = 0, rem = 0;

	enterValue(&mod, &rem);
	printf("몫 : %d, 나머지 : %d \n", mod, rem);

	return 0;
}

void enterValue(int* mod, int* rem)
{
	int num;
	printf("양수 입력 : ");
	scanf_s("%d", &num);
	*mod = num / 4;
	*rem = num % 4;
}


#pragma endregion









#pragma region
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
	if (*mid < *min)		swap(mid, min);
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


#pragma endregion




#pragma region
// start
// #include "header.h"
#include <stdio.h>

void rotate(int* n1, int* n2, int* n3);

int main()
{
	/*
	main함수는 정수 1,2,3을 차례대로 출력한다.
	엔터가 입력시 roate함수를 호출하고 그 결과를 받아서 출력
	단, 엔터 이외의 값이 들어오면 프로그램을 종료 !
	rotate함수는 아래와 같이 1:2:3을 차례대로 섞어주는 함수이다.
	*/
	int num1 = 1, num2 = 2, num3 = 3;
	char enter = '\n';

	while (enter == '\n')
	{
		printf("%d:%d:%d", num1, num2, num3);
		scanf_s("%c", &enter, (unsigned int)sizeof(enter));
		rotate(&num1, &num2, &num3);
	}

	return 0;
}

void rotate(int* n1, int* n2, int* n3)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = *n3;
	*n3 = temp;
}





#pragma endregion


#pragma region



#pragma endregion
