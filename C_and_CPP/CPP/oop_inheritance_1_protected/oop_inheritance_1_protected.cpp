/*
	상속계통구조 에서
	접근제한지정자 들이 어떻게 동작하는지 관찰해보자.

	접근제한지정자

	public : 어디서나 접근가능
	private : 해당클래스 내에서만 접근가능
	protected : 상속계통구조 안에서 접근가능


*/

#include <iostream>
using namespace std;

class CUnit
{
private:
	int mHP = 0;

protected:
	int mAP = 0;

public:
	int mExp = 0;

};

//CUnit : 부모클래스 Parent Class, Base Class 기반클래스
//CSlime : 자식클래스 Child Class, Derived Class 파생클래스

class CSlime :public CUnit
{
public:
	void DisplayHp();
	void DisplayAp();
	void DisplayExp();
};

int main()
{
	CSlime tSlime;

	tSlime.DisplayHp();
	tSlime.DisplayAp();
	tSlime.DisplayExp();
	
	//cout << tSlime.mHP << endl; //private 해당 클래스내에서만 접근가능이므로 mP는 CUnit클래스 영역에서만 접근가능
	//cout << tSlime.mAP << endl; //protected 상속계통구조 안에서만 접근가능이므로 mAP는 CSlime에서 접근가능. 이곳은 외부라서 불가능
	cout << tSlime.mExp << endl;  //public 어디서나 접근가능이므로 여기 외부에서도 접근가능
	return 0;
}

void CSlime::DisplayHp()
{
	//cout << this->mHP << endl;  //private 해당 클래스내에서만 접근가능이므로 mP는 CUnit클래스 영역에서만 접근가능
}
void CSlime::DisplayAp()
{
	cout << this->mAP << endl;	  //protected 상속계통구조 안에서만 접근가능이므로 mAP는 CSlime에서 접근가능
}
void CSlime::DisplayExp()
{
	cout << this->mExp << endl;   //public 어디서나 접근가능이므로 CSlime에서도 접근가능
}