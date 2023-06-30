// start -> flag �غ��� ��
// #include "header.h"
#include <stdio.h>

void input_nums(int* arr, int len);
void print_nums(int* arr, int len);
void input_nums_dup(int* arr, int len);

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
	input_nums_dup(arr, len);
	print_nums(arr, len);

	return 0;
}

// arr[i]�� �̿��� �Լ�
void input_nums(int* arr, int len)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		printf("��ȣ �Է� : ");
		scanf_s("%d", &arr[i]); // ������ �ְڴٴ� ��? �����ȿ��� ���϶�� ��
		for (j = 0; j < i; j++)
		{
			if (arr[i] == arr[j]) // ���� ���� ������ ���� �� !
			{
				printf("���� ��ȣ�� �ֽ��ϴ� ! \n");
				i--;
			}
		}
	}
}

/*
duplicate �ǹ̸� �����ϸ� dup ���� �����ϰ� �̿�
dup == 1�̸� �ߺ��̴� ��� ���� ����϶�� �Ͻ� ��
*/
void input_nums_dup(int* arr, int len)
{
	int i, j, dup = 0;

	for (i = 0, dup = 0; i < len; i++)
	{
		printf("��ȣ �Է� : ");
		if (dup == 0) scanf_s("%d", &arr[i]);
		for (j = 0; j < i; j++)
			if (arr[i] == arr[j]) dup = 1;
	}
}

void print_nums(int* arr, int len)
{
	int i;
	printf("�ζ� ��ȣ : ");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
}



// ù��° -> ���� ������ if�� �ʹ� ���� break;�� �ʹ� ����
//void input_nums(int* arr, int len)
//{
//	int putNum, i = 0, j = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("��ȣ �Է� : ");
//		scanf_s("%d", &putNum);
//		if (i == 0) arr[i] = putNum;
//		else
//		{
//			// �ߺ��˻� for��
//			for (j = 0; j < len; j++)
//			{
//				if (arr[j] == putNum)
//				{
//					printf("���� ��ȣ�� �ֽ��ϴ� ! \n");
//					i--;
//					break;
//				}
//				else if (j == i) // �� ���Ҵµ��� ���� ������ �־��ֱ�
//				{
//					arr[i] = putNum;
//					break;
//				}
//			}
//		}
//		
//	}
//}


