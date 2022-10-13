
/*
    namespace
    


*/

//전역 영역
//지역 영역(함수의 정의 영역)
//사용자 정의 타입의 정의 영역

//이름 영역

#include <iostream>


namespace Name_0
{
    void Doit();
}
namespace Name_1
{
    void Doit();
}

//step_1
using namespace Name_0;
//using namespace Name_1;

int main()
{
    //step_0
    Name_0::Doit();
    Name_1::Doit();

    //step_1
    Doit();

    return 0;
}

// ::  영역 결정 연산자(범위 지정 연산자) scope resolution operator
//     해당 부품이 어디에 속하는지를 나타내는 연산자
void Name_0::Doit()
{
    std::cout << "Name_0::Doit()" << std::endl;
}

void Name_1::Doit()
{
    std::cout << "Name_1::Doit()" << std::endl;
}