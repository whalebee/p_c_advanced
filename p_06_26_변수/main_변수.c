#pragma region static

#include <stdio.h>

void simpleFunc();

int main()
{
	/*
	main
	: simpleFunc �Լ� 3�� ȣ��. ����x
	3�� ȣ���̸� �ݺ��� ��� �� ��������

	simpleFunc �Լ�
	- num1. 0���� ������(??) ( ��, num1�� static ���� )
	- num2. 0���� ������(???) ( ����� ���ÿ� �ʱ�ȭ ���� )
	- num1, num2 1�� ����
	- num1, num2 ���
	*/
	int i;
	for (i = 0; i < 3; i++)
		simpleFunc();

	return 0;
}

void simpleFunc()
{
	static int num1 = 0;
	// ȣ���� ���� �ʾƵ� static�� ������ �� ( ������ �ٵ� ���� �ȿ����� ��ϱ� ���� ������� )
	int num2 = 0;
	num1++;
	num2++;
	printf("num1: %d, num2 : %d \n", num1, num2);
}



#pragma endregion


#pragma region factorial ����Լ� (����)
#include <stdio.h>

int fac(int value);

int main()
{
	int num;
	printf("input: ");
	scanf_s("%d", &num);
	if (num < 0) return -1;
	printf("%d! : %d ", num, fac(num));

	return 0;
}

int fac(int value)
{
	if (value == 0) return 1;
	return value * fac(value - 1);
}


#pragma endregion





#pragma region 1���� 2��
#include <stdio.h>

void gugudan(int n1, int n2);

