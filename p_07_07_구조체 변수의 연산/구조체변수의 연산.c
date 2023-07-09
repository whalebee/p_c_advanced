
#pragma region �������� -> ����ü ������ ���� ����
// start
// #include "header.h"
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

#pragma endregion


#pragma region circle ����
// start
// #include "header.h"
#include <stdio.h>

typedef struct point
{
	int xPos;
	int yPos;
}Point;

typedef struct circle
{
	Point cen;
	double rad;
}Circle;

typedef struct circle2
{
	Point cen;
	double rad;
}Circle2;


void showCircleInfo(Circle cir);
void showCircleInfo2(Circle2* cir);

int main()
{
	/*
	point ����ü ����. �̸� Point

	circle ����ü ����. �̸� Circle
	- ��ǥ ���� �׸�. cen
	- ������ ���� �׸�. rad

	main()
	- c1. 1,2, 3.5�� ������
	- c2. 2,4, 3.9�� ������

	- showCircleInfo(). ���� �Ѱ�
	- showCircleInfo(). ���� �Ѱ�

	showCircleInfo().
	- ���޹��� �༮�� ��ǥ ���
	- ���޹��� �༮�� ������ ���
	*/

	// �� �� ���� -> highlight
	Circle c1 = { {1,2}, 3.5 };
	Circle2 c2 = { 2,4, 3.9 };

	showCircleInfo(c1);
	showCircleInfo2(&c2);

	return 0;
}

void showCircleInfo(Circle cir)
{
	printf("��ǥ: [%d, %d], ������: %.1f \n", cir.cen.xPos, cir.cen.yPos, cir.rad);
}

void showCircleInfo2(Circle2* cir)
{
	printf("��ǥ: [%d, %d], ������: %.1f \n", cir->cen.xPos, cir->cen.yPos, cir->rad);
}


#pragma endregion


#pragma region getUserData ����
// start
// #include "header.h"
#include <stdio.h>

typedef struct
{
	int age;
	char name[50];
	char phoneNum[20];
}USERDATA;

typedef struct
{
	int age;
	char name[50];
	char phoneNum[20];
}USERDATA2;

USERDATA getUserData();					// �ּҰ��� ���� ����
void getUserData2(USERDATA* data);		// �ּҰ��� �̿��� !

int main()
{
	/*
	USERDATA����ü ����
	- ����.age
	- �̸�.name
	- ��ȭ��ȣ.phone

	main()
	- USERDATA�� user. 0 ������
	- getUserData�Լ� ȣ��
	- ����, �̸�, ���� ���

	getUserData()
	- ���� �Է� �ޱ�
	- �̸� �Է� �ޱ�. ��, gets �Լ� �Ẹ��
	- ���� �Է� �ޱ�. ��, gets �Լ� �Ẹ��
	- ��ü ���� ��ȯ!!
	*/

	// ����
	USERDATA user = { 0, };
	USERDATA2 user2 = { 0, };

	// ó��
	user = getUserData();
	getUserData2(&user2);

	// ���
	printf("����: %d, �̸�: %s, ��ȭ��ȣ: %s \n", user.age, user.name, user.phoneNum);
	printf("����: %d, �̸�: %s, ��ȭ��ȣ: %s \n", user2.age, user2.name, user2.phoneNum);

	return 0;
}

USERDATA getUserData()
{
	int tmp;
	USERDATA temp = { 0, };
	printf("���̸� �Է��ϼ���: "); scanf_s("%d", &temp.age);
	tmp = getchar();
	printf("�̸��� �Է��ϼ���: "); gets_s(temp.name, sizeof(temp.name));
	printf("��ȭ��ȣ�� �Է��ϼ���: "); gets_s(temp.phoneNum, sizeof(temp.phoneNum));
	return temp;
}
// unsigned int�� gets_s�� ���ڿ� �����ϱ� ���� ���⼭�� �� ���൵ �ʤ���

void getUserData2(USERDATA* data)
{
	// int tmp;
	USERDATA temp = { 0, };
	printf("���̸� �Է��ϼ���: "); scanf_s("%d%*c", &data->age); // %*c �� ���� 1����Ʈ ������
	// tmp = getchar();
	printf("�̸��� �Է��ϼ���: "); gets_s(data->name, sizeof(temp.name));
	printf("��ȭ��ȣ�� �Է��ϼ���: "); gets_s(data->phoneNum, sizeof(temp.phoneNum));
}



