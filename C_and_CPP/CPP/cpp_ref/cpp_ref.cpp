
/*
    reference
*/

#include <iostream>

using namespace std;

void DoSwap(int* tpA, int* tpB);

void DoSwapRef(int& tA, int& tB);

int main()
{
    //step_0
    int tAA = 777;
    //레퍼런스 연산자 붙여 선언하면
    //'변수의 다른 이름'를 붙인다.
    int& tBB = tAA;
    /*
        i) 선언할 때 같이 초기화해줘야만 한다.
        ii) NULL 값으로 초기화할 수 없다. <-- 포인터 '변수'가 아니므로 당연하다.
        iii) 다른 변수를 간접참조하게 할 수 없다. <-- 포인터 '변수'가 아니므로 당연하다.
    */

    cout << "tAA " << tAA << endl;
    cout << "tBB " << tBB << endl;
    
    //step_1
    /*
    int tA = 3;
    int tB = 2;
    int tResult = 0;

    //before
    cout << tA << "," << tB << endl;

     
    //int tTemp = 0;
    //tTemp = tA;
    //tA = tB;
    //tB = tTemp; 
    
    
    DoSwap(&tA, &tB);

    //after
    cout << tA << "," << tB << endl;
    
    */

    //step_2
    int tA = 3;
    int tB = 2;
    int tResult = 0;

    //before
    cout << tA << "," << tB << endl;


    //int tTemp = 0;
    //tTemp = tA;
    //tA = tB;
    //tB = tTemp; 


    DoSwapRef(tA, tB);

    //after
    cout << tA << "," << tB << endl;

    return 0;
}

//call by address
void DoSwap(int* tpA, int* tpB)
{
    int tTemp =  *tpA;
    *tpA = *tpB;
    *tpB = tTemp;
}
//call by reference
void DoSwapRef(int& tA, int& tB)
{
    int tTemp = 0;
    tTemp = tA;
    tA = tB;
    tB = tTemp;
}