/*

    분할 컴파일 : 클래스 등의 부품 단위로 소스파일을 분리하여 컴파일 하는 것

    
    ========================== build =======================

                    compile             link
        *.cpp      -------->   *.obj   -------->  *.exe
        *.cpp      -------->   *.obj
        *.cpp      -------->   *.obj
        ...
     소스코드파일             목적파일           실행파일
    =========================================================


    분할 컴파일의 목적 :
        
        i) 빌드 시간을 단축한다.(컴파일 시간을 단축하여)  <-- 주요한 목적

            파일 단위로 컴파일을 수행하기 때문에
            수정 사항 발생시
            수정사항이 발생한 파일만 다시 컴파일하면 되므로
            (다른 파일들에 대해서는 이전에 컴파일해둔 obj 파일로 링킹)
            전체적으로 빌드 시간이 단축된다.


        ii) 부품 단위로 파일을 나눌 수 있으므로 작업분담을 하기 좋다.
*/


/*
 created by pokpoongryu


 지형속성:
 100    집
 200    세상의 끝
 1      슬라임 출몰 지역

 */

#include <iostream>
#include <time.h>

//해당 클래스의 형태를 여기에 포함한다.
#include "Brave.h"
#include "Slime.h"

using namespace std;



int main()
{
    srand((unsigned int)time(nullptr));

    int tWorld[5] = { 100, 0, 1, 0, 200 };
    
    //클래스 CBrave 로 데이터 추상화. 접근제한지정자는 그냥 public.
    CBrave tBrave;

    //클래스 CSlime 로 데이터 추상화
    CSlime tSlime;



    char tMoveDir = 'd';




    cout << "((용사와 슬라임))" << endl;
    cout << "==종료하려면 n을 입력하세요==" << endl;


    while (true)
    {
        //input
        cout << "move?(a/d)";
        cin >> tMoveDir;


        if ('n' == tMoveDir)
        {
            cout << "brave is sleeping." << endl;
            break;
        }

        if ('a' == tMoveDir)
        {
            if (tBrave.GetX() > 0)
            {
                //void DoMove(int tVelocity);
                tBrave.DoMove(-1);
                cout << "<--move left" << endl;
            }
            else
            {
                cout << "Brave can not move any more." << endl;
            }
        }

        if ('d' == tMoveDir)
        {
            if (tBrave.GetX() < 4)
            {
                tBrave.DoMove(1);
                cout << "-->move right" << endl;
            }
            else
            {
                cout << "Brave can not move any more." << endl;
            }
        }

        int tAttrib = 0;
        tAttrib = tWorld[tBrave.GetX()];
        switch (tAttrib)
        {
        case 0: //아무것도 없음
        {
            cout << "No one here." << "(You are on" << tBrave.GetX() << "Tile)" << endl;
        }
        break;
        case 1: //슬라임 있음
        {
            cout << "Slime is here." << "(You are on" << tBrave.GetX() << "Tile)" << endl;

            char tIsRollDice = 'r';
            while (1)
            {
                cout << "Roll a Dice of Fate!(r):";
                cin >> tIsRollDice;

                if ('r' == tIsRollDice)
                {
                    //roll dice
                    int tDiceNumber = rand() % 6 + 1;
                    cout << tDiceNumber << endl;

                    switch (tDiceNumber)
                    {
                    case 1:
                    case 2:
                    case 3:
                    {
                        //void DoDamage(int tSlimeAP)
                        tBrave.DoDamage(&tSlime);

                        cout << "Brave is damaged" << endl;
                    }
                    break;
                    case 4:
                    case 5:
                    case 6:
                    {
                        //void DoDamage(int tBraveAP)
                        tSlime.DoDamage(&tBrave);

                        cout << "Slime is damaged." << endl;
                    }
                    break;
                    }

                    if (tSlime.GetHP() <= 0)
                    {
                        cout << "Slime is very tired." << endl;

                        break;
                    }
                    if (tBrave.GetHP() <= 0)
                    {
                        cout << "Brave is very tired." << endl;

                        break;
                    }
                }
            }
        }
        break;
        case 100:
        {
            cout << "Brave is in home." << "(You are on" << tBrave.GetX() << "Tile)" << endl;
        }
        break;
        case 200:
        {
            cout << "Brave is in End of world." << "(You are on" << tBrave.GetX() << "Tile)" << endl;
        }
        break;
        }
    }


    cout << "슬라임은 심심하다." << endl << "어서 빨리 일어나라! 용사!" << endl;


    return 0;
}

