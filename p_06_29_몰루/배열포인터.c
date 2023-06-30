
#pragma region ������ �迭 �⺻
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*

	*/
	int arr[3] = { 10,11,12 };
	printf("%p \n", arr); // ��� ������ ������ ( �ּ� ���� �ٲ� �� ���� )
	printf("%p \n", &arr[0]);
	printf("%p \n", &arr[1]);
	printf("%p \n", &arr[2]);



	return 0;
}



#pragma endregion


#pragma region ������ ���� �������� 1��
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	// �������� 1��
	/*
	���̰� 5�� int�� �迭 arr�� �����ϰ� �̸� 1 2 3 4 5�� �ʱ�ȭ �� ����,
	�� �迭�� ù ��° ��Ҹ� ����Ű�� ������ ���� ptr�� ����
	�� ���� ������ ���� ptr�� ����� ���� ������Ű�� ������ ������ �������
	�迭 ��ҿ� �����ϸ鼭 ��� �迭 ����� ���� 2�� ���� ��Ű��
	���������� ������ �̷������� Ȯ���ϴ� ������ �ۼ�
	*/

	// �ǵ��
	/*
	for (i = 0; i < len; i++)
		ptr[i] += 2; // -> �̰͵� 2�� ����̶� 1���� ++ ��ߵ� �� ���� -> ����
	*/


	// 1��

	// ����
	int arr[5] = { 1,2,3,4,5 };
	int i, len;
	int* ptr = arr;
	// while (arr[len] != '\0') len++; // NULL���� ��� �� ��
	len = sizeof(arr) / sizeof(int);
	// printf("%d", len);

	// ó��
	for (i = 0; i < len; i++)
		*(ptr++) += 2;

	// Ȯ��
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);




	return 0;
}



#pragma endregion


#pragma region ������ ���� �������� 2��
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* �������� 2��
	1�� ���������� ������ ���� ptr�� ����� ���� ������Ѱ��鼭 �迭 ��ҿ� �����϶�� �ߴ�.
	�׷��� �̹����� ������ ���� ptr�� ����� ���� �����ϴ°� �ƴ϶�,
	ptr�� ������� ���� ������ �Ͽ�
	�� ����� ��ȯ�Ǵ� �ּ� ���� ���ؼ� -> ?
	��� �迭 ��ҿ� �����Ͽ�
	���� 2�� ���� ��Ű�� ������ �ۼ� !
	*/

	// 2��

	// ����
	int arr[5] = { 1,2,3,4,5 };
	int i, len;
	int* ptr = arr;

	len = sizeof(arr) / sizeof(int);

	// ó��
	for (i = 0; i < len; i++)
		printf("%d ", ptr[i] + 2);

	// ���� �� Ȯ��
	/*for (i = 0; i < len; i++)
		printf("%d ", arr[i]);*/



	return 0;
}



#pragma endregion


#pragma region ������ ���� �������� 3��
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* �������� 3��
	���̰� 5�� int�� �迭 arr�� �����ϰ�,
	�̸� 1 2 3 4 5�� �ʱ�ȭ �Ѵ���, �� �迭�� ������ ��Ҹ� ����Ű�� ������ ���� ptr ����
	�� ���� ������ ���� ptr�� ����� ���� ���ҽ�Ű�� ������ ������ �������
	��� �迭��ҿ� �����Ͽ�, �迭�� ����� ��� ������ ���Ͽ�,
	�� ����� ����ϴ� ���α׷��� �ۼ�.
	*/

	// ����
	int arr[5] = { 1,2,3,4,5 };
	int i, len, sum = 0;
	len = sizeof(arr) / sizeof(int);
	int* ptr = &arr[len - 1];

	// ó��
	for (i = 0; i < len; i++)
		sum += *(ptr--);
	
	// Ȯ��
	printf("sum: %d \n", sum);
	printf("%d", *ptr);

	return 0;
}



#pragma endregion


