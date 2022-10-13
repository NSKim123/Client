
#include <stdio.h> //헤더파일이라고 부름

void DoSwap(int tA, int tB);

void DoSwapPtr(int* tpA, int* tpB);

int main()
{
	//step_0
	//두 정수의 값의 교환

	/*
	int tA = 3;
	int tB = 2;

	//교환 루틴
	int tTemp = 0;
	tTemp = tA;
	tA = tB;
	tB = tTemp;

	printf("tA: %d, tB: %d\n", tA, tB);

	//void DoSwap(int tA, int tB) 만들어보기 (callbyvalue 때문에 실제로 매개변수가 swap 되는 것이고 여기 main함수의 지역변수는 swap 되지 않음)
	DoSwap(tA, tB);

	printf("tA: %d, tB: %d\n", tA, tB);
	*/

	//step_1
	int tA = 3;
	int tB = 2;

	//교환 루틴
	DoSwapPtr(&tA, &tB);

	printf("tA: %d, tB: %d\n", tA, tB);


	return 0;
}

void DoSwap(int tA, int tB)
{
	int tTemp = 0;
	tTemp = tA;
	tA = tB;
	tB = tTemp; 
}
//call by address(pointer)
void DoSwapPtr(int* tpA, int* tpB)
{
	int tTemp = 0;
	tTemp = *tpA;
	*tpA = *tpB;
	*tpB = tTemp;
}
