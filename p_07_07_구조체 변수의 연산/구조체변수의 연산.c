
#pragma region 연습문제 -> 구조체 변수의 연산 예제
// start
// #include "header.h"
#include <stdio.h>

typedef struct point
{
	int xPos;
	int yPos;
}Point;

void SwapPoint(Point* pos1, Point* pos2);


int main()
{
	/*
	다음 구조체의 두 변수를 대상으로 저장된 값을 서로 바꿔주는 함수를 정의, 호출

	예를 들어서 아래와 같은 두 개의 구조체 변수가 선언된 상태일 때,
	Point pos1 = {2,4};
	Point pos2 = {5,7};
	이 두개의 구조체 변수를 대상으로, 혹은 두개의 구조체 변수의 주소값을 대상으로
	SwapPoint 라는 이름의 함수를 호출하면 pos1의 xPos, yPos에는
	각각 5와 7이, 그리고 pos2의 xPos, yPos에는 각각 2와 4가 저장
	*/
	Point pos1 = { 2,4 };
	Point pos2 = { 5,7 };

	SwapPoint(&pos1, &pos2);

	printf("pos1: [%d, %d] \n", pos1.xPos, pos1.yPos);
	printf("pos2: [%d, %d] \n", pos2.xPos, pos2.yPos);

	return 0;
}

void SwapPoint(Point* pos1, Point* pos2)
{
	Point temp = *pos1;
	*pos1 = *pos2;
	*pos2 = temp;
}

#pragma endregion


#pragma region circle 예제
// start
// #include "header.h"
#include <stdio.h>

typedef struct point
{
	int xPos;
	int yPos;
}Point;

typedef struct circle
{
	Point cen;
	double rad;
}Circle;

typedef struct circle2
{
	Point cen;
	double rad;
}Circle2;


void showCircleInfo(Circle cir);
void showCircleInfo2(Circle2* cir);

int main()
{
	/*
	point 구조체 정의. 이름 Point

	circle 구조체 정의. 이름 Circle
	- 좌표 담을 그릇. cen
	- 반지름 담을 그릇. rad

	main()
	- c1. 1,2, 3.5로 선동초
	- c2. 2,4, 3.9로 선동초

	- showCircleInfo(). 인자 한개
	- showCircleInfo(). 인자 한개

	showCircleInfo().
	- 전달받은 녀석의 좌표 출력
	- 전달받은 녀석의 반지름 출력
	*/

	// 둘 다 가능 -> highlight
	Circle c1 = { {1,2}, 3.5 };
	Circle2 c2 = { 2,4, 3.9 };

	showCircleInfo(c1);
	showCircleInfo2(&c2);

	return 0;
}

void showCircleInfo(Circle cir)
{
	printf("좌표: [%d, %d], 반지름: %.1f \n", cir.cen.xPos, cir.cen.yPos, cir.rad);
}

void showCircleInfo2(Circle2* cir)
{
	printf("좌표: [%d, %d], 반지름: %.1f \n", cir->cen.xPos, cir->cen.yPos, cir->rad);
}


#pragma endregion


#pragma region getUserData 예제
// start
// #include "header.h"
#include <stdio.h>

typedef struct
{
	int age;
	char name[50];
	char phoneNum[20];
}USERDATA;

typedef struct
{
	int age;
	char name[50];
	char phoneNum[20];
}USERDATA2;

USERDATA getUserData();					// 주소값을 쓰지 않음
void getUserData2(USERDATA* data);		// 주소값을 이용함 !

int main()
{
	/*
	USERDATA구조체 정의
	- 나이.age
	- 이름.name
	- 전화번호.phone

	main()
	- USERDATA형 user. 0 선동초
	- getUserData함수 호출
	- 나이, 이름, 전번 출력

	getUserData()
	- 나이 입력 받기
	- 이름 입력 받기. 단, gets 함수 써보기
	- 전번 입력 받기. 단, gets 함수 써보기
	- 전체 정보 반환!!
	*/

	// 선언
	USERDATA user = { 0, };
	USERDATA2 user2 = { 0, };

	// 처리
	user = getUserData();
	getUserData2(&user2);

	// 출력
	printf("나이: %d, 이름: %s, 전화번호: %s \n", user.age, user.name, user.phoneNum);
	printf("나이: %d, 이름: %s, 전화번호: %s \n", user2.age, user2.name, user2.phoneNum);

	return 0;
}

