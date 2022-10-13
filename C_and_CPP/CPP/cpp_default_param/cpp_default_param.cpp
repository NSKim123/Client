
/*
    매개변수 기본값

    함수의 호출시 매개변수parameter의 인자argument의 값을 지정하지 않아도 된다.
    '선언'할 때 지정된 값이 전달된다.

    물론 호출시 값을 지정할 수도 있다.
    이 경우에는 호출시 지정한 값이 전달된다.
*/


#include <iostream>

using namespace std;

int DoAdditive(int tA, int tB);

int CalcuAttackDamage(int tStrength = 1, int tHP = 1, int tHitRatio = 1);//<--선언할 떄 기본값을 지정해줄 수 있다.
//기본값은 맨오른쪽 뒤에서부터 차례대로 채워야 한다.
//int CalcuDefensePoint(int tStength = 2, int tHP); <--에러
int CalcuDefensePoint(int tStength, int tHP = 3);

int main()
{
    int tResult = 0;
    tResult = DoAdditive(3, 2);
    cout << tResult << endl;

    tResult = CalcuAttackDamage(7, 7, 7);
    cout << tResult << endl;
    
    tResult = CalcuAttackDamage();
    cout << tResult << endl;
    
    tResult = CalcuAttackDamage(3,2);
    cout << tResult << endl;

    tResult = CalcuAttackDamage(8);
    cout << tResult << endl;

    //
    tResult = CalcuDefensePoint(5,4);
    cout << tResult << endl;

    tResult = CalcuDefensePoint(5);
    cout << tResult << endl;

    return 0;
}

int DoAdditive(int tA, int tB)
{
    return tA + tB;
}

int CalcuAttackDamage(int tStrength, int tHP, int tHitRatio)
{
    int tResult = tStrength * tHP * tHitRatio;
    return tResult;
}

int CalcuDefensePoint(int tStength, int tHP)
{
    return tStength * tHP;
}