
#pragma region 포인터 배열 기본
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*

	*/
	int arr[3] = { 10,11,12 };
	printf("%p \n", arr); // 상수 형태의 포인터 ( 주소 값을 바꿀 수 없다 )
	printf("%p \n", &arr[0]);
	printf("%p \n", &arr[1]);
	printf("%p \n", &arr[2]);



	return 0;
}



#pragma endregion


#pragma region 포인터 연산 연습문제 1번
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	// 연습문제 1번
	/*
	길이가 5인 int형 배열 arr을 선언하고 이를 1 2 3 4 5로 초기화 한 다음,
	이 배열의 첫 번째 요소를 가리키는 포인터 변수 ptr을 선언
	그 다음 포인터 변수 ptr에 저장된 값을 증가시키는 형태의 연산을 기반으로
	배열 요소에 접근하면서 모든 배열 요소의 값을 2씩 증가 시키고
	정상적으로 증가가 이뤄졌는지 확인하는 예제를 작성
	*/

	// 피드백
	/*
	for (i = 0; i < len; i++)
		ptr[i] += 2; // -> 이것도 2번 방법이라서 1번은 ++ 써야될 것 같음 -> 맞음
	*/


	// 1번

	// 선언
	int arr[5] = { 1,2,3,4,5 };
	int i, len;
	int* ptr = arr;
	// while (arr[len] != '\0') len++; // NULL값이 없어서 못 씀
	len = sizeof(arr) / sizeof(int);
	// printf("%d", len);

	// 처리
	for (i = 0; i < len; i++)
		*(ptr++) += 2;

	// 확인
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);




	return 0;
}



#pragma endregion


#pragma region 포인터 연산 연습문제 2번
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* 연습문제 2번
	1번 문제에서는 포인터 변수 ptr에 저장된 값을 변경시켜가면서 배열 요소에 접근하라고 했다.
	그런데 이번에는 포인터 변수 ptr에 저장된 값을 변경하는게 아니라,
	ptr을 대상으로 덧셈 연산을 하여
	그 결과로 반환되는 주소 값을 통해서 -> ?
	모든 배열 요소에 접근하여
	값을 2씩 증가 시키는 예제를 작성 !
	*/

	// 2번

	// 선언
	int arr[5] = { 1,2,3,4,5 };
	int i, len;
	int* ptr = arr;

	len = sizeof(arr) / sizeof(int);

	// 처리
	for (i = 0; i < len; i++)
		printf("%d ", ptr[i] + 2);

	// 원래 값 확인
	/*for (i = 0; i < len; i++)
		printf("%d ", arr[i]);*/



	return 0;
}



#pragma endregion


#pragma region 포인터 연산 연습문제 3번
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* 연습문제 3번
	길이가 5인 int형 배열 arr을 선언하고,
	이를 1 2 3 4 5로 초기화 한다음, 이 배열의 마지막 요소를 가리키는 포인터 변수 ptr 선언
	그 다음 포인터 변수 ptr에 저장된 값을 감소시키는 형태의 연산을 기반으로
	모든 배열요소에 접근하여, 배열에 저장된 모든 정수를 더하여,
	그 결과를 출력하는 프로그램을 작성.
	*/

	// 선언
	int arr[5] = { 1,2,3,4,5 };
	int i, len, sum = 0;
	len = sizeof(arr) / sizeof(int);
	int* ptr = &arr[len - 1];

	// 처리
	for (i = 0; i < len; i++)
		sum += *(ptr--);
	
	// 확인
	printf("sum: %d \n", sum);
	printf("%d", *ptr);

	return 0;
}



#pragma endregion


