
#pragma region 연습문제 -> 과목과 총점구하기 ( 전역 변수 )
// start
// #include "header.h"
#include <stdio.h>

int record[5][5];
void writeRecord();
void writeSumRecord();
void showAllRecord();

int main()
{
	/*
	성적관리 프로그램 작성
	4과목이고 학생은 네 사람이다 !
	이 네사람의 네 과목 점수를 입력받는다.
	마지막 열은 총점
	미리 선언해 놓은 배열에 다음의 형태로 그 값을 저장.

	메인은 지금 이 상태에서
	그 어떤 것도 만지면 안됨 -> 애초에 만질 필요가 없음
	No Touch Zone임
	*/

	writeRecord();		// 입력
	writeSumRecord();	// 총점 구하는 함수 ( 9칸 )
	showAllRecord();	// 값을 보여줌


	return 0;
}
void writeRecord()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		printf("%d번째 학생의 성적 입력 \n", i + 1);
		for (j = 0; j < 4; j++)
		{
			printf("과목 %d: ", j + 1);
			scanf_s("%d", &record[i][j]);
		}
	}
}


/*
	0,4		1,4		2,4		3,4
	4,4
	4,0		4,1		4,2		4,3
*/
void writeSumRecord()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			record[i][4] += record[i][j]; // 오른쪽 합계
			record[4][j] += record[i][j]; // 밑 합계
		}
		record[4][4] += record[i][4]; // 총 합계 // 아하 ~
	}
}

void showAllRecord()
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%3d ", record[i][j]);
		printf("\n");
	}
}




#pragma endregion


#pragma region 과목과 총점구하기 2번째 버전
// start
// #include "header.h"
#include <stdio.h>

int record[5][5];
void writeRecord();
void writeSumRecord();
void showAllRecord();

int main()
{
	/*
	성적관리 프로그램 작성
	4과목이고 학생은 네 사람이다 !
	이 네사람의 네 과목 점수를 입력받는다.
	마지막 열은 총점
	미리 선언해 놓은 배열에 다음의 형태로 그 값을 저장.

	메인은 지금 이 상태에서
	그 어떤 것도 만지면 안됨 -> 애초에 만질 필요가 없음
	*/

	writeRecord();		// 입력
	writeSumRecord();	// 총점 구하는 함수 ( 9칸 )
	showAllRecord();	// 값을 보여줌

	return 0;
}
void writeRecord()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		printf("%d번째 학생의 성적 입력 \n", i + 1);
		for (j = 0; j < 4; j++)
		{
			printf("과목 %d: ", j + 1);
			scanf_s("%d", &record[i][j]);
			record[i][4] += record[i][j];
		}
	}
}


/*
	0,4		1,4		2,4		3,4
	4,4
	4,0		4,1		4,2		4,3
*/
// record[i][4] += record[i][j]; // 오른쪽 합계
void writeSumRecord()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			record[4][j] += record[i][j]; // 밑 합계
		record[4][4] += record[i][4]; // 총 합계 // 아하 ~
	}
}

void showAllRecord()
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%3d ", record[i][j]);
		printf("\n");
	}
}


#pragma endregion


#pragma region 더블 포인터 기본 개념
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*

	*/
	double num = 3.14;
	double* ptr = &num;
	double** dptr = &ptr;

	printf("%p \n", ptr);
	printf("%p \n", *dptr);

	printf("%g \n", num);
	printf("%g \n", **dptr);

	double* ptr2;
	ptr2 = *dptr;
	*ptr2 = 10.99;

	printf("%g \n", num);
	printf("%g \n", **dptr);

	return 0;
}

#pragma endregion


#pragma region 연습문제 -> 더블 포인터의 활용 
// start
// #include "header.h"
#include <stdio.h>


void MaxAndMin(int* arr, int len, int** maxPtr, int** minPtr);

int main()
{
	/* 연습문제
	다음과 같이 두개의 int형 포인터 변수와 길이가 5인 int형 배열을 선언한다.

	그리고 MaxAndMin이란 이름의 함수를 정의
	호출하면서 두 포인터 변수에 대한 정보를 전달
	어떠한 정보를 어떻게 전달할지는 스스로 결정
	함수 호출이 완료되면, 포인터 변수 maxPtr에는 가장 큰 값이 저장된
	배열요소의 주소 값!!!이,
	minPtr에는 가장 작은 값이 저장된 배열 요소의 주소 값!!!!이 저장됨.

	메인 5줄 ( 변수 빼고 )
	함수 6줄
	*/
	int* maxPtr;
	int* minPtr;
	int arr[5];
	int i, len;
	len = sizeof(arr) / sizeof(int);

	// 배열에 값 입력
	for (i = 0; i < len; i++)
	{
		printf("정수 입력 %d : ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	// 함수 호출
	MaxAndMin(arr, len, &maxPtr, &minPtr);

	printf("최대: %d, 최소: %d", *maxPtr, *minPtr);

	return 0;
}
// 포인터 변수의 주소값을 받는 더블포인터 dM??Ptr
void MaxAndMin(int* arr, int len, int** dMaxPtr, int** dMinPtr)
{
	int i;
	// 1줄로
	*dMinPtr = *dMaxPtr = &arr[0]; // 주소값을 arr의 주소값으로 선언 

	// 주소값을 변경하는 반복문을 써야할 듯?
	for (i = 1; i < len; i++)
	{
		if (**dMaxPtr < arr[i]) *dMaxPtr = &arr[i]; // +1 없이
		if (**dMinPtr > arr[i]) *dMinPtr = &arr[i];
	}
}


#pragma endregion


#pragma region 구조체 예제
// start
// #include "header.h"
#include <stdio.h>
#include <math.h>
struct point {
	int xpos;
	int ypos;
};

int main()
{
	/* 예제
	point형 구조체 정의
	- 멤버로 정수형 xpos 선언
	- 멤버로 정수형 ypos 선언

	main함수에서
	- point형 변수 pos1, pos2 선언
	- 실수 담을 그릇 distance 선언
	- "point 1 pos: " 출력, 단 fputs 사용
	- pos1에 x좌표, y좌표 입력 받기
	- "point 2 pos: " 출력, 단 fputs 사용
	- pos1에 x좌표, y좌표 입력 받기

	- distance 구하기.
	->(x좌표끼리의 차 x x좌표끼리의 차 ) + (y좌표끼리의 차 x y좌표끼리의 차 )의 값을
		루트를 씌우기
	-> sqrt함수 사용. 소속 math.h
	- "두 점의 거리는 땡입니다." 출력 pritnf 사용
	*/


	struct point pos1;
	struct point pos2;
	double distance;

	fputs("point 1 pos: ", stdout);
	scanf_s("%d %d", &pos1.xpos, &pos1.ypos);

	fputs("point 2 pos: ", stdout);
	scanf_s("%d %d", &pos2.xpos, &pos2.ypos);

	distance = sqrt((pos1.xpos - pos2.xpos) * (pos1.xpos - pos2.xpos) + (pos1.ypos - pos2.ypos) * (pos1.ypos - pos2.ypos));

	// printf("%d", ~(pos1.xpos - pos2.xpos)+1);
	printf("두 점의 거리는 %.1f입니다.", distance);

	return 0;
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





