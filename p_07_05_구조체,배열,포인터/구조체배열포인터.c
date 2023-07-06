
#pragma region 구조체와 배열 포인터 기본 예제
// start
// #include "header.h"
#include <stdio.h>

struct point
{
	int xpos;
	int ypos;
};

int main()
{
	/*
	point 구조체. 멤버2개

	main()
	- 길이가 3인 point형 배열 arr선언
	- 세 점의 좌표 입력 받기
	- 세 점의 좌표 출력
	*/
	struct point arr[3];
	int i, len;
	len = sizeof(arr) / sizeof(struct point);

	// 입력
	for (i = 0; i < len; i++)
	{
		printf("점의 좌표 입력: ");
		scanf_s("%d %d", &arr[i].xpos, &arr[i].ypos);
	}

	// 출력
	for (i = 0; i < len; i++)
		printf("[%d, %d] \n", arr[i].xpos, arr[i].ypos);

	return 0;
}

#pragma endregion


#pragma region 연습문제 -> 직원정보(구조체 배열)
#include <stdio.h>

struct employee
{
	char name[50];
	char addr_num[15];
	int  salary;
};


int main()
{
	/* 연습문제
	길이가 3인 배열로 선언하고
	세 명의 정보를 입력 받아서 배열에 저장한 다음, 배열에 저장된 데이터를
	순서대로 출력하는 예제를 작성한다.
	*/
	struct employee emp[3] = { 0, };
	int i, len;
	len = sizeof(emp) / sizeof(struct employee);

	for (i = 0; i < len; i++)
	{
		fputs("이름은?: ", stdout);
		scanf_s("%s", emp[i].name, (unsigned int)sizeof(emp[i].name));
		fputs("주민등록번호는?: ", stdout);
		scanf_s("%s", emp[i].addr_num, (unsigned int)sizeof(emp[i].addr_num));
		fputs("월급은?: ", stdout);
		scanf_s("%d", &emp[i].salary);
	}

	printf("--- 직원 정보 ---\n");
	for (i = 0; i < len; i++)
	{
		printf("이름		: %s \n", emp[i].name);
		printf("주민등록번호: %s \n", emp[i].addr_num);
		printf("나이		: %d \n\n", emp[i].salary);
	}

	return 0;
}


#pragma endregion


#pragma region 구조체 포인터 예시
// start
// #include "header.h"
#include <stdio.h>

struct point
{
	int xPos;
	int yPos;
};

int main()
{
	/*
	point 구조체 정의.

	main()
	- point형 변수 pos1. 1,2 로 선동초
	- point형 변수 pos2. 100,200 로 선동초
	- point형 포인터 변수 pptr. pos1의 주소로 선동초
	- pptr을 활용해 x좌표 4증가
	- pptr을 활용해 y좌표 4증가
	- pptr을 활용해 좌표 출력

	- pptr. pos2의 주소로 초기화
	- pptr을 활용해 x좌표 1증가
	- pptr을 활용해 y좌표 2증가
	- pptr을 활용해 좌표 출력
	*/
	struct point pos1 = { 1,2 };
	struct point pos2 = { 100,200 };
	struct point* pptr = &pos1;

	// (*pptr).member 형태
	(*pptr).xPos += 4;
	(*pptr).yPos += 4;
	printf("[%d,%d] \n", (*pptr).xPos, (*pptr).yPos);

	// pptr->member 형태
	pptr = &pos2;
	pptr->xPos += 1;
	pptr->yPos += 2;
	printf("[%d,%d] \n", pptr->xPos, pptr->yPos);

	return 0;
}




#pragma endregion


#pragma region 못 풀었었던 구조체 포인터 예제 ( 지금은 풀었음 )
// start
// #include "header.h"
#include <stdio.h>

struct point
{
	int xPos;
	int yPos;
};

struct circle
{
	double radius;
	struct point* center; // 여기 포인터를 주는 거였누..
};

int main()
{
	/*
	point 구조체 정의.

	circle 구조체 정의.
	- 실수 radius(반지름)
	- 자료형 -> 비밀 / 변수명 center ( main 함수가 힌트 )

	main ( ) 5줄임
	- ??? cen. 2, 7로 선동초 ( 좌표 )
	- ??? rad. 5.5 선동초
	- ??? ring. 반지름과 원의 중심 좌표로 선동초 -> 존재이유?
	- 원의 반지름: 땡 출력
	- 원의 중심 [땡, 땡] 출력 ( 좌표 )
	*/
	struct point cen = { 2, 7 };
	double rad = 5.5;
	struct circle ring = { rad, &cen };
	// 아놔 cen의 주소값을 주려면 circle 안에 있는 center로 포인터 변수로
	// 선언을 했었어야지 으아ㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏ
	printf("원의 반지름: %.1f \n", ring.radius);
	printf("원의 중심 [%d, %d] \n", ring.center->xPos, (*ring.center).yPos);

	// 구조체 포인터를 써야할 것 같은데
	// struct circle ring = { rad, cen }; 
	/*
	printf("원의 반지름: %.1f \n", ring.radius);
	printf("원의 중심 [%d, %d] \n", ring.center.xPos, ring.center.yPos);
	*/

	return 0;
}