#pragma region ������ ���� �������� 4��
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* �������� 4��
	���̰� 6�� int�� �迭 arr�� �����ϰ� �̸� 1,2,3,4,5,6 ���� �ʱ�ȭ�� ����,
	�迭�� ����� ���� ������ 6,5,4,3,2,1�� �ǵ��� �����ϴ� ���� �ۼ�
	��, �迭�� �հ� �ڸ� ����Ű�� ������ ���� �� ���� �����ؼ� �̸� Ȱ�����Ḹ �Ѵ�.
	*/
	/*printf("%d ", len);
	printf("%d ", *back);
	printf("%d ", back[-1]);
	printf("%d ", back[len - 1 - 0]);
	printf("%d ", arr[5]);*/

	// ó�� -> ����� �ٽ�, �Ǳ� ��
	// int* back = &arr[len - 1]; // ������ ��� ����� ��
	/*for (i = 0; i < len / 2 ; i++)
	{
		temp = front[i];
		front[i] = back[-i];
		back[-i] = temp;
	}*/

	// ó�� ( ����� ����� ������ �ʾ��� �� printf Ȱ�� �߾��� ��� )
	//for (i = 0; i < len / 2; i++)
	//{
	//	// printf("%d ", front[i]);
	//	temp = front[i];
	//	// printf("%d ", temp);
	//	front[i] = back[-i];
	//	// printf("%d ", back[len-1-i]);
	//	back[-i] = temp;
	//}
	/* �ٸ� ���� ���
	for (i = 0; i < len / 2; i++)
	{
		temp = *(front++);
		*(front++) = *(back--);
		*(back--) = temp;
	}
	*/


	// ����
	int arr[6] = { 1,2,3,4,5,6 };
	int i, len, temp;
	len = sizeof(arr) / sizeof(int);
	int* front = arr;
	int* back = arr;

	// ó��
	// i < len/2 ����, �ʱ�ĸ���..
	// ���̸� �����ϴ� ���		-> 0���� �����ؼ� �߰��� ���ų� �߰����� �����ϴ°�?
	// if break�� Ż���ϴ� ��� -> ����
	for (i = 0; i < len / 2; i++)
	{
		temp = front[i];
		front[i] = back[len - i - 1];
		back[len - i - 1] = temp;
	}

	// Ȯ��
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	return 0;
}



#pragma endregion


#pragma region ���ڿ��� ���� ����
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	char* str = "Your team";
	str = "Our team";
	���ڿ��� �ּҰ����� �ٶ󺸱� ������ �ٲ�� ���� ����������,
	your team�� �ٲ�� �ƴ϶� our team�̶�� ���ο� �ּҰ��� ���� ��


	char str[] = "Your team"; // �迭�� �̸��� ù��° ����� �ּҰ��̸鼭 ������ ����ݾ�
	str = "our team"; // �̰ɷ� �ٲ�ڳ�?����
	�迭�� ������ �ٲ� �� ����
	���� ������ �ٲٰų� ����� �ٲٷ��� ���ο� �迭�� ������ �����ϰų�
	���ο� �迭�� ����ٿ��ֱ� �ؾ��Ѵ�.

	*/
	char str1[] = "My String";
	char* str2 = "Your String";

	printf("%s %s \n", str1, str2);

	str2 = "Our String";
	printf("%s %s \n", str1, str2);

	str1[0] = 'X';
	// str2[0] = 'X'; -> ���� �� ���� ��
	printf("%s %s \n", str1, str2);

	return 0;
}




#pragma endregion


#pragma region ������ �迭 ���� -> ������ ������ ũ�� ����
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/* �̰� ����
	num1. 10���� ������
	num2. 20���� ������
	num3. 30���� ������
	���̰� 3�� ������ ������ �迭 arr. num1�� �ּ�, num2�� �ּ�, num3�� �ּҷ� ������
	arr�� Ȱ���ؼ� ��ü ��� ���
	*/
	int num1 = 10, num2 = 20, num3 = 30, i, len;
	int* arr[3] = { &num1, &num2, &num3 };
	len = sizeof(arr) / sizeof(int*);

	for (i = 0; i < len; i++)
		printf("%d ", *(arr[i])); // �� ǥ����ĵ� ������ ��

	return 0;
}



#pragma endregion


#pragma region ������ �������� 4��.. ��Ǫ������
#include <stdio.h>

int main()
{
	int arr[6] = { 1,2,3,4,5,6 };
	int i, len, temp;
	int* frontPtr = arr;
	int* backPtr = arr;
	len = sizeof(arr) / sizeof(int);

	// ó��
	for (i = 0; i < len / 2; i++)
	{
		temp = frontPtr[i];
		frontPtr[i] = backPtr[len - 1 - i];
		backPtr[len - 1 - i] = temp;
	}

	// ���ǽĿ� len / 2�� �� �� ���� ��

	// 1. len�� �����°� �ƴ϶� i�� ���� ���غ���
	// int* backPtr2 = &arr[len - 1];
	/*for (i = 0; i < (len - i); i++)
	{
		temp = frontPtr[i];
		frontPtr[i] = backPtr2[-i];
		backPtr2[-i] = temp;
	}*/

	// Ȯ��
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	// 2. len ��ü�� ����..
	/*for (i = 0; i < len; i++, len--)
	{
		temp = frontPtr[i];
		frontPtr[i] = backPtr[len - 1];
		backPtr[len - 1] = temp;
	}*/
	// 2�� ��¿�
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





