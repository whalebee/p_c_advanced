
#pragma region ���ڿ��� ����ϴ� ������ �迭 �⺻ ����
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	strArr. ���� ���ڿ� Simple, String, Array ( 3�� ) �� ������

	strArr�� ����ؼ� ���ڿ� ���
	( ���ڿ��� �������� �ּҰ� )
	*/

	// ����
	char* strArr[3] = { "Simple", "String", "Array" };
	int i, len;
	len = sizeof(strArr) / sizeof(char*);
	// printf("%d", len);

	// ���
	for (i = 0; i < len; i++)
		printf("%s \n", strArr[i]);

	return 0;
}





#pragma endregion


#pragma region �������� -> �迭�� ���� 5�� ���� ��ŭ �� ���
// start
// #include "header.h"
#include <stdio.h>

#define FIVE 5 // ����� define�̳� const�� �س��°� ���� ! tip ���Ҵ�
				// �ٵ� �̰� for�� ���ǽĿ��� �� �� ������ -> 5; �̷��� ������ �ع��ȴ� �ͤ���

void printf_graph(int* array, int len);

int main()
{
	/*
	main �Լ��� ������ �迭 5���� �����ؼ� 72, 88, 95, 64, 100���� �ʱ�ȭ
	print_graph �Լ��� ȣ���ؼ� �Ʒ� ���ó�� ��� !
	������ ������ �����ϰ� �� ������ 5�� ���� �� ��ŭ�� *�� ���

	����: �Լ��� ������ �Լ��� �ؾ��ϰ� �� �Լ��� �� �� ���� ȣ���� �� �ִ�.
	�Ű����� ����? X, �Լ��ȿ��� �������� 2������, �Ű������� 2���� ����
	*/

	// ����
	int arr[5] = { 72, 88, 95, 64, 100 };
	int i, len;
	len = sizeof(arr) / sizeof(int);

	// ȣ��
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



#pragma region ������ �Լ� ����
// start
// #include "header.h"
#include <stdio.h>

void showArrElem(int* pArr, int len);

int main()
{
	/* ����
	arr1. 1,2,3 ������
	arr2. 4,5,6,7,8 ������

	showArrElem�Լ� ȣ��. ���ڷ� 2�� ����
	showArrElem�Լ� ȣ��. ���ڷ� 2�� ����

	showArrElem�Լ�.
	- ���޹��� �迭�� ��ü ��� ���

	���� 4��, �Լ� 4��, len ���� ���� ����, �Լ� ������ �Ű������� ���� �� �̸� �����
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



#pragma region addArrElem �����ϱ�
// start
// #include "header.h"
#include <stdio.h>

void showArrElem(int* pArr, int len);
void addArrElem(int* pArr, int len, int putNum);

int main()
{
	/* ����
	arr. 1,2,3 ������

	addArrElem�Լ� ȣ��. ���� 3��. ������ ���ڴ� 1
	showArrElem�Լ� ȣ��. ���ڷ� 2�� ����

	addArrElem�Լ� ȣ��. ���� 3��. ������ ���ڴ� 2
	showArrElem�Լ� ȣ��. ���ڷ� 2�� ����

	addArrElem�Լ� ȣ��. ���� 3��. ������ ���ڴ� 3
	showArrElem�Լ� ȣ��. ���ڷ� 2�� ����

	showArrElem�Լ�.
	- ���޹��� �迭�� ��ü ��� ���

	addArrElem�Լ�.
	- ���޹��� ���ڸ� �迭�� �� ��ҿ� ����

	*/
	int arr1[] = { 1,2,3 };
	int len;
	len = sizeof(arr1) / sizeof(int);

	addArrElem(arr1, len, 1); // �Լ��� �ּҰ��� �����ؼ� ���� ��ŭ�� ��ҿ� 1�� ���ϱ�
	showArrElem(arr1, len);

	addArrElem(arr1, len, 2);
	showArrElem(arr1, len);

	addArrElem(arr1, len, 3);
	showArrElem(arr1, len);

	return 0;
}

//void addArrElem(int pArr[] �迭�� �޾Ҵٴ� ǥ�÷� �̷��Ե� ���� ( �Ű����� �ڸ������� )
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
#pragma region �������� -> Call By Value�� Call By Reference
// start
// #include "header.h"
#include <stdio.h>

int SqaureByValue(int n);
void SqaureByReference(int* pNum);

int main()
{
	/* �������� 1��
	���� num1�� ����� ���� ������ ����ϴ� �Լ� ����
	�̸� ȣ���ϴ� main �Լ� �ۼ�
	��, ���� �� ���� ���·� �Լ��� ����
	CBV ����� SqaureByValue �Լ�
	CBR ����� SqaureByReference �Լ�

	���� 4��?? ����? -> C.B.R�� void������ ���������������ϱ� !!
	�Լ� ���� 1��
	����� main���� �ؾ���
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


#pragma region �������� -> 3���� �Ű����� swap
// start
// #include "header.h"
#include <stdio.h>


void swap(int* n1, int* n2, int* n3);
int main()
{
	/* �������� 2��
	�� ������ ����� ���� ���� �ڹٲٴ� �Լ��� ����
	�� �Լ��� �̸��� swap3�̸�
	swap3(&num1, &num2, &num3); ���� ȣ���ؾ���

	�Լ� ȣ���� ����� num1�� ����� ���� num2��
	num2�� 3��, 3�� 1��
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
#pragma region �������� -> �ζ� ��ȣ ��
// start
// #include "header.h"
#include <stdio.h>

int check_same(int* lottoArr, int* myArr, int len);

int main()
{
	/*
	main�Լ����� �ζ� ��ȣ�� ������ �迭 ���� (4, 10, 25, 30, 41, 45)�ϰ�
	�� ��ȣ�� ������ �迭�� ����(1, 4, 7, 22, 41, 43)
	�׸��� check_same�Լ��� ȣ���ؼ� ����� �޾Ƽ� ���.
	check_same�Լ��� �ζ� ��ȣ�� �� ��ȣ�� ���Ͽ� ��ġ�ϴ� ��ȣ�� ���� ��ȯ!!��.

	����: main 6��, �Լ� 6��
	*/

	int lottoArr[] = { 4, 10, 25, 30, 41, 45 };
	int myArr[] = { 1, 4, 7, 22, 41, 43 };
	int len;
	len = sizeof(lottoArr) / sizeof(int);

	printf("��ġ�ϴ� ��ȣ�� ���� : %d \n", check_same(lottoArr, myArr, len));

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








#pragma region �������� -> �迭 �ߺ� �˻�
// start -> flag �غ��� ��
// #include "header.h"
#include <stdio.h>

void input_nums(int* arr, int len);
void print_nums(int* arr, int len);
void input_nums_dup(int* arr, int len);
void input_nums_var(int* arr, int len);


int main()
{
	/*
	main�Լ����� �ζ� ��ȣ�� ������ ���� 6�� ������ �迭 �����ϰ�
	input_nums�� ȣ���ؼ� �ζ� ��ȣ�� �Է� �ް�,
	print_nums�� ȣ���ؼ� �ζ� ��ȣ�� ���.
	��, input_nums �Լ��� �ߺ� ��ȣ �Է½� �̸� �˸��� �ٽ� �Է� ���� !
	*/

	/*
	for 2��, if 1��

	1. arr[i] -> �迭 -> �ϼ�
	2. �Ϲ� ������ �ϴ� ��� -> ���� �� �ǰ�? -> ����ȭ�� �� �ʿ��� ����
	3. duplicate. dup=0 -> flag ���
		�ߺ��� ������ 1, ������ 0
		���� ���� �ڵ��� �帧�� ¥�� ��
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


// 1. �迭�� �ƴ� ������ �̿��� �Լ� ����
void input_nums_var(int* pArr, int len)
{
	int putNum = 0, i = 0, j = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d��° ��ȣ �Է� : ", i + 1); // Ȯ�ο�
		scanf_s("%d", &putNum);
		pArr[i] = putNum;

		// ����ȿ��� �ߺ��� �ƴ� ������ ����
		for (j = 0; j < i; j++)
		{
			if (pArr[j] == putNum)
			{
				printf("���� ���� �ߺ��Դϴ� !! \n");
				i--; // �ߺ��� �� ���� �ε����� �Ѿ �� ���� ����
			}
		}
	}
}


// 2. arr[i]�� �̿��� �Լ� ����
void input_nums(int* arr, int len)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		printf("%d��° ��ȣ �Է� : ", i + 1);
		scanf_s("%d", &arr[i]); // ������ �ְڴٴ� ��? �����ȿ��� ���϶�� ��
		for (j = 0; j < i; j++)
			if (arr[i] == arr[j]) // ���� ���� ������ ���� �� !
			{
				printf("���� ��ȣ�� �ֽ��ϴ� ! \n");
				i--;
				break; // �� ������? �׷��� �ǳ�?
			}
	}
}

// 3. dup ������ �̿��� �Լ� ���� ( flags )
void input_nums_dup(int* pArr, int len)
{
	int i, j, dup = 0;
	// dup = 0�� for �� �ȿ� ���� �ʿ�� ����
	for (i = 0; i < len; i += 1 - dup)
	{
		printf("%d��° ��ȣ �Է� : ", i + 1);
		scanf_s("%d", &pArr[i]);
		for (j = 0; j < i; j++)
		{
			if (pArr[i] == pArr[j])
			{
				printf("���� ��ȣ �ߺ��Դϴ� !! \n");
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
	printf("�ζ� ��ȣ : ");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
}









#pragma endregion






#pragma region ���ο� ��������
// start
// #include "header.h"
#include <stdio.h>

void getOddNum(int* arr, int len);
void getEvenNum(int* arr, int len);

int main()
{
	// NEW
	/* ��������
	���̰� 10�� �迭�� �����ϰ� �� 10���� ������ �Է� �޾Ƽ�,
	Ȧ���� ¦���� ���� ���� ����ϴ� ���α׷��� �ۼ�
	�ϴ� Ȧ������ ����� �ϰ�, �� ������ ¦���� ���
	��, 10���� ������ main �Լ� ������ �Է��� �ް�� �ϰ�,
	�迭 ���� �����ϴ� Ȧ���� ����ϴ� �Լ���,
	�迭 ���� �����ϴ� ¦���� ����ϴ� �Լ��� ���� �����ؼ� �� �� �Լ��� ȣ���ϴ� ���

	����
	���ľ���
	*/
	int arr[10];
	int i, len;
	len = sizeof(arr) / sizeof(int);
	printf("�� 10���� ���� �Է�\n");

	for (i = 0; i < len; i++)
	{
		printf("%d��° �Է�: ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	getOddNum(arr, len);
	getEvenNum(arr, len);

	return 0;
}

void getOddNum(int* arr, int len)
{
	int i;
	printf("Ȧ�� ��� : ");
	for (i = 0; i < len; i++)
		if (arr[i] % 2 == 1 || arr[i] % 2 == -1) printf("%d, ", arr[i]);
	printf("\n");
}

void getEvenNum(int* arr, int len)
{
	int i;
	printf("¦�� ��� : ");
	for (i = 0; i < len; i++)
		if (arr[i] % 2 == 0) printf("%d, ", arr[i]);
	printf("\n");
}

#pragma endregion


#pragma region �������� 10���� -> 2������ �ٲٱ�
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	10���� ���·� ������ �ϳ� �Է� ���� ����,
	�̸� 2������ ��ȯ�ؼ� ����ϴ� ���α׷� �ۼ�

	����: main�Լ����� �ۼ�
	if (num % 2 == 1) arr[0] = 1; -> �̷��� ����
	*/

	// ����
	int arr[100];
	int i, num;
	printf("10���� ���� �Է� : ");
	scanf_s("%d", &num);

	// ó��
	for (i = 0; num > 0; i++)
	{
		arr[i] = num % 2;
		num /= 2;
	}

	// ���
	for (; i > 0; i--)
		printf("%d", arr[i - 1]);

	return 0;
}




#pragma endregion






#pragma region Ȧ���� ������ ¦���� �ڷ� !
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	���̰� 10�� �迭�� �����ϰ� �� 10���� ������ �Է� �޴´�
	��, �Է� ���� ���ڰ� Ȧ���̸� �迭�� �տ������� ä��������,
	¦���̸� �ڿ������� ä�������� ������ ���Ѵ�.
	���� ����ڰ� [1,2,3,4,5,6,7,8,9,10]�� �Է��ߴٸ�,
	�迭���� [ 1,3,5,7,9,10,8,6,4,2 ] �� ������ ���� main �Լ��� �����ؾ��Ѵ�.
	main 12��
	*/

	int arr[10];
	int i, temp, len, backCnt = 0, frontCnt = 0;
	len = sizeof(arr) / sizeof(int);

	// �Է� & ó��
	printf("�� 10���� ���� �Է� \n");
	for (i = 0; i < len; i++)
	{
		printf("%d��° �Է�: ", i + 1);
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

	// ���
	printf("�迭 ����� ��� : ");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	return 0;
}




#pragma endregion





#pragma region ȸ��
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

	// 4��, ��� main����
	if (isPalindrome(string) == 1)	printf("ȸ���Դϴ�. \n");
	else										printf("ȸ���� �ƴϿ��� ! \n");
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

int isPalindrome(char* pStr)
{
	// �Ϲ� ���� 2��, ������ ���� 1���� ����ϴٰ� �Ͻ�
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





