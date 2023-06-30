// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	길이가 10인 배열을 선언하고 총 10개의 정수를 입력 받는다
	단, 입력 받은 숫자가 홀수이면 배열의 앞에서부터 채워나가고,
	짝수이면 뒤에서부터 채워나가는 형식을 취한다.
	따라서 사용자가 [1,2,3,4,5,6,7,8,9,10]을 입력했다면,
	배열에는 [ 1,3,5,7,9,10,8,6,4,2 ] 의 순으로 저장 main 함수만 구현해야한다.
	main 12줄
	*/

	int arr[10];
	int i, temp, back = 0, front = 0, len;
	len = sizeof(arr) / sizeof(int);

	// 입력 & 처리
	printf("총 10개의 숫자 입력 \n");
	for (i = 0; i < len; i++)
	{
		printf("%d번째 입력: ", i + 1);
		scanf_s("%d", &temp);

		if (temp % 2 == 0)
		{

		}




		//if (arr[i] % 2 == 0)
		//{
		//	arr[len - 1 - back] = arr[front];
		//	// 문제점: 뒤쪽에 배치하면 앞쪽에 남아있는 애가 있음
		//	back++;
		//}
		//else front++; // 후방으로 가지 않았다면
	}

	// 출력
	printf("배열 요소의 출력 : ");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);



	return 0;
}
