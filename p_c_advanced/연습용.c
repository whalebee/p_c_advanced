// start
// #include "header.h"
#include <stdio.h>
#include <string.h>

double score(char* grade);

struct student
{
	char object[10];	// 강좌명
	int grade;			// 학점
	char level[5];		// 등급
	
};



int main()
{
	/*
	다음과 같이 학생의 한 학기 5강좌의 성적으로부터 한 학기 평점 (GPA)을 계산하여 출력
	각 강좌마다 강좌명, 학점, 등급 정보를 구조체에 저장
	다섯 강좌의 정보는 구조체 배열을 선언하면서 초기화
	등급을 전달하면 등급에 해당하는 점수를 반환하는 score 함수를 정의하여 사용
	등급에 따른 점수는 아래 표와 같음 !
	평점은 2 * A0를 했을 때 -> 2 * 4.0 이런식으로
	2 * 4 + 3 * 3.5 + 2* 4 + ...
	하고 ( 학점 2+3+2+2+3 ) 으로 나누면 됨

	A0를 4.0으로 바꿔주는 함수가 score
	score함수 안에서 strcmp 사용
	*/
	int i, grade_sum = 0;
	double grade_score = 0;
	struct student example[5] = {
		{"글쓰기",	2,	"A0"},
		{"수학",	3,	"B+"},
		{"체육",	2,	"A0"},
		{"회화",	2,	"B0"},
		{"C언어",	3,	"A+"}
	};
	printf("-------------------------- \n");
	printf("%-10s %-8s %-10s \n", "강좌명", "학점", "등급");
	printf("-------------------------- \n");
	for (i = 0; i < sizeof(example) / sizeof(struct student); i++) // 테스트를 위해서 상수
	{
		printf("%-12s %-8d %-10s \n", example[i].object, example[i].grade, example[i].level);
		grade_sum += example[i].grade;
		grade_score += example[i].grade * score(example[i].level);
		// printf("%d번째 score : %f \n", i+1, score(example[i].level));
	}
	printf("-------------------------- \n");
	/*printf("2*4 등 등급 합친 값 %f\n", grade_score);
	printf("2+3+2 등 학점 합친 값 %d\n", grade_sum);*/
	printf("%14s : %.1f\n", "평점", (double)grade_score / grade_sum);
	
	return 0;
}

// 등급(A0 같은 문자)을 주면 해당하는 점수로 반환
double score(char* grade)
{
	/*printf("grade 는 : %s\n", grade);
	printf("A+가 맞을까? :%d", strcmp(grade, "A+"));*/
	if		(!strcmp(grade, "A+"))	return 4.5;
	else if (!strcmp(grade, "A0"))	return 4.0;
	else if (!strcmp(grade, "B+"))	return 3.5;
	else if (!strcmp(grade, "B0"))	return 3.0;
	else if (!strcmp(grade, "C+"))	return 2.5;
	else if (!strcmp(grade, "C0"))	return 2.0;
	else if (!strcmp(grade, "D+"))	return 1.5;
	else if (!strcmp(grade, "D0"))	return 1.0;
	else							return 0;
}