#pragma endregion


#pragma region 연습문제 -> 구조체와 배열의 공통점과 차이점
// start
// #include "header.h"
#include <stdio.h>

struct info
{
	char id[50];
	char passwd[30];
	char name[50];
	int age;
};

int main()
{
	/*
	인터넷 카페 회원 1명의 아이디(smartC), 비밀번호(sm8448), 나이(20), 이름(신세대)
	정보를 변수로 선언함과 동시에 초기화 한 후 출력하고자 한다.
	회원의 정보를 구조체를 사용하지 않고 처리하는 프로그램과, -> ?
	구조체를 사용하는 프로그램,
	두 개를 작성한 후 구조체와 배열의 같은 점과 차이점을 비교 설명
	*/
	// 구조체 사용
	struct info member = { "smartC", "sm8448", "신세대", 20 };
	// 출력
	printf("아이디: %s \n비밀번호: %s\n이름: %s\n나이: %d\n\n", member.id, member.passwd, member.name, member.age);


	// 구조체 미사용 ->
	char* memberArr[4] = { "smartA", "sm1234", "MZ", "15" };

	//출력
	printf("아이디: %s \n비밀번호: %s\n이름: %s\n나이: %s\n\n", memberArr[0], memberArr[1], memberArr[2], memberArr[3]);

	/*
	공통점
	배열을 사용하여 값을 저장하고 출력할 수 있다.

	차이점
	배열은 구조체와 다르게 같은 자료형들끼리만 저장할 수 있고,
	구조체는 서로 다른 자료형으로도 저장할 수 있다.

	printf할 때 [] .id 등 표현이 다름

	배열은 재사용에 어려움이 있지만,
	구조체는 배열을 사용하면서 그 배열을 어디서든지 다시 사용할 수 있게
	자료형으로 배열이나 변수들을 정의하여 다시 사용할 수 있다.
	*/


	return 0;
}



#pragma endregion


#pragma region 연습문제 -> 틀린 곳 찾기
// start
// #include "header.h"
#include <stdio.h>

struct rectangle {
	// 구조체 안에서 선언과 동시에 초기화를 하려했음
	int width, height, area;
};
// } 이렇게만 쓰여져있을 때 문제는 정의가 끝나지 않았음	  ; 로 끝내야함 !

int main() // 연습문제
{
	// rectangle r1 = { 3,7 }, r2 = { 2,5 }; // 자료형자체가 틀렸음, struct 빼먹었기때문
	struct rectangle r1 = { 3,7 }, r2 = { 2,5 };
	// int larger; 
	//	담아내려하는 자료형이 다름, r1이나 r2를 담아내야하는데 
	//	4바이트로 12바이트의 내용을 담아내려했기때문 !
	struct rectangle larger;
	r1.area = r1.width * r1.height;
	r2.area = r2.width * r2.height;

	// if ( r1 > r2 ) // 구조체의 멤버 중 면적을 비교해야하므로 구조체.area 를 비교해야함
	if (r1.area > r2.area)
		larger = r1;
	else
		larger = r2;
	printf("더 큰 사각형의 면적은 %d입니다.", larger.area);


	return 0;
}




#pragma endregion


#pragma region 연습문제 -> 한 학기 평점(GPA)
#include <stdio.h>
#include <string.h>

// double score(char grade[2]); // 선생님 버전
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
// double score(char grade[2]); // 선생님 버전
double score(char* grade)
{
	/*printf("grade 는 : %s\n", grade);
	printf("A+가 맞을까? :%d", strcmp(grade, "A+"));*/
	if (!strcmp(grade, "A+"))	return 4.5;
	else if (!strcmp(grade, "A0"))	return 4.0;
	else if (!strcmp(grade, "B+"))	return 3.5;
	else if (!strcmp(grade, "B0"))	return 3.0;
	else if (!strcmp(grade, "C+"))	return 2.5;
	else if (!strcmp(grade, "C0"))	return 2.0;
	else if (!strcmp(grade, "D+"))	return 1.5;
	else if (!strcmp(grade, "D0"))	return 1.0;
	else							return 0;
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


#pragma region



#pragma endregion





