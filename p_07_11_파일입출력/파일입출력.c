
#pragma region ���� ����� ���� ���ڿ� ����
// start
// #include "header.h"
#include <stdio.h>
int main()
{

	// ����
	FILE* src, * des;
	errno_t src_err;
	errno_t des_err;
	src_err = fopen_s(&src, "C:\\cTest\\src.txt", "rt");
	des_err = fopen_s(&des, "C:\\cTest\\des.txt", "wt");

	// ����
	if (src_err != 0 || des_err != 0)
	{
		puts("���� ���� ����!!");
		return -1;
	}

	// ó�� ( ���ڿ� ���� )
	char temp[5];
	while (fgets(temp, sizeof(temp), src) != NULL)
		fputs(temp, des);

	if (feof(src) == 0)
	{
		puts("���� ���� ����");
		return -1;
	}
	puts("���� ���� �Ϸ�");

	// ����
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





