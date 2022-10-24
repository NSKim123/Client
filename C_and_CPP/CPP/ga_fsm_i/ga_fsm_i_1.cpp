
#include <iostream>
using namespace std;

class CUnit
{
private: 
	int mState = 0;

	typedef void (CUnit::*FuncPtr)();

	FuncPtr mArray[2] = { &CUnit::DoIdle, &CUnit::DoAttack };
	//클래스의 멤버함수는 전역함수와는 다루는 방식이 다르므로
	// i) 위와 같이 주소연산자를 사용하여 표기한다.
	// ii) 소속 클래스도 밝혀준다.

private:
	//상태에 따른 행동 함수
	void DoIdle();
	void DoAttack();

public:
	//상태 변경 함수
	void SetState(int tState);
	void Execute(); //상태에 따른 행동 수행
};


int main()
{
	CUnit* tpUnit = nullptr;
	tpUnit = new CUnit();
	
	//null check 생략
	tpUnit->SetState(0);
	tpUnit->Execute();

	tpUnit->SetState(1);
	tpUnit->Execute();

	//if(nullptr != tpUnit)
	if (tpUnit)
	{
		delete tpUnit;
		tpUnit = nullptr;
	}

	return 0;
}

void CUnit::DoIdle()
{
	cout << "CUnit::DoIdle()" << endl;
}
void CUnit::DoAttack()
{
	cout << "CUnit::DoAttack()" << endl;
}

void CUnit::SetState(int tState)
{
	mState = tState;
}
void CUnit::Execute()
{
	//클래스의 멤버함수의 포인터를 이용하자.
	(this->*mArray[mState])(); 
	//*(this->mArray[mState])();
	//클래스의 멤버함수이므로 한번 더 간접참조하는 형태
	//객체의 가 아니라(객체의 크기는 데이터만 영향을 미친다 라는 의미의 맥락이다) 멤버함수자체만 이라는 개념으로 *기호를 함수쪽에 붙인다.

	/*
	switch (mState)
	{
	case 0:
	{
		DoIdle();
	}
	break;
	case 1:
	{
		DoAttack();
	}
	break;
	default:
		break;
	}
	*/
	
}
