
/*
    
    C의 프로그래밍 패러다임 : 구조화 프로그래밍
    CPP의 프로그래밍 패러다임 : 멀티 프로그래밍
        <-- 구조화 structured programming : 함수와 구조체로 '구조화'하여 프로그램 구조를 작성하는 방법
        <-- 객체지향 Object Oriented Programming : 클래스간 '관계', 객체 간 '관계' 등을 이용하여 프로그램 구조를 작성하는 방법
        <-- 일반화 General Programming : 타입을 매개변수화하여 프로그래밍하는 방법



    OOP의 4가지 특징
    추상화 abstraction
    은닉화 encapsulation
    상속성 inheritance
    다형성 polymorphism

    추상화

*/

#include <iostream>
using namespace std;

typedef struct Slime
{
    int tSlimeX;
    int tSlimeHP;
    int tSlimeAP;
}SSlime;

void DisplayInfo(SSlime* tSlime);

//step_1
//cpp의 struct는 데이터의 추상화 + 코드의 추상화 ---> 데이터의 추상화로 나타낸다.
struct CSlime
{
    int tSlimeX;
    int tSlimeHP;
    int tSlimeAP;

    //void DisplayInfo(CSlime* tSlime);
    void DisplayInfo();
};

int main()
{
    //step_0
    //구조체
    /*
    int tSlimeX = 0;
    int tSlimeHP = 100;
    int tSlimeAP = 30;
    */
    SSlime tSlime;
    tSlime.tSlimeX = 0;
    tSlime.tSlimeHP = 100;
    tSlime.tSlimeAP = 30;

    //DisplayInfo()
    /*
    cout << "slime x: " << tSlime.tSlimeX << endl;
    cout << "slime HP: " << tSlime.tSlimeX << endl;
    cout << "slime AP: " << tSlime.tSlimeX << endl;
    */
    DisplayInfo(&tSlime);

    //step_1
    CSlime tSlime_0;
    tSlime_0.tSlimeX = 0;
    tSlime_0.tSlimeHP = 77;
    tSlime_0.tSlimeAP = 3;
    //tSlime_0.DisplayInfo(&tSlime_0);
    tSlime_0.DisplayInfo();

    return 0;
}

void DisplayInfo(SSlime* tSlime)
{
    cout << "slime x: " << tSlime->tSlimeX << endl;
    cout << "slime HP: " << tSlime->tSlimeHP << endl;
    cout << "slime AP: " << tSlime->tSlimeAP << endl;
}

void CSlime::DisplayInfo()
{
    cout << "slime x: " << tSlimeX << endl;
    cout << "slime HP: " << tSlimeHP << endl;
    cout << "slime AP: " << tSlimeAP << endl;
}
