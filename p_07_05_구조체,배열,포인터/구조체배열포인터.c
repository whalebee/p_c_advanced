
#pragma region ����ü�� �迭 ������ �⺻ ����
// start
// #include "header.h"
#include <stdio.h>

struct point
{
	int xpos;
	int ypos;
};

int main()
{
	/*
	point ����ü. ���2��

	main()
	- ���̰� 3�� point�� �迭 arr����
	- �� ���� ��ǥ �Է� �ޱ�
	- �� ���� ��ǥ ���
	*/
	struct point arr[3];
	int i, len;
	len = sizeof(arr) / sizeof(struct point);

	// �Է�
	for (i = 0; i < len; i++)
	{
		printf("���� ��ǥ �Է�: ");
		scanf_s("%d %d", &arr[i].xpos, &arr[i].ypos);
	}

	// ���
	for (i = 0; i < len; i++)
		printf("[%d, %d] \n", arr[i].xpos, arr[i].ypos);

	return 0;
}

#pragma endregion


#pragma region �������� -> ��������(����ü �迭)
#include <stdio.h>

struct employee
{
	char name[50];
	char addr_num[15];
	int  salary;
};


int main()
{
	/* ��������
	���̰� 3�� �迭�� �����ϰ�
	�� ���� ������ �Է� �޾Ƽ� �迭�� ������ ����, �迭�� ����� �����͸�
	������� ����ϴ� ������ �ۼ��Ѵ�.
	*/
	struct employee emp[3] = { 0, };
	int i, len;
	len = sizeof(emp) / sizeof(struct employee);

	for (i = 0; i < len; i++)
	{
		fputs("�̸���?: ", stdout);
		scanf_s("%s", emp[i].name, (unsigned int)sizeof(emp[i].name));
		fputs("�ֹε�Ϲ�ȣ��?: ", stdout);
		scanf_s("%s", emp[i].addr_num, (unsigned int)sizeof(emp[i].addr_num));
		fputs("������?: ", stdout);
		scanf_s("%d", &emp[i].salary);
	}

	printf("--- ���� ���� ---\n");
	for (i = 0; i < len; i++)
	{
		printf("�̸�		: %s \n", emp[i].name);
		printf("�ֹε�Ϲ�ȣ: %s \n", emp[i].addr_num);
		printf("����		: %d \n\n", emp[i].salary);
	}

	return 0;
}


#pragma endregion


#pragma region ����ü ������ ����
// start
// #include "header.h"
#include <stdio.h>

struct point
{
	int xPos;
	int yPos;
};

int main()
{
	/*
	point ����ü ����.

	main()
	- point�� ���� pos1. 1,2 �� ������
	- point�� ���� pos2. 100,200 �� ������
	- point�� ������ ���� pptr. pos1�� �ּҷ� ������
	- pptr�� Ȱ���� x��ǥ 4����
	- pptr�� Ȱ���� y��ǥ 4����
	- pptr�� Ȱ���� ��ǥ ���

	- pptr. pos2�� �ּҷ� �ʱ�ȭ
	- pptr�� Ȱ���� x��ǥ 1����
	- pptr�� Ȱ���� y��ǥ 2����
	- pptr�� Ȱ���� ��ǥ ���
	*/
	struct point pos1 = { 1,2 };
	struct point pos2 = { 100,200 };
	struct point* pptr = &pos1;

	// (*pptr).member ����
	(*pptr).xPos += 4;
	(*pptr).yPos += 4;
	printf("[%d,%d] \n", (*pptr).xPos, (*pptr).yPos);

	// pptr->member ����
	pptr = &pos2;
	pptr->xPos += 1;
	pptr->yPos += 2;
	printf("[%d,%d] \n", pptr->xPos, pptr->yPos);

	return 0;
}




#pragma endregion


#pragma region �� Ǯ������ ����ü ������ ���� ( ������ Ǯ���� )
// start
// #include "header.h"
#include <stdio.h>

struct point
{
	int xPos;
	int yPos;
};

struct circle
{
	double radius;
	struct point* center; // ���� �����͸� �ִ� �ſ���..
};

int main()
{
	/*
	point ����ü ����.

	circle ����ü ����.
	- �Ǽ� radius(������)
	- �ڷ��� -> ��� / ������ center ( main �Լ��� ��Ʈ )

	main ( ) 5����
	- ??? cen. 2, 7�� ������ ( ��ǥ )
	- ??? rad. 5.5 ������
	- ??? ring. �������� ���� �߽� ��ǥ�� ������ -> ��������?
	- ���� ������: �� ���
	- ���� �߽� [��, ��] ��� ( ��ǥ )
	*/
	struct point cen = { 2, 7 };
	double rad = 5.5;
	struct circle ring = { rad, &cen };
	// �Ƴ� cen�� �ּҰ��� �ַ��� circle �ȿ� �ִ� center�� ������ ������
	// ������ �߾������ ���Ƥ�����������������������������������������
	printf("���� ������: %.1f \n", ring.radius);
	printf("���� �߽� [%d, %d] \n", ring.center->xPos, (*ring.center).yPos);

	// ����ü �����͸� ����� �� ������
	// struct circle ring = { rad, cen }; 
	/*
	printf("���� ������: %.1f \n", ring.radius);
	printf("���� �߽� [%d, %d] \n", ring.center.xPos, ring.center.yPos);
	*/

	return 0;
}