#pragma endregion


#pragma region �������� -> ����ü ���簢���� ���̿� ��ǥ
// start
// #include "header.h"
#include <stdio.h>

typedef struct
{
	int xPos;
	int yPos;
}Point;

typedef struct
{
	Point leftTop;
	Point rightBot;
}RECTANGLE;

// ���̿� �Լ�
void ShowRecArea(RECTANGLE Rec);
void ShowRecArea2(RECTANGLE* Rec); // ��¿�

// ��ǥ�� �Լ�
void ShowRecPos(RECTANGLE Rec);
void ShowRecPos2(RECTANGLE* Rec);

int main()
{
	/*
	�� ����� x, y ��ǥ�� [0, 0], �� �ϴ��� x,y��ǥ�� [100, 100]�� ��ǥ ������
	���簢�� ������ ǥ���ϱ� ���� ����ü Rectangle�� �����ϵ�,
	���� ����ü�� ������� ����

	�׸��� Rectangle ����ü ������ ���ڷ� ���޹޾Ƽ�
	�ش� ���簭���� ���̸� ����ؼ� ���!!!!�ϴ� �Լ���
	���簢���� �̷�� �� ���� ��ǥ������ ���!!!�ϴ� �Լ���
	����!!!! ����.

	��, ��ǥ ���󿡼� ���簢���� ǥ���ϱ� ���ؼ� �ʿ��� ���� ������ 4���� �ƴ� 2��.
	���簢���� �ǹ��ϴ� Rectangle ���� ������ �� ���� ������ �����Ѵ�.
	*/
	RECTANGLE Rectangle = { {1,1} , {4,4} };	// call by value
	RECTANGLE Rectangle2 = { 0,0 , 7,5 };		// call by reference

	ShowRecArea(Rectangle);
	ShowRecPos(Rectangle);

	ShowRecArea2(&Rectangle2);
	ShowRecPos2(&Rectangle2);

	return 0;
}

void ShowRecArea(RECTANGLE Rec)
{
	printf("Rectangle�� ����: %d\n", Rec.rightBot.xPos - Rec.leftTop.xPos)* (Rec.rightBot.yPos - Rec.leftTop.xPos);
}

void ShowRecPos(RECTANGLE Rec)
{
	printf("�� ���: [%d, %d] \n", Rec.leftTop.xPos, Rec.leftTop.yPos);
	printf("�� �ϴ�: [%d, %d] \n", Rec.leftTop.xPos, Rec.rightBot.yPos);
	printf("�� ���: [%d, %d] \n", Rec.rightBot.xPos, Rec.leftTop.yPos);
	printf("�� �ϴ�: [%d, %d] \n", Rec.rightBot.xPos, Rec.rightBot.yPos);
}

void ShowRecArea2(RECTANGLE* Rec)
{
	printf("Rectangle2�� ����: %d\n", (Rec->rightBot.xPos - Rec->leftTop.xPos) * (Rec->rightBot.yPos - Rec->leftTop.xPos));
}

void ShowRecPos2(RECTANGLE* Rec)
{
	printf("�� ���: [%d, %d] \n", Rec->leftTop.xPos, Rec->leftTop.yPos);
	printf("�� �ϴ�: [%d, %d] \n", Rec->leftTop.xPos, Rec->rightBot.yPos);
	printf("�� ���: [%d, %d] \n", Rec->rightBot.xPos, Rec->leftTop.yPos);
	printf("�� �ϴ�: [%d, %d] \n", Rec->rightBot.xPos, Rec->rightBot.yPos);
}



#pragma endregion


#pragma region ����ü�� ����ü
// start
// #include "header.h"
#include <stdio.h>

typedef struct
{
	int mem1;
	int mem2;
	double mem3;
}SBOX;

typedef union
{
	int mem1;
	int mem2;
	double mem3;
}UBOX;

