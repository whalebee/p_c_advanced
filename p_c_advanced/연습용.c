// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	ȸ���� ������ ������ �ڷ� ������ ���̰� ���� �ܾ ���Ѵ�.
	level�̳� bob���� �ܾ�
	ȸ������ �ƴ� ���� �Ǵ��Ϸ��� �Ѵ�.
	ȸ��(Palindrome)�Լ��� �����غ��ÿ�.
	��, ������ ���Ǹ� ���ؼ� ��ҹ��ڱ��� ��� ��ġ�ؾ߸� ȸ������ ����
	*/

	char string[100];

	printf("���ڿ� �Է� : ");
	scanf_s("%s", &string, (unsigned char)sizeof(string));

	// printf("%s", arr);
	
	// 4��, ��� main����
	if (isPalindrome(string) == 1)	printf("ȸ���Դϴ�. \n");
	else							printf("ȸ���� �ƴϳ׿� \n");

	return 0;
}

// ���� ��ȯ �Լ�
int stringLen(char* pArr)
{
	int i, cnt = 0;
	for (i = 0; pArr[i] != '\0'; i++)
		cnt++;
	return cnt;
}

int isPalindrome(int* pStr)
{
	// �Ϲ� ���� 2��, ������ ���� 1���� ����ϴٰ� �Ͻ�
	int i, j = stringLen(pStr);
	for (i = 0; i < j; i++, j--)
	{
		if (pStr[i] == pStr[j-1]) return 1;
	}
	return 0;
}
