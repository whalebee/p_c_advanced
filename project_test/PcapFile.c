#include "PcapFile.h"

char buffer[0x1000000];
void ViewPCapFile(PFHeader* pfh);
void ViewPacketHeaderInfo(PackHeader* ph, int pno);

void ParseEther(FILE* fp)
{
	PackHeader ph = { 0 };
	int pno = 0;
	while (fread(&ph, sizeof(PackHeader), 1, fp) == 1)
	{
		pno++;
		ViewPacketHeaderInfo(&ph, pno);
		fread(buffer, sizeof(uchar), ph.caplen, fp);
	}
}

int ParsePCapFile(FILE* fp, PFHeader* pfh)
{
	fread(pfh, sizeof(PFHeader), 1, fp);
	if (pfh->magic != PF_MAGIC)
	{
		return 0;
	}
	ViewPCapFile(pfh);
	return 1;
}


void ViewPCapFile(PFHeader* pfh)
{
	printf("============ PCAP File ��� ����============ \n");
	printf("\t ����: %d.%d\n", pfh->major, pfh->minor);
	printf("\t �ִ�ĸ�� ����:%d bytes\n", pfh->max_caplen);
}

void ViewPacketHeaderInfo(PackHeader* ph, int pno)
{
	printf("!!! <%4d th> ������ !!!\n", pno);
	printf("��Ŷ: %6d bytes ĸ��: %6d\n", ph->packlen, ph->caplen);

}