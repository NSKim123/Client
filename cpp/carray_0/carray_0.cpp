

#include <iostream>

/*
    배열 array : '동일한 타입'의 '원소'들의 (물리적으로) '연속적인' 메모리블럭
        
*/
using namespace std;


int main()
{
    //변수의 선언과 초기화
    //타입은 정수 이름은 tA, 초기값은 0
    int tA = 0;

    //배열의 선언과 초기화
    int tArray[5] = {0,0,0,0,0};
    
    //index 인덱스(첨자)
    //인덱스 접근 연산자 []
    tArray[0] = 4;
    tArray[1] = 0;
    tArray[2] = 1;
    tArray[3] = 2;
    tArray[4] = 3;


    cout << tArray[0] << endl;
    cout << tArray[1] << endl;
    cout << tArray[2] << endl;
    cout << tArray[3] << endl;
    cout << tArray[4] << endl;

    cout << endl;

    int ti = 0;
    for(ti= 0; ti < 5; ti=ti+1)
    {
        cout << tArray[ti] << endl;
    }

    //ti=ti+1
    //ti++  후위 증가 연산자

    for (ti = 0; ti < 5; ti++)
    {
        cout << tArray[ti] << endl;
    }

    return 0;
}