int main()
{
	// 16����
	/*
	int num = 0;
	printf("input: ");
	scanf_s("%d", &num);
	printf("16����ȭ: %x", num);
	*/



	// 2��
	// ���� 4���� �ؾ���
	int num1 = 0, num2 = 0, i, j;

	printf("input 2 numbers: ");
	scanf_s("%d %d", &num1, &num2);

	// �Լ� �ƴ� ��
	// 1. 3,5 �� �� ( �ϴ� 5,3 �����ϰ� Ʋ �������� )
	// 2. ���� 5,3 �� ��쵵 �־���� -> swap����� ����? �ֳ��� ����
	i = (num1 < num2 ? num1 : num2);
	for (; i < 10; i++)
	{
		if (i >= num1 && i >= num2) break;

		for (j = 1; j < 10; j++) printf("%d x %d = %d \n", i, j, i * j);

		printf("\n");



		// �Լ� �������� ���� �� -> �Լ� �ƴϿ��� ��
		// int num1 = 0, num2 = 0;
		// gugudan(num1, num2);


		return 0;
	}




	void gugudan(int n1, int n2)
	{
		int temp, j = 0;

		if (n1 > n2)
		{
			temp = n1;
			n1 = n2;
			n2 = temp;
		}
		for (; n1 < 10; n1++)
		{
			if (n1 > n2) break;
			for (j = 1; j < 10; j++)
				printf("%d x %d = %d \n", n1, j, n1 * j);
			printf("\n");
		}
	}





#pragma endregion






#pragma region 3�� ���� ��Ǯ�� -> while�� Ǫ��
#include <stdio.h>

int GCD(int v1, int v2);

int main()
{
	// �� ���� ���� �Է¹޾Ƽ� �ִ� ������� ���ϴ� ���α׷� �ۼ�
	// 6�� 9�� �Է��ϸ� 3�� ���;���.
	// 12 : 1 2 3 4 6 12
	// 16 : 1 2 4 8 16
	// ������ �� 0 �̶���� -> ��Ʈ��

	int v1, v2;
	printf("�� ���� ���� �Է� : ");
	scanf_s("%d %d", &v1, &v2);

	printf("gcd : %d \n", GCD(v1, v2));


	return 0;
}

//int GCD(int v1, int v2)
//{
//	// int i, gcd;
//	int result;
//	// ���� �ؿ� 4��?	 �ϴ� �̾Ƴ�����
//
//	// �ʹ� ����� �̰� �³�
//	// �ٸ� ���� result <= v1 > v2 ? v1+1 : v2+1
//	result = v1 > v2 ? v1 : v2;
//	for (; result <= v1 || result <= v2; result--)
//		if (v1 % result == 0 && v2 % result == 0) return result;
//}

// while
int GCD(int v1, int v2)
{
	// int i, gcd; // ������ !
	// ���� �ؿ� 4��?	 �ϴ� �̾Ƴ�����
	// result = v1 > v2 ? v1 : v2;
	int result;
	result = v1;
	while (result)
	{
		if (v1 % result == 0 && v2 % result == 0) return result;
		result--;
	}
	return 0;

	// ����� ����
	//int result = v1 < v2 ? v1 : v2;
	//while (v1 % result != 0 || v2 % result != 0)
	//	result--;
	//return result;


}

//int GCD(int n1, int n2)
//{
//	int result;
//
//	while (n2 != 0) {
//		result = n1 % n2;
//		n1 = n2;
//		n2 = result;
//	}
//	return n1;
//}




#pragma endregion



#pragma region 4�� �ݺ������� ����� ���� �ʴ´ٳ�
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	3500���� ������ ����(500��), ��ī�ݶ�(700��), ���(400��)�� ����Ѵ�.
	�ܵ��� �� ����� �� ������ ������ �ϳ� �̻� �ݵ�� �����Ϸ���
	��� ���Ÿ� �����ؾ� �ϴ°�?
	�������� ����� ���� �����ٵ� �����غ���

	ex
	���� �����ݾ� 3500��
	���� 1��, ��ī�ݶ� 2��, �� �� 4��
	���� 2��, ��ī�ݶ� 3��, �� �� 1��
	���� 4��, ��ī�ݶ� 1��, �� �� 2��

	��� �����ҷ���?
	*/
	// A Z ��Ʈ

	// ������ ��Ʈ�� A Z ��� �� �̰� �������������� õõ�� �����غ���
	// AZ�� printf���� �峭ġ�� �������µ�
	// �׷� ���⿡��?

	// printf("���� %d��, ��ī�ݶ� %d��, �� �� %d�� \n", );

	// 124 231 412 �̰� ���� ���� �� ������
	// �׷� �� ���� ��� ã�ƾ��ϳ�??

	// 500		1400	1600
	// 1000		2100	400
	// 2000		700		800

	// 1		2		4
	// 2		3		1
	// 4		1		2

	// A������ Z������?

	int basic = 0, x, y, z;
	int mac = 500, coke = 700, coou = 400;
	printf("���� ����� �����ϰ� �ִ� �ݾ� : ");
	scanf_s("%d", &basic);
	// �� ������ �ƴ϶� ������ ������
	for (x = 1; x <= basic / mac; x++)
		for (y = 1; y <= basic / coke; y++)
			for (z = 1; z <= basic / coou; z++)
			{
				if (basic == (x * mac) + (y * coke) + (z * coou))
					printf("��	�� %d��,  ��ī�ݶ� %d��,  ��	�� %d�� \n", x, y, z);
			}


	return 0;
}


#pragma endregion



#pragma region 5�� ���� Ǯ����
// start
// #include "header.h"
#include <stdio.h>

int isPrime(int num);

int main()
{
	/*
	5. ����� �ϳ� �Է� �޾� 1���� �� �������� �Ҽ��� ���
	1�� �ڱ��ڽŹۿ� ���� �༮
	�̰� ��� ���ұ�
	*/

	int num, i, cnt = 0;
	printf("��� �Է� : ");
	scanf_s("%d", &num);

	// �Ҽ��� �ƴϳĸ� ��ȯ�� �ؼ� �Ҽ��� i�� ����ϰ� �ƴϸ� �ѱ��?
	// for (i = 2; i < num+1; i++) // ���� �̷��� ��
	for (i = 2; i < num; i++)
	{
		if (isPrime(i) == 1)
		{
			printf("%3d ", i);
			cnt++;
		}
		else continue;
		if (cnt % 5 == 0) printf("\n");
	}
	return 0;
}

