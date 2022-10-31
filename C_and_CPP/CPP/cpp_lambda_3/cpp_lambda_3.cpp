
/*
    [] lambda introducer 람다 함수 소개자
        캡처 절 capture clause
        람다 함수 외부 (그리고 람다함수가 있는 지역의)의 변수를 캡처한다는 의미의 연산자


    캡처 규칙
    []          아무것도 캡처하지 않음
    [&]         모든 외부변수를 레퍼런스로 캡처   <--call by reference
    [=]         모든 외부변수를 값으로 캡처       <--call by value

    [x]         외부변수 x를 값으로 캡처          <--변수 이름을 직접 명기
    [x,y]       외부변수 x,y를 값으로 캡처
    [&x]        외부변수 x를 레퍼런스로 캡처      <--캡처방식과 변수의 이름을 명기

    [&x,&y]     외부변수 x,y를 레퍼런스로 캡처
    [&x,y]      외부변수 x를 레퍼런스로, 외부변수 y를 값으로 캡처
    [x,&y]      외부변수 x를 값로, 외부변수 y를 레퍼런스으로 캡처

    [&,x] 외부변수 x는 값으로, 나머지는 모두 레퍼런스로 캡처
    [=,&x] 외부변수 x는 레퍼런스으로, 나머지는 모두 값으로 캡처


        값으로 캡처된 변수는 const의 특성을 갖게 된다.
        그러므로,
        람다함수 내부에서 캡처된 변수의 값을 바꾸고 싶다면
        레퍼런스로 캡처해야 한다.



*/

#include <iostream>
using namespace std;

int main()
{
    //람다함수는 실제로 함수가 만들어지는 것이 아니다.
    //함수의 정의 형식으로 만들기는 하지만,
    //호출부에 쌩제어구조의 바이너리가 만들어져 그대로 삽입되는 것이다.
    //---> 함수의 호출비용이 없으므로 함수로 만든 것보다 빠르다.
    //
    //변경의 국지화가 일어난다
    []() {cout << "This is game" << endl; }; //선언, 정의

    []() {cout << "That is game" << endl; }(); //선언, 정의, 호출

    bool tIs = []() {return false; }(); //<-- 컴파일러가 함수의 구문을 보고 리턴타입을 결정한다
    bool tIs_1 = []()->bool {return true; }(); //리턴타입을 명시적으로 적어줄 수도 있다.

    cout << endl;

    int tA = 3;
    int tB = 2;
    int tResult = 0;

    //tResult는 레퍼런스로, 나머지는 값으로 캡처
    [=,&tResult]() {tResult = tA + tB; }();
    cout << "tResult : " << tResult << endl;

    //tA는 값으로 캡처, tB는 값으로 캡처
    tResult = [tA, tB]() {return tA - tB; }();
    cout << "tResult : " << tResult << endl;

    //tA는 레퍼런스로 캡처, tB는 값으로 캡처
    tResult = [&tA,tB]() 
    {
        tA++;
        return tA * tB; 
    }();
    cout << "tResult : " << tResult << endl;




    return 0;
}


