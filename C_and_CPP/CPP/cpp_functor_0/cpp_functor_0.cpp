

#include <iostream>
#include <array> //cpp11의 array
#include <algorithm> //stl의 algorithm

using namespace std;

/*
    functor 함수객체

*/



class CEvenOddFunctor
{
public:
    //'함수 호출 연산자'() 를 overload
    void operator()(int tX)
    {
        if (0 == tX%2)
        {
            mEvenSum = mEvenSum + tX;
        }
        else
        {
            mOddSum = mOddSum + tX;
        }
    }



    int GetEvenSum()
    {
        return mEvenSum;
    }
    int GetOddSum()
    {
        return mOddSum;
    }

private:
    int mEvenSum = 0; //짝수들을 누적해서 합
    int mOddSum = 0;  //홀수들을 누적해서 합  
};


int main()
{
    //step_0
    CEvenOddFunctor tFunctor_0;

    tFunctor_0(3); //'함수객체'를 호출
    //함수는 아니지만 함수호출 표현이 만들어졌다.

    cout << tFunctor_0.GetEvenSum() << endl;
    cout << tFunctor_0.GetOddSum() << endl;


    //step_1
    CEvenOddFunctor tFunctor_1;

    array<int, 3> tArray = { 1,2,3 };

    //STL 알고리즘에 함수 객체 사용. 여기서 배열의 각각의 원소들(객체들)의 ()연산자가 호출된다.
    //  호출은 for_each내부에서 되는 것이고, tFunctor_1은 부품으로 사용되는 것이다
    tFunctor_1 = for_each(tArray.begin(), tArray.end(), tFunctor_1);
            //알고리즘의 이런 표현은 프로그래머의 실수를 방지하게 해주는 역할을 한다.

    cout << endl;
    cout << tFunctor_1.GetEvenSum() << endl;
    cout << tFunctor_1.GetOddSum() << endl;


    return 0;
}