#pragma endregion


#pragma region �������� -> ����ü�� �迭�� �������� ������
// start
// #include "header.h"
#include <stdio.h>

struct info
{
	char id[50];
	char passwd[30];
	char name[50];
	int age;
};

int main()
{
	/*
	���ͳ� ī�� ȸ�� 1���� ���̵�(smartC), ��й�ȣ(sm8448), ����(20), �̸�(�ż���)
	������ ������ �����԰� ���ÿ� �ʱ�ȭ �� �� ����ϰ��� �Ѵ�.
	ȸ���� ������ ����ü�� ������� �ʰ� ó���ϴ� ���α׷���, -> ?
	����ü�� ����ϴ� ���α׷�,
	�� ���� �ۼ��� �� ����ü�� �迭�� ���� ���� �������� �� ����
	*/
	// ����ü ���
	struct info member = { "smartC", "sm8448", "�ż���", 20 };
	// ���
	printf("���̵�: %s \n��й�ȣ: %s\n�̸�: %s\n����: %d\n\n", member.id, member.passwd, member.name, member.age);


	// ����ü �̻�� ->
	char* memberArr[4] = { "smartA", "sm1234", "MZ", "15" };

	//���
	printf("���̵�: %s \n��й�ȣ: %s\n�̸�: %s\n����: %s\n\n", memberArr[0], memberArr[1], memberArr[2], memberArr[3]);

	/*
	������
	�迭�� ����Ͽ� ���� �����ϰ� ����� �� �ִ�.

	������
	�迭�� ����ü�� �ٸ��� ���� �ڷ����鳢���� ������ �� �ְ�,
	����ü�� ���� �ٸ� �ڷ������ε� ������ �� �ִ�.

	printf�� �� [] .id �� ǥ���� �ٸ�

	�迭�� ���뿡 ������� ������,
	����ü�� �迭�� ����ϸ鼭 �� �迭�� ��𼭵��� �ٽ� ����� �� �ְ�
	�ڷ������� �迭�̳� �������� �����Ͽ� �ٽ� ����� �� �ִ�.
	*/


	return 0;
}



#pragma endregion


#pragma region �������� -> Ʋ�� �� ã��
// start
// #include "header.h"
#include <stdio.h>

struct rectangle {
	// ����ü �ȿ��� ����� ���ÿ� �ʱ�ȭ�� �Ϸ�����
	int width, height, area;
};
// } �̷��Ը� ���������� �� ������ ���ǰ� ������ �ʾ���	  ; �� �������� !

int main() // ��������
{
	// rectangle r1 = { 3,7 }, r2 = { 2,5 }; // �ڷ�����ü�� Ʋ����, struct ���Ծ��⶧��
	struct rectangle r1 = { 3,7 }, r2 = { 2,5 };
	// int larger; 
	//	��Ƴ����ϴ� �ڷ����� �ٸ�, r1�̳� r2�� ��Ƴ����ϴµ� 
	//	4����Ʈ�� 12����Ʈ�� ������ ��Ƴ����߱⶧�� !
	struct rectangle larger;
	r1.area = r1.width * r1.height;
	r2.area = r2.width * r2.height;

	// if ( r1 > r2 ) // ����ü�� ��� �� ������ ���ؾ��ϹǷ� ����ü.area �� ���ؾ���
	if (r1.area > r2.area)
		larger = r1;
	else
		larger = r2;
	printf("�� ū �簢���� ������ %d�Դϴ�.", larger.area);


	return 0;
}




#pragma endregion


#pragma region �������� -> �� �б� ����(GPA)
#include <stdio.h>
#include <string.h>

// double score(char grade[2]); // ������ ����
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
// double score(char grade[2]); // ������ ����
double score(char* grade)
{
	/*printf("grade �� : %s\n", grade);
	printf("A+�� ������? :%d", strcmp(grade, "A+"));*/
	if (!strcmp(grade, "A+"))	return 4.5;
	else if (!strcmp(grade, "A0"))	return 4.0;
	else if (!strcmp(grade, "B+"))	return 3.5;
	else if (!strcmp(grade, "B0"))	return 3.0;
	else if (!strcmp(grade, "C+"))	return 2.5;
	else if (!strcmp(grade, "C0"))	return 2.0;
	else if (!strcmp(grade, "D+"))	return 1.5;
	else if (!strcmp(grade, "D0"))	return 1.0;
	else							return 0;
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





