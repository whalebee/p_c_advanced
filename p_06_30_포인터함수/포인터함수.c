
#pragma region 문자열을 사용하는 포인터 배열 기본 예제
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	strArr. 각각 문자열 Simple, String, Array ( 3개 ) 로 선동초

	strArr를 사용해서 문자열 출력
	( 문자열로 보이지만 주소값 )
	*/

	// 선언
	char* strArr[3] = { "Simple", "String", "Array" };
	int i, len;
	len = sizeof(strArr) / sizeof(char*);
	// printf("%d", len);

	// 출력
	for (i = 0; i < len; i++)
		printf("%s \n", strArr[i]);

	return 0;
}





#pragma endregion


#pragma region 연습문제 -> 배열의 값을 5로 나눈 만큼 별 찍기
// start
// #include "header.h"
#include <stdio.h>

#define FIVE 5 // 상수는 define이나 const로 해놓는게 좋다 ! tip 좋았다
				// 근데 이거 for문 조건식에서 왜 안 써지지 -> 5; 이렇게 저장을 해버렸던 것ㅋㅋ

void printf_graph(int* array, int len);

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

void printf_graph(int* array, int len)
{
	int i, j;
	for (i = 0; i < len; i++) {
		printf("(%3d) ", array[i]);
		for (j = 0; j < array[i] / FIVE; j++)
			printf("*");
		printf("\n");
	}
}


#pragma endregion



#pragma region 포인터 함수 예제
// start
// #include "header.h"
#include <stdio.h>

void showArrElem(int* pArr, int len);

int main()
{
	/* 예제
	arr1. 1,2,3 선동초
	arr2. 4,5,6,7,8 선동초

	showArrElem함수 호출. 인자로 2개 전달
	showArrElem함수 호출. 인자로 2개 전달

	showArrElem함수.
	- 전달받은 배열의 전체 요소 출력

	메인 4줄, 함수 4줄, len 변수 선언 ㄴㄴ, 함수 포인터 매개변수로 받을 때 이름 제대로
	*/
	int arr1[] = { 1,2,3 };
	int arr2[] = { 4,5,6,7,8 };

	showArrElem(arr1, sizeof(arr1) / sizeof(int));
	showArrElem(arr2, sizeof(arr2) / sizeof(int));

	return 0;
}

void showArrElem(int* pArr, int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", pArr[i]);
	printf("\n");
}


#pragma endregion



#pragma region addArrElem 구현하기
// start
// #include "header.h"
#include <stdio.h>

void showArrElem(int* pArr, int len);
void addArrElem(int* pArr, int len, int putNum);

int main()
{
	/* 예제
	arr. 1,2,3 선동초

	addArrElem함수 호출. 인자 3개. 마지막 인자는 1
	showArrElem함수 호출. 인자로 2개 전달

	addArrElem함수 호출. 인자 3개. 마지막 인자는 2
	showArrElem함수 호출. 인자로 2개 전달

	addArrElem함수 호출. 인자 3개. 마지막 인자는 3
	showArrElem함수 호출. 인자로 2개 전달

	showArrElem함수.
	- 전달받은 배열의 전체 요소 출력

	addArrElem함수.
	- 전달받은 인자를 배열의 각 요소에 더함

	*/
	int arr1[] = { 1,2,3 };
	int len;
	len = sizeof(arr1) / sizeof(int);

	addArrElem(arr1, len, 1); // 함수의 주소값을 참조해서 길이 만큼의 요소에 1씩 더하기
	showArrElem(arr1, len);

	addArrElem(arr1, len, 2);
	showArrElem(arr1, len);

	addArrElem(arr1, len, 3);
	showArrElem(arr1, len);

	return 0;
}

//void addArrElem(int pArr[] 배열을 받았다는 표시로 이렇게도 가능 ( 매개변수 자리에서만 )
// , int len, int putNum)
void addArrElem(int* pArr, int len, int putNum)
{
	int i;
	for (i = 0; i < len; i++)
		pArr[i] += putNum;
}

void showArrElem(int* pArr, int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", pArr[i]);
	printf("\n");
}



#pragma endregion


// NEW
#pragma region 연습문제 -> Call By Value와 Call By Reference
// start
// #include "header.h"
#include <stdio.h>

int SqaureByValue(int n);
void SqaureByReference(int* pNum);

int main()
{
	/* 연습문제 1번
	변수 num1에 저장된 값의 제곱을 계산하는 함수 정의
	이를 호출하는 main 함수 작성
	단, 다음 두 가지 형태로 함수를 정의
	CBV 기반의 SqaureByValue 함수
	CBR 기반의 SqaureByReference 함수

	메인 4줄?? 왜지? -> C.B.R가 void형으로 만들어졌어야했으니까 !!
	함수 각각 1줄
	출력은 main에서 해야함
	*/
	int num1 = 10;

	printf("Value		: %d \n", SqaureByValue(num1));
	SqaureByReference(&num1);
	printf("Reference	: %d \n", num1);

	return 0;
}

int SqaureByValue(int n)
{
	return n * n;
}

void SqaureByReference(int* pNum)
{
	*pNum *= *pNum;
}



