
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
	//���޸𸮿� �������� �޸𸮸� Ȯ���Ѵ�
	//�׷��Ƿ� �����ͺ����� ������ ���� �����ڸ� ����Ͽ� ������ ������ ������ �� �ִ�.
	tpPtr = (int*)malloc(sizeof(int) * 3);

	if (NULL != tpPtr)
	{
		//������ ���� �����ڷ� ������ �޸𸮿� �����Ͽ� ���� �����غ���.
		*(tpPtr + 0) = 777; // tpPtr �� + 0*sizeof(int)
		*(tpPtr + 1) = 999; // tpPtr �� + 1*sizeof(int)
		*(tpPtr + 2) = 64;  // tpPtr �� + 2*sizeof(int)

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
	//������(�������� dynamic, runtime)�� �������� �޸� ���� ũ�⸦ ���� �� �ִ�. (���ù迭�� �Ұ���)
	//���ù迭�� compiletime�� ũ�Ⱑ �����ȴ�.
	int tMemorySize = 0;
	tMemorySize = 5;

	//���ù迭�� ������ ���� ����� �迭�� ũŰ�� �����ؾ߸� �Ѵ�.
	//int tArray_0[tMemorySize];   ---> ����

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
	//����ü�� ����� �����Ҵ� �����غ���
	/*
	�䱸����

		1)SBrave �̸����� ����ü�� �����.
		��������� int mX, int mY

		2)DisplayBraveInfo
		SBrave Ÿ���� ������ ����������� ���� ����ϴ� �Լ��� �����.

		3)SBraveŸ���� ������ '��'�� �Ҵ��Ѵ�.
		�ش� ������ ��������� ���� �����ϰ� ȭ�鿡 ����Ѵ�.
	
	*/

	SBrave* tpBrave = NULL;
	tpBrave = (SBrave*)malloc(sizeof(SBrave) * 1);

	if (NULL != tpBrave)
	{
		/*
		(*tpBrave).mX = 200;
		(*tpBrave).mY = 300;
		*/
		tpBrave->mX = 200; // -> ������ ��� ���� ������
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