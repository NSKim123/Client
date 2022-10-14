

/*

    함수의 overload (중복정의)
        함수가 '이름'은 같고 '매개변수 리스트'가 다른 것 <-- 매개변수의 갯수, 매개변수의 타입이 다르다.
        (리턴타입은 관계없다)
    

    
    같은 이름의 함수 호출을
    서로 다른 매개변수 리스트를 가지고 할 수 있다.

*/


#include <iostream>

using namespace std;

void DisplayAddictive();
void DisplayAddictive(int tA, int tB);
void DisplayAddictive(int tA, int tB, int tC);
void DisplayAddictive(float tA, float tB);

//함수의 overload가 안 된다.
//int DisplayAddictive(int tA, int tB);

int DisplayAddictive(int tA, float tB);

int main()
{
    DisplayAddictive();

    DisplayAddictive(3, 2);

    DisplayAddictive(1, 2, 3);
    //컴파일러가 어느 함수를 호출하는지는
    //넘겨주는 인자의 값(타입으로 결정된)을 보고 결정한다.
    DisplayAddictive(12.5f, 3.3f);

    //DisplayAddictive(12.5f, 2); <-- 에러

    DisplayAddictive(2, 12.5f);

    
    return 0;
}


void DisplayAddictive()
{
    cout << 0 << endl;
}
void DisplayAddictive(int tA, int tB)
{
    int tResult = tA + tB;
    cout << tResult << endl;
}
void DisplayAddictive(int tA, int tB, int tC)
{
    int tResult = tA + tB + tC;
    cout << tResult << endl;
}
void DisplayAddictive(float tA, float tB)
{
    float tResult = tA + tB;
    cout << tResult << endl;
}
int DisplayAddictive(int tA, float tB)
{
    //실수 + 정수 ------> 실수로 (암묵적으로) 형변환 된다.
    float tResult = tA + tB;
    cout << tResult << endl;

    return (int)tResult;
}