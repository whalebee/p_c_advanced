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