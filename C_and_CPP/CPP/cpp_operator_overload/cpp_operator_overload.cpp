/*
    프로그래밍 언어의 가장 기본적인 구성요소 3가지
        타입 Data Type
        연산자 operator
        제어구조 flow control



    연산자 오버로드 operator overload
        (C++에서)  클래스(사용자정의타입)에 대해 연산자를 중복해서 정의하는 것.


        함수의 오버로드가 '함수의 이름은 같고 매개변수 리스트가 다른 것'처럼
        연산자 오버로드는 그 '연산자의 형태는 같고 그 연산가 다루는 타입들'이 달라진다




    사용법: 'operator예약어 뒤에 해당 연산자를 붙이고' 나서 함수의 정의를 구현을 하면 된다.


    장점:
    1)해당 연산자 표기의 의미가 유지된다.
    2)간략한 표기가 가능하다.

    단점:
    1)구현 난이도가 있다.



*/

#include <iostream>
using namespace std;

//prealgebra 산수
//algebra 대수학
//geometry 기하학

class CRyuAlgebra
{
private:
    int mVal = 0;

public:
    //매개변수 있는 생성자
    CRyuAlgebra(int tVal)
        :mVal(tVal)   //초기화 목록
    {
        //mVal = tVal;   <-- 이것과 같은 의미이며, 이것과 연산이 더 빠르다.
    }
    ~CRyuAlgebra(){}

    void operator=(const CRyuAlgebra& t)
    {
        this->mVal = t.mVal;
    }

    CRyuAlgebra operator+(const CRyuAlgebra& t)
    {
        return this->mVal * 10 + t.mVal;
    }

    int GetVal()
    {
        return mVal;
    }

};


//전역으로 만든 연산자 오버로드
ostream& operator<<(ostream& tOS, CRyuAlgebra& t)
{
    tOS << t.GetVal();

    return tOS;
}


int main()
{
    /*
    int tA = 3;
    int tB = 2;
    int tResult = 0;

    tResult = tA + tB;
    */


    /*CRyuAlgebra tA(1);
    CRyuAlgebra tB(2);
    CRyuAlgebra tResult(0);*/

    //이 코드들은 매개변수 있는 생성자로 컴파일됨
    //(변수선언의 초기화 구문의 =은 일반적인 대입연산자가 아니다.)
    CRyuAlgebra tA = 1;
    CRyuAlgebra tB = 2;
    CRyuAlgebra tResult = 0;

    tResult = tA + tB;  //여기의 =은 대입연산자이다.

    //cout << tResult.GetVal() << endl;
    cout << tResult << endl;

    


    return 0;
}


