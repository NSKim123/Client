
#include <stdio.h>
#include <stdlib.h> //malloc, free


/*

	메모리의 동적할당과 해제

	void* malloc( size_t size ) 

	주어진 매개변수 숫자만큼 '바이트' 단위로 메모리를 동적으로(실행중에, dynamic, runtime) 할당(확보)하고 해당 메모리의 '주소'를 반환한다.


	free   주어진 포인터 변수를 참조(주소가 붙은 메모리에 접근)하여, 동적할당된 메모리를 해제(메모리소유권해제)한다. 

	이것은 표준 '함수' 이다.

	메모리의 동적할당과 해제의 기능을 수행한다.
	이렇게 할당된 메모리는 '힙'메모라애 위치하게 된다.

	stack frame vs Dynamaic Memory Allocation
*/

int main()
{
	//step_0
	//스택 메모리는 응용프로그램마다 사용하는 크기가 운영체제에 의해 정해져있다.
	//그래서, 규모가 큰 응용프로그램을 스택만을 사용하여 만드는 것에는 한계가 있다.
	//char tArray[1000100];
	//char tArray[9000100];   스택오버플로우

	//step_1
	char* tpA = NULL;
	tpA = (char*)malloc(sizeof(char) * 9000100); //힙메모리 동적할당
		  //malloc 함수는 void 타입이므로 char*로 형변환 해야한다.

	if (NULL != tpA) //널 체크
	{
		//동적할당한 메모리 해제
		free(tpA);
		tpA = NULL;
	}



	//step_2
	//힙메모리에 int 타입의 변수를 1개 만들고
	//값을 777로 설정하자

	int* tpB = NULL;
	tpB = (int*)malloc(sizeof(int) * 1); 
	
	if (NULL != tpB)
	{
		*tpB = 777; //간접참조

		printf("%d\n", *tpB);
	}

	if (NULL != tpB) 
	{
		free(tpB);
		tpB = NULL;
	}

	return 0;
}