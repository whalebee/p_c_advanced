#include <stdio.h>
#include <string.h>

int solution(char* moves);

int main() {

	
	char moves[500] = {0};
	int i = 0;
	printf("다음 움직은 어디로?");
	while (1) {
		scanf_s(" %c", &moves[i], (unsigned int)sizeof(char));
		fflush(stdin);
		if ( !strncmp(&moves[i++], "S", 1) ) break;
	}

	printf("제발.. : %d \n", solution(moves));



	return 0;
}



int solution(char *moves) {
	int i = 0, cnt = 0, ck = 0;
	int temp = 3;

	while (moves[temp] != NULL) {
		// printf("gogo %d \n", i);
		if( !strncmp(&moves[i], "L",1)) {
			if ( !strncmp(&moves[i - 1], "D",1)) {
				if ( !strncmp(&moves[i - 2], "R",1))
					if ( !strncmp(&moves[i - 3], "U",1) )
						cnt++;
			}
			else if (!strncmp(&moves[i - 1], "U", 1)) {
				if (!strncmp(&moves[i - 2], "R", 1))
					if (!strncmp(&moves[i - 3], "D", 1))
						cnt++;
			}
		}

		else if (!strncmp(&moves[i], "D", 1)) {
						if (!strncmp(&moves[i - 1], "R", 1)) {
							if (!strncmp(&moves[i - 2], "U", 1))
								if (!strncmp(&moves[i - 3], "L", 1))
									cnt++;
						}
						else if (!strncmp(&moves[i - 1], "L", 1)) {
							if (!strncmp(&moves[i - 2], "U", 1))
								if (!strncmp(&moves[i - 3], "R", 1))
									cnt++;
						}
		}

		else if (!strncmp(&moves[i], "R", 1)) {
						if (!strncmp(&moves[i - 1], "U", 1)) {
							if (!strncmp(&moves[i - 2], "L", 1))
								if (!strncmp(&moves[i - 3], "D", 1))
									cnt++;
						}
						else if (!strncmp(&moves[i - 1], "D", 1)) {
							if (!strncmp(&moves[i - 2], "L", 1))
								if (!strncmp(&moves[i - 3], "U", 1))
									cnt++;
						}
		}

		else if (!strncmp(&moves[i], "U", 1)) {
				if (!strncmp(&moves[i - 1], "L", 1)) {
					if (!strncmp(&moves[i - 2], "D", 1))
						if (!strncmp(&moves[i - 3], "R", 1))
							cnt++;
				}
				else if (!strncmp(&moves[i - 1], "R", 1)) {
					if (!strncmp(&moves[i - 2], "D", 1))
						if (!strncmp(&moves[i - 3], "L", 1))
							cnt++;
				}

			}
		i++;
		if ( moves[i] == NULL ) break;
	}
	return cnt;
}



// 	while( moves[3] != NULL ) {
		// printf("1 : %c \n", moves[i]);
// i++;
// 	}
//switch (moves[i])
//{
//case 'U':
//	if (moves[i + 1] != NULL && !strcmp(moves[i + 1], 'R'))
//		if (moves[i + 2] != NULL && !strcmp(moves[i + 2], 'D'))
//			if (moves[i + 3] != NULL && !strcmp(moves[i + 3], 'L'))
//				cnt++;
//
//	/*case 'R':
//		if (!strcmp(moves[i + 1], 'D'))
//			if (!strcmp(moves[i + 2], 'L'))
//				if (!strcmp(moves[i + 3], 'U'))
//					cnt++;
//
//	case 'D':
//		if (!strcmp(moves[i + 1], 'L'))
//			if (!strcmp(moves[i + 2], 'U'))
//				if (!strcmp(moves[i + 3], 'R'))
//					cnt++;
//
//	case 'L':
//		if (!strcmp(moves[i + 1], 'U'))
//			if (!strcmp(moves[i + 2], 'R'))
//				if (!strcmp(moves[i + 3], 'D'))
//					cnt++;*/
//}