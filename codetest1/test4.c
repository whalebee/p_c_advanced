#include <stdio.h>

int solution(int n);

int main() {

	int N = 4;
	printf("%d \n", solution(N+1) );

	return 0;
}

int solution(int n) {
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;

	return solution(n - 1) + solution(n - 2);
}