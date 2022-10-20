/*
    다형성 polymorphism
        같은 메시지의 다른 반응
            <-- 같은 메시지 : 모양이 같은 함수 를 의미.

        'override + virtual + 부모클래스 타입의 포인터'




        가상함수 virtual function



*/

#include <iostream>
using namespace std;

class CUnit
{
public:
    CUnit();
    virtual ~CUnit(); //<-- 가상함수가 적용된 클래스에는 소멸자에도 virtual을 붙여준다

    virtual void Display();   //<-- virtual 예약어를 부모클래스의 함수, 자식클래스의 함수에 모두 붙이면 된다.
};

class CSlime : public CUnit
{
public:
    CSlime();
    virtual ~CSlime();

    virtual void Display() override;  //<-- override 된 함수라고 표시해주는 예약어
};

class CSlimeBoss : public CUnit
{
public:
    CSlimeBoss();
    virtual ~CSlimeBoss();

    virtual void Display() override;
};


int main()
{
    CSlime tSlime;
    CSlimeBoss tBoss;

    CUnit* tSlimes[2] = { nullptr, nullptr };

    tSlimes[0] = &tSlime;
    tSlimes[1] = &tBoss;

    for (int ti = 0; ti < 2; ++ti)
    {
        tSlimes[ti]->Display();   //같은 메시지에 다른 반응
    }
    //'부모클래스 포인터 타입으로 간접참조'하는 경우에도 이제는 각각의 '객체의 타입에 맞게' '의도한 함수의 호출'이 일어난다.
    // i) 동일한 타입의 '자료구조'로 한꺼번에 다룰 수 있게 된다.
    // ii) 함수 호출부의 코드가 매우 간결해진다.
    //
    // iii) 함수의 형태와 실제 구현의 분리가 가능해지는 개념의 시발점이 된다.


    return 0;
}


CUnit::CUnit()
{

}
CUnit::~CUnit()
{

}

void CUnit::Display()
{
    cout << "CUnit::Display()" << endl;
}



CSlime::CSlime()
{

}
CSlime::~CSlime()
{

}

void CSlime::Display()
{
    cout << "CSlime::Display()" << endl;
}



CSlimeBoss::CSlimeBoss()
{

}
CSlimeBoss::~CSlimeBoss()
{

}

void CSlimeBoss::Display()
{
    cout << "CSlimeBoss::Display()" << endl;
}