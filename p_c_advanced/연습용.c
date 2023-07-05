// start
// #include "header.h"
#include <stdio.h>
#include <string.h>

double score(char* grade);

struct student
{
	char object[10];	// ���¸�
	int grade;			// ����
	char level[5];		// ���
	
};



int main()
{
	/*
	������ ���� �л��� �� �б� 5������ �������κ��� �� �б� ���� (GPA)�� ����Ͽ� ���
	�� ���¸��� ���¸�, ����, ��� ������ ����ü�� ����
	�ټ� ������ ������ ����ü �迭�� �����ϸ鼭 �ʱ�ȭ
	����� �����ϸ� ��޿� �ش��ϴ� ������ ��ȯ�ϴ� score �Լ��� �����Ͽ� ���
	��޿� ���� ������ �Ʒ� ǥ�� ���� !
	������ 2 * A0�� ���� �� -> 2 * 4.0 �̷�������
	2 * 4 + 3 * 3.5 + 2* 4 + ...
	�ϰ� ( ���� 2+3+2+2+3 ) ���� ������ ��

	A0�� 4.0���� �ٲ��ִ� �Լ��� score
	score�Լ� �ȿ��� strcmp ���
	*/
	int i, grade_sum = 0;
	double grade_score = 0;
	struct student example[5] = {
		{"�۾���",	2,	"A0"},
		{"����",	3,	"B+"},
		{"ü��",	2,	"A0"},
		{"ȸȭ",	2,	"B0"},
		{"C���",	3,	"A+"}
	};
	printf("-------------------------- \n");
	printf("%-10s %-8s %-10s \n", "���¸�", "����", "���");
	printf("-------------------------- \n");
	for (i = 0; i < sizeof(example) / sizeof(struct student); i++) // �׽�Ʈ�� ���ؼ� ���
	{
		printf("%-12s %-8d %-10s \n", example[i].object, example[i].grade, example[i].level);
		grade_sum += example[i].grade;
		grade_score += example[i].grade * score(example[i].level);
		// printf("%d��° score : %f \n", i+1, score(example[i].level));
	}
	printf("-------------------------- \n");
	/*printf("2*4 �� ��� ��ģ �� %f\n", grade_score);
	printf("2+3+2 �� ���� ��ģ �� %d\n", grade_sum);*/
	printf("%14s : %.1f\n", "����", (double)grade_score / grade_sum);
	
	return 0;
}

// ���(A0 ���� ����)�� �ָ� �ش��ϴ� ������ ��ȯ
double score(char* grade)
{
	/*printf("grade �� : %s\n", grade);
	printf("A+�� ������? :%d", strcmp(grade, "A+"));*/
	if		(!strcmp(grade, "A+"))	return 4.5;
	else if (!strcmp(grade, "A0"))	return 4.0;
	else if (!strcmp(grade, "B+"))	return 3.5;
	else if (!strcmp(grade, "B0"))	return 3.0;
	else if (!strcmp(grade, "C+"))	return 2.5;
	else if (!strcmp(grade, "C0"))	return 2.0;
	else if (!strcmp(grade, "D+"))	return 1.5;
	else if (!strcmp(grade, "D0"))	return 1.0;
	else							return 0;
}
