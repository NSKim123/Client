// csecond.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//컴퓨터 기본구조 : CPU - RAM(메모리) - 디스크
//저장 : RAM에 있는 내용을 디스크에 저장. (램에 있는 정보는 종료 시 사라짐.)

#include <iostream>
using namespace std;

//window console applicatiomn 윈도우 콘솔 응용프로그램


//'윈도우 콘솔 응용프로그램'의 가장 기본적인 구조

//main함수의 정의. 윈도우 콘솔 응용프로그램의 시작점
int main()
{
    //변수의 선언과 초기화
    //타입은 정수, 이름은 tA, 초기값은 0
    //타입은 정수, 이름은 tB, 초기값은 0
    //타입은 정수, 이름은 tresult, 초기값은 0

    int tA = 0; //메모리 그림을 그려 생각해보기.
    int tB = 0;
    int tResult = 0;

    tA = 3;
    tB = 2;

    //더하기 연산( 정수)
    tResult = tA + tB;

    //한줄 주석 comment : 이 프로그램과 전혀 상관없다. 작성자가 설명문을 달아놓는 용도이다.
    //"" : 문자열
    cout <<"addictive: "<< tResult << endl;  //콘솔에 출력 console output

    //뺴기 연산( 정수)
    tResult = tA - tB;
    cout << "subtract: " << tResult << endl;

    //곱하기 연산( 정수)
    tResult = tA * tB;
    cout << "multiply: " << tResult << endl;

    float tResult_0 = 0.0f;  //리터럴 상수 문자 : 상수의 타입을 확실히 명기
    //나누기 연산( 정수)
    tResult_0 = (float)tA / (float)tB; //형 변환 type cast : 임시적으로 메모리를 다루는 규칙을 바꾼다.
    cout << "divide: " << tResult_0 << endl;

    return 0;
}


