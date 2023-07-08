#pragma once

#include <stdio.h>

typedef unsigned int  uint;
typedef unsigned short  ushort;
typedef unsigned char  uchar;


typedef struct
{
	uint magic; // 0xA1B2C1
	ushort major;
	ushort minor;
	uint gmt_to_local;
	uint timestamp;
	uint max_caplen;
	uint linktype;
}PFHeader;


typedef struct
{
	uint captime; // second
	uint caputime; // u second
	uint caplen; // capture len
	uint packlen; // total  packet len
}PackHeader;

#define PF_MAGIC 0xA1B2C3D4
#define LT_ETHER 0x01
void ParseEther(FILE* fp);

int(ParsePCapFile(FILE* fp, PFHeader* pfh));