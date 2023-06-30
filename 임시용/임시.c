// start -> flag 해보는 중
// #include "header.h"
#include <stdio.h>

void input_nums(int* arr, int len);
void print_nums(int* arr, int len);
void input_nums_dup(int* arr, int len);

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
	input_nums_dup(arr, len);
	print_nums(arr, len);

	return 0;
}

// arr[i]를 이용한 함수
void input_nums(int* arr, int len)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		printf("번호 입력 : ");
		scanf_s("%d", &arr[i]); // 본진에 넣겠다는 건? 본진안에서 비교하라는 것
		for (j = 0; j < i; j++)
		{
			if (arr[i] == arr[j]) // 같은 값이 본진에 있을 때 !
			{
				printf("같은 번호가 있습니다 ! \n");
				i--;
			}
		}
	}
}

/*
duplicate 의미를 생각하며 dup 변수 선언하고 이용
dup == 1이면 중복이다 라는 뜻을 사용하라고 하신 것
*/
void input_nums_dup(int* arr, int len)
{
	int i, j, dup = 0;

	for (i = 0, dup = 0; i < len; i++)
	{
		printf("번호 입력 : ");
		if (dup == 0) scanf_s("%d", &arr[i]);
		for (j = 0; j < i; j++)
			if (arr[i] == arr[j]) dup = 1;
	}
}

void print_nums(int* arr, int len)
{
	int i;
	printf("로또 번호 : ");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
}



// 첫번째 -> 답은 맞지만 if가 너무 많고 break;도 너무 많음
//void input_nums(int* arr, int len)
//{
//	int putNum, i = 0, j = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("번호 입력 : ");
//		scanf_s("%d", &putNum);
//		if (i == 0) arr[i] = putNum;
//		else
//		{
//			// 중복검사 for문
//			for (j = 0; j < len; j++)
//			{
//				if (arr[j] == putNum)
//				{
//					printf("같은 번호가 있습니다 ! \n");
//					i--;
//					break;
//				}
//				else if (j == i) // 다 돌았는데도 같지 않으면 넣어주기
//				{
//					arr[i] = putNum;
//					break;
//				}
//			}
//		}
//		
//	}
//}


