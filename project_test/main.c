#include "PcapFile.h"
#include <stdio.h>
#include <stdlib.h>'

int main()
{
	char fname[256 + 1] = "";
	
	printf("�м��� pcap ���ϸ�: ");
	scanf_s("%s", fname, (unsigned int)sizeof(fname));

	FILE* fp = 0;
	fopen_s(&fp, fname, "rb");
	if (fp == 0)
	{
		perror("���� ���� ����"); // ���� �ֱٿ� �߻��� error���� �����ؼ� ���
		system("pause");
		return 0;
	}
	
	PFHeader pfh = { 0, };
	if (ParsePCapFile(fp, &pfh) == 0)
	{
		printf("PCAP ������ �ƴϾ� !");
		fclose(fp);
		system("pause");
		return 0;
	}


	switch (pfh.linktype)
	{
	case LT_ETHER: ParseEther(fp); break;
	default: printf("Not Support \n"); break;
		break;
	}



	fclose(fp);
	system("pause");
	return 0;
}