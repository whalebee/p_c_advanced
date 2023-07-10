// start
// #include "header.h"
#include <stdio.h>

#define LEN 5
#define SUB_CNT 3.0

typedef struct
{
	char name[30];
	int stuNum;
	int kor;
	int eng;
	int math;
	int total;
	double avg;
	char grade;
}Student;

void input_data(Student* example);
void calc_data(Student* example);
void printf_data(Student* example);
void sort_data(Student* example);


int main()
{
	// �迭�� SIZE�� define���� ����
	// ���̴� �Ű������� �� ��
	/*
	5���� �й�, �̸�, ����,����, ���� ������ �Է¹޾� ���� �� ������ ��� �Ŀ�
	���� �� ������ �̷��� 2���� �����͸� ���

	�й�, �̸�, ���� ����, ����, ���, ���� ����ü ����

	main�Լ����� input_data, calc_data ȣ���ϰ� ���� printf_data��
	sort_data �Լ� ����� �� ���������� printf_data �Լ� ȣ�� ( �񱳸� ���� )

	input_data �Լ��� 5���� ����(�й�, �̸�, ����)�� �Է�
	calc_data �Լ��� 5���� ���� ����, ���, ���� ���
	(90�̻� A, 80�̻� B, 70�̻� C, �� F)

	sort_data �Լ��� ��� ������ ����
	printf_data �Լ��� 5���� ���� ���
	*/
	Student example[5] = { 0, };

	input_data(&example);
	calc_data(&example);
	printf("#���� �� ������... \n");
	printf_data(&example);
	sort_data(&example);
	printf("#���� �� ������... \n");
	printf_data(&example);

	return 0;
}

void input_data(Student* example)
{
	int i;
	for (i = 0; i < LEN; i++)
	{
		printf("�й� : "); scanf_s("%d", &example[i].stuNum);
		printf("�̸� : "); scanf_s("%s", example[i].name, (unsigned char)sizeof(example->name));
		printf("����, ����, ���� ���� : "); scanf_s("%d %d %d", &example[i].kor, &example[i].eng, &example[i].math);
	}
}

// ����, ���, ���� ���
void calc_data(Student* example)
{
	int i;
	for (i = 0; i < LEN; i++)
	{
		example[i].total = example[i].kor + example[i].eng + example[i].math;
		// printf("����Ȯ��: %d \n", example[i].total);
		example[i].avg = example[i].total / SUB_CNT;
		if (example[i].avg >= 90)	example[i].grade = 'A';
		else if (example[i].avg >= 80)	example[i].grade = 'B';
		else if (example[i].avg >= 70)	example[i].grade = 'C';
		else 							example[i].grade = 'F';
		// printf("���� Ȯ�� : %c \n", example[i].grade); 
	}
}

void printf_data(Student* example)
{
	int i;
	for (i = 0; i < LEN; i++)
		printf("%10d %10s %5d %5d %5d %5d %.1f %5c \n", example[i].stuNum, example[i].name, example[i].kor, example[i].eng, example[i].math, example[i].total, example[i].avg, example[i].grade);
}

// ���������̿�
void sort_data(Student* example)
{
	Student temp;
	int i, j, max = 0;
	for (i = 0; i < LEN; i++)
	{
		// �ؾ��� ���� �� �ؾ��� ���� ������?
		max = i;
		for (j = i; j < LEN; j++)
			if (example[max].avg < example[j].avg) max = j;


		temp = example[max];
		example[max] = example[i];
		example[i] = temp;

		
		/*
		3 5 1 4
		1�̶�� �ε��� ���� ���� ũ�ٴ� ���� ã��
		�װ� �������� �־����

		�� ó���� �ٲ�¡
		ù��°�� max�ε����� ����Ͽ� ������ ���־��� ������
		ó������ ���ϴ� j�� ������ ���� ū ù��° ���� max�� �־��� �� �ۿ� �����ϱ�.

		*/

	}
}
// ���� �մ���
// printf("i�� %f\n", example[j].avg);
// printf("i+1�� %f\n", example[j + 1].avg);

// ������ ���������� �� �� �� �ϴ� ���̰�,
// �ݺ��� �ȿ����� ���� ū ���� �ε����� ã�´