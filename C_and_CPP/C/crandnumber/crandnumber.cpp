

#include <iostream>
using namespace std;

/*
	난수 random number 

	임의의 불규칙적으로 생성되는 수


	게임 프로그램에서
	현실에 존재하는 '불확실성' 을 표현하기 위한 수단으로 
	'난수' 라는 개념을 사용하겠다.


	컴퓨터에서 제공하는 난수는
	실제 세계의 진짜 불확실한 랜덤한 수가 아니라
	흉내를 내는 것이다.



	내부적으로는 다음과 같이 동작한다.

	난수의 씨앗 seed를 뿌리면
	해당씨앗을 기반으로 난수의 나열을 만든다.

	rand 함수를 사용하면 , <-- 함수(기능부품)
	위에 만든 난수의 나열된 수들중에서 하나씩 가져온다.
*/


int main()
{
	//step_0
	//난수의 씨앗을 뿌린다
	//srand(7);

	//int tResult = 0;

	//tResult = rand(); //난수를 하나 얻는다
	//cout << tResult << endl;

	//tResult = rand(); //난수를 하나 얻는다
	//cout << tResult << endl;

	//tResult = rand(); //난수를 하나 얻는다
	//cout << tResult << endl;



	//step_1
	//unsignde int : nonnegative integer
	//srand((unsigned int)time(nullptr));



	//int tResult = rand();
	//cout << tResult << endl;

	//tResult = rand();
	//cout << tResult << endl;
	//
	//tResult = rand();
	//cout << tResult << endl;



	//step_2
	//MOD 나머지 연산 moduio 연산, 연산자 %
	/*
		2/2 = 1   몫이 1
		3/2 = 1.5 몫은 1, 나머지는 1
		5/2 = 2.5 몫은 2, 나머지는 1




		2%2 = 0 
		3/2 = 1
		5/2 = 1

		==============================
		
		0%3 = 0
		1%3 = 1
		2%3 = 2
		3%3 = 0
		4%3 = 1
		5%3 = 2
		. . .




	*/

	//srand((unsigned int)time(nullptr));

	//int tResult = 0;

	//tResult = rand() % 3;
	//cout << tResult << endl;

	//tResult = rand() % 5;
	//cout << tResult << endl;


	//step_3
	//육면체 주사위
	srand((unsigned int)time(nullptr));

	int tResult = 0;

	//육면체 주사위를 던져서 나온 수( 1, 2, 3, 4, 5, 6 )
	int ti = 0;

	for ( ti = 0; ti<10 ; ti++)
	{
		tResult = rand() % 6 + 1;
		cout << tResult << endl;
	}
	



	return 0;
}


