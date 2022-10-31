

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

class CEvenOddFunctor
{
public:
    void operator()(int tX)
    {
        if (0 == tX % 2)
        {
            mEvenSum = mEvenSum + tX;
        }
        else
        {
            mOddSum = mOddSum + tX;
        }
    }
    int GetEvenSum() { return mEvenSum; };
    int GetOddSum() { return mOddSum; };


private:
    int mEvenSum = 0;
    int mOddSum = 0;
};

int main()
{
    CEvenOddFunctor tFunctor;
    
    array<int, 3> tArray = { 1,2,3 };

    tFunctor = for_each(tArray.begin(), tArray.end(), tFunctor);

    cout << tFunctor.GetEvenSum() << endl;
    cout << tFunctor.GetOddSum() << endl;


    //위의 구문을 람다함수를 이용해 만들어보자

    //외부변수 <-- 람다함수가 있는 지역의 변수를 람다함수는 가져와 사용가능하다.
    int tEvenSum = 0;
    int tOddSum = 0;

    for_each(tArray.begin(), tArray.end(),
        [&](int tX) //<--레퍼런스 형식으로 외부변수를 캡춰
        {
            if (0 == tX % 2)
            {
                tEvenSum = tEvenSum + tX;
            }
            else
            {
                tOddSum = tOddSum + tX;
            }
        }    
    );

    cout << tEvenSum << endl;
    cout << tOddSum << endl;

    return 0;
}


