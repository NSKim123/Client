
#include <stdio.h>
#include <stdlib.h>


/*

	managed ----> java, C#

	vs

	unmanaged ----> C/C++


	�޸� ���� momory leak : �Ҵ�� �޸𸮰� �������� �ʰ� �����ִ� ��

*/

void CreateRyu(int* tpPtr);
void DestroyRyu(int* tpPtr);

void CreateRyu_0(int** tpPtr);
void DestroyRyu_0(int** tpPtr);

int main()
{
	//step_0
	//���޸𸮿� int Ÿ���� ������ 100�� ����� �����ϼ���.
	/*
	int* tpA = NULL;
	tpA = (int*)malloc(sizeof(int) * 100);

	if (NULL != tpA)
	{
		free(tpA);
		tpA = NULL;
	}
	*/


	//step_1

	//�ش� �ڵ�� �޸� ������ �߻��Ѵ�.
	int* tpA = NULL;
	//CreateRyu(tpA);
	//DestroyRyu(tpA);


	//step_2
	//step_1�� �������� �ذ�����
	CreateRyu_0(&tpA);
	DestroyRyu_0(&tpA);



	//step_3
	//��۸� ������ dangling pointer
	int* tpB = NULL;
	int* tpC = NULL;

	tpB = (int*)malloc(sizeof(int) * 64);
	tpC = tpB;

	if (NULL != tpB)
	{
		free(tpB);
		tpB = NULL;
	}
	//���� ������ ���� tpC�� ��۸� dangling �Ǿ���.
	//	(����Ű�� �ּҰ��� �ִµ� , ���� �� �ּ��� �޸𸮿��� �Ҵ�� ���� ����)
	//  -----> ���� ����Ϸ��� �ϸ� �޸� ���� ������ ����.

	printf("tpB�� �ּҰ�: %p\n", tpB);
	printf("tpC�� �ּҰ�: %p\n", tpC);

	return 0;
}

void CreateRyu(int* tpPtr) 
{
	tpPtr = (int*)malloc(sizeof(int) * 100);
}
void DestroyRyu(int* tpPtr)
{
	if (NULL != tpPtr)
	{
		free(tpPtr);
		tpPtr = NULL;
	}
}

void CreateRyu_0(int** tpPtr)
{
	*tpPtr = (int*)malloc(sizeof(int) * 100);
}
void DestroyRyu_0(int** tpPtr)
{
	if (NULL != *tpPtr)
	{
		free(*tpPtr);
		*tpPtr = NULL;
	}
}