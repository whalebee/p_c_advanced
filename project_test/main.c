#include "PcapFile.h"
#include <stdio.h>
#include <stdlib.h>'

int main()
{
	char fname[256 + 1] = "";
	
	printf("분석할 pcap 파일명: ");
	scanf_s("%s", fname, (unsigned int)sizeof(fname));

	FILE* fp = 0;
	fopen_s(&fp, fname, "rb");
	if (fp == 0)
	{
		perror("파일 열기 실패"); // 가장 최근에 발생한 error정보 포함해서 출력
		system("pause");
		return 0;
	}
	
	PFHeader pfh = { 0, };
	if (ParsePCapFile(fp, &pfh) == 0)
	{
		printf("PCAP 파일이 아니야 !");
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