#pragma region 포인터 연산 연습문제 4번
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* 연습문제 4번
	길이가 6인 int형 배열 arr을 선언하고 이를 1,2,3,4,5,6 으로 초기화한 다음,
	배열에 저장된 값의 순서가 6,5,4,3,2,1이 되도록 변경하는 예제 작성
	단, 배열의 앞과 뒤를 가리키는 포인터 변수 두 개를 선언해서 이를 활용해햐만 한다.
	*/
	/*printf("%d ", len);
	printf("%d ", *back);
	printf("%d ", back[-1]);
	printf("%d ", back[len - 1 - 0]);
	printf("%d ", arr[5]);*/

	// 처리 -> 양수로 다시, 되긴 됨
	// int* back = &arr[len - 1]; // 음수로 찍는 방법일 때
	/*for (i = 0; i < len / 2 ; i++)
	{
		temp = front[i];
		front[i] = back[-i];
		back[-i] = temp;
	}*/

	// 처리 ( 결과가 제대로 나오지 않았을 때 printf 활용 했었던 방법 )
	//for (i = 0; i < len / 2; i++)
	//{
	//	// printf("%d ", front[i]);
	//	temp = front[i];
	//	// printf("%d ", temp);
	//	front[i] = back[-i];
	//	// printf("%d ", back[len-1-i]);
	//	back[-i] = temp;
	//}
	/* 다른 연산 방법
	for (i = 0; i < len / 2; i++)
	{
		temp = *(front++);
		*(front++) = *(back--);
		*(back--) = temp;
	}
	*/


	// 선언
	int arr[6] = { 1,2,3,4,5,6 };
	int i, len, temp;
	len = sizeof(arr) / sizeof(int);
	int* front = arr;
	int* back = arr;

	// 처리
	// i < len/2 말고, 초기식말고..
	// 길이를 통제하는 방법		-> 0부터 시작해서 중간에 끊거나 중간부터 시작하는거?
	// if break로 탈출하는 방법 -> 금지
	for (i = 0; i < len / 2; i++)
	{
		temp = front[i];
		front[i] = back[len - i - 1];
		back[len - i - 1] = temp;
	}

	// 확인
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	return 0;
}



#pragma endregion


#pragma region 문자열에 대한 개념
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	char* str = "Your team";
	str = "Our team";
	문자열은 주소값으로 바라보기 때문에 바뀌는 것이 가능하지만,
	your team이 바뀐게 아니라 our team이라는 새로운 주소값이 생긴 것


	char str[] = "Your team"; // 배열의 이름은 첫번째 요소의 주소값이면서 포인터 상수잖아
	str = "our team"; // 이걸로 바뀌겠냐?ㅋㅋ
	배열은 통으로 바꿀 수 없다
	뭔가 통으로 바꾸거나 사이즈를 바꾸려면 새로운 배열에 통으로 복사하거나
	새로운 배열에 복사붙여넣기 해야한다.

	*/
	char str1[] = "My String";
	char* str2 = "Your String";

	printf("%s %s \n", str1, str2);

	str2 = "Our String";
	printf("%s %s \n", str1, str2);

	str1[0] = 'X';
	// str2[0] = 'X'; -> 숨을 안 쉬게 됨
	printf("%s %s \n", str1, str2);

	return 0;
}




#pragma endregion


#pragma region 포인터 배열 예제 -> 포인터 변수의 크기 생각
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/* 이건 예제
	num1. 10으로 선동초
	num2. 20으로 선동초
	num3. 30으로 선동초
	길이가 3인 정수형 포인터 배열 arr. num1의 주소, num2의 주소, num3의 주소로 선동초
	arr을 활용해서 전체 요소 출력
	*/
	int num1 = 10, num2 = 20, num3 = 30, i, len;
	int* arr[3] = { &num1, &num2, &num3 };
	len = sizeof(arr) / sizeof(int*);

	for (i = 0; i < len; i++)
		printf("%d ", *(arr[i])); // 이 표현방식도 생각할 것

	return 0;
}



#pragma endregion


#pragma region 포인터 연습문제 4번.. 지푸라기잡기
#include <stdio.h>

int main()
{
	int arr[6] = { 1,2,3,4,5,6 };
	int i, len, temp;
	int* frontPtr = arr;
	int* backPtr = arr;
	len = sizeof(arr) / sizeof(int);

	// 처리
	for (i = 0; i < len / 2; i++)
	{
		temp = frontPtr[i];
		frontPtr[i] = backPtr[len - 1 - i];
		backPtr[len - 1 - i] = temp;
	}

	// 조건식에 len / 2를 쓸 수 없을 때

	// 1. len을 나누는게 아니라 i를 빼서 구해보기
	// int* backPtr2 = &arr[len - 1];
	/*for (i = 0; i < (len - i); i++)
	{
		temp = frontPtr[i];
		frontPtr[i] = backPtr2[-i];
		backPtr2[-i] = temp;
	}*/

	// 확인
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	// 2. len 자체를 빼기..
	/*for (i = 0; i < len; i++, len--)
	{
		temp = frontPtr[i];
		frontPtr[i] = backPtr[len - 1];
		backPtr[len - 1] = temp;
	}*/
	// 2번 출력용
	/*for (i = 0; i < len * 2; i++)
		printf("%d ", arr[i]);*/

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





