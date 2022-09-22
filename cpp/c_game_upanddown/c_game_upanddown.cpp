
#include <time.h>
#include <iostream>
using namespace std;
/*
	game : up and down
		
		1~8까지의 숫자 맞추기
		9 입력은 종료

	//게임 루프 구조 추가 <--게임이니까
	//컴퓨터가 숫자를 결정해낸다. <-- 난수
	//입력된 수자가 맞는지 판다 <-- 판단제어구조

*/

int main()
{
	srand((unsigned int)time(nullptr));
	
	int tInput = 0;
	


	//game loop
	while (1)
	{
		//컴퓨터가 숫자를 생각해낸다.
		int tAINumber = 0;
		tAINumber = rand() % 8 + 1;
		cout << "( debug: tAINumber " << tAINumber << " )" << endl; //개발의 편의를 위해 표시

		while (1)
		{
			cin >> tInput;
			//종료조건
			if (9 == tInput)
			{
				break;
			}

			//게임로직
			if (tAINumber == tInput)
			{
				cout << "맞습니다 . 정답은 " << tAINumber << "입니다" << endl;
				break;
			}
			else if (tAINumber < tInput)
			{
				cout << "좀더 작은 숫자입니다." << endl;
			}
			else if (tAINumber > tInput)
			{
				cout << "좀더 큰 숫자입니다." << endl;
			}
		}
		//종료조건
		if (9 == tInput)
		{
			break;
		}
	}



	return 0;
}


