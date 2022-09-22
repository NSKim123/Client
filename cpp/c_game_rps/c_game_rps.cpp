
#include <time.h>
#include <iostream>
using namespace std;
/*
	가위바위보 게임

	//게임 <-- 게임루프

	//플레이어의 가위바위보 <-- 입력
	//컴퓨터의 가위바위보 <-- 난수
	//

	//가위바위보의 개념 <-- 수로 대응시키자 0: 가위, 1: 바위, 2:보
	//판단제어구조 <-- 가위바위보 비교
*/

int main()
{
	srand((unsigned int)time(nullptr));

	int tPlayerRPS = 0;

	cout << "어서와 이 곳은 처음이지" << endl;
	cout << "가위바위보 게임을 시작하지" << endl;
	
	//게임 루프
	while (1)
	{
		cout << "가위바위보를 입력하세요(0:가위, 1:바위 , 2:보): ";
		//플레이어의 가위바위보
		cin >> tPlayerRPS;

		//종료조건
		if (9==tPlayerRPS)
		{
			break;
		}

		//컴퓨터의 가위바위보 결정
		int tAIRPS = 0;
		tAIRPS = rand() % 3;

		cout << "(debug: AI " << tAIRPS << ")" << endl;

		//test
		//tAIRPS = 1;

		//승/패/무승부 판단
		switch (tPlayerRPS)
		{
		case 0 : //플레이어: 가위
		{
			switch (tAIRPS)
			{
			case 0: //AI : 가위
			{
				cout << "무승부, player : 가위, ai : 가위" << endl;
			}
			break;
			case 1: //AI : 바위
			{
				cout << "패, player : 가위, ai : 바위" << endl;
			}
			break;
			case 2: //AI : 보
			{
				cout << "승, player : 가위, ai : 보" << endl;
			}
			break;

			default:
				break;
			}
		}
		break;
		case 1:
		{
			switch (tAIRPS)
			{
			case 0:
			{
				cout << "승, player : 바위, ai : 가위" << endl;
			}
			break;
			case 1:
			{
				cout << "무승부, player : 바위, ai : 바위" << endl;
			}
			break;
			case 2:
			{
				cout << "패, player : 바위, ai : 보" << endl;
			}
			break;

			default:
				break;
			}
		}
		break;
		case 2:
		{
			switch (tAIRPS)
			{
			case 0:
			{
				cout << "패, player : 보, ai : 가위" << endl;
			}
			break;
			case 1:
			{
				cout << "승, player : 보, ai : 바위" << endl;
			}
			break;
			case 2:
			{
				cout << "무승부, player : 보, ai : 보" << endl;
			}
			break;

			default:
				break;
			}
		}
		break;
		}

	}

	cout << "게임을 종료합니다." << endl;

	return 0;
}


