// start
// #include "header.h"
#include <stdio.h>
#include<string.h>


int main()
{
	/*

	*/
	char test1[9999] = { 0, };
	FILE* test;
	fopen_s(&test, "test11.pcap", "r");
	if (test == NULL)	printf("ÀÌ·¯Áö¸¶ Á¦¹ß\n");
	else						printf("±»±»\n");

	if (test)
	{
		fread(test1, 9999, 1, test);
		printf("%s\n", test1);
	}
	fclose(test);


	return 0;
}
