#include <stdio.h>

void MaxAnㄹdMin(int**, int**, int*, int);

int main() {
    int* maxPtr; //arr[5]중 가장 큰 값의 주소
    int* minPtr; //arr[5]중 가장 작은 값의 주소
    int arr[5];
    int i, len = sizeof(arr) / sizeof(int);

    for (i = 0; i < len; i++) {
        printf("정수 입력 %d:", i + 1);
        scanf_s("%d", &arr[i]);
    }

    /*MaxAndMin(&maxPtr,&minPtr,arr,len);*/

    //MaxAndMin함수와 비교
    maxPtr = minPtr = &arr[0];
    for (i = 1; i < len; i++) {
        if (*maxPtr < arr[i]) maxPtr = &arr[i];
        else minPtr = &arr[i];
    }

    printf("최대: %d, 최소: %d", *maxPtr, *minPtr);

    return 0;
}

