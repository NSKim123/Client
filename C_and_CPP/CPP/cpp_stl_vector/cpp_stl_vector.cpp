




/*
    STL의 vector
        STL Standard Template Library 표준 템플릿 라이브러리
        -템플릿 template : cpp에서 일반화프로그래밍 도구
        -라이브러리 library : 임의의 클래스, 함수의 집합
        
        템플릿 문법을 이용하여 만들어진 표준적인 클래스와 함수 모음집

    
    STL의 세가지 구성요소

        i) 컨테이너 container : 자료구조를 일반화하여 만들어 둔 것(그러므로 범용성을 가진다)
        ii) 반복자 iterator : 컨테이너와 알고리즘과 같이 사용할 수 있게 만들어진 '일반화된 포인터' 형식이다.
        iii) 알고리즘 algorithm : 알고리즘을 일반화하여 만들어 둔 것(그러므로 범용성을 가진다)

    vector
        가변 배열: 실행 중에 배열의 크기가 바뀔 수 있다. <-- 원소가 추가, 삭제될 수 있다.


    자료구조 와 알고리즘


    자료구조 data structure : 자료들을 담아두는 구조물
        예) 배열, ...

    알고리즘 algorithm : 임의의 문제를 해결할 수 있는 절차적인 명세  


*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tArray[5] = { 0 };
    //원시 배열, compile time에 해당 배열의 크기가 결정된다
    //실행 중에는 바꿀 수 없다.

    vector<int> tArray_0; //배열의 이름은 tArray_0, 원소는 0개, 가변배열

    //배열의 원소의 갯수를 얻어오는 함수
    cout << "tArray_0의 원소의 갯수: " << tArray_0.size() << endl;

    tArray_0.resize(5);
    cout << "tArray_0의 원소의 갯수: " << tArray_0.size() << endl;

    for (int ti = 0; ti < tArray_0.size(); ++ti)
    {
        cout << tArray_0.at(ti) << endl; //인덱스를 인자로 원소에 접근한다.
    }

    //해당 값을 가진 원소를 배열의 맨 뒤에 하나 추가
    tArray_0.push_back(777);
    tArray_0.push_back(3);

    cout << endl;
    for (int ti = 0; ti < tArray_0.size(); ++ti)
    {
        cout << tArray_0.at(ti) << endl; //인덱스를 인자로 원소에 접근한다.
    }

    //맨 뒤에 원소 하나를 삭제
    tArray_0.pop_back();

    cout << endl;
    for (int ti = 0; ti < tArray_0.size(); ++ti)
    {
        cout << tArray_0.at(ti) << endl; //인덱스를 인자로 원소에 접근한다.
    }

    tArray_0.push_back(999);

    cout << endl;
    for (int ti = 0; ti < tArray_0.size(); ++ti)
    {
        //[] 인덱스 접근 연산자도 지원한다
        cout << tArray_0[ti] << endl; //인덱스 접근 연산자
    }

    tArray_0[0] = 1024;


    vector<int>::iterator tItor;
    //반복자를 이용한 순회(traverse, 모든 원소를 중복없이 한번씩 방문하는 것)구문
    for (tItor = tArray_0.begin(); tItor != tArray_0.end(); ++tItor)
    {
        cout << *tItor << endl;
    }
    return 0;
}
