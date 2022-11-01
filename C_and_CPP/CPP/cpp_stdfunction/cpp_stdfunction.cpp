/*
    std::function 객체

    호출가능한 것(callable)에 대표적인 것
        함수
        함수객체
        람다

    cpp에서는 ()를 붙여서 호출할 수 있는 모든 것을 Callable이라고 정의한다
        대표적인 것이 '함수'이다.


    std::function은 호출가능한 것들을 모두 다룰 수 있게 만들어졌다.



*/

#include <iostream>
#include <functional>  //<-- std::function을 사용하기 위해 포함
using namespace std;

//예시라서 간단히 하기 위해 선언, 정의를 합쳐 명기했다.
void DoAdd(int tA, int tB)
{
    int tResult = tA + tB;
    cout << "tResult: " << tResult << endl;
}

//함수객체로 위의 DoAdd함수의 기능을 만들어보기
class CAdd
{
public:
    void operator()(int tA, int tB)
    {
        int tResult = tA + tB;
        cout << "tResult: " << tResult << endl;
    }
};


int main()
{
    //step_0
    //호출가능한 것들

    DoAdd(3, 2);   //callable

    CAdd tAdd;
    tAdd(1, 2);    //callable

    //람다함수를 이용하여 DoAdd 함수와 같은 기능을 만들고, 람다함수 객체에 담고, 람다함수객체를 호출
    auto LAdd = [](int tA, int tB)
    {
        int tResult = tA + tB;
        cout << "tResult: " << tResult << endl; 
    };
    LAdd(2, 5);    //callable



    //step_1
    //std::function
    //간접호출 도구
    //cpp에서는 이러한 callable들을 객체로 담아두고 다룰 수 있게 'std::function 클래스'를 제공한다
    //템플릿 인자로 함수의 원형(signature) 을 넘겨준다
    std::function<void(int, int)> tFunc_0 = DoAdd;   //일반 함수를 담음
    tFunc_0(9, 1);

    std::function<void(int, int)> tFunc_1 = tAdd;    //함수객체를 담음
    tFunc_1(3, 12);

    std::function<void(int, int)> tFunc_2 = LAdd;    //람다함수객체를 담음
    tFunc_2(9, 10);



    //step_2
    //std::bind
    //호출가능한 것들을 객체화하면서, 필요한 값들도 바인드bind(연동)한다.

    auto tAddRyu_0 = std::bind(DoAdd, 3, 2);   //<--바인드 명기 시점에 아예 인자들을 지정
    tAddRyu_0(); //5

    auto tAddRyu_1 = std::bind(DoAdd, 3, std::placeholders::_1);   //<--바인드 명기 시점에 인자의 일부를 지정도하고, 호출하여 실행시 어떻게 수행할지도 지정
    tAddRyu_1(11); //14

    auto tAddRyu_2 = std::bind(DoAdd, std::placeholders::_1, std::placeholders::_2);
    tAddRyu_2(10, 7); //17
    
    auto tAddRyu_3 = std::bind(DoAdd, 11, std::placeholders::_2);
    tAddRyu_3(10, 7); //18

    auto tAddRyu_4 = std::bind(DoAdd, std::placeholders::_2, std::placeholders::_2);
    tAddRyu_4(10, 7); //14


    return 0;
}

