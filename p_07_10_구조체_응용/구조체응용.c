
#pragma region 연습문제 -> 5명의 학번 구조체 연산
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

// 오름차순으로 보임
void sort_data(Student* example)
{
	Student temp;
	int i, j;
	for (i = 0; i < LEN - 1; i++)
	{
		for (j = 0; j < LEN - 1; j++)
		{
			if (example[j].avg < example[j + 1].avg) // 0보다 크면
			{
				temp = example[j];
				example[j] = example[j + 1];
				example[j + 1] = temp;
			}
		}
	}
}
// 순서 앞당기기
// printf("i의 %f\n", example[j].avg);
// printf("i+1의 %f\n", example[j + 1].avg);



#pragma endregion


#pragma region 첫번째 연습문제 응용
// 총점, 평균, 학점 계산
void calc_data(Student* example)
{
	int i;
	for (i = 0; i < LEN; i++)
	{
		example->total = example->kor + example->eng + example->math;
		// printf("총점확인: %d \n", example[i].total);
		example->avg = example->total / SUB_CNT;
		if		(example->avg >= 90)	example->grade = 'A';
		else if (example->avg >= 80)	example->grade = 'B';
		else if (example->avg >= 70)	example->grade = 'C';
		else 							example->grade = 'F';
		example++;
		// printf("학점 확인 : %c \n", example[i].grade);
		// 피드백: 90.0 80.0 이런식으로 소수점으로 써놔도 괜찮을 듯
		// 주소값을 이용한 방식 ! ( 배열 말고 )
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

		// 쌤 방법
		/*if (max != i)
		{
			temp = example[max];
			example[max] = example[i];
			example[i] = temp;
		}*/

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



#pragma endregion


#pragma region 파일입출력 예제
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* 파일입출력 예제
	"data.txt" 쓰기 용도로 스트림 생성. fp

	만약에 스트림 생성에 실패하면 "파일 오픈 실패"출력(puts로 하기)하고 프로그램 종료

	data.txt에 A 쓰기. fputc
	data.txt에 B 쓰기. fputc
	data.txt에 C 쓰기. fputc
	*/
	// fopen_s()
	FILE* fp;
	if (fopen_s(&fp, "C:\\cTest\\data.txt", "w") != 0)
	{
		perror("파일 열기 실패");
		// puts("파일 오픈 실패");
		return -1;
	}
	//errno_t err;
	//err = fopen_s(&fp, "C:\\cTest\\data.txt", "w");
	//if (err != 0)
	//{
	//	perror("파일 열기 실패");
	//	// puts("파일 오픈 실패");
	//	return -1;
	//}

	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);

	fclose(fp);

	return 0;
}



#pragma endregion


#pragma region 파일 읽기 예제
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/* 파일입출력 예제
	"data.txt" 쓰기 용도로 스트림 생성. fp

	만약에 스트림 생성에 실패하면 "파일 오픈 실패"출력(puts로 하기)하고 프로그램 종료

	data.txt에 A 쓰기. fputc
	data.txt에 B 쓰기. fputc
	data.txt에 C 쓰기. fputc
	*/
	// fopen_s()
	int i = 0;

	FILE* fp;
	if (fopen_s(&fp, "C:\\cTest\\data.txt", "rt") != 0)
	{
		perror("파일 열기 실패");
		// puts("파일 오픈 실패");
		return -1;
	}

	for (i = 0; i < 3; i++)
		printf("%c \n", fgetc(fp));
	// printf("%s", fgets( stdin, 4, fp)); -> 기교부린거 때문에 fgetc 써야됨

	fclose(fp);

	return 0;
}



#pragma endregion


#pragma region 파일 입출력 쓰고 읽기 예제
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	simple.txt 쓰기 용도로 스트림 생성. fp
	만약에 스트림 생성에 실패하면 puts로 파일 오픈 실패 출력하고 프로그램 종료

	simple.txt에 A쓰기
	simple.txt에 B쓰기
	simple.txt에 My name is Ho쓰기
	simple.txt에 Yuor name is No쓰기

	fclose로 스트림 소멸

	////////////////////////////////////////////////////////////////////////////////

	simple.txt 읽기읽어서 화면에 출력
	*/

	FILE* fp;
	if (fopen_s(&fp, "C:\\cTest\\simple.txt", "wt") != 0)
	{
		puts("파일 오픈 실패");
		return -1;
	}

	fputc('A', fp);
	fputc('B', fp);
	fputs("My name is Ho \n", fp);
	fputs("Your name is No \n", fp);

	fclose(fp);

	////////////////////////////////////////////////////////////////////////////////

	char temp[100];
	if (fopen_s(&fp, "C:\\cTest\\simple.txt", "rt") != 0)
	{
		puts("파일 오픈 실패");
		return -1;
	}

	// 쓰는 것도 4번 -> 읽는 것도 4번

	printf("%c", fgetc(fp));
	printf("%c", fgetc(fp));
	printf("%s", fgets(temp, sizeof(temp), fp)); // 배열의 이름은 첫번째 요소의 주소값 !!
	printf("%s", fgets(temp, sizeof(temp), fp));

	// 반복문 버전
	/*int i;
	for (i = 0; i < 2; i++)
		printf("%s", fgets(&temp, 100, fp));*/

	fclose(fp);

	return 0;
}




