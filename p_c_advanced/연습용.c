// start
// #include "header.h"
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
	���ڿ� ������ ������ �̸��� �ֹε�Ϲ�ȣ
	�׸��� ���� ������ �޿������� ������ �� �ִ� employee��� �̸��� ����ü ����

	����ü ������ �ϳ� ������ ���� ����� �Է¹޾Ƽ� ������ ä���,
	����ü ������ ä���� �����͸� ����Ѵ�.
	*/
	struct employee salary_info;

	fputs("�̸���?: ", stdout);
	scanf_s("%s", salary_info.name, (unsigned int)sizeof(salary_info.name));
	fputs("�ֹε�Ϲ�ȣ��?: ", stdout);
	scanf_s("%s", salary_info.addr_num, (unsigned int)sizeof(salary_info.addr_num));
	fputs("������?: ", stdout);
	scanf_s("%d", &salary_info.salary);


	printf("--- ���� ����--- \n\n�̸�: %s \n�ֹε�Ϲ�ȣ: %s \n������?: %d", salary_info.name, salary_info.addr_num, salary_info.salary);

	return 0;
}
