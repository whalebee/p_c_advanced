
#pragma region �������� -> 5���� �й� ����ü ����
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

// ������������ ����
void sort_data(Student* example)
{
	Student temp;
	int i, j;
	for (i = 0; i < LEN - 1; i++)
	{
		for (j = 0; j < LEN - 1; j++)
		{
			if (example[j].avg < example[j + 1].avg) // 0���� ũ��
			{
				temp = example[j];
				example[j] = example[j + 1];
				example[j + 1] = temp;
			}
		}
	}
}
// ���� �մ���
// printf("i�� %f\n", example[j].avg);
// printf("i+1�� %f\n", example[j + 1].avg);



#pragma endregion


#pragma region ù��° �������� ����
// ����, ���, ���� ���
void calc_data(Student* example)
{
	int i;
	for (i = 0; i < LEN; i++)
	{
		example->total = example->kor + example->eng + example->math;
		// printf("����Ȯ��: %d \n", example[i].total);
		example->avg = example->total / SUB_CNT;
		if		(example->avg >= 90)	example->grade = 'A';
		else if (example->avg >= 80)	example->grade = 'B';
		else if (example->avg >= 70)	example->grade = 'C';
		else 							example->grade = 'F';
		example++;
		// printf("���� Ȯ�� : %c \n", example[i].grade);
		// �ǵ��: 90.0 80.0 �̷������� �Ҽ������� ����� ������ ��
		// �ּҰ��� �̿��� ��� ! ( �迭 ���� )
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

		// �� ���
		/*if (max != i)
		{
			temp = example[max];
			example[max] = example[i];
			example[i] = temp;
		}*/

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



#pragma endregion


#pragma region ��������� ����
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* ��������� ����
	"data.txt" ���� �뵵�� ��Ʈ�� ����. fp

	���࿡ ��Ʈ�� ������ �����ϸ� "���� ���� ����"���(puts�� �ϱ�)�ϰ� ���α׷� ����

	data.txt�� A ����. fputc
	data.txt�� B ����. fputc
	data.txt�� C ����. fputc
	*/
	// fopen_s()
	FILE* fp;
	if (fopen_s(&fp, "C:\\cTest\\data.txt", "w") != 0)
	{
		perror("���� ���� ����");
		// puts("���� ���� ����");
		return -1;
	}
	//errno_t err;
	//err = fopen_s(&fp, "C:\\cTest\\data.txt", "w");
	//if (err != 0)
	//{
	//	perror("���� ���� ����");
	//	// puts("���� ���� ����");
	//	return -1;
	//}

	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);

	fclose(fp);

	return 0;
}



#pragma endregion


#pragma region ���� �б� ����
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* ��������� ����
	"data.txt" ���� �뵵�� ��Ʈ�� ����. fp

	���࿡ ��Ʈ�� ������ �����ϸ� "���� ���� ����"���(puts�� �ϱ�)�ϰ� ���α׷� ����

	data.txt�� A ����. fputc
	data.txt�� B ����. fputc
	data.txt�� C ����. fputc
	*/
	// fopen_s()
	int i = 0;

	FILE* fp;
	if (fopen_s(&fp, "C:\\cTest\\data.txt", "rt") != 0)
	{
		perror("���� ���� ����");
		// puts("���� ���� ����");
		return -1;
	}

	for (i = 0; i < 3; i++)
		printf("%c \n", fgetc(fp));
	// printf("%s", fgets( stdin, 4, fp)); -> �ⱳ�θ��� ������ fgetc ��ߵ�

	fclose(fp);

	return 0;
}



#pragma endregion


#pragma region ���� ����� ���� �б� ����
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	simple.txt ���� �뵵�� ��Ʈ�� ����. fp
	���࿡ ��Ʈ�� ������ �����ϸ� puts�� ���� ���� ���� ����ϰ� ���α׷� ����

	simple.txt�� A����
	simple.txt�� B����
	simple.txt�� My name is Ho����
	simple.txt�� Yuor name is No����

	fclose�� ��Ʈ�� �Ҹ�

	////////////////////////////////////////////////////////////////////////////////

	simple.txt �б��о ȭ�鿡 ���
	*/

	FILE* fp;
	if (fopen_s(&fp, "C:\\cTest\\simple.txt", "wt") != 0)
	{
		puts("���� ���� ����");
		return -1;
	}

	fputc('A', fp);
	fputc('B', fp);
	fputs("My name is Ho \n", fp);
	fputs("Your name is No \n", fp);

	fclose(fp);

	////////////////////////////////////////////////////////////////////////////////

	char temp[100];
	if (fopen_s(&fp, "C:\\cTest\\simple.txt", "rt") != 0)
	{
		puts("���� ���� ����");
		return -1;
	}

	// ���� �͵� 4�� -> �д� �͵� 4��

	printf("%c", fgetc(fp));
	printf("%c", fgetc(fp));
	printf("%s", fgets(temp, sizeof(temp), fp)); // �迭�� �̸��� ù��° ����� �ּҰ� !!
	printf("%s", fgets(temp, sizeof(temp), fp));

	// �ݺ��� ����
	/*int i;
	for (i = 0; i < 2; i++)
		printf("%s", fgets(&temp, 100, fp));*/

	fclose(fp);

	return 0;
}




