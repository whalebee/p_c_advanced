#include <stdio.h>

int solution(int v1, int v2, int budget);

int main() {

    int budget, v1, v2;

    printf("���� ����� �����ϰ� �ִ� �ݾ� : ");
    while (scanf_s("%d", &budget)) {
        if (1 <= budget && budget <= 1000000) break;
        printf("budget�� 1�̻� 1,000,000������ �ڿ����̾���մϴ�. \n");
    }

    printf("ù��° ��ǰ�� ���� : ");
    while (scanf_s("%d", &v1)) {
        if (1 <= v1 && v1 <= 10000) break;
        printf("a�� 1�̻� 10,000������ �ڿ����̾���մϴ�. \n");
    }

    printf("�ι�° ��ǰ�� ���� : ");
    while (scanf_s("%d", &v2)) {
        if (1 <= v2 && v2 <= 10000) break;
        printf("b�� 1�̻� 10,000������ �ڿ����̾���մϴ�. \n");
    }

    printf("������ : %d \n", solution(v1, v2, budget));

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
