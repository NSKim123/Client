
#include <stdio.h>

/*

	함수가 매개변수를 넘기는 기본방식은 call by value 이다.


	두 정수의 swap 교환

*/

// void : 아무것도 리턴하지 않는다.
void DoSwap(int tA, int tB);

int main()
{
	//step_0
	/*
	int tA = 3;
	int tB = 2;


	//before
	printf("tA: %d\n", tA);
	printf("tB: %d\n", tB);

	//두 정수의 값 교환
	int tTemp = 0;  //임시적으로 값을 저장해줄 변수가 하나 필요하다.

	tTemp = tA;
	tA = tB;
	tB = tTemp;

	//after
	printf("tA: %d\n", tA);
	printf("tB: %d\n", tB);
	*/

	

	//step_1
	int tA = 3;
	int tB = 2;


	//before
	printf("tA: %d\n", tA);
	printf("tB: %d\n", tB);


	//void DoSwap
	DoSwap(tA, tB);  //변수 tA,tB를 call by value로 받고, DoSwap이 끝나면 매개변수 tA와 tB는 사라지므로 swap이 안일어난다.

	

	//after
	printf("tA: %d\n", tA);
	printf("tB: %d\n", tB);

	return 0;
}

//call(pass) by value
void DoSwap(int tA, int tB)
{
	int tTemp = 0;

	tTemp = tA;
	tA = tB;
	tB = tTemp;
}