USERDATA getUserData()
{
	int tmp;
	USERDATA temp = { 0, };
	printf("나이를 입력하세요: "); scanf_s("%d", &temp.age);
	tmp = getchar();
	printf("이름을 입력하세요: "); gets_s(temp.name, sizeof(temp.name));
	printf("전화번호를 입력하세요: "); gets_s(temp.phoneNum, sizeof(temp.phoneNum));
	return temp;
}
// unsigned int가 gets_s의 인자에 없으니까 굳이 여기서도 안 써줘도 됨ㅋㅋ

void getUserData2(USERDATA* data)
{
	// int tmp;
	USERDATA temp = { 0, };
	printf("나이를 입력하세요: "); scanf_s("%d%*c", &data->age); // %*c 를 쓰면 1바이트 가져감
	// tmp = getchar();
	printf("이름을 입력하세요: "); gets_s(data->name, sizeof(temp.name));
	printf("전화번호를 입력하세요: "); gets_s(data->phoneNum, sizeof(temp.phoneNum));
}



#pragma endregion


#pragma region 연습문제 -> 구조체 직사각형의 넓이와 좌표
// start
// #include "header.h"
#include <stdio.h>

typedef struct
{
	int xPos;
	int yPos;
}Point;

typedef struct
{
	Point leftTop;
	Point rightBot;
}RECTANGLE;

// 넓이용 함수
void ShowRecArea(RECTANGLE Rec);
void ShowRecArea2(RECTANGLE* Rec); // 출력용

// 좌표용 함수
void ShowRecPos(RECTANGLE Rec);
void ShowRecPos2(RECTANGLE* Rec);

int main()
{
	/*
	좌 상단의 x, y 좌표가 [0, 0], 우 하단의 x,y좌표가 [100, 100]인 좌표 평면상의
	직사각형 정보를 표현하기 위한 구조체 Rectangle을 정의하되,
	다음 구조체를 기반으로 정의

	그리고 Rectangle 구조체 변수를 인자로 전달받아서
	해당 직사강형의 넓이를 계산해서 출력!!!!하는 함수와
	직사각형을 이루는 네 점의 좌표정보를 출력!!!하는 함수를
	각각!!!! 정의.

	단, 좌표 평면상에서 직사각형을 표현하기 위해서 필요한 점의 개수는 4개가 아닌 2개.
	직사각형을 의미하는 Rectangle 변수 내에는 두 점의 정보만 존재한다.
	*/
	RECTANGLE Rectangle = { {1,1} , {4,4} };	// call by value
	RECTANGLE Rectangle2 = { 0,0 , 7,5 };		// call by reference

	ShowRecArea(Rectangle);
	ShowRecPos(Rectangle);

	ShowRecArea2(&Rectangle2);
	ShowRecPos2(&Rectangle2);

	return 0;
}

void ShowRecArea(RECTANGLE Rec)
{
	printf("Rectangle의 넓이: %d\n", Rec.rightBot.xPos - Rec.leftTop.xPos)* (Rec.rightBot.yPos - Rec.leftTop.xPos);
}

void ShowRecPos(RECTANGLE Rec)
{
	printf("좌 상단: [%d, %d] \n", Rec.leftTop.xPos, Rec.leftTop.yPos);
	printf("좌 하단: [%d, %d] \n", Rec.leftTop.xPos, Rec.rightBot.yPos);
	printf("우 상단: [%d, %d] \n", Rec.rightBot.xPos, Rec.leftTop.yPos);
	printf("우 하단: [%d, %d] \n", Rec.rightBot.xPos, Rec.rightBot.yPos);
}

void ShowRecArea2(RECTANGLE* Rec)
{
	printf("Rectangle2의 넓이: %d\n", (Rec->rightBot.xPos - Rec->leftTop.xPos) * (Rec->rightBot.yPos - Rec->leftTop.xPos));
}

void ShowRecPos2(RECTANGLE* Rec)
{
	printf("좌 상단: [%d, %d] \n", Rec->leftTop.xPos, Rec->leftTop.yPos);
	printf("좌 하단: [%d, %d] \n", Rec->leftTop.xPos, Rec->rightBot.yPos);
	printf("우 상단: [%d, %d] \n", Rec->rightBot.xPos, Rec->leftTop.yPos);
	printf("우 하단: [%d, %d] \n", Rec->rightBot.xPos, Rec->rightBot.yPos);
}



#pragma endregion


