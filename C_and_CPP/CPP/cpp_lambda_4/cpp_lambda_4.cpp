

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;


int main()
{
    array<int, 5> tArray = { 3,2,1,9,10 };

    //외부변수 모두 값으로 캡춰
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

    return 0;
}


