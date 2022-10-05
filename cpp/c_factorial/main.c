
#include <stdio.h>

/*


	재귀호출
	자기자신을 호출한다.

	'전체 구조'와 같은 '부분구조'가
	전체구조에 포함되어 있다면
	이것은 재귀호출로 만들 수 있다.

*/

unsigned int DoFactorial(unsigned int tN);

int main()
{
	int tA = 4;
	int tResult = 0;
	tResult = DoFactorial(tA);

	printf("4!의 결과값: %d\n", tResult);

	return 0;
}

//함수의 정의가 끝나지 않았음에도 불구하고
//해당 함수를 호출하고 있다.
/*
이것이 가능한 이유는 함수의 정의도 메모리에 있기 떄문이다.
함수 호출은 함수의 이름으로 하는데
함수의 이름은 주소를 나타낸다.
즉, 함수호출을 하면 해당 함수의 정의부의 시작부분으로 가서 명령문을 실행한다.
*/

/*
 
	재귀호출의 단점
	i)함수 호출 비용이 든다( 속도가 느리다 )
	ii)스택 오버 플로우 stack over flow : 스택 메모리가 모자랄 수도 있다.

	재귀호출의 장점
	i)코드가 심미적이다..

*/
unsigned int DoFactorial(unsigned int tN)
{
	if (0 == tN) 
	{
		//base case ( 재귀호출의 종료조건이라고 생각하면 된다.)
		return 1;
	}
	else 
	{
		//reculsive case
		return tN * DoFactorial(tN - 1);
	}
}