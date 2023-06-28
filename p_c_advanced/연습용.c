// start
// #include "header.h"
#include <stdio.h>

void rotate(char* en, int* n1, int* n2, int* n3);

int main()
{
	/*
	main�Լ��� ���� 1,2,3�� ���ʴ�� ����Ѵ�.
	���Ͱ� �Է½� roate�Լ��� ȣ���ϰ� �� ����� �޾Ƽ� ���
	��, ���� �̿��� ���� ������ ���α׷��� ���� !
	rotate�Լ��� �Ʒ��� ���� 1:2:3�� ���ʴ�� �����ִ� �Լ��̴�.
	*/
	int num1 = 1, num2 = 2, num3 = 3;
	char enter = '\n';
	
	printf("%d:%d:%d\n", num1, num2, num3);

	while (enter == '\n')
	{
		scanf_s("%c", &enter, (unsigned int)sizeof(enter));
		rotate(&enter, &num1, &num2, &num3);
		printf("%d:%d:%d", num1, num2, num3);
	}

	return 0;
}

void rotate(char* en, int* n1, int* n2, int* n3)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = *n3;
	*n3 = temp;
}


