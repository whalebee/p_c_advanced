
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

	int arr[5] = { 1,2,3,4,5 };
	int i, len, sum = 0;

	len = sizeof(arr) / sizeof(int);

	int* ptr = &arr[len - 1];

	// ó��
	for (i = 0; i < len; i++)
		sum += *(ptr--);

	// Ȯ��
	printf("sum: %d \n", sum);

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


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion





