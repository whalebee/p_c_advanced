
#pragma region ������ �迭 �������� �̾ ( �������� ���� )
// start
// #include "header.h"
#include <stdio.h>

void sort(int* arr, int len);

int main()
{
	// ��������
	/*
	* �����̶� ?
	���̰� 5�� �迭�� ���� 4,3,5,1,2�� ����Ǿ� �ִ�.
	�̰��� ��������(ascending order)���� �����ϸ� 1,2,3,4,5 ���ġ
	��������(descending order) 5,4,3,2,1 �� ���ġ


	����
	3 2 4 1 �� �� �������� asc_order
	2 3 4 1
	2 3 1 // 4�� ��
	2 1 // 3 4 �� ��
	1 // 2 3 4 �� ��
	1 2 3 4 �� !
	*/

	int arr[4] = { 3,2,4,1 };
	int i, len;
	len = sizeof(arr) / sizeof(int);

	sort(arr, len);
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);



	return 0;
}

void sort(int* arr, int len)
{
	int i, temp, j;
	// ����� ���� �ϳ��ۿ� ���� else�� ���� �ʴ� ��
	// for�� ������ ��� �ϸ� ������?
	// 2 3 1 4 ���� 2���� �� �ؾ���
	// 3���� 2���� �� �����ؾߵ�
	// �Ǳ� �Ǿ��µ� �ݺ�����.. 2�� ��߸��ϳ�?
	// �ʹ� ��� ������
	/*while (i < len - 1) // int peek = len - 1
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
		i+=2;
	}
	while (peek > 0)
	{
		if (arr[peek] < arr[peek - 1])
		{
			temp = arr[peek];
			arr[peek] = arr[peek -1];
			arr[peek-1] = temp;
		}
		peek--;
	}*/

	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
}





#pragma endregion


#pragma region �������� �̾ ( �������� )
// start
// #include "header.h"
#include <stdio.h>

void DesSort(int* arr, int len);

int main()
{
	// ��������
	/*
	������������ �����ϴ� �Լ��� ���� -> DesSort �Լ��̸�
	���̰� 7�� int�� �迭 �����ϰ�
	����ڷκ��� 7���� ������ �޴´�

	Ȯ���ϱ� ���ؼ� ��±���
	*/

	int arr[7];
	int i, len;
	len = sizeof(arr) / sizeof(int);

	for (i = 0; i < len; i++)
	{
		printf("%d��° �Է� : ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	DesSort(arr, len);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	return 0;
}

void DesSort(int* arr, int len)
{
	int i, j, temp, cnt = 0;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
		{
			// ���ǹ��� -i�� �־��� �� ������ �޶����°� �����ϱ�
			// �������� �� ���� ū ���� �ڷ� �о�ִ� ����
			// �������� �� ���� ū ���� ������ ���� ����
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
}




#pragma endregion


#pragma region �������� -> villa ( 2���� �迭, keyword: ���۾� )
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	int villa[4][2];
	int i, j, popu = 0;
	// ���̴� �� ����� �� ��õ��ȸ�
	/*
	�� �� ��ȣ �α��� ���
	�� �� �� ȣ �α��� �Է�

	�׸��� �� ���� �α��� ���
	*/

	// �Է�
	for (i = 0; i < 4; i++)
		for (j = 0; j < 2; j++)
		{
			printf("%d�� %dȣ �α��� : ", i + 1, j + 1);
			scanf_s("%d", &villa[i][j]);
		}

	// ���
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++) // �ݺ����� �� ���� ���۾����ζ� �ؾ���
			popu += villa[i][j];
		printf("%d�� �α��� : %d \n", i + 1, popu);
		popu = 0;
	}

	return 0;
}



#pragma endregion


#pragma region �������� -> ���ȣ�� ����ȣ ���ϱ�
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* ��������
	������ �����͸� �����ϴ� 2���� �迭 degree[4][4]�� ����
	�� �׸� ���� �� ��ȣ + �� ��ȣ�� ������ �����ϰ�,
	��ü �迭 �׸��� �հ�� ��հ��� ���
	*/
	int degree[4][4];
	int i, j, sum = 0;

	// �Է�
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			degree[i][j] = i + j;
			sum += degree[i][j];
		}

	// ���
	printf("sum : %d -> avg : %.1f \n", sum, (double)sum / (i * j));
	// printf("sum : %d -> avg : %.1f \n", sum, sum/16.0); // double�� ����տ��� ��������


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





