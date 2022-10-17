

#include <iostream>
//bitset 컨테이너를 사용하기 위해 포함
#include <bitset>

using namespace std;

/*

    비트 연산자

    &   AND
    |   OR
    ^   XOR     배타적 논리합
    ~   NOT
    <<  left shift
    >>  right shift

*/


int main()
{
    bitset<8> tBitset_0;
    tBitset_0.reset(); // 0000 0000
    tBitset_0 = 127;   // 0111 1111

    bitset<8> tBitset_1;
    tBitset_1.reset(); // 0000 0000
    tBitset_1 = 0x20;  // 0010 0000 , 십진수 32

    bitset<8> tBitset_2 = tBitset_0 & tBitset_1; //둘다 1이면 1, 하나라도 0이면 0
    bitset<8> tBitset_3 = tBitset_0 | tBitset_1; //하나라도 1이면 1, 둘다 0이면 0
    bitset<8> tBitset_4 = tBitset_0 ^ tBitset_1; //배타적 논리합, 다르면 1, 같으면 0
    bitset<8> tBitset_5 = ~tBitset_0;            //반대
    bitset<8> tBitset_6 = tBitset_1 << 1;        //비트 쉬프트, 자리이동
    bitset<8> tBitset_7 = ~tBitset_1 >> 1;       //~연산이 먼저 일어난다.
    
    cout << tBitset_2 << ", " << tBitset_2.to_ulong() << endl;
    cout << tBitset_3 << ", " << tBitset_3.to_ulong() << endl;
    cout << tBitset_4 << ", " << tBitset_4.to_ulong() << endl;
    cout << tBitset_5 << ", " << tBitset_5.to_ulong() << endl;
    cout << tBitset_6 << ", " << tBitset_6.to_ulong() << endl;
    cout << tBitset_7 << ", " << tBitset_7.to_ulong() << endl;

    return 0;
}


