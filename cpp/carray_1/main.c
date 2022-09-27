
#include <stdio.h>

/*

	(원시)배열 : 동일한 타입의 원소들의 (물리적으로) 연속적인 메모리 블럭
	
*/

//배열을 매개변수로 넘기는 표기법
void DoChangeElement(int tArray[], int tIndex, int tValue);

int main()
{
	int tArray[5] = {0,0,0,0,0};

	tArray[0] = 4;
	tArray[1] = 0;
	tArray[2] = 1;
	tArray[3] = 2;
	tArray[4] = 3;

	int ti = 0;
	for (ti = 0; ti < 5; ti++)
	{
		printf("%d\n", tArray[ti]);
	}

	printf("\n");


	//step_0
	/*
	
	tArray[0] = 777;

	for (ti = 0; ti < 5; ti++)
	{
		printf("%d\n", tArray[ti]);
	}
	
	*/

	//step_1
	//void DoChangeElement(int tArray[],int tIndex, int tValue);
	//배열의 이름은 배열의 시작주소의 값을 나타낸다.
	//여기서는 배열의 이름을 넘겨준다. (call by value 가 아니다.)
	DoChangeElement(tArray, 0, 777); 

	for (ti = 0; ti < 5; ti++)
	{
		printf("%d\n", tArray[ti]);
	}

	return 0;
}

void DoChangeElement(int tArray[], int tIndex, int tValue)
{
	tArray[tIndex] = tValue;
}