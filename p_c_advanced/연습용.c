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

	// printf("%s", arr);
	
	// 4줄, 결과 main에서
	if (isPalindrome(string) == 1)	printf("회문입니다. \n");
	else							printf("회문이 아니네요 \n");

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

int isPalindrome(int* pStr)
{
	// 일반 변수 2개, 포인터 변수 1개로 충분하다고 하심
	int i, j = stringLen(pStr);
	for (i = 0; i < j; i++, j--)
	{
		if (pStr[i] == pStr[j-1]) return 1;
	}
	return 0;
}
