/*
	OOP의 4가지 특징

		추상화 
		은닉화
		상속성 : '공통된 특성(멤버변수, 멤버함수)'을 '부모클래스'로 몰아두고 '자식클래스'를 이를 '이어받아' 만드는 것
		다형성


		상속의 목적은 코드의 효율적인 재사용reuse 이다. ( 타이핑 수를 줄여준다. 수정사항이 발생했을 경우 국지화가 일어난다.)

*/

#include <iostream>
using namespace std;

class CSlime
{
private:
	int mX = 0;
public:
	CSlime();
	~CSlime();

	void DisplaySlime();
};
//자식클래스 : public 부모클래스
class CSlimeBoss :public CSlime
{
private :
	int mCriticalRatio = 0;

public :
	CSlimeBoss();
	~CSlimeBoss();
};

int main()
{
	/*CSlime tSlime;
	tSlime.DisplaySlime();*/

	CSlimeBoss tBoss;  //<--CSlimeBoss 타입의 객체 생성.
	//생성자 호출 순서
	//부모클래스의 생성자 호출
	//자식클래스의 생성자 호출
	tBoss.DisplaySlime();

	//소멸자 호출 순서
	//자식클래스의 소멸자 호출
	//부모클래스의 소멸자 호출
	return 0;
}

CSlime::CSlime()
{
	cout << "CSlime::CSlime()" << endl;
}
CSlime::~CSlime()
{
	cout << "CSlime::~CSlime()" << endl;
}

void CSlime::DisplaySlime()
{
	cout << "void CSlime::DisplaySlime()" << endl;
}

CSlimeBoss:: CSlimeBoss()
{
	cout << "CSlimeBoss::CSlimeBoss()" << endl;
}
CSlimeBoss::~CSlimeBoss()
{
	cout << "CSlimeBoss::~CSlimeBoss()" << endl;
}