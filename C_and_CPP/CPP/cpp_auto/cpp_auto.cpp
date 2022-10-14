
/*

    auto
    타입 추론 예약어



*/


#include <iostream>

using namespace std;

int main()
{
    float tF = 0.0f;
    auto tG = 0.0f;
    //타입 추론 예약어 :
    //타입 추론 예약어로 변수를 선언하면 변수의 타입은 '컴파일러'가 '컴파일시점'에 결정한다.
    //초기값을 보고 결정한다. ---> 그러므로 auto 예약어를 사용하여 변수 선언 시에는 반드시 초기화를 해야 한다.

    
    //auto tGG;  이것은 초기화하지 않았으므로 컴파일 시점에 에러를 낸다.

    auto tB = 3; //여기서 tB 타입은 int
    cout << tB << endl;

    int* tC = new int;

    if (nullptr != tC)
    {
        delete tC;
        tC = nullptr;
    }

    //char*
    auto tD = new char;

    if (nullptr != tD)
    {
        *tD = 'b';
        cout << *tD << endl;
    }

    if (nullptr != tD)
    {
        delete tD;
        tD = nullptr;
    }


    return 0;
}

