// start
// #include "header.h"
#include <stdio.h>

#define LEN 5
#define SUB_CNT 3.0

typedef struct
{
	char name[30];
	int stuNum;
	int kor;
	int eng;
	int math;
	int total;
	double avg;
	char grade;
}Student;

void input_data(Student* example);
void calc_data(Student* example);
void printf_data(Student* example);
void sort_data(Student* example);


int main()
{
	// 배열의 SIZE를 define으로 놓고
	// 길이는 매개변수로 줄 것
	/*
	5명의 학번, 이름, 국어,영어, 수학 점수를 입력받아 정렬 전 데이터 출력 후에
	정렬 후 데이터 이렇게 2개의 데이터를 출력

	학번, 이름, 과목 점수, 총점, 평균, 학점 구조체 생성

	main함수에서 input_data, calc_data 호출하고 이후 printf_data와
	sort_data 함수 출력한 뒤 마지막으로 printf_data 함수 호출 ( 비교를 위해 )

	input_data 함수는 5명의 정보(학번, 이름, 점수)를 입력
	calc_data 함수는 5명의 과목 총점, 평균, 학점 계산
	(90이상 A, 80이상 B, 70이상 C, 외 F)

	sort_data 함수는 평균 점수로 정렬
	printf_data 함수는 5명의 정보 출력
	*/
	Student example[5] = { 0, };

	input_data(&example);
	calc_data(&example);
	printf("#정렬 전 데이터... \n");
	printf_data(&example);
	sort_data(&example);
	printf("#정렬 후 데이터... \n");
	printf_data(&example);

	return 0;
}

void input_data(Student* example)
{
	int i;
	for (i = 0; i < LEN; i++)
	{
		printf("학번 : "); scanf_s("%d", &example[i].stuNum);
		printf("이름 : "); scanf_s("%s", example[i].name, (unsigned char)sizeof(example->name));
		printf("국어, 영어, 수학 점수 : "); scanf_s("%d %d %d", &example[i].kor, &example[i].eng, &example[i].math);
	}
}

// 총점, 평균, 학점 계산
void calc_data(Student* example)
{
	int i;
	for (i = 0; i < LEN; i++)
	{
		example[i].total = example[i].kor + example[i].eng + example[i].math;
		// printf("총점확인: %d \n", example[i].total);
		example[i].avg = example[i].total / SUB_CNT;
		if (example[i].avg >= 90)	example[i].grade = 'A';
		else if (example[i].avg >= 80)	example[i].grade = 'B';
		else if (example[i].avg >= 70)	example[i].grade = 'C';
		else 							example[i].grade = 'F';
		// printf("학점 확인 : %c \n", example[i].grade); 
	}
}

void printf_data(Student* example)
{
	int i;
	for (i = 0; i < LEN; i++)
		printf("%10d %10s %5d %5d %5d %5d %.1f %5c \n", example[i].stuNum, example[i].name, example[i].kor, example[i].eng, example[i].math, example[i].total, example[i].avg, example[i].grade);
}

// 내림차순이여
void sort_data(Student* example)
{
	Student temp;
	int i, j, max = 0;
	for (i = 0; i < LEN; i++)
	{
		// 해야할 때와 안 해야할 때를 가려서?
		max = i;
		for (j = i; j < LEN; j++)
			if (example[max].avg < example[j].avg) max = j;


		temp = example[max];
		example[max] = example[i];
		example[i] = temp;

		
		/*
		3 5 1 4
		1이라는 인덱스 값이 가장 크다는 것을 찾음
		그걸 마지막에 넣어야함

		왜 처음만 바뀌징
		첫번째에 max인덱스를 사용하여 스왑을 해주었기 때문에
		처음부터 비교하는 j는 무조건 가장 큰 첫번째 값을 max에 넣어줄 수 밖에 없으니까.

		*/

	}
}
// 순서 앞당기기
// printf("i의 %f\n", example[j].avg);
// printf("i+1의 %f\n", example[j + 1].avg);

// 스왑은 마지막에만 한 번 을 하는 것이고,
// 반복문 안에서는 제일 큰 값의 인덱스를 찾는다