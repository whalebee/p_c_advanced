#include <stdio.h>

int GCD(int v1, int v2);

int main()
{
	// �� ���� ���� �Է¹޾Ƽ� �ִ� ������� ���ϴ� ���α׷� �ۼ�
	// 6�� 9�� �Է��ϸ� 3�� ���;���.
	// 12 : 1 2 3 4 6 12
	// 16 : 1 2 4 8 16
	// ������ �� 0 �̶���� -> ��Ʈ��

	int v1, v2;
	printf("�� ���� ���� �Է� : ");
	scanf_s("%d %d", &v1, &v2);

	printf("gcd : %d \n", GCD(v1, v2));


	return 0;
}

int GCD(int v1, int v2)
{
	// int i, gcd;
	int result;
	// ���� �ؿ� 4��?	 �ϴ� �̾Ƴ�����

	// �ʹ� ����� �̰� �³�
	// �ٸ� ���� result <= v1 > v2 ? v1+1 : v2+1
	result = v1 > v2 ? v1 : v2;
	/*for (; result <= v1 || result <= v2; result--)
		if (v1 % result == 0 && v2 % result == 0) return result;*/
	for (result = 1; result < 1 || result < v2; result++)
		if (v1 % result == 0 && v2 % result == 0) return result;

}