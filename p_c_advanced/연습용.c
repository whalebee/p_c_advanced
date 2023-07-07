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
	while(1)
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

