#include <stdio.h>
#include <stdlib.h>

int main() {

	int temp = 0;
	printf("ªÁ¿Ã¡Ó : ");
	scanf_s("%d", &temp);
	int *gold_prices = (int*)malloc(sizeof(int) * temp);


	int i;

	for (i = 0; i < temp; i++) {
		scanf_s("%d", &gold_prices[i]);
	}

	solution(gold_prices);


	free(gold_prices);
	return 0;
}


int solution(int* gold_prices) {

	7 2 5 6 4 4 2 8 


}