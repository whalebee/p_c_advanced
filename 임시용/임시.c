#include <stdio.h>

int main()
{

    FILE* src;
    FILE* des;

    errno_t error = fopen_s(&src, "C:\\cTest\\src.txt", "rt");
    errno_t error1 = fopen_s(&des, "C:\\cTest\\des.txt", "wt");
    if (error != 0 || error1 != 0) {
        printf("���Ͽ��½���");
        return -1;
    }


    //0�ƴѰ� ����. NULl = �� 0 ����
    int i;
    while ((i = fgetc(src)) != EOF)
        fputc(i, des);


    if (fgetc(src) != 0)
        printf("����");
    else printf("����");


    fclose(src);
    fclose(des);
}