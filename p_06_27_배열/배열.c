#pragma region 배열의 합계와 평균
// start
// #include "header.h"
#include <stdio.h>


int main()
{
	/*
	정수형 값 3개를 입력받아서 배열에 저장
	합계와 평균 출력 ( 평균은 소수점 1자리까지 )
	*/

	int arr[3] = { 0 };
	int arrLen, i, sum = 0;

	arrLen = sizeof(arr) / sizeof(int);

	for (i = 0; i < arrLen; i++)
	{
		printf("input: ");
		scanf_s("%d", &arr[i]); // 입력
		sum += arr[i]; // 처리
	}
	printf("sum: %d, avg: %.1f", sum, (double)sum / (double)arrLen);

	return 0;
}
#pragma endregion



#pragma region 배열의 최대값, 최소값 ( 정렬 ㄴㄴ )
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	int arr[5] = { 0, };
	int i, arrLen, max, min, sum = 0;
	arrLen = sizeof(arr) / sizeof(int);

	// 입력 for문
	printf("input 5 numbes: ");
	for (i = 0; i < arrLen; i++)
		scanf_s("%d", &arr[i]);

	// 처리 for문
	max = arr[0];
	min = arr[0];
	for (i = 0; i < arrLen; i++)
	{
		// 삼항연산자는 if와 else 같이 써질 때 쓰는 것 !! ( 한 줄이면 무조건이 아니라 )
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
		sum += arr[i];
	}

	// 출력
	printf("Max: %d \n", max);
	printf("Min: %d \n", min);
	printf("Sum: %d \n", sum);

	return 0;
}

#pragma endregion



#pragma region 배열의 최대값 최소값 sum과 min max 합친거
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	int arr[5] = { 0, };
	int i, arrLen, max, min, sum;

	arrLen = sizeof(arr) / sizeof(int);

	// 입력 for문
	printf("input 5 numbes: ");
	for (i = 0; i < arrLen; i++)
		scanf_s("%d", &arr[i]);

	// 처리 for문
	min = max = sum = arr[0];
	// i = 0 이면 arr[0]과 arr[0]을 비교하면서 시작하기 때문에
	// i = 1 로 바꾼 것
	for (i = 1; i < arrLen; i++)
	{
		// 삼항연산자는 if와 else 같이 써질 때 쓰는 것 !! ( 한 줄이면 무조건이 아니라 )
		if (max < arr[i]) max = arr[i];
		else if (min > arr[i]) min = arr[i]; // else if 쩔었다
		sum += arr[i];
	}

	// 출력
	printf("Max: %d \n", max);
	printf("Min: %d \n", min);
	printf("Sum: %d \n", sum);

	return 0;
}
#pragma endregion



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
	int i, temp, cnt = 4, idx = 0;

	printf("input: ");
	scanf_s("%s", arr, (unsigned int)sizeof(arr));
	while (arr[idx] != '\0') idx++;
	printf("길이: %d \n", idx);


	/*printf("뒤집힌 영단어: ");
	for (i = idx-1; i >= 0; i--)
		printf("%c", arr[i]);*/
		// 출력때만이 아니라 저장까지 바꿔야함

	for (i = 0; i < idx; i++, cnt--)
	{
		temp = arr[i];
		arr[i] = arr[cnt];
		arr[cnt] = temp;
		if (arr[i] == arr[cnt]) break;
	}
	printf("뒤집힌 영단어: %s \n", arr);

	// idx가 변하는 방법
	/*for (i = 0; i < idx; i++, idx--)
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
	int i, max, idx = 0;

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





#pragma region



#pragma endregion





#pragma region



#pragma endregion





#pragma region



#pragma endregion





#pragma region








#pragma region



#pragma endregion





#pragma region



#pragma endregion
#pragma endregion