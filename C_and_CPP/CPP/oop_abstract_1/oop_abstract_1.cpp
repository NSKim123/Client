/*

    구조화 프로그래밍 structured programming
        함수, 구조체 등을 이용하여 구조화 하여 프로그램 구조를 작성하는 방법

    객체지향 프로그래밍 OOP Object Oriented Programming
        클래스 간 '관계', 객체 간 '관계'를 이용하여 프로그램 구조를 작성하는 방법

    일반화 프로그래밍 General Programming
        타입으 매개변수화하여 다루는 프로그래밍 방법

*/





#include <iostream>
using namespace std;
/*
struct Slime
{
    int tSlimeX = 0;
    int tSlimeHP = 100;
    int tSlimeAP = 33;
};

void DisPlayInfo(Slime& tSlime);
*/

/*
struct Slime
{
    int tSlimeX = 0;
    int tSlimeHP = 100;
    int tSlimeAP = 33;

    void DisPlayInfo();    //멤버함수
};
*/

//cpp에서는 struct와 class가 완전히 같다.
//단, struct와 class는 한가지 다른 점이 있는데, 기본적인 접근제한지정자의 설정이 다르다.
// struct ---> public
// class  ---> private

//데이터의 추상화 + 코드의 추상화 ==> 사용자 정의 타입(데이터)

class Slime
{
    //접근제한 지정자 access modifier
    //사용자 정의 타입(struct, class)에 멤버(멤버변수, 멤버함수)들이 어느 정도 수준으로 접근가능한지 정해주는 연산자
    /*
        public      어디서나 접근가능 
        private     해당 클래스 내에서만 접근가능
        protected   상속계통구조 안에서 접근가능
    */
public:
    int tSlimeX = 0;
    int tSlimeHP = 100;
    int tSlimeAP = 33;

    void DisPlayInfo();    //멤버함수
};

int main()
{   
    //step_0
    //쌩 제어구조
    /*
    int tSlimeX = 0;
    int tSlimeHP = 100;
    int tSlimeAP = 33;
    */
    //step_1  
    /*cpp 스타일의 구조체, 데이터의 추상화 Slime
    Slime tSlime;
    */

    //전역함수로 코드의 추상화. DisPlayInfo
    /*
    cout << "slime x : " << tSlimeX << endl;
    cout << "slime hp : " << tSlimeHP << endl;
    cout << "slime ap : " << tSlimeAP << endl;
    */
    //DisPlayInfo(tSlime);
    
    //step_2
    /*
    Slime tSlime;
    tSlime.DisPlayInfo(); //여기서 this는 tSlime 을 나타낸다.
    */

    //step_3
    Slime tSlime;
    tSlime.DisPlayInfo();


    return 0;
}

/*
void DisPlayInfo(Slime& tSlime)
{
    cout << "slime x : " << tSlime.tSlimeX << endl;
    cout << "slime hp : " << tSlime.tSlimeHP << endl;
    cout << "slime ap : " << tSlime.tSlimeAP << endl;
}
*/

void Slime::DisPlayInfo() //:: 영역 결정 연산자
{
   /* cout << "slime x : " << tSlimeX << endl;
    cout << "slime hp : " << tSlimeHP << endl;
    cout << "slime ap : " << tSlimeAP << endl;*/

    //this 객체 자기자신을 가리키는 포인터 변수
    cout << "slime x : " << this->tSlimeX << endl;
    cout << "slime hp : " << this->tSlimeHP << endl;
    cout << "slime ap : " << this->tSlimeAP << endl;
}
