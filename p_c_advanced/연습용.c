// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*
	이 상태에서 파일의 이미지를 복사 붙여넣기 해보시오 !
	*/
	// 선언
	FILE* src, * des;
	errno_t src_err, des_err;
	src_err = fopen_s(&src, "C:\\cTest\\src.jpg", "rb");
	des_err = fopen_s(&des, "C:\\cTest\\des.jpg", "wb");

	// 예외
	if (src_err != 0 || des_err != 0)
	{
		puts("파일 오픈 실패!!");
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
		puts("파일 복사 실패");
		return -1;
	}
	puts("파일 복사 완료");


	fclose(src);
	fclose(des);

	return 0;
}