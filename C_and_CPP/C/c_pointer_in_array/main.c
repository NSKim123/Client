
#include <stdio.h>

int main()
{
	int tArray_0[5] = { 0 };


	//step_0
	int* tArray[5] = { NULL, NULL, NULL, NULL, NULL}; // int (*tArray)[5]과 헷갈리지 말 것!
	int ti = 0;
	for (ti = 0; ti < 5; ++ti)
	{
		printf("%p\n", tArray[ti]);
	}

	int tA = 777;
	int tB = 333;

	tArray[0] = &tA;
	tArray[1] = &tA;
	tArray[3] = &tB;
	
	printf("tA의 주소값 : %p\n", &tA);
	printf("tB의 주소값 : %p\n", &tB);

	for (ti = 0; ti <5 ; ++ti)
	{
		printf("%p\n", tArray[ti]);
	}

	for (ti = 0; ti < 5; ++ti)
	{
		if (NULL != tArray[ti])
		{
			printf("%d\n", *tArray[ti]);

		}
	}

	printf("\n\n");

	//step_1
	int** tArray_1[5] = {NULL}; //포인터타입 변수의 주소값을 담는 데이터들의 배열

	for (ti = 0; ti < 5; ++ti)
	{
		printf("%p\n", tArray_1[ti]);
	}

	int* tpPtr = NULL;
	int tX = 1024;

	tpPtr = &tX;
	
	for (ti = 0; ti < 5; ++ti)
	{
		tArray_1[ti] = &tpPtr;
	}

	printf("\n");

	for (ti = 0; ti < 5; ++ti)
	{
		printf("%p\n", tArray_1[ti]);
	}

	printf("tpPtr의 주소값 : %p\n", &tpPtr);
	printf("tpPtr의 값 : %p\n", tpPtr);
	printf("tX의 주소값 : %p\n", &tX);

	printf("before: %d\n", tX);
	**(tArray_1[0]) = 64;
	printf("after: %d\n", tX);


	return 0;
}