#pragma endregion


#pragma region 연습문제 -> 3개의 매개변수 swap
// start
// #include "header.h"
#include <stdio.h>


void swap(int* n1, int* n2, int* n3);
int main()
{
	/* 연습문제 2번
	세 변수에 저장된 값을 서로 뒤바꾸는 함수를 정의
	예 함수의 이름이 swap3이면
	swap3(&num1, &num2, &num3); 으로 호출해야함

	함수 호출의 결과로 num1에 저장된 값은 num2에
	num2는 3에, 3은 1에
	*/

	int num1 = 10, num2 = 20, num3 = 30;
	swap(&num1, &num2, &num3);
	printf("1: %d, 2: %d, 3: %d\n", num1, num2, num3);

	return 0;
}

void swap(int* n1, int* n2, int* n3)
{
	int temp;
	temp = *n1;
	*n1 = *n3;
	*n3 = *n2;
	*n2 = temp;

}




#pragma endregion



// NEW
#pragma region 연습문제 -> 로또 번호 비교
// start
// #include "header.h"
#include <stdio.h>

int check_same(int* lottoArr, int* myArr, int len);

int main()
{
	/*
	main함수에서 로또 번호를 저장할 배열 선언 (4, 10, 25, 30, 41, 45)하고
	내 번호를 저장할 배열도 선언(1, 4, 7, 22, 41, 43)
	그리고 check_same함수를 호출해서 결과를 받아서 출력.
	check_same함수는 로또 번호와 내 번호를 비교하여 일치하는 번호의 수를 반환!!함.

	조건: main 6줄, 함수 6줄
	*/

	int lottoArr[] = { 4, 10, 25, 30, 41, 45 };
	int myArr[] = { 1, 4, 7, 22, 41, 43 };
	int len;
	len = sizeof(lottoArr) / sizeof(int);

	printf("일치하는 번호의 개수 : %d \n", check_same(lottoArr, myArr, len));

	return 0;
}

int check_same(int* lottoArr, int* myArr, int len)
{
	int i, j, cnt = 0;
	for (i = 0; i < len; i++)
		for (j = 0; j < len; j++)
			if (lottoArr[i] == myArr[j]) cnt++;
	return cnt;
}



#pragma endregion








#pragma region 연습문제 -> 배열 중복 검사
// start -> flag 해보는 중
// #include "header.h"
#include <stdio.h>

void input_nums(int* arr, int len);
void print_nums(int* arr, int len);
void input_nums_dup(int* arr, int len);
void input_nums_var(int* arr, int len);


int main()
{
	/*
	main함수에서 로또 번호를 저장할 길이 6인 정수형 배열 선언하고
	input_nums를 호출해서 로또 번호를 입력 받고,
	print_nums를 호출해서 로또 번호를 출력.
	단, input_nums 함수는 중복 번호 입력시 이를 알리고 다시 입력 유도 !
	*/

	/*
	for 2개, if 1개

	1. arr[i] -> 배열 -> 완성
	2. 일반 변수로 하는 방법 -> 내가 한 건가? -> 최적화는 좀 필요할 듯ㅋㅋ
	3. duplicate. dup=0 -> flag 방법
		중복이 있으면 1, 없으면 0
		값에 따라서 코드의 흐름을 짜는 것
	*/

	int arr[6];
	int len;
	len = sizeof(arr) / sizeof(int);
	// input_nums_var(arr, len);
	// input_nums(arr, len);
	input_nums_dup(arr, len);
	print_nums(arr, len);

	return 0;
}


// 1. 배열이 아닌 변수를 이용한 함수 정의
void input_nums_var(int* pArr, int len)
{
	int putNum = 0, i = 0, j = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d번째 번호 입력 : ", i + 1); // 확인용
		scanf_s("%d", &putNum);
		pArr[i] = putNum;

		// 여기안에서 중복이 아닐 때까지 돌기
		for (j = 0; j < i; j++)
		{
			if (pArr[j] == putNum)
			{
				printf("같은 숫자 중복입니다 !! \n");
				i--; // 중복일 때 다음 인덱스로 넘어갈 수 없는 조건
			}
		}
	}
}


// 2. arr[i]를 이용한 함수 정의
void input_nums(int* arr, int len)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		printf("%d번째 번호 입력 : ", i + 1);
		scanf_s("%d", &arr[i]); // 본진에 넣겠다는 건? 본진안에서 비교하라는 것
		for (j = 0; j < i; j++)
			if (arr[i] == arr[j]) // 같은 값이 본진에 있을 때 !
			{
				printf("같은 번호가 있습니다 ! \n");
				i--;
				break; // 왜 안했지? 그래도 되나?
			}
	}
}

// 3. dup 변수를 이용한 함수 정의 ( flags )
void input_nums_dup(int* pArr, int len)
{
	int i, j, dup = 0;
	// dup = 0이 for 문 안에 있을 필요는 없음
	for (i = 0; i < len; i += 1 - dup)
	{
		printf("%d번째 번호 입력 : ", i + 1);
		scanf_s("%d", &pArr[i]);
		for (j = 0; j < i; j++)
		{
			if (pArr[i] == pArr[j])
			{
				printf("같은 번호 중복입니다 !! \n");
				dup = 1;
				break;
			}
			else dup = 0;
		}
	}
}

