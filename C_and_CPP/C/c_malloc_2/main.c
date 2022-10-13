
#include <stdio.h>
#include <stdlib.h>


typedef struct Brave
{
	int mX;
	int mY;
} SBrave;

void DIsplayBraveInfo(SBrave* tBrave);

int main()
{
	int tArray[3] = { 777, 999, 64 };
	int ti = 0;
	for (ti = 0; ti < 3; ++ti)
	{
		printf("%d\n", tArray[ti]);
	}

	printf("\n");

	int* tpPtr = NULL;
	//힙메모리에 연속적인 메모리를 확보한다
	//그러므로 포인터변수와 포인터 증감 연산자를 사용하여 임의의 변수에 접근할 수 있다.
	tpPtr = (int*)malloc(sizeof(int) * 3);

	if (NULL != tpPtr)
	{
		//포인터 증감 연산자로 각각의 메모리에 접근하여 값을 대입해본다.
		*(tpPtr + 0) = 777; // tpPtr 값 + 0*sizeof(int)
		*(tpPtr + 1) = 999; // tpPtr 값 + 1*sizeof(int)
		*(tpPtr + 2) = 64;  // tpPtr 값 + 2*sizeof(int)

		for (ti = 0; ti < 3; ++ti)
		{
			printf("%d\n", *(tpPtr + ti));
		}
	}


	if (NULL != tpPtr)
	{
		free(tpPtr);
		tpPtr = NULL;
	}



	//step_1
	//실행중(동적으로 dynamic, runtime)에 연속적인 메모리 블럭의 크기를 정할 수 있다. (원시배열은 불가능)
	//원시배열은 compiletime에 크기가 결정된다.
	int tMemorySize = 0;
	tMemorySize = 5;

	//원시배열을 선언할 때는 상수로 배열의 크키를 고정해야만 한다.
	//int tArray_0[tMemorySize];   ---> 오류

	int* tpPtr_0 = NULL;
	tpPtr_0 = (int*)malloc(sizeof(int) * tMemorySize);

	if (NULL != tpPtr_0)
	{
		for(ti = 0; ti < tMemorySize; ++ti)
		{
			*(tpPtr_0 + ti) = ti;
		}

		for (ti = 0; ti < tMemorySize; ++ti)
		{
			printf("ti: %d\n", *(tpPtr_0 + ti));
		}
	}

	if (NULL != tpPtr_0)
	{
		free(tpPtr_0);
		tpPtr_0 = NULL;
	}


	//step_2
	//구조체를 만들고 동적할당 적용해보기
	/*
	요구사항

		1)SBrave 이름으로 구조체를 만든다.
		멤버변수는 int mX, int mY

		2)DisplayBraveInfo
		SBrave 타입의 변수의 멤버변수들의 값을 출력하는 함수를 만든다.

		3)SBrave타입의 변수는 '힙'에 할당한다.
		해당 변수의 멤버변수에 값을 설정하고 화면에 출력한다.
	
	*/

	SBrave* tpBrave = NULL;
	tpBrave = (SBrave*)malloc(sizeof(SBrave) * 1);

	if (NULL != tpBrave)
	{
		/*
		(*tpBrave).mX = 200;
		(*tpBrave).mY = 300;
		*/
		tpBrave->mX = 200; // -> 포인터 멤버 접근 연산자
		tpBrave->mY = 300;
		DIsplayBraveInfo(tpBrave);
	}

	if (NULL != tpBrave)
	{
		free(tpBrave);
		tpBrave = NULL;
	}

	return 0;
}

void DIsplayBraveInfo(SBrave* tBrave)
{
	printf("X : %d\n", (*tBrave).mX);
	printf("Y : %d\n", (*tBrave).mY);
}