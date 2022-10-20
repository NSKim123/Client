

#include <iostream>
using namespace std;

/*
    부모클래스의 생성자
    자식클래스의 생성자


    자식클래스의 소멸자
    부모클래스의 소멸자


*/
//동적할당과 해제시
//부모클래스 포인터 타입으로 다룬다면( 흔히 다형성을 만들기 떄문에 virtual이 적용된 경우라고 할 수도 있다.) 가상소멸자를 적용하는 것이 바람직하다.
//그래야만 소멸자가 안전하게 의도대로 호출된다.
class CUnit
{
public:
    CUnit();
    virtual ~CUnit(); //가상소멸자 virtual destructor
    virtual void Display();
};

class CActor : public CUnit
{
public:
    CActor();
    virtual ~CActor();
    virtual void Display() override;
};

int main()
{
    //부모클래스 포인터 타입으로 다룬다
    CUnit* tpUnit = nullptr;
    tpUnit = new CActor;


    if (nullptr != tpUnit)
    {
        delete tpUnit;
        tpUnit = nullptr;
    }

    
    return 0;

}

CUnit::CUnit()
{
    cout << "CUnit::CUnit()" << endl;
}
CUnit::~CUnit()
{
    cout << "CUnit::~CUnit()" << endl;
}
void CUnit::Display()
{

}

CActor::CActor()
{
    cout << "CActor::CActor()" << endl;
}
CActor::~CActor()
{
    cout << "CActor::~CActor()" << endl;
}
void CActor::Display()
{

}