#include <stdio.h>

int main()
{

    FILE* src;
    FILE* des;

    errno_t error = fopen_s(&src, "C:\\cTest\\src.txt", "rt");
    errno_t error1 = fopen_s(&des, "C:\\cTest\\des.txt", "wt");
    if (error != 0 || error1 != 0) {
        printf("파일오픈실패");
        return -1;
    }


    //0아닌값 성공. NULl = 끝 0 오류
    int i;
    while ((i = fgetc(src)) != EOF)
        fputc(i, des);


    if (fgetc(src) != 0)
        printf("성공");
    else printf("실패");


    fclose(src);
    fclose(des);
}