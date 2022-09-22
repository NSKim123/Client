
#include <stdio.h>

/*
	sizeof 연산자

	---> 변수가 타입에 따라 메모리가 어떻게(얼마만큼) 확보되는지 살펴보자

*/

int main()
{
	char tChar = 0;
	int tInt = 0;

	//sizeof 연산자 : 타입이나 변수의 메모리 크기를 얻어온다.( byte 단위 )
	printf("%d\n", (unsigned int)sizeof(tChar));  //1byte ==8bit
	//256개의 경우를 표현 가능
	//음의 정수를 포함하지 않는다면 0~255
	//음의 정수까지 포함한다면 -128~127
	printf("%d\n", (unsigned int)sizeof(tInt)); //4byte == 32bit
	//4,294,967,296 = 2^32
	//음의 정수를 포함하지 않는다면 0~(2^32-1)
	//음의 정수까지 포함한다면 -2^31 ~ 2^31-1
	
	short int tShortInt = 0;
	long int tLongInt = 0;
	long long int tLongLongInt = 0;


	printf("%d\n", (unsigned int)sizeof(tShortInt));    //2byte == 16bit
	printf("%d\n", (unsigned int)sizeof(tLongInt));     //4byte == 32bit
	printf("%d\n", (unsigned int)sizeof(tLongLongInt)); //8byte == 64bit

	float tFloat = 0.0f;
	double tDouble = 0.0; //보다 높은 정밀도의 실수를 표현

	printf("%d\n", (unsigned int)sizeof(tFloat));     //4byte == 32bit
	printf("%d\n", (unsigned int)sizeof(tDouble));    //8byte == 64bit






	return 0;
}