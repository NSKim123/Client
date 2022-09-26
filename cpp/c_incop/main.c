#include <stdio.h>


/*
	증감 연산자

	증가, 감소

	전위
	후위

	증감 연산자들이 '단독'으로 쓰이면 전위와 후위가 의미가 같지만
	다른 연산들과 혼합되어 쓰이면 의미가 달라진다.
	

*/

int main()
{
	//step_0

	int tX = 1;
	printf("tX : %d\n", tX);			//tX는 1을 출력

	tX++;  //후위 증가 연산자
	printf("tX : %d\n", tX);			//tX는 2를 출력

	++tX;  //전위 증가 연산자
	printf("tX : %d\n", tX);			//tX는 3을 출력

	tX--;  //후위 감소 연산자
	printf("tX : %d\n", tX);			//tX는 2를 출력

	--tX;  //전위 감소 연산자
	printf("tX : %d\n", tX);			//tX는 1을 출력



	printf("\n");



	//step_1
	// 
	//전위 증감 연산자의 경우는 해당 연산을 수행한 후, 다른 연산을 수행한다.
	//후위 증감 연산자의 경우는 다른 연산을 수행한 후, 해당 연산을 수행한다.

	tX = 1;

	printf("tX : %d\n", tX++);			//tX 는 1을 출력, 이 줄을 지나면 tX의 값은 2
	printf("tX : %d\n", tX++);			//tX 는 2를 출력, 이 줄을 지나면 tX의 값은 3
	printf("tX : %d\n", ++tX);			//tX 는 4를 출력, 이 줄을 지나면 tX의 값은 4
	printf("tX : %d\n", tX--);			//tX 는 4를 출력, 이 줄을 지나면 tX의 값은 3
	printf("tX : %d\n", tX--);			//tX 는 3을 출력, 이 줄을 지나면 tX의 값은 2
	printf("tX : %d\n", --tX);			//tX 는 1을 출력, 이 줄을 지나면 tX의 값은 1
	

	printf("\n");


	//step_2
	tX = 1;
	int tA = tX++;  //tA = 1 대입되고, tX = tX + 1;
	tX = 1;
	int tB = ++tX;	//tX = tX + 1되고 , tB = 2 대입

	//전위 증감 연산자가 일반적으로 후위 증감 연산자보다 빠르다.
	//왜냐하면 컴파일 된 후에 생기는 명령문의 갯수가 후위 증감 연산자가 더 많기 떄문이다.

	printf("tA : %d\n", tA); //1
	printf("tB : %d\n", tB); //2


	//p.s

	int tY = 0;
	//tY = tY + 10;
	tY += 10;
	//tY = tY - 3;
	tY -= 3;


	return 0;
}