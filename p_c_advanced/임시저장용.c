#include <stdio.h>

#define H (60*60)
#define M 60

int gcd(int v1, int v2);
int isPrime(int n);
void secondToHMS(int sec);
int square_re(int num);

int main()
{
	//	1. 16����
	//	2. 3 5 �Է��ϸ� 3�� ~5�ܱ��� ��� !, ���ϱ�� 9���� �� ���
	//	3. GCD �Լ���
	//	4. ��Ű��, �ݶ�, ����Ƽ
	//	5. ����� �Է��ϸ� 1���� �Է��� ��������� �Ҽ��� ���
	//	6. �� �Է��ϸ� h m s �Է�
	//	7. �Է��� ���� 2�� k�¼�(���� �۰ų� ����)
	//	8. 7���� ����Լ���



	//	1. 16���� -ch
	/*int num;
	printf("input: ");
	scanf_s("%d", &num);

	printf("%x", &num);
	// o�� 8����, x�� 16����
	*/


	// 2. 3 5 �Է��ϸ� 3�� ~ 5�ܱ��� ��� ! , ���ϱ�� 9���� �� ���
	/*int v1, v2, i, j;
	printf("2. input: ");
	scanf_s("%d %d", &v1, &v2);

	i = v1 < v2 ? v1 : v2;
	for (; i < 10; i++)
	{
		if (i > v1 && i > v2) break;
		for (j = 1; j < 10; j++)
		{
			printf("%d x %d = %d \n", i, j, i * j);
		}
		puts("");
	}*/
	int v1, v2, i, j;
	scanf_s("%d %d", &v1, &v2);
	i = v1 < v2 ? v1 : v2;
	for (; i < 10; i++) // �������̴ϱ� ���� !!
	{
		if (i > v1 && i > v2) break; // ������ �� �����ؾ���. ����!! break �ؾߵ�?
		for (j = 1; j < 10; j++)
			printf("%d x %d = %d \n", i, j, i * j);
		printf("\n");
	}



	// 3. GCD �Լ���
	/*int v1, v2;
	printf("3. input: ");
	scanf_s("%d %d", &v1, &v2);

	printf("gcd: %d\n", gcd(v1, v2));*/


	//	4. ��Ű��, �ݶ�, ����Ƽ ( �Լ� �ƴ� )
	int basic, mil = 500, coke = 700, remon = 400;
	int x, y, z;
	printf("4. input: ");
	scanf_s("%d", &basic);

	for (x = 1; x < basic / mil; x++)
		for (y = 1; y < basic / coke; y++)
			for (z = 1; z < basic / remon; z++)
			{
				if (basic == (x * mil) + (y * coke) + (z * remon))
					printf("��Ű�� %d, �ݶ� %d, �����̵� %d \n", x, y, z);
			}


	//	5. ����� �Է��ϸ� 1���� �Է��� ��������� �Ҽ��� ��� (�Լ�)
	int num, i, cnt = 0;
	printf("5. input: ");
	scanf_s("%d", &num);

	for (i = 2; i < num + 1; i++)
	{
		if (isPrime(i))
		{
			printf("%5d ", i);
			cnt++;
		}
		else continue;
		if (cnt % 5 == 0) printf("\n");
	}


	//	6. �� �Է��ϸ� h m s �Է�
	int sec;
	printf("6. input: ");
	scanf_s("%d", &sec);

	secondToHMS(sec);


	//	7. �Է��� ���� 2�� k�¼�(���� �۰ų� ����) ( ���ϱ� �� ������ �� �� �� �� �� )
	int num, i, cnt = 0;
	printf("7. input: ");
	scanf_s("%d", &num);

	// ������ ���� 2��
	for (cnt = 0; num > 1; cnt++)
		num /= 2;
	printf("2�� k�� : %d \n", cnt);

	// ���ϱ� ���� 3��
	// for�� ���ۿ��� i = 2�� �����ϸ� 1024 ���� 11���� ���͹���
	for (i = 1; i < num; cnt++)
		i *= 2;
	printf("2�� k�� : %d \n", cnt);


	//	8. 7���� ����Լ���
	/*int num;
	printf("8. input: ");
	scanf_s("%d", &num);

	printf("%d", square_re(num));*/

	return 0;
}

// 3��
int gcd(int v1, int v2)
{
	int result;
	// ���ǰ� while���̶�� �� !
	result = v1 < v2 ? v1 : v2; // result�� ���� ������
	while (v1 % result != 0 || v2 % result != 0) // or���ǰ� != ��� �� !
		result--;
	return result;
}

// 5��
int isPrime(int n)
{
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0) return 0;
	return 1;
}


// 6��
void secondToHMS(int sec)
{
	int h, m, s;
	h = sec / H;
	m = (sec % H) / M;
	s = sec % M;

	printf("h: %d, m: %d, s: %d \n", h, m, s);
}


int square_re(int num)
{
	if (num == 0) return 1;
	return 2 * square_re(num - 1);
}