

#include <iostream>
using namespace std;

/*

    기본 생성자
    소멸자
    복사 생성자
    복사 대입 연산자

    등은 명시적으로 만들지 않으면
    컴파일러에 의해서 자동으로 만들어진다.


    복사 함수 : 복사 생성자 copy constructor, 복사 대입 연산자 copy assignment 등을 복사함수라고 한다.


*/

class CWeapon
{
private:
    int mAP = 0;
};

class CSlime
{
//private:
public:
    int mX = 0;
    int mHP = 0;
    int mAP = 0;

    CWeapon* mpWeapon = nullptr;    //무기 객체 참조

public:
    CSlime();
    ~CSlime();

    CSlime(const CSlime& t);         //복사 생성자
   
    void operator=(const CSlime& t); //복사 대입 연산자
};

class CSlimeBoss : public CSlime
{
public:
    CSlimeBoss();
    ~CSlimeBoss();

    CSlimeBoss(const CSlimeBoss& t);

    void operator=(const CSlimeBoss& t);
};


int main()
{
    CSlime tSlimeA;     //기본 생성자가 호출
    CSlime tSlimeB;     //기본 생성자가 호출

    tSlimeA.mX = 2;
    tSlimeA.mHP = 100;
    tSlimeA.mAP = 3;

    CSlime tSlimeC = tSlimeA;    //'복사 생성자'가 호출

    tSlimeB = tSlimeA;      //'복사 대입 연산자'가 호출


    return 0;
}

CSlime::CSlime()
    :mX(0), mHP(0), mAP(0),mpWeapon(nullptr)
{
    mpWeapon = new CWeapon;
}
CSlime::~CSlime()
{
    if (nullptr != mpWeapon)
    {
        delete mpWeapon;
        mpWeapon = nullptr;
    }
}

CSlime::CSlime(const CSlime& t)         //복사 생성자
{
    //얕은 복사 shallow copy   (곧이곧대로 복사)

    /*this->mX = t.mX;
    mHP = t.mHP;
    mAP = t.mAP;

    mpWeapon = t.mpWeapon;*/

    //깊은 복사 deep copy
    this->mX = t.mX;
    mHP = t.mHP;
    mAP = t.mAP;

    //새롭게 CWeapon타입의 객체 생성
    mpWeapon = new CWeapon();
    //CWeapon의 복사대입연산자가 작동
    *mpWeapon = *t.mpWeapon;
}
void CSlime::operator=(const CSlime& t)   //복사 대입 연산자
{
    //얕은 복사 shallow copy
    /*this->mX = t.mX;
    mHP = t.mHP;
    mAP = t.mAP;

    mpWeapon = t.mpWeapon;*/

    //깊은 복사 deep copy
    this->mX = t.mX;
    mHP = t.mHP;
    mAP = t.mAP;

    //무기가 없는 경우
    if (nullptr == mpWeapon)
    {
        //새롭게 CWeapon타입의 객체 생성
        mpWeapon = new CWeapon();
        //CWeapon의 복사대입연산자가 작동
        *mpWeapon = *t.mpWeapon;
    }
    else //무기가 있는 경우
    {
        //CWeapon의 복사대입연산자가 작동
        *mpWeapon = *t.mpWeapon;
    }
}

CSlimeBoss::CSlimeBoss()
{

}
CSlimeBoss::~CSlimeBoss()
{

}

CSlimeBoss::CSlimeBoss(const CSlimeBoss& t)
{

}

void CSlimeBoss::operator=(const CSlimeBoss& t)
{

}