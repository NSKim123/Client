
#include <stdio.h>

int main()
{
	int tArray_0[5] = { 0 };


	//step_0
	int* tArray[5] = { NULL, NULL, NULL, NULL, NULL}; // int (*tArray)[5]�� �򰥸��� �� ��!
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
	
	printf("tA�� �ּҰ� : %p\n", &tA);
	printf("tB�� �ּҰ� : %p\n", &tB);

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
	int** tArray_1[5] = {NULL}; //������Ÿ�� ������ �ּҰ��� ��� �����͵��� �迭

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

	printf("tpPtr�� �ּҰ� : %p\n", &tpPtr);
	printf("tpPtr�� �� : %p\n", tpPtr);
	printf("tX�� �ּҰ� : %p\n", &tX);

	printf("before: %d\n", tX);
	**(tArray_1[0]) = 64;
	printf("after: %d\n", tX);


	return 0;
}