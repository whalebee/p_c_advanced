// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	�� ���¿��� ������ �̹����� ���� �ٿ��ֱ� �غ��ÿ� !
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

	while ( ( temp = fread((char*)buf, sizeof(char), sizeof(buf), src) ) != '\0' )
	{
		fwrite((char*)buf, sizeof(char), temp, des);
	}
		

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