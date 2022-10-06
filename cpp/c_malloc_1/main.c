
#include <stdio.h>
#include <stdlib.h>


/*

	managed ----> java, C#

	vs

	unmanaged ----> C/C++


	메모리 누수 momory leak : 할당된 메모리가 해제되지 않고 남아있는 것

*/

void CreateRyu(int* tpPtr);
void DestroyRyu(int* tpPtr);

void CreateRyu_0(int** tpPtr);
void DestroyRyu_0(int** tpPtr);

int main()
{
	//step_0
	//힙메모리에 int 타입의 변수를 100개 만들고 해제하세요.
	/*int* tpA = NULL;
	tpA = (int*)malloc(sizeof(int) * 100);

	if (NULL != tpA)
	{
		free(tpA);
		tpA = NULL;
	}
	*/


	//step_1

	//해당 코드는 메모리 누수가 발생한다.
	int* tpA = NULL;
	//CreateRyu(tpA);
	//DestroyRyu(tpA);


	//step_2
	//step_1의 문제점을 해결하자
	CreateRyu_0(&tpA);
	DestroyRyu_0(&tpA);

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