
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

class CIsLesser
{
public:
    bool operator()(int tA, int tB)
    {
        return tA < tB;
    }
};

//홀수인지 판별하는 함수객체 클래스(타입)
class CIsOdd
{
public:
    bool operator()(int tE)
    {
        return tE % 2 == 1;
    }
};

bool IsOdd(int tE);

int main()
{
    //step_0
    array<int, 5> tIntArray = { 333, 222, 1, 55, 777 };

    //before
    auto tRyu = tIntArray.cbegin();    //c 접두사는 const의 의미, 간접참조 당하는 원소가 read only
    while (tRyu != tIntArray.cend())
    {
        cout << *tRyu++ << endl;  //간접참조 후에, 다음 반복자로 의 의미이다.
    }

    cout << endl;
    //정렬 함수
    //   정렬 sort : 순서(수의 대소관계)없이 나열된 것들을 순서 있게 다시 나열하는 것
    // 
    //오름차순 정렬( 작은 것부터 큰 것 순서대로 )
    //std::sort(tIntArray.begin(), tIntArray.end(), CIsLesser());   //CIsLesser() 생성자를 호출하여 객체를 만들어 넘김
    //std::sort(tIntArray.begin(), tIntArray.end(), std::less<int>());  //<--이것은 미리 만들어져 제공되는 것이다.
     
    //내림차순
    std::sort(tIntArray.begin(), tIntArray.end(), std::greater<int>()); //<--이것은 미리 만들어져 제공되는 것이다.

    //after
    tRyu = tIntArray.cbegin();    
    while (tRyu != tIntArray.cend())
    {
        cout << *tRyu++ << endl;  
    }



    //step_1
    //람다함수 lambda: 익명(이름이 없는) 함수

    //람다함수 기본형식.
    []() {};  //캡춰절, 매개변수리스트, 함수몸체
    //이를테면, 함수의 선언과 정의를 이 위치에서 한꺼번에 수행한 것이다

    []() {cout << "I am a Good Boy." << endl; };
    //여기서는 함수 몸체를 정의해봤다.

    //캡춰절, 매개변수리스트. 함수몸체, 함수호출연산자
    []() {cout << "You are a Good Girl." << endl; }();

    //마치 함수포인터처럼 간접호출의 도구로도 사용가능하다.
    auto t = []() { cout << "BAD BOY" << endl; }; //람다함수를 객체에 담음
    t();  //람다함수객체 호출



    //step_2
    //함수객체 + 알고리즘함수를 이용하여 첫번쨰 나오는 홀수 찾기

    array<int, 5> tArray = { 222,1,55,333,777 };

    CIsOdd tIsOdd;
    auto tP = std::find_if(tArray.cbegin(), tArray.cend(), tIsOdd);
    cout << "find: " << *tP << endl;

    cout << endl;

    //람다를 이용하여 위의 구문을 작성해보자
    auto tR = std::find_if(tArray.cbegin(), tArray.cend(), [](int tE) {return tE % 2 == 1; });
    cout << "find: " << *tR << endl;

    cout << endl;
    //일반적인 전역함수를 사용하여 위의 구문을 작성해보자
    auto tQ = std::find_if(tArray.cbegin(), tArray.cend(), IsOdd);
    cout << "find: " << *tQ << endl;


    return 0;
}

bool IsOdd(int tE)
{
    return tE % 2 == 1;
}