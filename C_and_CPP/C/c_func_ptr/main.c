
#include <stdio.h>

/*

	함수 포인터 

		포인터 변수 : 주소를 값으로 가지는 변수
		
*/


int DoAdditive(int tA, int tB);

int main()
{
	int tA = 3;
	int tB = 2;
	int tResult = 0;

	//step_0
	//함수 포인터의 선언 : 함수의 형태를 가지고 선언한다.
	int (*tpPtr)(int, int) = NULL;


	tpPtr = DoAdditive;


	//tResult = DoAdditive(tA, tB); //함수를 호출 (직접호출)
	tResult = tpPtr(tA, tB);		//함수 포인터를 이용하여 간접호출
	
	printf("tResult : %d\n", tResult);


	//step_1
	//함수포인터와 typedef
	//typedef A B    typedef unsigned int RYU_INT

	//typedef을 함수포인터의 선언구문과 함께 써주면 이름 부분이 타입처럼 취급된다.
	typedef int (*FuncPtrRyu)(int, int);
	
	FuncPtrRyu tpRyu; 
	tpRyu = DoAdditive;

	tResult = tpRyu(tA, tB);
	printf("tResult : %d\n", tResult);


	return 0;
}

int DoAdditive(int tA, int tB)
{
	int tResult = 0;

	tResult = tA + tB;

	return tResult;
}