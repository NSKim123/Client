
/*

    inline 예약어

        'inline 함수'를 만든다.

        코드 상으로는 함수 형태를 띄지만
        실제로 컴파일 결과물은 쌩제어구조의 결과물이라는 이야기이다.

        inline키워드가 적용된 함수는 호출지점에 해당 함수의 정의의 코드가
        그대로 바이너리로 컴파일되어 삽입된다.
        즉, 함수호출비용이 없다.
        --> 그리하여 속도가 빨라진다.

        inlinging을 수행하는 것은 컴파일러이다.
        다만,
        inlinging 수행여부는 컴파일러가 알아서 한다.
        즉, 인라인함수가 반드시 된다는 보장은 없다.


        대개, 자주 호출되는 짧은 정의의 코드는 인라인 후보로 삼는다. 

*/

#include <iostream>

//함수의 선언 앞에 inline예약어를 적용한다.
inline int DoMax(int tA, int tB);


int main()
{
    int tResult = 0;

    tResult = DoMax(3, 12);
    std::cout << tResult << std::endl;


    return 0;
}

int DoMax(int tA, int tB)
{
    //삼항 연산자
    //(조건식)?A:B
    return tA > tB ? tA : tB;
}

