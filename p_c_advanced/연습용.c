// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	src.txt를 읽기 모드. 지시자 이름 src
	des.txt를 쓰기 모드. 지시자 이름 des

	src든 des든 못 열면 "파일 오픈 실패" 출력하고 프로그램 종료

	src로부터 한 글자씩 읽어서 des에 저장(반복문 while사용)
	파일 끝까지 잘 되었다면 "파일 복사 완료"출력. puts
	파일 끝까지 잘 안 되었다면 "파일 복사 실패"출력. puts

	리소스 반환

	*/
	FILE* src; 
	FILE* des;
	// 합친거
	if (fopen_s(&src, "C:\\cTest\\src.txt", "rt") != 0 || fopen_s(&des, "C:\\cTest\\des.txt", "wt") != 0)
	{
		puts("파일 오픈 실패");
		return -1;
	}
	// 나눈거
	/*if (fopen_s(&src, "C:\\cTest\\src.txt", "rt") != 0)
	{
		puts("파일 오픈 실패");
		return -1;
	}
	if (fopen_s(&des, "C:\\cTest\\des.txt", "wt") != 0)
	{
		puts("파일 오픈 실패");
		return -1;
	}*/

	// while은 그저 복사할 뿐
	// feof(src) == 0 이건 판단할 때만 쓰기
	while (fgetc(src) != EOF)
	{
		printf("%c",fgetc(src));
		fputc(fgetc(src), des);
		// printf("확인 %c", fgetc(src));
		
	}

	if (feof(src) == 0)
		{
			puts("파일 복사 실패");
			return -1;
		}
	puts("파일 복사 완료");

	/* 문제점
	1. des.txt 파일안에 src.txt의 마지막 NULL값도 가져온 듯 하다.

	2. 파일 복사 실패를 구분하는 방법을 모르겠다.

	*/

	return 0;
}
