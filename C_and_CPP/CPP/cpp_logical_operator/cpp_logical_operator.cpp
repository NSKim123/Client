

#include <iostream>
using namespace std;

/*
    논리 연산자

    &&      and

    ||      or

    !       not
*/


int main()
{
    int tX = 120;
    int tY = 20;

    //cpp에는 bool이라는 참, 거짓을 나타내는 타입도 추가되었다.
    bool tIsX = true;
    bool tIsY = false;

    cout << "sizeof(bool): " << sizeof(bool) << endl; //1byte

    //&& 둘다 참이면 참이다.
    if (true == tIsX && true == tIsY)
    {
        cout << "true == tIsX && true == tIsY, true" << endl;
    }
    else
    {
        cout << "true == tIsX && true == tIsY, false" << endl;
    }

    //둘 중에 하나라도 참이면 참이다.
    if (10 == tX || true == tIsX)
    {
        cout << "10 == tX || true == tIsX, true" << endl;
    }
    else
    {
        cout << "10 == tX || true == tIsX, false" << endl;
    }

    if (!tIsY)
    {
        cout << "!tIsY, true" << endl;
    }
    else
    {
        cout << "!tIsY, false" << endl;
    }



    return 0;
}