int main()
{
	/*

	*/
	SBOX sbx;
	UBOX ubx;

	printf("%p %p %p \n", &sbx.mem1, &sbx.mem2, &sbx.mem3);
	// 0 ... 062EF6FFA78	0 ... 062EF6FFA7C		0 ... 062EF6FFA80
	printf("%p %p %p \n", &ubx.mem1, &ubx.mem2, &ubx.mem3);
	// 0 ... 062EF6FFAA8	0 ... 062EF6FFAA8		0 ... 0062EF6FFAA8
	printf("%zd %zd \n", sizeof(SBOX), sizeof(UBOX));
	// 16, 8

	/*
	mem1���� mem2���� ���� 4����Ʈ, �� ������ 4����Ʈ�̰�, ���⼱ ������ �ʾ�����
	���� �ּҴ� double�� ũ��� 8����Ʈ�� �߰��� �ּҰ��� ������ �˴ϴ�.

	struct�� �ٸ��� union�� ���� ū ũ���� ����Ʈ�� �����ϱ� ������
	���� �ּҸ� ���� ù��° �ּҰ��� ���� ���� ������ �˴ϴ�.

	������� struct�� ��� ũ�⸦ ���� 4 + 4 + 8 = 16�̰�,
	union�� ���� ū ũ���� ����Ʈ�� ��Ÿ���� 8 �Դϴ�.
	*/

	return 0;
}

#pragma endregion


#pragma region ����ü�� ����
// start
// #include "header.h"
#include <stdio.h>


typedef union
{
	int mem1;
	int mem2;
	double mem3;
}UBOX;

int main()
{
	/*

	*/

	UBOX ubx;
	ubx.mem1 = 20;

	printf("%d \n", ubx.mem2);  // mem2�� int��ŭ ���� �״� 20

	ubx.mem3 = 7.15;

	printf("%d \n", ubx.mem1); // 7.15��� �Ǽ��� int�� �о�� �� -> �����Ⱚ
	printf("%d \n", ubx.mem2); // 7.15��� �Ǽ��� int�� �о�� �� -> �����Ⱚ
	printf("%g \n", ubx.mem3); // double��ŭ ���� �״� 7.15

	return 0;
}




#pragma endregion


#pragma region �������� -> ����ü�� �̿��� ����������
// start
// #include "header.h"
#include <stdio.h>

typedef struct
{
	int w500;
	int w100;
	int w50;
	int w10;
}Money;

void init(Money* price);
void save(Money* price, int won, int count);
int total(Money* price);

int main()
{

	/*
	���� �ݾװ� ������ �Է� �޾Ƽ� ��ü �ݾ��� ����ϴ� ���α׷� �ۼ�

	1. ���� �ݾ׺� ����ü �� �� ����
	2. main �Լ����� "������ �ݾ�, ����"�� ��� �Է� �ް� "�� ���ݾ�"���
		��, 0�� �ԷµǸ� ���ݱ��� ���� �� ���ݾ� ���
	3. main�Լ����� �ʱ�ȭ �Լ�(init)ȣ��
	4. save�Լ����� ���� �� ���� ī��Ʈ
	5. total�Լ����� �� ���ݾ� ��� �� �� ��ȯ


	��Ʈ
	�ܶ� ��� �ִ� ���� �ʱ�ȭ�ϱ� -> init �Լ�
	save: main�Լ��� ���� �� ������ �𸣴ϱ� save�� ì��� ��
	500���̳�? -> 500���� 10�� �÷����� �̷���
	*/
	int won, count = 0;
	Money price;
	init(&price); // �ܶ� ��� �ִ� ���� �ʱ�ȭ
	while (1)
	{
		printf("������ �ݾװ� ����: ");
		scanf_s("%d", &won);
		if (won == 0) break;
		scanf_s("%d", &count);
		save(&price, won, count);
	}

	printf("�� ���ݾ�: %d��\n", total(&price));

	return 0;
}

void init(Money* price)
{
	price->w500 = price->w100 = price->w50 = price->w10 = 0;
}


void save(Money* price, int won, int count)
{
	// ����ü ��ü�� �޾Ƽ� ���ݺ��� �������ֱ�?
	// �� ���� ������ ��� �����ֱ�
	if (won == 500) price->w500 += count;
	else if (won == 100) price->w100 += count;
	else if (won == 50) price->w50 += count;
	else if (won == 10) price->w10 += count;
}


int total(Money* price)
{
	return (price->w500 * 500) + (price->w100 * 100) + (price->w50 * 50) + (price->w10 * 10);
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





