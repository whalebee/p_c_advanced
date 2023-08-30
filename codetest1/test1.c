#include <stdio.h>

int solution(int v1, int v2, int budget);

int main() {

    int budget, v1, v2;

    printf("현재 당신이 소유하고 있는 금액 : ");
    while (scanf_s("%d", &budget)) {
        if (1 <= budget && budget <= 1000000) break;
        printf("budget은 1이상 1,000,000이하의 자연수이어야합니다. \n");
    }

    printf("첫번째 물품의 가격 : ");
    while (scanf_s("%d", &v1)) {
        if (1 <= v1 && v1 <= 10000) break;
        printf("a는 1이상 10,000이하의 자연수이어야합니다. \n");
    }

    printf("두번째 물품의 가격 : ");
    while (scanf_s("%d", &v2)) {
        if (1 <= v2 && v2 <= 10000) break;
        printf("b는 1이상 10,000이하의 자연수이어야합니다. \n");
    }

    printf("가지수 : %d \n", solution(v1, v2, budget));

    return 0;
}

int solution(int v1, int v2, int budget) {
    int x, y, cnt = 0;

    for (x = 1; x <= budget / v1; x++) {
        for (y = 1; y <= budget / v2; y++) {
            if (budget == (x * v1) + (y * v2))
                cnt++;
        }
    }
    return cnt;
}