// True False ?
int isPrime(int num)
{
	int i;
	// if (num <= 1) return 0; �Լ��� �ٸ� ������ ������ ���ٸ� ���⼭ ���°� ���� ��
	for (i = 2; i <= num; i++)
		if (num % i == 0 && i != num) return 0;
	// num�� i�� ������ �� �������� 0�̶�� �� ���� �� �ִ� ����� �ִٴ� ��
	// �ٵ� �̷��Ը� �ع����� ���� �ݺ����� i��(�Ű�����)�� ���� i���� ������ ��
	// num % i == 0 �� ���ǿ��� ������ 0�� �����ϱ�  ��� return 0���� ������ �ſ���
	return 1;

	// if (num % i == 0) return 0; // ���� �̷��� ��
}

#pragma endregion



#pragma region 6��
// start
// #include "header.h"
#include <stdio.h>

#define H (60*60)
#define M 60

void secondToHMS(int sec);

int main()
{
	/*
	��(second)�� �Է� ���� �Ŀ� �̸� [��, ��, ��]�� ���·� ����ϴ� ���α׷� �ۼ�

	ex) ��(second) �Է�: 3615
		[h:1, m:0, s:15]

	keypoint: ��� �������� ��� �̿��� Ǯ��
	*/
	int sec;
	printf("��(second) �Է�: ");
	scanf_s("%d", &sec);
	secondToHMS(sec);

	return 0;
}

void secondToHMS(int sec)
{
	int h, m;
	h = sec / H;
	m = (sec % H) / M;
	sec = sec % M;
	printf("[h:%d, m:%d, s:%d]", h, m, sec);
}

#pragma endregion




#pragma region 7�� ����n�� ���غ���
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	���� n�� �Է¹ް� ���� ������ �����ϴ� k�� �ִ밪�� ����ؼ� ����ϴ� ���α׷� �ۼ�

	2�� k�� <= n

	���� �� ��� 256 �Է����� ��
	������ �����ϴ� k�� �ִ밪�� 8
	*/

	int num, i, cnt = 1;
	printf("input: ");
	scanf_s("%d", &num);

	// for������ ( ������� Ǯ�����ϱ� )
	// ���� 2��?? -> i�� �̿��ؾ��� �� -> ����
	for (i = 2; (num / i) != 1; )
		num = num / i;
	printf("k: %d", num);

	//*  ( ���ϱ�� Ǯ��� )
	/*for (i = 2; i < num; cnt++)
		i = i*2;
	printf("k: %d", cnt);*/


	// �������� ������
	// 256 % 2 == 0 ����
	/*
	i = 2;
	while (num / i != 1)
	{
		num = num / i;
		cnt++;
	}
	printf("%d ", cnt);
	*/


	return 0;
}





#pragma endregion




#pragma region 8�� n�� ���ϱ� ( ����Լ� )
// start
// #include "header.h"
#include <stdio.h>

int squre_re(int num);

int main()
{
	/*
	 2�� n���� ���ϴ� �Լ�!!!�� ��������� ����.
	 �׿� ���� ������ main �Լ��� ����

	 ���� �� ���� 8�Է��ϸ� 2��8���� 256

	*/
	int num;
	printf("input: ");
	scanf_s("%d", &num);

	printf("2�� %d����: %d \n", num, squre_re(num));

	return 0;
}

int squre_re(int num)
{
	if (num == 0) return 1;
	// ������� 8���̴�
	// 2 * 2 * 2 * 2 * �̷������� ���;���
	return 2 * squre_re(num - 1);
}




#pragma endregion


