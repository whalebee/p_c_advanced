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
	문자열 형태의 종업원 이름과 주민등록번호
	그리고 정수 형태의 급여정보를 저장할 수 있는 employee라는 이름의 구조체 정의

	구조체 변수를 하나 선언한 다음 사용자 입력받아서 변수를 채우고,
	구조체 변수에 채워진 데이터를 출력한다.
	*/
	struct employee salary_info;

	fputs("이름? ", stdout);
	scanf_s("%s", salary_info.name, (unsigned int)sizeof(salary_info.name));
	fputs("주민등록번호? ", stdout);
	scanf_s("%s", salary_info.addr_num, (unsigned int)sizeof(salary_info.addr_num));
	fputs("급여? ", stdout);
	scanf_s("%d", &salary_info.salary);


	printf("이름은 : %s \n주민등록번호: %s\n급여: %d", salary_info.name, salary_info.addr_num, salary_info.salary);





	return 0;
}