void print_nums(int* arr, int len)
{
	int i;
	printf("로또 번호 : ");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
}









#pragma endregion






#pragma region 새로운 연습문제
// start
// #include "header.h"
#include <stdio.h>

void getOddNum(int* arr, int len);
void getEvenNum(int* arr, int len);

int main()
{
	// NEW
	/* 연습문제
	길이가 10인 배열을 선언하고 총 10개의 정수를 입력 받아서,
	홀수와 짝수를 구분 지어 출력하는 프로그램을 작성
	일단 홀수부터 출력을 하고, 그 다음에 짝수를 출력
	단, 10개의 정수는 main 함수 내에서 입력을 받고록 하고,
	배열 내에 존재하는 홀수만 출력하는 함수와,
	배열 내에 존재하는 짝수만 출력하는 함수를 각각 정의해서 이 두 함수를 호출하는 방식

	조건
	정렬없음
	*/
	int arr[10];
	int i, len;
	len = sizeof(arr) / sizeof(int);
	printf("총 10개의 숫자 입력\n");

	for (i = 0; i < len; i++)
	{
		printf("%d번째 입력: ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	getOddNum(arr, len);
	getEvenNum(arr, len);

	return 0;
}

void getOddNum(int* arr, int len)
{
	int i;
	printf("홀수 출력 : ");
	for (i = 0; i < len; i++)
		if (arr[i] % 2 == 1 || arr[i] % 2 == -1) printf("%d, ", arr[i]);
	printf("\n");
}

void getEvenNum(int* arr, int len)
{
	int i;
	printf("짝수 출력 : ");
	for (i = 0; i < len; i++)
		if (arr[i] % 2 == 0) printf("%d, ", arr[i]);
	printf("\n");
}

#pragma endregion


#pragma region 연습문제 10진수 -> 2진수로 바꾸기
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	10진수 형태로 정수를 하나 입력 받은 다음,
	이를 2진수로 변환해서 출력하는 프로그램 작성

	조건: main함수에서 작성
	if (num % 2 == 1) arr[0] = 1; -> 이런거 금지
	*/

	// 선언
	int arr[100];
	int i, num;
	printf("10진수 정수 입력 : ");
	scanf_s("%d", &num);

	// 처리
	for (i = 0; num > 0; i++)
	{
		arr[i] = num % 2;
		num /= 2;
	}

	// 출력
	for (; i > 0; i--)
		printf("%d", arr[i - 1]);

	return 0;
}




#pragma endregion






#pragma region 홀수는 앞으로 짝수는 뒤로 !
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	길이가 10인 배열을 선언하고 총 10개의 정수를 입력 받는다
	단, 입력 받은 숫자가 홀수이면 배열의 앞에서부터 채워나가고,
	짝수이면 뒤에서부터 채워나가는 형식을 취한다.
	따라서 사용자가 [1,2,3,4,5,6,7,8,9,10]을 입력했다면,
	배열에는 [ 1,3,5,7,9,10,8,6,4,2 ] 의 순으로 저장 main 함수만 구현해야한다.
	main 12줄
	*/

	int arr[10];
	int i, temp, len, backCnt = 0, frontCnt = 0;
	len = sizeof(arr) / sizeof(int);

	// 입력 & 처리
	printf("총 10개의 숫자 입력 \n");
	for (i = 0; i < len; i++)
	{
		printf("%d번째 입력: ", i + 1);
		scanf_s("%d", &temp);

		if (temp % 2 == 0)
		{
			arr[len - 1 - backCnt] = temp;
			backCnt++;
		}
		else
		{
			arr[frontCnt] = temp;
			frontCnt++;
		}
	}

	// 출력
	printf("배열 요소의 출력 : ");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	return 0;
}




#pragma endregion





#pragma region 회문
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	회문은 앞으로 읽으나 뒤로 읽으나 차이가 없는 단어를 말한다.
	level이나 bob같은 단어
	회문인지 아닌 지를 판단하려고 한다.
	회문(Palindrome)함수를 정의해보시오.
	단, 구현의 편의를 위해서 대소문자까지 모두 일치해야만 회문으로 인정
	*/

	char string[100];

	printf("문자열 입력 : ");
	scanf_s("%s", &string, (unsigned char)sizeof(string));

	// 4줄, 결과 main에서
	if (isPalindrome(string) == 1)	printf("회문입니다. \n");
	else										printf("회문이 아니에요 ! \n");
	return 0;
}

// 길이 반환 함수
int stringLen(char* pArr)
{
	int i, cnt = 0;
	for (i = 0; pArr[i] != '\0'; i++)
		cnt++;
	return cnt;
}

int isPalindrome(char* pStr)
{
	// 일반 변수 2개, 포인터 변수 1개로 충분하다고 하심
	int i, j = stringLen(pStr);
	for (i = 0; i < j; i++, j--)
		if (pStr[i] != pStr[j - 1]) return 0;
	return 1;
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





