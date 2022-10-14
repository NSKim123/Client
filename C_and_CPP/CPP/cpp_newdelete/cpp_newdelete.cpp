
/*
    cpp 동적 메모리 할당과 해제
    
    new
    delete

    cpp의 new/delete는 '연산자' 이다.
    ( c의 malloc/free는 '함수'이다 )

    i) '연산자' 이다.
    ii) new 연산자 사용시 힙메모리를 초기화할 수 있는 수단을 제공한다.(생성자)
    ( mallic 함수 호출은 호출했다고 해서 메모리를 초기화해주지는 않는다.

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    //step_0
    //C버전
    int* tpPtr_0 = NULL;
    tpPtr_0 = (int*)malloc(sizeof(int) * 1);

    if (NULL != tpPtr_0)
    {
        free(tpPtr_0);
        tpPtr_0 = NULL;
    }

    //CPP버전
    int* tpPtr_1 = nullptr;
    tpPtr_1 = new int;  //생성자 호출

    if (nullptr != tpPtr_1)
    {
        delete tpPtr_1; //소멸자 호출
        tpPtr_1 = nullptr;
    }

    //char 타입의 변수 하나를 힙메모리에 할당하고 'a'로 설정하고 출력해라
    char* tpPtr_2 = nullptr;
    tpPtr_2 = new char;
    
    if (nullptr != tpPtr_2)
    {
        *tpPtr_2 = 'a';
        cout << *tpPtr_2 << endl;
    }

    if (nullptr != tpPtr_2)
    {
        delete tpPtr_2;
        tpPtr_2 = nullptr;
    }

    //step_1
    //  malloc 과는 동작이 좀 다르다. 즉, C에서는 그냥 메모리 덩어리로 해석하는 경향이 있는 것이다.
    //  CPP에서는 좀 다르게 '객체'라는 개념으로 보기 위한 장치 들이 마련된다.
    int* tpPtr_3 = nullptr;
    tpPtr_3 = new int[5];

    for (int ti = 0; ti < 5; ++ti)
    {
        *(tpPtr_3 + ti) = ti;
    }

    for (int ti = 0; ti < 5; ++ti)
    {
        cout << *(tpPtr_3 + ti) << endl;
    }


    if (nullptr != tpPtr_3)
    {
        delete[] tpPtr_3; //<--delete[]로 해제하는 것에 주의
        tpPtr_3 = nullptr;
    }

    return 0;
}


