

#include <iostream>

using namespace std;

/*

    C++ integral promotion
    //암묵적(묵시적) 형변환 시에 이야기이다.
    i) 정수타입 + 실수타입                            ---> 정수타입이 실수타입으로 변환
    ii) 정수타입 + 정수타입, 실수타입 + 실수타입      ---> 보다 넓은 범위를 갖는 타입으로 변환
    iii) 양쪽 다 int 타입보다 작은 정수타입이라면     ---> 양쪽 다 int로 변환
    iv) 부호 없는 정수타입 + 부호 있는 정수 타입      ---> 부호 없는 타입으로 변환


    cpp 스타일의 형변환 연산자
    i) static_cast<>()          가장 기본적인 타입 캐스트, 정적(컴파일시)으로 작동

    //다음 세가지는 참조(포인터)를 요구
    ii) dynamic_cast<>()        상속계통구조에서 모호한 타입 캐스팅 오류를 막기 위함, 동적으로 작동
    iii) const_cast<>()         data type이 가진 상수 속성을 제거
    iv) reinterpret_cast<>()    어떤 포인터 타입끼리도 변환할 수 있게 함

*/


int main()
{
    int tX      = 2;
    double tY = 4.4;
    
    //암묵적(묵시적) 형변환
    double tA = tY / tX;
    cout << tA << endl;

    int tB = tY / tX;
    cout << tB << endl;

    //명시적 형변환
    int tC = (int)(tY / tX); //<--C 스타일 형변환
    cout << tC << endl;

    int tD = static_cast<int>(tY / tX); //<--CPP스타일 형변환 중 정적형변환
    cout << tD << endl;






    //step_1
    int tZ = 777;
    cout << "tZ: " << tZ << endl;
    
    //꾸며주는 곳(현재 int*)이 readonly 되었다.
    //const int* tpRyu = nullptr;
    int const* tpRyu = nullptr;
    tpRyu = &tZ; //포인터 변수의 값을 변경하는 것은 가능하지만,

    //*tpRyu = 1024; 간접참조하여 변경하는 것은 안 된다.
    tZ = 1024;
    cout << "tZ: " << tZ << endl;

    //const_cast<>()
    //상수 속성이 제거된 형변환
    int* tpPP = const_cast<int*>(tpRyu);
    *tpPP = 512;
    cout << "tZ: " << tZ << endl;

        //꾸며주는 것이 reedonly되었다. 여기서는 포인터 변수가 readonly다.
        int* const tpRR = nullptr;
        //tpRR = &tZ; <--그래서 포인터 변수에 값을 변경할 수 없다.

        




    //step_2
    //아무타입도 아닌 경우 내가 원하는 타입으로 형변환(뭐든지 형변환)
    int* tpPtr = nullptr;

    //tpPtr = (int*)malloc(sizeof(int) * 1);
    tpPtr = reinterpret_cast<int*>(malloc(sizeof(int) * 1)); //malloc : void

    if (nullptr != tpPtr)
    {
        *tpPtr = 256;
        cout << *tpPtr << endl;
    }

    if (nullptr != tpPtr)
    {
        free(tpPtr);
        tpPtr = nullptr;
    }

    return 0;
}


