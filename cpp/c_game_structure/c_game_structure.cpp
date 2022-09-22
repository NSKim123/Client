

#include <iostream>

using namespace std;

/*
	'게임 프로그램의 구조'는
	'일반적인 응용프로그램 구조'와는 특성에 차이를 보인다.

	게임 프로그램 구조에는
	'게임루프 game loop' 라는 핵심적인 구조가 들어간다.

	게임루프는
	'게임세계'가
	끊임없이 '갱신'되도록 하는 구조이다
	(일반적인 응용프로그램은 사용자의 입력에 의한 출력으로 동작한다.)

*/

//여기서는 게임루프가 불완전하다. ( 스스로 갱신하지 못하고 있기 때문이다.
//불완전함은 인지하고 나머지 내용들을 살펴보자.
int main()
{
	//create game program
	//게임 프로그램이 구동하는데 필요한 여러 작업들을 하자
	cout << "create game program" << endl;
	int tinput = 0;

	//game loop
	//게임 세계가 지속적으로 갱신되는 곳이다.
	while (1)  //조건식 : c에서 0은 거짓, 0이 아닌수는 참으로 간주한다.
	{ 
		cout << "update game program" << endl;
		
		//console input, 입력장치가 추상화된 객체, cpp
		//문자열이 입력되기를 대기한다. 입력완료는 enter 이고
		//입력완료가 되기까지 프로그램의 진행은 멈춰있다.( 블러킹 blocking )
		cin >> tinput; 


		if (9 == tinput) //등호를 하나만 썼을 때의 실수를 방지하기 위해 tinput과 9의 순서를 바꿔서 쓴다.
		{
			//반복제어구조와 함께 쓰이면
			//거슬러 올라가봐서 '처음으로 만나는 반복제어구조'에서의 '탈출'
			//이라는 의마가 된다.
			break;  
		}
	}


	//destroy game program
	//게임 프로그램이 종료되는데 필요한 여러 작업들을 하자
	cout << "destroy game program" << endl;

	return 0;
}


