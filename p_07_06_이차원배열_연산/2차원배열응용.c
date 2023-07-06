
#pragma region 이차원 배열 연산 기본 예제
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*

	*/
	int arr1[3][2]; // 열 만큼 올라가는구나 ~
	int arr2[2][3];

	printf("arr: %p \n", arr1);				// 000 000 17B68FF878
	printf("arr+1: %p \n", arr1 + 1);		// 000 000 17B68FF880			8이네
	printf("arr+2: %p \n", arr1 + 2);		// 000 000 17B68FF888			16이네ㅋㅋ

	printf("arr2: %p \n", arr2);			// 000 000 17B68FF8A8
	printf("arr2+1: %p \n", arr2 + 1);		// 000 000 17B68FF8B4			12
	return 0;
}

// 0 1 2 3 4 5 6 7 8 9 a b c d e f





#pragma endregion


#pragma region 배열 포인터 예시
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	2행 2열 배열 arr1. 1,2,3,4 선동초
	3행 2열 배열 arr2. 1,2,3,4,5,6 선동초
	4행 2열 배열 arr3. 1,2,3,4,5,6,7,8 선동초

	정수형 포인터 연산의 크기가 2인 배포 ptr 선언
	ptr을 arr1의 값으로 초기화
	ptr을 가지고 전체 요소 출력

	ptr을 arr2의 값으로 초기화
	ptr을 가지고 전체 요소 출력

	ptr을 arr3의 값으로 초기화
	ptr을 가지고 전체 요소 출력
	*/
	int i, j;
	int arr1[2][2] = { 1,2,3,4 };
	int arr2[3][2] = { 1,2,3,4,5,6 };
	int arr3[4][2] = { 1,2,3,4,5,6,7,8 };

	int(*ptr)[2];

	ptr = arr1;
	printf("* * Show 2, 2, arr1 * *\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%2d ", ptr[i][j]);
		printf("\n");
	}

	ptr = arr2;
	printf("* * Show 3, 2, arr2 * *\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%2d ", ptr[i][j]);
		printf("\n");
	}

	ptr = arr3;
	printf("* * Show 4, 2, arr3 * *\n");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%2d ", ptr[i][j]);
		printf("\n");
	}


	return 0;
}


#pragma endregion


#pragma region 포배와 배포 예시
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	num1.10, num2.20, 3은 30, 4는 40으로 선동초

	2행 4열. arr2d. 1,2,3,4,5,6,7,8 선동초

	whoA. num1의 주소, num2의 주소, num3의 주소, num4의 주소로 선동초
	whoB. 위 배열(2행4열)로 선동초

	whoA를 사용해서 전체 요소 출력
	whoB를 사용해서 전체 요소 출력
	*/
	int i, j;
	int num1 = 10, num2 = 20, num3 = 30, num4 = 40;
	int arr2d[2][4] = { 1,2,3,4,5,6,7,8 };

	// whoA
	int* whoA[4] = { &num1, &num2, &num3, &num4 };
	// 주소니까 포인터, 4개니까 배열 -> 포인터 배열

	// whoB
	int(*whoB)[4] = arr2d;
	// 2차원 배열을 감당할 수 있는 포인터 -> 배열 포인터

	// whoA 사용 출력
	printf("--- whoA ---\n");
	for (i = 0; i < 4; i++)
		printf("%d ", *whoA[i]);
	printf("\n");

	// whoB 사용 출력
	printf("--- whoB ---\n");
	for (i = 0; i < 2; i++)
		for (j = 0; j < 4; j++)
			printf("%d ", whoB[i][j]);
	printf("\n");

	return 0;
}




#pragma endregion


#pragma region  배열 포인터의 길이와 매개변수 예제
// start
// #include "header.h"
#include <stdio.h>

#define ARR_COL 4

void showArr2DStyle(int(*arr)[4], int row);
int sum2DArr(int(*arr)[4], int row);

int main()
{
	/*
	2행4열 arr1. 1,2,3,4,5,6,7,8 선동초
	3행4열 arr2. 1,1,1,1,3,3,3,3,5,5,5,5 선동초

	showArr2DStyle함수 호출. 인자 arr1, 어떤거
	showArr2DStyle함수 호출. 인자 arr2, 어떤거

	arr1의 합 출력. sum2DArr함수 활용. 인자 arr1, 어떤거
	arr2의 합 출력. sum2DArr함수 활용. 인자 arr2, 어떤거

	showArr2DStyle 함수
	- 전달받은 전체 요소의 값 출력

	sum2DArr 함수
	- 전달받은 전체 요소의 합 반환!!!!!
	*/

	int arr1[2][4] = { 1,2,3,4,5,6,7,8 };
	int arr2[3][4] = { 1,1,1,1,3,3,3,3,5,5,5,5 };
	// int test[5][2];

	int row1, row2;
	row1 = sizeof(arr1) / sizeof(*arr1); // *arr1 이렇게 하면 열의 크기가 나옴
	row2 = sizeof(arr2) / sizeof(*arr2);
	// row2 = sizeof(arr2) / sizeof(arr2[0]);
	/*
	printf("%zd \n", sizeof(*arr1));
	printf("%zd \n", sizeof(*arr2));
	printf("%zd \n", sizeof(*test));
	*/
	/*printf("%zd \n", sizeof(*(test + 0)));
	printf("%zd \n", sizeof(*(test + 1)));*/

	// printf("%d\n\n", row1);
	// printf("%d\n\n", row2);
	// 상수말고 인자에 어떤 것을 줘야 상수를 쓰지 않을까
	// 행을 인자로 주고 열을 define -> 써도 됨
	showArr2DStyle(arr1, row1);
	showArr2DStyle(arr2, row2);

	printf("arr1의 합 : %d \n", sum2DArr(arr1, row1));
	printf("arr2의 합 : %d \n", sum2DArr(arr2, row2));

	return 0;
}

void showArr2DStyle(int(*arr)[4], int row)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < ARR_COL; j++)
			printf("%d ", arr[i][j]);
	printf("\n");
}

int sum2DArr(int(*arr)[4], int row)
{
	int i, j, result = 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < ARR_COL; j++)
			result += arr[i][j];
	return result;
}



#pragma endregion


#pragma region 함수의 매개변수 예제
// start
// #include "header.h"
#include <stdio.h>

typedef struct point
{
	int xPos;
	int yPos;
}Point;

Point getCurrentPosition();
void showPosition(Point curPos);

int main()
{
	/*
	point 구조체 정의. 단 이름은 Point로 변경

	main함수
	- point형 변수 curPos. getCurrentPosition이 전달해준 값으로 선동초
	- showPosition함수 호출. 인자는 알아서!

	getCurrentPosition함수
	- 사용자로부터 x좌표, y좌표를 받아서 반환!!하는 함수

	showPosition함수
	- 전달 받은 좌표 출력하는 함수
	*/

	/*Point curPos = getCurrentPosition();
	showPosition(&curPos);*/
	showPosition(getCurrentPosition());

	return 0;
}

Point getCurrentPosition()
{
	Point pos = { 0, };
	printf("input current pos: ");
	scanf_s("%d %d", &pos.xPos, &pos.yPos);

	// 구조체 자체를 넘겨줘야함
	return pos;
}

void showPosition(Point curPos)
{
	printf("[%d %d] \n", curPos.xPos, curPos.yPos);
}



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion




#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion





