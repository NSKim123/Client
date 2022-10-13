
#include <stdio.h>

/*


	재귀호출
	자기자신을 호출한다.

	'전체 구조'와 같은 '부분구조'가
	전체구조에 포함되어 있다면
	이것은 재귀호출로 만들 수 있다.

*/

unsigned int DoFactorial(unsigned int tN);
unsigned int DoFactorialNoReculsive(unsigned int tN); //비재귀버전의 함수

int main()
{
	int tA = 4;
	int tResult = 0;
	tResult = DoFactorial(tA);

	printf("4!의 결과값: %d\n", tResult);

	tResult = DoFactorialNoReculsive(tA);

	printf("(No Reculsive) 4!의 결과값: %d\n", tResult);

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
	i) 함수 호출 비용이 든다( 속도가 느리다 )
	ii) 스택 오버 플로우 stack over flow : 스택 메모리가 모자랄 수도 있다.

	재귀호출의 장점
	i) 코드가 심미적이다..

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
/*

비재귀버전의 함수 호출의 장점(vs 재귀호출)
i) 함수호출 비용이 들지 않는다.
ii) 선언된 지역변수(매개변수도)만큼의 메모리만 사용한다.

*/
unsigned int DoFactorialNoReculsive(unsigned int tN)
{
	if (0 == tN)
	{
		return 1;
	}
	else
	{
		unsigned int tTemp = 1;  //재귀호출버전의 함수에서 암묵적으로 표현되던 결과값을 담는 메모리가 여기서는 변수로 명시적으로 표현되었다.
		unsigned int ti = 0;
		//재귀호출되는 부분이 반복제어구조로 변경되었다.
		for (ti=tN;ti>0;--ti)
		{
			tTemp = tTemp * ti;
		}
		return tTemp;
	}
}