

#include <iostream>
using namespace std;

/*
	switch 예약어를 이용한 판단제어구조
	
	//case 구문은 원하는만틈
	//default구문은 생략가능

	switch(정수)
	{
		case 라벨번호:
		{
		}
		break;
		case 라벨번호:
		{
		}
		break;
		default:
		{
		}
		break;
	}


*/
int main()
{
	//변수 선언과 초기화
	//타입은 정수, 이름 tA, 초기값은 3
	//타입은 정수, 이름 tB, 초기값은 2
	//타입은 정수, 이름 tResult, 초기값은 0
	//타입은 정수, 이름 tSelectOperator, 초기값은 1

	int tA = 3;
	int tB = 2;
	int tResult = 0;
	int tSelectOperator = 4;

	float tResult_0 = 0.0f;

	//사칙연산 분기
	//tSelectOperator :1 -> +
	//tSelectOperator :2 -> -
	//tSelectOperator :3 -> *
	//tSelectOperator :4 -> /

	switch (tSelectOperator)  //if문에서는 조건들을 차례대로 참거짓을 따지면서 내려가는 반면, 스위치 구문은 해당 되는 값으로 바로 점프한다.
	{
		case 1:
		{
			tResult = tA + tB;
			cout <<"additive "<< "A: " << tA <<" B: " << tB <<" result : "<< tResult << endl;
		}
		break;
		case 2:
		{
			tResult = tA - tB;
			cout << "subtract " << " A: " << tA << " B: " << tB << " result : " << tResult << endl;
		}
		break;
		case 3:
		{
			tResult = tA * tB;
			cout << "multiply " << " A: " << tA << " B: " << tB << " result : " << tResult << endl;
		}
		break;
		case 4:
		{		
			tResult_0 = (float)tA / (float)tB; //type cast
			cout << "divide " << " A: " << tA << " B: " << tB << " result : " << tResult_0 << endl;
		}
		break;
	}
	return 0;
}

