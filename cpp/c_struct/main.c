
#include <stdio.h>

/*

	구조체

	C언어는 '구조화 프로그래밍 패러다임'에 기반하여 만들어진 언어다.
	<-- 함수나 구조체 등의 '구조물'을 '부품'으로 만들어 
		'프로그램 구조'를 만드는 방법론

	함수 : 코드의 추상화 
	구조체 : 데이터의 추상화

	'데이터' 들을 묶어 추상화하여
	'사용자( 프로그래머 )정의 타입'을 만든 것이다.

*/

//좌표계 : 물체의 위치를 지정하는 시스템

//사각형 데이터 라는 개념으로 추상화
//struct RyuRect
//{
//	//구조체의 정의 영역
//	//C언어에서는 구조체의 '멤버 변수'는 초기화 표현이 불가능하다. (C++은 가능)
//	int mLeft;
//	int mTop;
//	int mRight;
//	int mBottom;
//};

//step_2
//typedef A B         : A를 B로 재정의한다.
typedef unsigned int RYU_INT;

typedef struct RyuRect //A
{
	//구조체의 정의 영역
	//C언어에서는 구조체의 '멤버 변수'는 초기화 표현이 불가능하다. (C++은 가능)
	int mLeft;
	int mTop;
	int mRight;
	int mBottom;
} sRyuRect;//B

int CalcuAreaSize(sRyuRect tRect);

int main()
{
	//step_0
	//사각형의 넓이 구하기
	//좌표계는 윈도우 좌표계(2D) 가정
	/*int tLeft = 0;
	int tTop = 0;
	int tRight = 0;
	int tBottom = 0;

	tLeft = 100;
	tTop = 100;
	tRight = 200;
	tBottom = 200;

	int tWidth = tRight - tLeft;
	int tHeight = tBottom - tTop;

	int tAreaSize = tWidth * tHeight;

	printf("Area Size : %d\n", tAreaSize);*/

	//step_1
	/*int tLeft = 0;
	int tTop = 0;
	int tRight = 0;
	int tBottom = 0; */
	//struct RyuRect tRect;   //구조체 RyuRect 타입의 변수 선언(C++은 struct라고 안 써도 된다.)
	//

	//tRect.mLeft = 100;    //. : 멤버 접근 연산자
	//tRect.mTop = 100;
	//tRect.mRight = 200;
	//tRect.mBottom = 200;

	//int tWidth = tRect.mRight - tRect.mLeft;
	//int tHeight = tRect.mBottom - tRect.mTop;

	//int tAreaSize = tWidth * tHeight;

	//printf("Area Size : %d\n", tAreaSize);


	//step_2

	//unsigned int tA = 777;
	//printf("tA : %d\n", tA);
	//RYU_INT tB = 333;
	//printf("tB : %d\n", tB);


	//sRyuRect tRect; 


	//tRect.mLeft = 100;    
	//tRect.mTop = 100;
	//tRect.mRight = 200;
	//tRect.mBottom = 200;

	//int tWidth = tRect.mRight - tRect.mLeft;
	//int tHeight = tRect.mBottom - tRect.mTop;

	//int tAreaSize = tWidth * tHeight;

	//printf("Area Size : %d\n", tAreaSize);


	//step_3
	sRyuRect tRect;


	tRect.mLeft = 100;
	tRect.mTop = 100;
	tRect.mRight = 200;
	tRect.mBottom = 200;

	//int CalcuAreaSize(sRyuRect tRect)
	int tAreaSize = CalcuAreaSize(tRect);//int tWidth = tRect.mRight - tRect.mLeft;
										 //int tHeight = tRect.mBottom - tRect.mTop;
										 //tWidth * tHeight;
	printf("Area Size : %d\n", tAreaSize);
	

	return 0;
}

int CalcuAreaSize(sRyuRect tRect)
{
	int tResult = 0;

	int tWidth = tRect.mRight - tRect.mLeft;
	int tHeight = tRect.mBottom - tRect.mTop;

	tResult = tWidth * tHeight;

	return tResult;
}
