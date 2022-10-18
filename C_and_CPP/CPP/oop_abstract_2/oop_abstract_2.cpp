/*
    OOP Object Oriented Programming 객체지향프로그래밍

        추상화 abstraction     데이터의 추상화 + 코드의 추상화 --> 데이터의 추상화(사용자 정의타입, class 예약어로 사용하여 만든다)
        은닉화 encapsulation
        상속성 inheritance
        다형성 polymorphism
    

    객체는 반드시 생성자, 소멸자를 가진다.

    생성자, 소멸자

    생성자 constructor : 객체가 생성될 때 자동으로 호출되는 함수 --> 즉, 객체가 생성될 때 해야할 일들을 여기서 처리하기에 적합하다.
    소멸자 destroyer : 객체가 해제될 때 자동으로 호출되는 함수 --> 즉, 객체가 소멸될 때 해야할 일들을 여기서 처리하기에 적합하다.
*/

#include <iostream>
using namespace std;
//클래스 정의의 선언부
class CSlime
{
public:
    //멤버변수의 선언
    int mX = 0;
    int mHP = 100;
    int mAP = 33;
    //멤버함수의 선언
    void DisPlayInfo();
    //기본생성자, 기본소멸자를 명시적으로 만들어줌
    //i) 클래스와 이름이 같다.
    //ii) 리턴타입이 아예 없다.(void도 없음)
    //iii)명시적으로 만들어주지 않으면 컴파일러가 자동으로 만들어준다. <-- compile-time에
    CSlime();    //기본 생성자
    ~CSlime();   //기본 소멸자
};

int main()
{
    //지역객체
    //CSlime tSlime; //변수의 선언 ---> 객체object의 선언
    //tSlime.DisPlayInfo(); //멤버함수의 호출


    //cpp문법으로 동적할당한 객체
    CSlime* tpSlime = nullptr;
    tpSlime = new CSlime;  

    if (nullptr != tpSlime)
    {
        tpSlime->DisPlayInfo();
    }

    if (nullptr != tpSlime)
    {
        delete tpSlime;
        tpSlime = nullptr;
    }

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

//멤버함수의 정의
void CSlime::DisPlayInfo()
{
    cout << "slime x :" << mX << endl;
    cout << "slime hp :" << mHP << endl;
    cout << "slime ap :" << mAP << endl;
}