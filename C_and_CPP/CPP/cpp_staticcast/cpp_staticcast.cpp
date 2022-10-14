

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

    return 0;
}


