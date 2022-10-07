
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



	//step_3
	//댕글링 포인터 dangling pointer
	int* tpB = NULL;
	int* tpC = NULL;

	tpB = (int*)malloc(sizeof(int) * 64);
	tpC = tpB;

	if (NULL != tpB)
	{
		free(tpB);
		tpB = NULL;
	}
	//이제 포인터 변수 tpC는 댕글링 dangling 되었다.
	//	(가리키는 주소값은 있는데 , 실제 그 주소의 메모리에는 할당된 것이 없다)
	//  -----> 만약 사용하려고 하면 메모리 참조 에러를 낸다.

	printf("tpB의 주소값: %p\n", tpB);
	printf("tpC의 주소값: %p\n", tpC);

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