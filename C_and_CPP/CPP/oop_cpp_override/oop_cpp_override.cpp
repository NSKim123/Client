
/*
    override: 재정의,
        상속계통구조에서 부모클래스와 동일한 형태의 함수를
        그 정의를 다시 정의하는 것


*/

#include <iostream>
using namespace std;

class CUnit
{
protected:
    int mX = 0;
public:
    void Display();
};
class CBrave : public CUnit
{
private:
    int mCriticalRatio = 2;
public:
    void Display();  //부모클래스의 함수와 동일한 형태이다.(여기서는 함수이름까지 동일하게 한다)
};

int main()
{
    //step_0
    CUnit tUnit;
    tUnit.Display();

    CBrave tBrave;
    tBrave.Display();

    //step_1
    CUnit* tpUnit = nullptr;  //상속계통구조로 작성된 객체는 부모클래스 타입의 포인터로 다룰 수 있다.
    tpUnit = &tBrave;

    tpUnit->Display();  //포인터 변수로 접근하므로 포인터변수가 인식하고 있는 타입을 따라간다.
    //(간접참조에서 해석하는 규칙을 따라간다)

    //================================================
    /*CBrave* tpBrave = nullptr;
    tpBrave = &tUnit;*/
    //자식클래스의 포인터로는 부모클래스의 객체를 다룰 수 없다.

    CUnit tUnit_0;
    CBrave tBrave_0;

    //tUnit_0으로는 tBrave_0을 모두 채울 수 없다.
    //tBrave_0 = tUnit_0;

    //slicing 데이터가 짤려나간다. 그러므로 위험하다.
    tUnit_0 = tBrave_0;


    return 0;
}

void CUnit::Display()
{
    cout << "CUnit::Display()" << endl;
}

void CBrave::Display()
{
    cout << "CBrave::Display()" << endl; //정의부의 구현 내용이 다르다
}
