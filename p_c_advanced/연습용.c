#include <stdio.h>



int main()
{
	int num1 = 0, num2 = 0, i, j;

	printf("input 2 numbers: ");
	scanf_s("%d %d", &num1, &num2);

	// ���� test1
	// �Լ� �ƴ� ��
	// 1. 3,5 �� �� ( �ϴ� 5,3 �����ϰ� Ʋ �������� )
	// 2. ���� 5,3 �� ��쵵 �־���� -> swap����� ����? �ֳ��� ����
	// swap ������
	for (i = (num1 < num2 ? num1 : num2); i < num1+1 || i < num2+1; i++)
	{
		if (i > (num1 > num2 ? num1 : num2)) break;
		for (j = 1; j < 10; j++) printf("%d x %d = %d \n", i, j, i * j);
		printf("\n");
	}


	return 0;
}


