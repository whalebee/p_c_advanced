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
	���� ����ü�� �� ������ ������� ����� ���� ���� �ٲ��ִ� �Լ��� ����, ȣ��

	���� �� �Ʒ��� ���� �� ���� ����ü ������ ����� ������ ��,
	Point pos1 = {2,4};
	Point pos2 = {5,7};
	�� �ΰ��� ����ü ������ �������, Ȥ�� �ΰ��� ����ü ������ �ּҰ��� �������
	SwapPoint ��� �̸��� �Լ��� ȣ���ϸ� pos1�� xPos, yPos����
	���� 5�� 7��, �׸��� pos2�� xPos, yPos���� ���� 2�� 4�� ����
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