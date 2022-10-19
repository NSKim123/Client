/*

    OOP의 네가지 특징
        추상화 abstraction        데이터의 추상화 + 코드의 추상화 ---> 데이터의 추상화
        은닉화 encapsulation      data hiding, 데이터를 감춘다, 멤버변수를 멤버함수 뒤로 감춘다
        상속성 inheritance
        다형성 polymorphism


*/

#include <iostream>
using namespace std;

//추상화 + 은닉화 <-----객체 Object의 근간이 된다.

class CSlime
{
    /*
        public : 어디서나 접근가능
        private : 해당 클래스 내에서만 접근가능
        protected : 상속계통구조 안에서 접근가능
    */

    //접근제한 지정자를 이용하여 멤버변수를 멤버함수 뒤로 감추었다.
    //즉, 수정사항이 발생한 경우 많은 부분, 클래스를 경계로 '변경의 국지화'가 이루어졌다.
    //이것이 은닉화의 목적이다.
//public:
private:
    int mX = 0;
    int mHP = 100;
    int mMP = 33;

    int mStrength = 0;

public:
    void DisplayInfo();
    void BuildInfo(int tX, int tHP, int tMP);

    CSlime();
    ~CSlime();
};

//Setter, Getter
class CBrave
{
private:
    int mX = 0;

public:
    void SetX(int tX);      //Setter
    int GetX();             //Getter
    
};

int main()
{
    CSlime tSlime;

    //BuildInfo(int tX, int tHP, int tAP)
    /*tSlime.mX = 5;
    tSlime.mHP = 120;
    tSlime.mAP = 66;*/
    tSlime.BuildInfo(5, 120, 66);
    tSlime.DisplayInfo();


    CBrave tBrave;
    tBrave.SetX(2048);
    cout << tBrave.GetX() << endl;

    return 0;
}

void CSlime::DisplayInfo()
{
    cout << mX << endl;
    cout << mHP << endl;
    cout << mMP << endl;

    cout << mStrength << endl;
}
void CSlime::BuildInfo(int tX, int tHP, int tMP)
{
    mX = tX;
    mHP = tHP;
    mMP = tMP;
    mStrength = mHP * mMP;
}

CSlime::CSlime()
{

}
CSlime::~CSlime()
{

}

void CBrave::SetX(int tX)
{
    mX = tX;
}
int CBrave::GetX()
{
    return mX;
}