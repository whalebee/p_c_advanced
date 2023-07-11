// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*

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

	// 사이즈를 어떻게 하지? 리턴값이 count보다 작게 나오는 값을 조건으로 사용
	// -> 이렇게 하니까 크기가 딱 맞지 않음
	// 1바이트로 해야하나? -> 크기는 맞으나.. 화면 출력에 20이 아닌 1로 가득 참
	// feof를 사용해서 break를 사용하게 되는데 -> 이렇게 하지 않아도 가능함
	
	/*
	피드백
	1. 20씩 읽고 20씩 넣기때문에 마지막 16씩 읽어야했을 때 20씩 넣었음
	이걸 temp의 크기로 바꿔줌 !
	2. 조건문 설정하기가 어려웠는데 fread의 리턴값을 이용해서 조건문을 설정해줌
	3. 뭔가 사이즈와 개수가 패키지와 낱개 개념인 것 같음
	*/

	while ( ( temp = fread((int*)buf, sizeof(char), sizeof(buf), src) ) > sizeof(char) )
		fwrite((int*)buf, sizeof(char), temp, des);

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

