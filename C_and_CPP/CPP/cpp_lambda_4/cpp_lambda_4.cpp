/*
    i) 쌩 제어구조 : 

        이해하기 쉽다.
        코드 규모가 커질수록, 관리가 불편해지고 버그 발생 가능성이 높다.

    ii) 함수 :

        (쌩 제어구조에 비해) 관리가 편리하다.
        함수호출 비용이 있다.

    iii) 인라인 함수 :

        (쌩 제어구조에 비해) 관리가 편리하다.
        함수호출 비용이 없다. <-- 인라인이 아닌 함수에 비해서 속도가 빠르다.

        인라인 적용 여부는 컴파일러가 결정한다.

    iv) 함수객체 :
        
        클래스로 만든다. <-- 함수 호출 연산자를 오버로드한다.
            (쌩 제어구조에 비해) 관리가 편리하다.(장점)

        객체이다.
            객체 처리 비용이 든다.(단점)
            함수객체가 처리한 결과를 기억시켜둘 수 있다.(장점)

        비교적 만들기가 까다롭다.(단점)

    v) 람다함수 :
        
        (쌩 제어구조에 비해) 관리가 편리하다.

        함수호출 비용이 없다.(컴파일하고 나면 썡 제어구조 형태로 컴파일이 되므로)

        람다 여부는 작성자가 결정한다.

        람다함수객체는 처리한 결과를 기억한다.(장점)

*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;


int main()
{
    array<int, 5> tArray = { 3,2,1,9,10 };

    //외부변수 모두 값으로 캡춰
    //람다함수 객체에 람다함수를 담음
    auto tShowOrigin = [=]() 
    {
        cout << "tShowOrigin" << endl;

        for_each(tArray.cbegin(), tArray.cend(),
            [](int tE)
            {
                cout << tE << "\t";
            }
        );
        cout << endl;
    };


    //람다함수객체 호출
    tShowOrigin();

    //tArray 오름차순 정렬 수행
    std::sort(tArray.begin(), tArray.end(), std::less<int>());

    //람다함수 객체에 람다함수를 담음
    auto tShowSorted = [=]()
    {
        cout << "tShowSorted" << endl;

        for_each(tArray.cbegin(), tArray.cend(),
            [](int tE)
            {
                cout << tE << "\t";
            }
        );
        cout << endl;
    };
    //람다함수객체를 이용하여 호출
    tShowSorted();

    /*
        정령하기 전에 만든 '람다함수객체'를 호출해보자
        이 시점에 호출된 '람다함수객체'가 내는 결과는 '정렬되지 않은 것'이다.

        왜냐하면, '값으로 캡쳐'한 것의 결과가 '람다함수객체'에 (내부적으로) 기억되어 있기 때문이다.
        (즉, 유추해보건데, 람다는 데이터가 기억된다는 함수객체의 특성도 가지도록 만들어져 있다.)
    */

    tShowOrigin();  //<--람다함수객체는 그 결과값을 기억한다.
    cout << endl;

    //vs

    std::for_each(tArray.cbegin(), tArray.cend(), [](int tE) {cout << tE << "\t"; });





    return 0;
}


