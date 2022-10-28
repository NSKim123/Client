/*


C스타일 원시배열
    장점
       i)'물리적으로' 연속된 메모리 블럭이다. (CPU의 캐쉬적중률이 높아진다 --> 코드 속도가 빨라진다.)
       ii)객체가 아니므로 객체 처리비용이 없다. (생성자, 소멸자 등이 없다.)
       iii)위 사항들에 의해 속도가 빠르다.
    단점
       i)컴파일시 크기가 고정된다.
       ii)배열의 이름은 상수포인터로 취급되므로 묵시적(암묵적)타입 변환 등이 가능해 보안상 문제가 될 수도 있다.

STL의 vector 컨테이너(가변배열)
    장점
       i)실행중 크기가 가변적이다.
       ii)STL의 알고리즘 적용이 가능하다.
    단점
       i)물리적으로 연속된 메모르 불럭이라고 보장할 수 없다.
       ii)객체라서 객체 처리비용(생성사나 소멸자 등)이 있다.
       iii)위 사항들에 의해 접근 속도가 느릴 수도 있다.

CPP스타일의 배열 array
    i)STL의 알고리즘 적용이 가능하다.
    ii)'물리적으로 연속된'메모리 블럭이다. 즉, 접근속도가 비교적 빠르다.(CPU의 캐쉬 적중률이 높다.)
    iii)생성자, 소멸자, 복사 생성자, 대입 연산자 등의 객체스러움을 제공한다.
    iv)초기화 리스트가 배열의 크기보다 작으면 나머지 원소들은 0으로 초기화하므로 보다 안전하다.
    v)묵시적 형변환을 허용하지 않는다.
       


*/




#include <iostream>
#include <array>
using namespace std;

int main()
{
    //원시배열의 선언과 초기화
    int tArray_0[5] = { 0 };


    //cpp11에 추가된 array
    //템플릿 문법을 이용하여 만들어졌다.
    //원소들의 타입은 int, 원소들의 갯수는 5개, 배열의 이름은 tArray
    array<int, 5> tArray = { 1,2,3 }; //초기화 리스트가 배열의 크기보다 작으면 나머지는 0으로 자동으로 초기화된다.


    for (int ti = 0; ti < 5; ++ti)
    {
        cout << tArray.at(ti) << endl;
    }

    cout << endl;
    for (int ti = 0; ti < tArray.size(); ++ti) //<--배열의 크기를 얻는 등의 관련 멤버함수도 제공한다.
    {
        cout << tArray.at(ti) << endl;
    }

    tArray.at(3) = 777;

    cout << endl;
    for (int ti = 0; ti < tArray.size(); ++ti)
    {
        cout << tArray[ti] << endl;    //<--원시배열의 인덱스 접근 연산자도 지원한다.(호환성 유지)
    }

    //반복자iterator를 사용한 순회traverse구문도 작성할 수 있다.
    array<int, 5>::iterator tItor;

    cout << endl;
    for (tItor = tArray.begin(); tItor != tArray.end(); ++tItor)
    {
        cout << *tItor << endl;
    }

    tArray.fill(777);   //<-- 모든 원소의 값을 이 값으로 채운다.

    //array<int, 5>::iterator tItor;     <-- auto를 이용해보자
    cout << endl;
    for (auto tItor = tArray.begin(); tItor != tArray.end(); ++tItor)
    {
        cout << *tItor << endl;
    }

    tArray.at(0) = 1;
    tArray.at(4) = 9;

    cout << endl;
    for (auto tItor = tArray.begin(); tItor != tArray.end(); ++tItor)
    {
        cout << *tItor << endl;
    }
    cout << "첫번째 원소 : " << tArray.front() << " , 마지막 원소 : " << tArray.back() << endl;

    cout << endl;

    //cpp11에 추가된 for
    //for(자료구조에 임의의 원소의 값을 받아올 지역변수 : 자료구조) <-- 순회가 일어난다
    for (int t : tArray)  //<--이런 표현이면 프로그래머가 실수할 가능성을 매우 줄여준다.
    {
        cout << t << endl;
    }

    //cpp11에 추가된 for은 윈시배열과도 함께 작동한다.
    for (auto t : tArray_0)
    {
        cout << t << endl;
    }


    //c 와 cpp 에서 배열을 보는 관점이 달라졌다.
    //=========================
    int* tpPtr_0 = nullptr;
    tpPtr_0 = tArray_0;     // C에서의 원시배열. 메모리 덩어리 수준으로 본다
    //포인터 변수 : 주소를 값으로 가지는 변수
    //배열의 이름은 배열의 시작'주소의 값'


    int* tpPtr = nullptr;
    //tpPtr = tArray;       
    //tpPtr = (int*)tArray;  
    /*
    
    cpp11에서 추가된 array.  
    tpPtr은 int* 타입, tArray는 array<int,5>타입으로 바라보기때문에 타입이 완전히 다르다.
    cpp에서는 타입의 안전성이 높아졌다.

    */

    tpPtr = tArray.data();  //<-- C의 원시배열과 하위호환 보장을 위해 data()함수를 준비했다.

    cout << endl;
    cout << *(tpPtr + 4) << endl;

    return 0;
}


