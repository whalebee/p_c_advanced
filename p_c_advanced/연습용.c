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

	while ( ( temp = fread((int*)buf, sizeof(char), sizeof(buf), src) ) > sizeof(char) )
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

