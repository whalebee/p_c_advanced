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
	point ����ü ����. �� �̸��� Point�� ����

	pos1. 5,6������
	pos2. 2,9������

	��ǥ ���. ��ǥ�� �� ���. 7, 15
	��ǥ ���. ��ǥ�� �� ���. 3, -3

	*/

	Point pos1 = { 5,6 };
	Point pos2 = { 2,9 };

	printf("[%d, %d] \n", pos1.xPos + pos2.xPos, pos1.yPos + pos2.yPos);
	printf("[%d, %d] \n", pos1.xPos - pos2.xPos, pos1.yPos - pos2.yPos);



	return 0;
}

