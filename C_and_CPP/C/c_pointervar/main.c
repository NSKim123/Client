
#include <stdio.h>

/*

	포인터 변수
	: '주소'를 '값'으로 가지는 '변수'



*/
//int tA = 0;    정수 타입의 '값'을 가지는 '변수'

int main()
{
	int tA = 777;
	//tpA에는 주소의 값이 담기고, 그 주소값은 임의의 메모리의 주고인데 그 메모리는 int 타입 일것으로 기대한다
	//int* 까지가 타입이다.
	int* tpA = NULL;    //여기서 * 기호는 포인터 변수를 '선언'하는 연산자이다.
	//포인터 변수는 널 로 초기화한다.

	tpA = &tA; //& : 주소 연산자


	int tB = 0;
	tB = *tpA;  //간접참조연산자(번지 지정 연산자)
	//여기서 *는 포인터 변수가 가리키는 곳의 변수(메모리)를 참조하는 연산자이다.
	//그리고, 대입연산자(=)의 오른쪽에 위치했으므로 해당 메모리에 값을 가져온다.
		//tpA에 들어있는 값을 가지는 주소로가서 참조하라.
		//--> tA를 참조할 것임. 
	printf("tA : %d\n", tA);
	printf("tB : %d\n", tB);


	printf("tpA의 값:\t %p\n", tpA);
	printf("tpA의 주소의 값:\t %p\n", &tA); //\t : 탭

	return 0;
}