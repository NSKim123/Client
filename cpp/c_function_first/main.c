
#include <stdio.h>

/*

	함수의 사용법

	C언어는 '구조화 프로그래밍 패러다임'으로 만들어진 언어

	그리하여
		'구조화'하여 제어구조 코드의 일정 문단들을 '부품화'하여
		해당 부품들로 프로그램 구조를 구성하는 방법이 발명됨
		이것이 구조화 프로그래민 structured programming 이다.
		( --> 함수와 구조체를 이용하여 프로그램 구조를 작성하는 방법 )

		구조화 프로그래밍의 대표적인 도구가 '함수 function'이다.

		추상화 abstraction : 임의의 항목들을 묶어놓고 이름을 붙이는 행위
		일반화 generalization : 성질이 같은 임의의 대상들을 하나의 대표적인 상징을 통해 다루는 행위


	함수 : 기능 부품
			y = ax +b 독립변수와 종속변수 사이의 관계식
			독립변수에 input을 넣으면 종속변수의 output이 결정된다
			<-- 즉, 입력에 대한 어떤 처리를 하여 출력을 만드는 것

	함수 : 코드(제어구조)의 추상화


		함수 정의의 형태는 이와 같다.

			리턴타입 함수이름(매개변수타입 매개변수이름, ...)
			{
				//원하는 명령문들

				return 호출측에 돌려줄 값;
			}

	함수사용의 3단계
	    선언 : ( 호출할 측에 )함수의 형태를 알려주는 것
	    정의 : 함수의 실제 동작을 만드는 것
	    호출 : 함수를 실행하는 것  <-- 함수이름으로 한다.


*/

//함수의 선언
int DoAddictive(int tA, int tB);
int DoSubtract(int tA, int tB);

int main()
{

	int tA = 3;
	int tB = 2;

	int tResult = 0;


	//사칙연산
	//+
	//DoAddictive
	tResult = DoAddictive(tA, tB);//tA + tB;
	printf("addictive : %d\n", tResult);

	//-
	tResult = DoSubtract(tA, tB);//tA - tB;
	printf("subtract : %d\n", tResult);

	//*
	tResult = tA * tB;
	printf("multiply : %d\n", tResult);

	// /
	float tResult0 = 0.0f;
	tResult0 = (float)tA / (float)tB;
	printf("division : %f\n", tResult0);
	
	
	
	return 0;
}

//함수의 정의
int DoAddictive(int tA, int tB) 
{
	int tResult = 0;
	tResult = tA + tB;

	return tResult;
}

int DoSubtract(int tA, int tB)
{
	int tResult = 0;
	tResult = tA - tB;

	return tResult;
}