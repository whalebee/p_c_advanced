// start
// #include "header.h"
#include <stdio.h>

typedef struct score {
	int kor, eng, mat;
	int total;
}SCORE;

int main()
{
	// ���� ������
	//int a = 5;
	//int* p = &a;
	//int** pp = &p;


	//printf("%p \n",	p);		// a�� �ּҰ�
	//printf("%d	\n",	*p);		// 5
	//printf("%p	\n",	*pp);		// a�� �ּҰ�
	//printf("%p	\n",	pp);		// p�� �ּҰ�
	//printf("%d	\n",	**pp);	// 5



	/*
	 2���� ������ �迭
	int arr[4][3] = { 1,2,3,4,5,6,7,8,9,10,11 }; // �˾Ƽ� 3���� ©�� �迭�� �Էµ�
	 int* p[3] = arr;  -> �̷��� �ع����� 1���� ������ �迭
	int(*p)[3] = arr;  // -> �̷��� �ؾ� 2���� ������ �迭 [3] �̿Ͱ��� ���� ǥ�����ְ� ��ȣ�� ��������� !
	printf("%d \n", *p[1]);				// 4
	printf("%d \n", *(p[1] + 2));		// 6
	printf("%d \n", *(p[3] + 2));		// 0
	*/



	// ����ü ������
	SCORE s[3] = {
		{70, 70, 70},
		{80, 80, 80},
		{90, 90, 90}
	};

	// 1���� �迭 �� ��
	// s.total = s.kor + s.eng + s.mat;

	SCORE* pS = &s;

	// 1���� ������ ����ü
	// pS->total = pS->kor + pS->eng + pS->mat;
	// 
	// printf("%d \n", pS->total); 

	// 2���� ������ ����ü �迭
	// ������ ������ �ƴ� ����ü ������ �����ϱ�
	s[0].total = s[0].kor + s[0].eng + s[0].mat;
	s[1].total = s[1].kor + s[1].eng;
	s[2].total = s[2].kor;

	// �ּ��� ��ġ�� ���� ǥ��
	(pS + 0)->total = (pS + 0)->kor + (pS + 0)->eng + (pS + 0)->mat;
	(pS + 1)->total = (pS + 1)->kor + (pS + 1)->eng;
	(pS + 2)->total = (pS + 2)->kor;

	// �ε����� ǥ�� -> ����ȭ�� �Ǳ� ������ -> �� �ƴ� . ���� ��� ����
	pS[0].total = pS[0].kor + pS[0].eng + pS[0].mat;
	pS[1].total = pS[1].kor + pS[1].eng;
	pS[2].total = pS[2].kor;

	printf("2���� ������ ����ü �迭 0: %d \n", pS[0].total);
	printf("2���� ������ ����ü �迭 1: %d \n", pS[1].total);
	printf("2���� ������ ����ü �迭 2: %d \n", pS[2].total);


	return 0;
}


