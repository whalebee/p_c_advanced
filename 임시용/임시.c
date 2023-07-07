#include <stdio.h>

typedef struct point
{
	int xPos;
	int yPos;
}Point;

void SwapPoint(Point* pos1, Point* pos2);


int main()
{
	/*
	다음 구조체의 두 변수를 대상으로 저장된 값을 서로 바꿔주는 함수를 정의, 호출

	예를 들어서 아래와 같은 두 개의 구조체 변수가 선언된 상태일 때,
	Point pos1 = {2,4};
	Point pos2 = {5,7};
	이 두개의 구조체 변수를 대상으로, 혹은 두개의 구조체 변수의 주소값을 대상으로
	SwapPoint 라는 이름의 함수를 호출하면 pos1의 xPos, yPos에는
	각각 5와 7이, 그리고 pos2의 xPos, yPos에는 각각 2와 4가 저장
	*/
	Point pos1 = { 2,4 };
	Point pos2 = { 5,7 };

	SwapPoint(&pos1, &pos2);

	printf("pos1: [%d, %d] \n", pos1.xPos, pos1.yPos);
	printf("pos2: [%d, %d] \n", pos2.xPos, pos2.yPos);

	return 0;
}

void SwapPoint(Point* pos1, Point* pos2)
{
	Point temp = *pos1;
	*pos1 = *pos2;
	*pos2 = temp;
}