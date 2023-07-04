// start
// #include "header.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

struct person {
	char name[50];
	char phoneNum[50];
	int age;
};

int main()
{
	/* ���� 
	person�� ����ü ����
	- �̸�.name
	- ��ȭ��ȣ.phoneNum
	- ����.age

	main�Լ�����
	- person�� ���� man1, man2 ����
	- �̸��� ����ȣ -> strcpy() ��� -> �Ҽ��� string.h
	- 010-123-4567
	- ���̿� 40

	�̸�, ��ȣ, ���� ���

	(man2)
	����ڷκ��� �̸�, ��ȣ, ���� �Է� �ޱ�
	�̸�, ��ȣ, ���� ���
	*/
	
	// ����
	struct person man1;
	struct person man2;

	// �Է�
	strcpy_s(man1.name, sizeof(man1.name), "����ȣ");
	strcpy_s(man1.phoneNum, sizeof(man1.phoneNum), "010-123-4567");
	man1.age = 40;

	fputs("�̸�? ", stdout);
	scanf_s("%s", man2.name, (unsigned char)sizeof(man2.name));
	fputs("��ȣ? ", stdout);
	scanf_s("%s", man2.phoneNum, (unsigned char)sizeof(man2.phoneNum));
	fputs("����? ", stdout);
	scanf_s("%d", &man2.age);

	
	// ���
	puts(" ");
	printf("�ԷµǾ��ִ� �����\n");
	printf("�̸�: %s\n��ȣ: %s\n����: %d\n", man1.name, man1.phoneNum, man1.age);
	
	puts(" ");
	printf("�Է¹��� ����� \n");
	printf("�̸�: %s\n��ȣ: %s\n����: %d\n", man2.name, man2.phoneNum, man2.age);

	return 0;
}
