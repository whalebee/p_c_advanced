#include <stdio.h>
#define SIZE 20

int main()
{
    FILE* src = NULL;
    FILE* des = NULL;

    errno_t src_err;
    errno_t des_err;

    src_err = fopen_s(&src, "C:\\cTest\\small_leo.jpg", "rb");
    des_err = fopen_s(&des, "C:\\cTest\\des.gif", "wb");


    double buf[SIZE];
    size_t size;

    if (src_err != 0 || des_err != 0)
    {
        puts("file open failed");
        return -1;
    }

    while ((size = fread((void*)buf, sizeof(double), SIZE, src)) > 0)
    {
        printf("가져온 거 : %3zd\n", size);
        printf("쓰는 거 : %3zd\n", fwrite((void*)buf, sizeof(double), size, des));
    }



    if (feof(src) != 0)   puts("file copy successfil");
    else            puts("file copy failed");

    fclose(src);
    fclose(des);

    return 0;
}