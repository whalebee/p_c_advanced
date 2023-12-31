
#pragma region 포인터 배열 연습문제 이어서 ( 오름차순 정렬 )
// start
// #include "header.h"
#include <stdio.h>

void sort(int* arr, int len);

int main()
{
	// 연습문제
	/*
	* 정렬이란 ?
	길이가 5인 배열에 정수 4,3,5,1,2가 저장되어 있다.
	이것을 오름차순(ascending order)으로 정렬하면 1,2,3,4,5 재배치
	내림차순(descending order) 5,4,3,2,1 로 재배치


	예제
	3 2 4 1 일 때 오름차순 asc_order
	2 3 4 1
	2 3 1 // 4는 끝
	2 1 // 3 4 는 끝
	1 // 2 3 4 는 끝
	1 2 3 4 끝 !
	*/

	int arr[4] = { 3,2,4,1 };
	int i, len;
	len = sizeof(arr) / sizeof(int);

	sort(arr, len);
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);



	return 0;
}

void sort(int* arr, int len)
{
	int i, temp, j;
	// 경우의 수는 하나밖에 없음 else를 쓰지 않는 것
	// for문 조건을 어떻게 하면 좋을까?
	// 2 3 1 4 에서 2번을 더 해야함
	// 3번과 2번을 비교 시작해야됨
	// 되긴 되었는데 반복문을.. 2번 써야만하나?
	// 너무 길어 지옥감
	/*while (i < len - 1) // int peek = len - 1
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
		i+=2;
	}
	while (peek > 0)
	{
		if (arr[peek] < arr[peek - 1])
		{
			temp = arr[peek];
			arr[peek] = arr[peek -1];
			arr[peek-1] = temp;
		}
		peek--;
	}*/

	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
}





#pragma endregion


#pragma region 연습문제 이어서 ( 내림차순 )
// start
// #include "header.h"
#include <stdio.h>

void DesSort(int* arr, int len);

int main()
{
	// 연습문제
	/*
	내림차순으로 정렬하는 함수를 정의 -> DesSort 함수이름
	길이가 7인 int형 배열 선언하고
	사용자로부터 7개의 정수를 받는다

	확인하기 위해서 출력까지
	*/

	int arr[7];
	int i, len;
	len = sizeof(arr) / sizeof(int);

	for (i = 0; i < len; i++)
	{
		printf("%d번째 입력 : ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	DesSort(arr, len);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	return 0;
}

void DesSort(int* arr, int len)
{
	int i, j, temp, cnt = 0;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
		{
			// 조건문에 -i를 넣었을 때 무엇이 달라지는가 생각하기
			// 오름차순 일 때는 큰 수를 뒤로 밀어넣는 조건
			// 내림차순 일 때는 큰 수를 앞으로 당기는 조건
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
}




#pragma endregion


#pragma region 연습문제 -> villa ( 2차원 배열, keyword: 수작업 )
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	int villa[4][2];
	int i, j, popu = 0;
	// 길이는 걍 상수로 써 잠시동안만
	/*
	땡 층 땡호 인구수 출력
	땡 층 땡 호 인구수 입력

	그리고 각 층의 인구수 출력
	*/

	// 입력
	for (i = 0; i < 4; i++)
		for (j = 0; j < 2; j++)
		{
			printf("%d층 %d호 인구수 : ", i + 1, j + 1);
			scanf_s("%d", &villa[i][j]);
		}

	// 출력
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++) // 반복문을 못 쓰면 수작업으로라도 해야함
			popu += villa[i][j];
		printf("%d층 인구수 : %d \n", i + 1, popu);
		popu = 0;
	}

	return 0;
}



#pragma endregion


#pragma region 연습문제 -> 행번호와 열번호 더하기
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* 연습문제
	정수형 데이터를 저장하는 2차원 배열 degree[4][4]를 선언
	각 항목 값을 행 번호 + 열 번호의 값으로 설정하고,
	전체 배열 항목의 합계와 평균값을 출력
	*/
	int degree[4][4];
	int i, j, sum = 0;

	// 입력
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			degree[i][j] = i + j;
			sum += degree[i][j];
		}

	// 출력
	printf("sum : %d -> avg : %.1f \n", sum, (double)sum / (i * j));
	// printf("sum : %d -> avg : %.1f \n", sum, sum/16.0); // double을 상수앞에서 쓰지마라


	return 0;
}



#pragma endregion


#pragma region 연습문제 -> 구구단 저장하기
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* 연습문제
	가로의 길이가 9, 세로의 길이가 3인 int형 2차원 배열 선언하고
	구구단 중에 2,3,4단을 저장해라

	확인하기 위한 출력
	*/

	int gugudan[3][9];
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 9; j++)
			gugudan[i][j] = (i + 2) * (j + 1); // 연산 우선순위 생각

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 9; j++)
			printf("%3d ", gugudan[i][j]);
		printf("\n");
	}


	return 0;
}



#pragma endregion


#pragma region 연습문제 -> 4와 2, 행열 관계
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	배열 A와 배열 B 선언
	배열 A는 선언과 동시에 그림대로 초기화
	그 후에 배열 B는 그림대로 초기화를 하되, 반드시 !!
	배열 A에 저장된 값을 이용해서 초기화 진행.
	*/

	int arrA[2][4] = { 1,2,3,4,5,6,7,8 };
	int arrB[4][2];
	int i, j;

	printf("arrA: \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			arrB[j][i] = arrA[i][j];
			printf("%4d", arrA[i][j]);
		}
		printf("\n\n");
	}

	printf("arrB: \n");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%4d", arrB[i][j]);
		printf("\n");
	}

	return 0;
}

#pragma endregion


#pragma region 연습문제 -> rotateMath
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	정수형 2차원 배열 int math[2][3]의 항목 값을 각각
	행+열의 값으로 설정한 후에 출력 -> math[1][2]의 값은 3
	math[2][3] 배열을 새로운 2차원 배열 rotateMath[3][2]로 변환하여,
	저장하고 출력

	즉, 2차원 행렬 math[2][3]을 오른쪽, 시게방향으로 회전한 형태로 변환하여 저장

	hint: index로 바꿔서 풀기

	for문 덩어리는 총 2개로 !! ( 기본은 3개가 맞음 )
	*/

	int math[2][3];
	int rotateMath[3][2];
	int i, j;

	// 입력
	printf("--- math[2x3] --- \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			math[i][j] = i + j;
			rotateMath[j][(i + 1) % 2] = math[i][j];
			// rotateMath[j][1-i] = math[i][j];
			// rotateMath[j][!i] = math[i][j];
			printf("%-3d ", math[i][j]);
		}
		printf("\n\n");
	}

	printf("--- rotateMath[3x2] --- \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%-3d ", rotateMath[i][j]);
		printf("\n\n");
	}


	// 처리 -> 처음엔 수동으로 할 것
	/*for (i = 0; i < 3; i++)
	{
		rotateMath[i][0] = math[1][i];
		rotateMath[i][1] = math[0][i];
	}*/

	/* 꼭 인덱스로 그린 다음에 패턴을 찾아볼 것
	i j    j i				i j	   j i
	0,0 -> 1 0				0,1 -> 0 0
	1,0 -> 1 1				1,1 -> 0 1
	2,0 -> 1 2				2,1 -> 0,2
	*/


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





