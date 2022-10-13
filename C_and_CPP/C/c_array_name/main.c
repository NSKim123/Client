
#include <stdio.h>
/*

	(원시)배열 : 동일한 타입의 원소들의 (물리적으로) 연속적인 메모리 블럭

	C언어 배열의 이모저모를 살펴보자
*/


DoChangeElement(int tArray[], int tindex, int tValue);

int main()
{
	//step_0
	int tArray[5] = { 4, 0, 1, 2, 3 };

	int ti = 0;
	for (ti=0;ti<5;++ti)
	{
		printf("%d\n", tArray[ti]);
	}

	printf("\n");


	DoChangeElement(tArray, 0, 777); //'배열의 이름'은 '배열의 시작주소값'을 나타내도록 만들어져 있다.

	for (ti = 0; ti < 5; ++ti)
	{
		printf("%d\n", tArray[ti]);
	}


	//step_1
	// 원시 배열의 원소의 갯수 구하기
	//sizeof 연산자 : 데이터의 크기를 바이트 단위로 알려준다.
	int tA = sizeof(tArray);
	int tB = sizeof(tArray[0]);

	printf("tA: %d\n", tA); //배열에서 sizeof의 작동, 배열의 이름을 넣으면 배열의 전체크기를 바이트 단위로 알려준다.
	printf("tB: %d\n", tB); 
	
	int tArrayLength = tA / tB;

	printf("\n");

	//step_2
	int tArray_0[5] = {0};     //0으로 초기화를 다음 표기법으로 간략하게 할 수도 있다.


	//step_3
	//다음 세가지는 동일한 코드이다.
	printf("%p\n", &tArray_0);
	printf("%p\n", &tArray_0[0]);
	printf("%p\n", tArray_0); //배열의 이름은 배열 시작 주소의 값을 나타낸다.   <--  상수 포인터의 성질을 띄고 있다.



	return 0;
}

// 첫번째 매개변수는 배열타입(?)이므로 주소의 값을 전달 받는다.
DoChangeElement(int tArray[], int tindex, int tValue)
{
	//인덱스 접근 연산자의 실체는 배열의 이름(시작주소값)을 기준으로 몇개의 원소를 건너갈지 결정하는 것이다.
	tArray[tindex] = tValue;
}