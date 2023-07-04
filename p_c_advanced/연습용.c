// start
// #include "header.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

struct person {
	char name[50];
	char phoneNum[50];
	int age;
};

int main()
{
	/* 예제 
	person형 구조체 정의
	- 이름.name
	- 전화번호.phoneNum
	- 나이.age

	main함수에서
	- person형 변수 man1, man2 선언
	- 이름에 김찬호 -> strcpy() 사용 -> 소속은 string.h
	- 010-123-4567
	- 나이에 40

	이름, 번호, 나이 출력

	(man2)
	사용자로부터 이름, 번호, 나이 입력 받기
	이름, 번호, 나이 출력
	*/
	
	// 선언
	struct person man1;
	struct person man2;

	// 입력
	strcpy_s(man1.name, sizeof(man1.name), "김찬호");
	strcpy_s(man1.phoneNum, sizeof(man1.phoneNum), "010-123-4567");
	man1.age = 40;

	fputs("이름? ", stdout);
	scanf_s("%s", man2.name, (unsigned char)sizeof(man2.name));
	fputs("번호? ", stdout);
	scanf_s("%s", man2.phoneNum, (unsigned char)sizeof(man2.phoneNum));
	fputs("나이? ", stdout);
	scanf_s("%d", &man2.age);

	
	// 출력
	puts(" ");
	printf("입력되어있던 사용자\n");
	printf("이름: %s\n번호: %s\n나이: %d\n", man1.name, man1.phoneNum, man1.age);
	
	puts(" ");
	printf("입력받은 사용자 \n");
	printf("이름: %s\n번호: %s\n나이: %d\n", man2.name, man2.phoneNum, man2.age);

	return 0;
}
