/*
    구조화 프로그래밍 stryctured programming
    객체지향 프로그래밍 OOP Object Oriented Programming

        클래스나 객체의 '관계'들로 프로그램 구조를 작성하는 방법
        
        추상화 abstraction : 데이터의 추상화 + 코드의 추상화 ----> 데이터의 추상화
        은닉화 encapsulation : 데이터를 감춘다.
        ------------------객체의 근간----------------
        상속성 inheritence  : 공통된 특성을 부모클래스에 두고 자식클래스는 이를 이어받아 작성. 코드의 효율적인 재사용
        다형성 : 같은 메시지의 다른 반응. override + virtual + 부모클래스 포인터 타입


    일반화 프로그래밍 General Programming

        타입type을 매개변수화하여 다루는 기법


    템플릿 template 
        cpp의 일반화 프로그래밍( General Programming ) 도구

*/



#include <iostream>

using namespace std;

//함수의 오버로드 <-- 함수가 이름은 같고 매개변수리스트가 다른 것

//함수 이름은 DoAdd, 리턴타입은 int, 매개변수는 두개, 각각 int
//함수 이름은 DoAdd, 리턴타입은 float, 매개변수는 두개, 각각 float
// 기능은 두 수의 덧셈

/*
int DoAdd(int tA, int tB);
float DoAdd(float tA, float tB);
*/


/*
    컴파일러가 호출부의 코드를 해석하여 T를 결정하고
    거기에 대한 함수를 컴파일 시점에 만든다.
*/


//탬플릿 함수
template<typename T>
T DoAdd(T tA, T tB);

int main()
{
    int tResult_0 = 0;
    tResult_0 = DoAdd(3, 2);
    cout << tResult_0 << endl;

    float tResult_1 = 0.0f;
    tResult_1 = DoAdd(3.0f, 2.5f);
    cout << tResult_1 << endl;

    char tResult_2 = 0;
    tResult_2 = DoAdd(95, 2);
    cout << tResult_2 << endl;
    
    //
    int tResult_3 = 0;
    tResult_3 = DoAdd<float>(95.5f, 2.3f);  //명시적으로 타입을 밝혀서 써줄 수도 있다.
    cout << tResult_3 << endl;

    return 0;
}

/*
int DoAdd(int tA, int tB)
{
    return tA + tB;
}
float DoAdd(float tA, float tB)
{
    return tA + tB;
}
*/

template<typename T>
T DoAdd(T tA, T tB)
{
    return tA + tB;
}