
/*
    STL Standard Template Library

        구성요소 세가지 
            container : 자료구조를 일반화하여 범용적으로 만들어놓은 것
            iterator : container와 algorithm과 같이 사용할 수 있게 만들어진 일반화된 포인터
            algorithm : 알고리즘을 일반화하여 범용적으로 만들어놓은 것




    STL의 list컨테이너

        더블링크드리스트로 만들어졌다.

*/

#include <iostream>
#include <list>
using namespace std;

class CUnit
{
private:
    int mVal = 0;

public:
    CUnit(int tVal)
        :mVal(tVal){
    }
    
    void SetVal(int tVal)
    {
        mVal = tVal;
    }
    int GetVal()
    {
        return mVal;
    }
};



int main()
{
    /*
    CUnit으로 다루면 복사되어 CUnit 객체가 새로 만들어지는 것이다. 
    
    list<CUnit> tUnitList;

    CUnit tUnit(0);
    tUnitList.push_back(tUnit);
    
    */

    //Cunit* 타입의 객체를 다루는 링크드리스트 선언
    list<CUnit*> tUnitList;

    CUnit* tpUnit = nullptr;

    //0번 아이디를 가진 유닛
    tpUnit = nullptr;
    tpUnit = new CUnit(0);

    tUnitList.push_back(tpUnit);

    //1번 아이디를 가진 유닛
    tpUnit = nullptr;
    tpUnit = new CUnit(1);

    tUnitList.push_back(tpUnit);

    //2번 아이디를 가진 유닛
    tpUnit = nullptr;
    tpUnit = new CUnit(2);

    tUnitList.push_back(tpUnit);

    list<CUnit*>::iterator tItor;
    for (tItor = tUnitList.begin(); tItor != tUnitList.end(); ++tItor)
    {
        cout << "원소의 값: " << (*tItor)->GetVal() << endl;
    }                            //iterator 도 포인터 변수이기 때문에 두번 참조해야한다.



    return 0;
}
