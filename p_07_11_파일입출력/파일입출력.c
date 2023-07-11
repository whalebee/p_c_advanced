
#pragma region 파일 입출력 예제 문자열 버전
// start
// #include "header.h"
#include <stdio.h>
int main()
{

	// 선언
	FILE* src, * des;
	errno_t src_err;
	errno_t des_err;
	src_err = fopen_s(&src, "C:\\cTest\\src.txt", "rt");
	des_err = fopen_s(&des, "C:\\cTest\\des.txt", "wt");

	// 예외
	if (src_err != 0 || des_err != 0)
	{
		puts("파일 오픈 실패!!");
		return -1;
	}

	// 처리 ( 문자열 단위 )
	char temp[5];
	while (fgets(temp, sizeof(temp), src) != NULL)
		fputs(temp, des);

	if (feof(src) == 0)
	{
		puts("파일 복사 실패");
		return -1;
	}
	puts("파일 복사 완료");

	// 해제
	fclose(src);
	fclose(des);
	return 0;
}



#pragma endregion


#pragma region 



#pragma endregion


#pragma region 



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion




#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion





