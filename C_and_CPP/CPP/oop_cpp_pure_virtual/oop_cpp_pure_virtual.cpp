

#include <iostream>
using namespace std;

/*

    순수가상함수

    '형태'를 강제한다.

*/

//추상클래스 abstraction class
class CUnit
{
public:
    virtual void Display() = 0; //'순수 가상 함수'로 선언
    //함수의 정의는 핮 ㅣ않고, 선언만 하고 '=0'으로 이것이 순수가상함수 임을 밝힌다.
    //즉, '형태'만 선언한 것이다.
    //순수 가상 함수를 포함한 클래스를 추상클래스라고 한다.
    //
    //'추상 클래스'로는 '객체'를 만들 수 없다.
};

/*
    추상클래스를 상속받고 순수가상함수의 정의부를 만들지 않으면(구현하지 않으면)
    해당 클래스 또한 추상클래스이다.
    그러므로 객체를 만들어 사용하려면 반드시 구현해야 한다.
    --> 즉, 형태가 같은 함수의 정의를 해당 클래스의 역할에 맞게 구현하게 된다.
    --> 즉, '형태를 강제'하는 것이다.
*/

class CSlime : public CUnit
{
public:
    virtual void Display() override;
};

class CSlimeBoss : public CUnit
{
public:
    virtual void Display() override;
};

int main()
{
    //'추상 클래스'로는 '객체'를 만들 수 없다.
    //CUnit tUnit;

    CSlime tSlime;
    tSlime.Display();

    CSlimeBoss tBoss;
    tBoss.Display();

    return 0;
}


void CSlime::Display()
{
    cout << "CSlime::Display()" << endl;
}
void CSlimeBoss::Display()
{
    cout << "CSlimeBoss::Display()" << endl;
}