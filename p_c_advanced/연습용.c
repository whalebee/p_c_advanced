#include <stdio.h>

int main()
{
	int arr[6] = { 1,2,3,4,5,6 };
	int i, len, temp;
	int* frontPtr = arr;
	int* backPtr = arr;
	len = sizeof(arr) / sizeof(int);

	// 처리
	for (i = 0; i < len / 2; i++)
	{
		temp = frontPtr[i];
		frontPtr[i] = backPtr[len - 1 - i];
		backPtr[len - 1 - i] = temp;
	}

	// 조건식에 len / 2를 쓸 수 없을 때
	
	// 1. len을 나누는게 아니라 i를 빼서 구해보기
	// int* backPtr2 = &arr[len - 1];
	/*for (i = 0; i < (len - i); i++)
	{
		temp = frontPtr[i];
		frontPtr[i] = backPtr2[-i];
		backPtr2[-i] = temp;
	}*/

	// 확인
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
		
	// 2. len 자체를 빼기..
	/*for (i = 0; i < len; i++, len--)
	{
		temp = frontPtr[i];
		frontPtr[i] = backPtr[len - 1];
		backPtr[len - 1] = temp;
	}*/
	// 2번 출력용
	/*for (i = 0; i < len * 2; i++)
		printf("%d ", arr[i]);*/

	return 0;
}