#pragma region 구조체와 공용체
// start
// #include "header.h"
#include <stdio.h>

typedef struct
{
	int mem1;
	int mem2;
	double mem3;
}SBOX;

typedef union
{
	int mem1;
	int mem2;
	double mem3;
}UBOX;

int main()
{
	/*

	*/
	SBOX sbx;
	UBOX ubx;

	printf("%p %p %p \n", &sbx.mem1, &sbx.mem2, &sbx.mem3);
	// 0 ... 062EF6FFA78	0 ... 062EF6FFA7C		0 ... 062EF6FFA80
	printf("%p %p %p \n", &ubx.mem1, &ubx.mem2, &ubx.mem3);
	// 0 ... 062EF6FFAA8	0 ... 062EF6FFAA8		0 ... 0062EF6FFAA8
	printf("%zd %zd \n", sizeof(SBOX), sizeof(UBOX));
	// 16, 8

	/*
	mem1에서 mem2까지 역시 4바이트, 그 다음도 4바이트이고, 여기선 구하지 않았지만
	다음 주소는 double의 크기는 8바이트를 추가한 주소값이 나오게 됩니다.

	struct와 다르게 union은 가장 큰 크기의 바이트를 공유하기 때문에
	다음 주소를 봐도 첫번째 주소값과 같은 값이 나오게 됩니다.

	사이즈는 struct는 모든 크기를 더한 4 + 4 + 8 = 16이고,
	union은 가장 큰 크기의 바이트를 나타내는 8 입니다.
	*/

	return 0;
}

#pragma endregion


#pragma region 공용체의 개념
// start
// #include "header.h"
#include <stdio.h>


typedef union
{
	int mem1;
	int mem2;
	double mem3;
}UBOX;

int main()
{
	/*

	*/

	UBOX ubx;
	ubx.mem1 = 20;

	printf("%d \n", ubx.mem2);  // mem2는 int만큼 뽑을 테니 20

	ubx.mem3 = 7.15;

	printf("%d \n", ubx.mem1); // 7.15라는 실수를 int로 읽어온 값 -> 쓰레기값
	printf("%d \n", ubx.mem2); // 7.15라는 실수를 int로 읽어온 값 -> 쓰레기값
	printf("%g \n", ubx.mem3); // double만큼 읽을 테니 7.15

	return 0;
}




#pragma endregion


#pragma region 연습문제 -> 구조체를 이용한 돼지저금통
// start
// #include "header.h"
#include <stdio.h>

typedef struct
{
	int w500;
	int w100;
	int w50;
	int w10;
}Money;

void init(Money* price);
void save(Money* price, int won, int count);
int total(Money* price);

int main()
{

	/*
	동전 금액과 개수를 입력 받아서 전체 금액을 계산하는 프로그램 작성

	1. 동전 금액별 구조체 한 개 생성
	2. main 함수에서 "동전의 금액, 개수"를 계속 입력 받고 "총 저금액"출력
		단, 0이 입력되면 지금까지 받은 총 저금액 출력
	3. main함수에서 초기화 함수(init)호출
	4. save함수에서 동전 별 수량 카운트
	5. total함수에서 총 저금액 계산 후 값 반환


	힌트
	잔뜩 들고 있는 놈을 초기화하기 -> init 함수
	save: main함수는 동전 별 개수를 모르니까 save가 챙기는 것
	500원이네? -> 500원을 10개 올려야지 이런식
	*/
	int won, count = 0;
	Money price;
	init(&price); // 잔뜩 들고 있는 놈을 초기화
	while (1)
	{
		printf("동전의 금액과 개수: ");
		scanf_s("%d", &won);
		if (won == 0) break;
		scanf_s("%d", &count);
		save(&price, won, count);
	}

	printf("총 저금액: %d원\n", total(&price));

	return 0;
}

void init(Money* price)
{
	price->w500 = price->w100 = price->w50 = price->w10 = 0;
}


void save(Money* price, int won, int count)
{
	// 구조체 전체를 받아서 가격별로 축적해주기?
	// 이 값의 개수를 계속 더해주기
	if (won == 500) price->w500 += count;
	else if (won == 100) price->w100 += count;
	else if (won == 50) price->w50 += count;
	else if (won == 10) price->w10 += count;
}


int total(Money* price)
{
	return (price->w500 * 500) + (price->w100 * 100) + (price->w50 * 50) + (price->w10 * 10);
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





