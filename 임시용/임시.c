#include <stdio.h>

void MaxAn��dMin(int**, int**, int*, int);

int main() {
    int* maxPtr; //arr[5]�� ���� ū ���� �ּ�
    int* minPtr; //arr[5]�� ���� ���� ���� �ּ�
    int arr[5];
    int i, len = sizeof(arr) / sizeof(int);

    for (i = 0; i < len; i++) {
        printf("���� �Է� %d:", i + 1);
        scanf_s("%d", &arr[i]);
    }

    /*MaxAndMin(&maxPtr,&minPtr,arr,len);*/

    //MaxAndMin�Լ��� ��
    maxPtr = minPtr = &arr[0];
    for (i = 1; i < len; i++) {
        if (*maxPtr < arr[i]) maxPtr = &arr[i];
        else minPtr = &arr[i];
    }

    printf("�ִ�: %d, �ּ�: %d", *maxPtr, *minPtr);

    return 0;
}