#pragma endregion


#pragma region 파일 입출력 feof 예제
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	src.txt를 읽기 모드. 지시자 이름 src
	des.txt를 쓰기 모드. 지시자 이름 des

	src든 des든 못 열면 "파일 오픈 실패" 출력하고 프로그램 종료

	src로부터 한 글자씩 읽어서 des에 저장(반복문 while사용)
	파일 끝까지 잘 되었다면 "파일 복사 완료"출력. puts
	파일 끝까지 잘 안 되었다면 "파일 복사 실패"출력. puts

	리소스 반환
	*/
	FILE* src, * des;
	// FILE;
	// 합친거
	if (fopen_s(&src, "C:\\cTest\\src.txt", "rt") != 0 || fopen_s(&des, "C:\\cTest\\des.txt", "wt") != 0)
	{
		puts("파일 오픈 실패!!");
		return -1;
	}
	// 나눈거
	/*if (fopen_s(&src, "C:\\cTest\\src.txt", "rt") != 0)
	{
		puts("파일 오픈 실패");
		return -1;
	}
	if (fopen_s(&des, "C:\\cTest\\des.txt", "wt") != 0)
	{
		puts("파일 오픈 실패");
		return -1;
	}*/

	// while은 그저 복사할 뿐
	// feof(src) == 0 이건 판단할 때만 쓰기
	int temp = 0;
	while ((temp = fgetc(src)) != EOF)
		fputc(temp, des);

	if (feof(src) == 0)
	{
		puts("파일 복사 실패");
		return -1;
	}
	puts("파일 복사 완료");

	/* 문제점
	1. des.txt 파일안에 src.txt의 마지막 NULL값도 가져온 듯 하다.
	조건을 제대로 해주니 NULL을 가져오지 않았다 !

	2. 파일 복사 실패를 구분하는 방법을 모르겠다.
	feof(src) == 0 으로 해결보았다.

	*/

	fclose(src);
	fclose(des);

	return 0;
}






#pragma endregion


#pragma region 파일 입출력 선생님 버전
// start
// #include "header.h"
#include <stdio.h>
int main()
{

	// 선언
	FILE* src, * des;
	errno_t src_err;
	errno_t des_err;
	src_err = fopen_s(&src, "C:\\cTest\\src.txt", "rt");
	des_err = fopen_s(&des, "C:\\cTest\\des.txt", "wt");

	// 예외
	if (src_err != 0 || des_err != 0)
	{
		puts("파일 오픈 실패!!");
		return -1;
	}

	// 처리
	int temp = 0;
	while ((temp = fgetc(src)) != EOF)
		fputc(temp, des);

	if (feof(src) == 0)
	{
		puts("파일 복사 실패");
		return -1;
	}
	puts("파일 복사 완료");

	// 해제
	fclose(src);
	fclose(des);
	return 0;
}



#pragma endregion


#pragma region 바이너리 복사 붙여넣기 예제
// start
// #include "header.h"
#include <stdio.h>

int main()
{
	/*

	*/
	// 선언
	FILE* src, * des;

	errno_t src_err, des_err;
	src_err = fopen_s(&src, "C:\\cTest\\src.jpg", "rb");
	des_err = fopen_s(&des, "C:\\cTest\\des.jpg", "wb");
	// 예외
	if (src_err != 0 || des_err != 0)
	{
		puts("파일 오픈 실패!!");
		return -1;
	}

	int buf[5];
	int i;
	int temp;

	// 사이즈를 어떻게 하지? 리턴값이 count보다 작게 나오는 값을 조건으로 사용
	// -> 이렇게 하니까 크기가 딱 맞지 않음
	// 1바이트로 해야하나? -> 크기는 맞으나.. 화면 출력에 20이 아닌 1로 가득 참
	// feof를 사용해서 break를 사용하게 되는데 -> 이렇게 하지 않아도 가능함

	/*
	피드백
	1. 20씩 읽고 20씩 넣기때문에 마지막 16씩 읽어야했을 때 20씩 넣었음
	이걸 temp의 크기로 바꿔줌 !
	2. 조건문 설정하기가 어려웠는데 fread의 리턴값을 이용해서 조건문을 설정해줌
	3. 뭔가 사이즈와 개수가 패키지와 낱개 개념인 것 같음
	*/
	// fread(버퍼, 패키지크기, 개수, src) -> 이런식으로 !
	while ((temp = fread((int*)buf, sizeof(char), sizeof(buf), src)) > 0)
		fwrite((int*)buf, sizeof(char), temp, des);

	if (feof(src) == 0)
	{
		puts("파일 복사 실패");
		return -1;
	}
	puts("파일 복사 완료");

	fclose(src);
	fclose(des);

	return 0;
}





#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion




#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion





