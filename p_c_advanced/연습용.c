// start
// #include "header.h"
#include <stdio.h>

typedef struct point
{
	int xPos;
	int yPos;
}Point;



int main()
{
	/*
	point 구조체 정의. 단 이름은 Point로 변경

	pos1. 5,6ㅅㄷㅊ
	pos2. 2,9ㅅㄷㅊ

	좌표 출력. 좌표의 합 계산. 7, 15
	좌표 출력. 좌표의 차 계산. 3, -3

	*/

	Point pos1 = { 5,6 };
	Point pos2 = { 2,9 };

	printf("[%d, %d] \n", pos1.xPos + pos2.xPos, pos1.yPos + pos2.yPos);
	printf("[%d, %d] \n", pos1.xPos - pos2.xPos, pos1.yPos - pos2.yPos);



	return 0;
}

