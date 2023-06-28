// start
// #include "header.h"
#include <stdio.h>

void line_up(double* max, double* mid, double* min);
void swap(double* n1, double* n2);

int main()
{
	/*
	main�Լ����� �Ǽ� ���� �� �� �Է� �޾Ƽ� line_up�Լ��� ȣ�� �ϰ� �� ��,
	���ĵ� ���� ��� ( �ִ밪, �߰���, �ּҰ�)

	line_up �Լ������� swap�Լ��� ȣ���ؼ� �� ������ ���� ũ�� ���� �����ϵ��� ����

	swap �Լ��� �� �Ǽ��� �ٲٴ� �Լ��� ����

	����� ���ο���
	��)
	�Ǽ��� �� �� �Է� : 4.7 11.2 -8.1
	���ĵ� �� ��� : 11.2 4.7 -8.1
	*/
	/*
	���� 5
	���� 3
	����3
	*/

	// ����
	double max = 0, mid = 0, min = 0;

	// �Է�
	printf("�Ǽ� �� �� �� �Է� : ");
	scanf_s("%lf %lf %lf", &max, &mid, &min);

	// line_up ���ĵ� ���� ����ϴ� �Լ�
	line_up(&max, &mid, &min);

	// Ȯ��
	printf("���ĵ� �� ��� : %.1lf %.1lf %.1lf", max, mid, min);
	return 0;
}

// �ּҰ��� �Ű������� ����
// �� 3��, �Ǵ��� line_up����
// swap �Լ� ȣ�� ( �Ű������� 2���� �־���Ѵٸ� �񱳸� �� �ؾ��� �� )
// printf("���� �ٲ���� ? %lf %lf %lf", *max, *mid, *min);
void line_up(double* max, double* mid, double* min)
{
	/*if (*max < *mid)		swap(max, mid);
	if (*mid < *min)		swap(mid, min);
	if (*max < *mid)		swap(max, mid);*/

	// ����
	if (*max < *mid)	swap(max, mid);
	if (*max < *min)	swap(max, min);
	if (*mid < *min)	swap(mid, min);
}

void swap(double* n1, double* n2)
{
	double temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
// �� �Ǽ��� �ٲٴ� �Լ��� ���� -> �Ű������� 2��
// �� 3��
//  �ּҰ��� �޾ƿ�
// �ּҰ��� ���԰� �� �Ǽ� �ڸ� ���� -> ���������� �ٷ� �ٲ