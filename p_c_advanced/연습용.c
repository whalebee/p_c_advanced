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
	FILE* src; 
	FILE* des;
	// ��ģ��
	if (fopen_s(&src, "C:\\cTest\\src.txt", "rt") != 0 || fopen_s(&des, "C:\\cTest\\des.txt", "wt") != 0)
	{
		puts("���� ���� ����");
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
	while (fgetc(src) != EOF)
	{
		printf("%c",fgetc(src));
		fputc(fgetc(src), des);
		// printf("Ȯ�� %c", fgetc(src));
		
	}

	if (feof(src) == 0)
		{
			puts("���� ���� ����");
			return -1;
		}
	puts("���� ���� �Ϸ�");

	/* ������
	1. des.txt ���Ͼȿ� src.txt�� ������ NULL���� ������ �� �ϴ�.

	2. ���� ���� ���и� �����ϴ� ����� �𸣰ڴ�.

	*/

	return 0;
}
