
#include <iostream>
using namespace std;

class CUnit
{
private: 
	int mState = 0;

	typedef void (CUnit::*FuncPtr)();

	FuncPtr mArray[2] = { &CUnit::DoIdle, &CUnit::DoAttack };
	//Ŭ������ ����Լ��� �����Լ��ʹ� �ٷ�� ����� �ٸ��Ƿ�
	// i) ���� ���� �ּҿ����ڸ� ����Ͽ� ǥ���Ѵ�.
	// ii) �Ҽ� Ŭ������ �����ش�.

private:
	//���¿� ���� �ൿ �Լ�
	void DoIdle();
	void DoAttack();

public:
	//���� ���� �Լ�
	void SetState(int tState);
	void Execute(); //���¿� ���� �ൿ ����
};


int main()
{
	CUnit* tpUnit = nullptr;
	tpUnit = new CUnit();
	
	//null check ����
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
	//Ŭ������ ����Լ��� �����͸� �̿�����.
	(this->*mArray[mState])(); 
	//*(this->mArray[mState])();
	//Ŭ������ ����Լ��̹Ƿ� �ѹ� �� ���������ϴ� ����
	//��ü�� �� �ƴ϶�(��ü�� ũ��� �����͸� ������ ��ģ�� ��� �ǹ��� �ƶ��̴�) ����Լ���ü�� �̶�� �������� *��ȣ�� �Լ��ʿ� ���δ�.

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
