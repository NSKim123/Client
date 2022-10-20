/*
    OOP Object Oriented Programming 의 4가지 특징
        
        추상화 abstraction         데이터의 추상화 + 코드의 추상화 ---> 데이터의 추상화
        은닉화 encapsulation       data hiding 멤버함수 뒤로 멤버변수를 감춘다. 변경의 국지화
        ==========================추상화, 은닉화 ===> object의 근간
        상속성 inheritance         공통된 특성을 부모클래스에 두고 자식클래스는 이를 이어받아 작성하는 것. 코드의 효율적인 재사용reuse
        다형성 polymorphism        같은 메시지의 다른 반응.      override + virtual + 부모클래스 포인터 타입




*/

#include <iostream>
using namespace std;

/*
class CBrave
{
private:
    int mX = 0;
    int mY = 0;
    int mZ = 0;
    int mHP = 0;

public:
    CBrave();
    ~CBrave();

    void Doit();

};
*/

class CBrave
{
private:
    int mX = 0;
    int mY = 0;
    int mZ = 0;
    int mHP = 0;

public:
    CBrave();
    virtual ~CBrave();

    virtual void Doit();

};

//16바이트 + 1*포인터변수의 크기 = 24바이트
//가상함수가 적용된 클래스에 대응되는 '가상함수 테이블'이라는 것을 만들고 해당 클래스의 객체는 모두 이 가상함수테이블을 가리키는 포인터변수를 가지게 된다.
// (물론 코드상에 드러나지는 않는다.)

/*
    전역함수 ---> 이름 그 자체가 주소값에 대응

    클래스의 일반적인 멤버함수 ---> 암묵적으로 클래스마다 관리되는 함수테이블에 함수의 주소가 기록되어있다.

    ============================ 위 : 정적, 아래 : 동적 ====================================================================================

    클래스의 가상 멤버함수 ---> 명시적으로 관리되는 가상함수 테이블에 해당주소가 기록되어 있다.
                                (객체에서 가상함수테이블의 주소값을 기억하고 있는 '포인터변수'를 디버거 상에서 '실행'중에 관찰할 수 있다.)
*/



int main()
{
    cout << sizeof(CBrave) << endl;
    
    CBrave tBrave;

    return 0;
}


CBrave::CBrave()
{
}
CBrave::~CBrave()
{
}

void CBrave::Doit()
{

}