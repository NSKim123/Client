

#include <iostream>
using namespace std;

/*
	for 예약어를 이용한 반복제어구조

	for(초기식;조건식;증감식)
	{
		//명령문들
	}


	//loop body

*/
int main()
{
	//for 예약어를 사용하는 문법
	int ti = 0;
	for (ti=0 ; ti<5 /*1*/; ti = ti + 1 /*3*/)  
	{
		/*2*/	cout << ti << endl;  //1->2->3 순으로 작동하고, 조건식이 거짓일때 탈출
	}


	cout << endl;

	//변형 연습해보기
	cout << "good" << endl;
	cout << "good" << endl;
	cout << "good" << endl;

	cout << endl;

	int tj = 0;
	for (tj = 0; tj < 3; tj++)
	{
		cout << "good" << endl;
	}

	//수식 : 수(숫자)로 이루어진 식.
	//대수식 : 숫자 대신 문자로 이루어진 식
	//방정식 : 미지수의 해를 구하는 것이 목적인 대수식.
	//함수 : 독립변수와 종속변수 사이의 관계를 나타내는 것이 목적인 대수식
	

	//구구단을 프로그램 코드로 만들어보자.
	/*
		구체적인 사실 하나를 예시해보자.
		2단을 가정해보자.
	
		2*1=2 (피승수) * (승수) = (결과값)
		2*2=4
		2*3=6
		2*4=8
		2*5=10
		2*6=12
		2*7=14
		2*8=16
		2*9=18
		
		피승수 --> 상수
		승수 --> 변수
		결과값 --> 변수
		(고정되어 나타나는 부분과 변화하며 나타나는 부분을 잘 구분짓는다.)

		타입은 정수

		2*tk = tResult (대수식)

		*/

	cout << endl << endl;
	//step_0
	//쌩으로 만들어보기 (순차처리를 이용하여 만들어보자.)
	int tk = 0;
	int tResult = 0;

	//1
	tk = 1;

	tResult = 2 * tk;
	cout << "2" << "*" << tk << "=" << tResult << endl;

	//2
	tk = tk+1;

	tResult = 2 * tk;
	cout << "2" << "*" << tk << "=" << tResult << endl;

	//3
	tk = tk + 1;

	tResult = 2 * tk;
	cout << "2" << "*" << tk << "=" << tResult << endl;
	
	//4
	tk = tk + 1;

	tResult = 2 * tk;
	cout << "2" << "*" << tk << "=" << tResult << endl;

	//5
	tk = tk + 1;

	tResult = 2 * tk;
	cout << "2" << "*" << tk << "=" << tResult << endl;

	//6
	tk = tk + 1;

	tResult = 2 * tk;
	cout << "2" << "*" << tk << "=" << tResult << endl;

	//7
	tk = tk + 1;

	tResult = 2 * tk;
	cout << "2" << "*" << tk << "=" << tResult << endl;

	//8
	tk = tk + 1;

	tResult = 2 * tk;
	cout << "2" << "*" << tk << "=" << tResult << endl;

	//9
	tk = tk + 1;

	tResult = 2 * tk;
	cout << "2" << "*" << tk << "=" << tResult << endl;

	cout << endl << endl;

	//step_1
	//for문을 이용하여 2단을 위의 코드의 결과와 같은 형태대로 출력

	
	for (tk = 1; tk < 10; tk = tk + 1)
	{
		tResult = 2 * tk;
		cout << "2" << "*" << tk << "=" << tResult << endl;
	}


	cout << endl << endl;

	for (tk=1;tk<=9;tk=tk+1)
	{
		tResult = 2 * tk;
		cout << "2" << "*" << tk << "=" << tResult << endl;
	}

	cout << endl << endl;
	//step_2
	//다른 단도 만들어보자

	for (tk = 1; tk <= 9; tk = tk + 1)
	{
		tResult = 3 * tk;
		cout << "3" << "*" << tk << "=" << tResult << endl;
	}

	cout << endl << endl;

	for (tk = 1; tk <= 9; tk = tk + 1)
	{
		tResult = 4 * tk;
		cout << "4" << "*" << tk << "=" << tResult << endl;
	}
	cout << endl << endl;


	//step_3
	//구구단

	int tm = 0;
	for (tm=2;tm<=9;tm=tm+1)
	{
		for (tk = 1; tk <= 9; tk = tk + 1)
		{
			tResult = tm * tk;
			cout << tm << "*" << tk << "=" << tResult << endl;
		}
		cout << endl;
	}
	cout << endl << endl;
	return 0;
}