#pragma endregion


#pragma region ���� ����� feof ����
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	src.txt�� �б� ���. ������ �̸� src
	des.txt�� ���� ���. ������ �̸� des

	src�� des�� �� ���� "���� ���� ����" ����ϰ� ���α׷� ����

	src�κ��� �� ���ھ� �о des�� ����(�ݺ��� while���)
	���� ������ �� �Ǿ��ٸ� "���� ���� �Ϸ�"���. puts
	���� ������ �� �� �Ǿ��ٸ� "���� ���� ����"���. puts

	���ҽ� ��ȯ
	*/
	FILE* src, * des;
	// FILE;
	// ��ģ��
	if (fopen_s(&src, "C:\\cTest\\src.txt", "rt") != 0 || fopen_s(&des, "C:\\cTest\\des.txt", "wt") != 0)
	{
		puts("���� ���� ����!!");
		return -1;
	}
	// ������
	/*if (fopen_s(&src, "C:\\cTest\\src.txt", "rt") != 0)
	{
		puts("���� ���� ����");
		return -1;
	}
	if (fopen_s(&des, "C:\\cTest\\des.txt", "wt") != 0)
	{
		puts("���� ���� ����");
		return -1;
	}*/

	// while�� ���� ������ ��
	// feof(src) == 0 �̰� �Ǵ��� ���� ����
	int temp = 0;
	while ((temp = fgetc(src)) != EOF)
		fputc(temp, des);

	if (feof(src) == 0)
	{
		puts("���� ���� ����");
		return -1;
	}
	puts("���� ���� �Ϸ�");

	/* ������
	1. des.txt ���Ͼȿ� src.txt�� ������ NULL���� ������ �� �ϴ�.
	������ ����� ���ִ� NULL�� �������� �ʾҴ� !

	2. ���� ���� ���и� �����ϴ� ����� �𸣰ڴ�.
	feof(src) == 0 ���� �ذẸ�Ҵ�.

	*/

	fclose(src);
	fclose(des);

	return 0;
}






#pragma endregion


#pragma region ���� ����� ������ ����
// start
// #include "header.h"
#include <stdio.h>
int main()
{

	// ����
	FILE* src, * des;
	errno_t src_err;
	errno_t des_err;
	src_err = fopen_s(&src, "C:\\cTest\\src.txt", "rt");
	des_err = fopen_s(&des, "C:\\cTest\\des.txt", "wt");

	// ����
	if (src_err != 0 || des_err != 0)
	{
		puts("���� ���� ����!!");
		return -1;
	}

	// ó��
	int temp = 0;
	while ((temp = fgetc(src)) != EOF)
		fputc(temp, des);

	if (feof(src) == 0)
	{
		puts("���� ���� ����");
		return -1;
	}
	puts("���� ���� �Ϸ�");

	// ����
	fclose(src);
	fclose(des);
	return 0;
}



#pragma endregion


#pragma region ���̳ʸ� ���� �ٿ��ֱ� ����
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*

	*/
	// ����
	FILE* src, * des;

	errno_t src_err, des_err;
	src_err = fopen_s(&src, "C:\\cTest\\src.jpg", "rb");
	des_err = fopen_s(&des, "C:\\cTest\\des.jpg", "wb");
	// ����
	if (src_err != 0 || des_err != 0)
	{
		puts("���� ���� ����!!");
		return -1;
	}

	int buf[5];
	int i;
	int temp;

	// ����� ��� ����? ���ϰ��� count���� �۰� ������ ���� �������� ���
	// -> �̷��� �ϴϱ� ũ�Ⱑ �� ���� ����
	// 1����Ʈ�� �ؾ��ϳ�? -> ũ��� ������.. ȭ�� ��¿� 20�� �ƴ� 1�� ���� ��
	// feof�� ����ؼ� break�� ����ϰ� �Ǵµ� -> �̷��� ���� �ʾƵ� ������

	/*
	�ǵ��
	1. 20�� �а� 20�� �ֱ⶧���� ������ 16�� �о������ �� 20�� �־���
	�̰� temp�� ũ��� �ٲ��� !
	2. ���ǹ� �����ϱⰡ ������µ� fread�� ���ϰ��� �̿��ؼ� ���ǹ��� ��������
	3. ���� ������� ������ ��Ű���� ���� ������ �� ����
	*/
	// fread(����, ��Ű��ũ��, ����, src) -> �̷������� !
	while ((temp = fread((int*)buf, sizeof(char), sizeof(buf), src)) > 0)
		fwrite((int*)buf, sizeof(char), temp, des);

	if (feof(src) == 0)
	{
		puts("���� ���� ����");
		return -1;
	}
	puts("���� ���� �Ϸ�");

	fclose(src);
	fclose(des);

	return 0;
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





