//
//  main.cpp
//  4_tiny_brave1d
//
//  Created by ryu on 2020/02/14.
//  Copyright © 2020 ryu. All rights reserved.
//


/*
 created by pokpoongryu


 지형속성:
 100    집
 200    세상의 끝
 1      슬라임 출몰 지역

 */

#include <iostream>
#include <time.h>

using namespace std;

typedef struct Brave
{
    int tBraveX = 0;
    float tBraveHP = 1000.0f;
    float tBraveAP = 100.0f;
} SBrave;

typedef struct Slime
{
    float tSlimeHP = 200.0f;
    float tSlimeAP = 500.0f;
} SSlime;

void DoBraveDamage(SBrave* tBrave, SSlime* tSlime);
void DoSlimeDamage(SBrave* tBrave, SSlime* tSlime);

typedef void (*DoDamage)(SBrave* tBrave, SSlime* tSlime);

int main()
{
    //함수 포인터를 사용하여 DoBraveDamage, DoSlimeDamage 를 직접호출하고 있는 부분을
    //간접호출로 프로그램 구조를 변경하세요.

    srand((unsigned int)time(nullptr));

    int tWorld[5] = { 100, 0, 1, 0, 200 };

    /*int tBraveX = 0;
    float tBraveHP = 1000.0f;
    float tBraveAP = 100.0f;*/
    SBrave tBrave;

    /*float tSlimeHP = 200.0f;
    float tSlimeAP = 500.0f;*/
    //SSlime tSlime;
    //동적할당
    SSlime* tpSlime = NULL;

    tpSlime = (SSlime*)malloc(sizeof(SSlime) * 1);
    //힙 메모리 초기화, malloc은 초기화를 수행하지 않는다.
    tpSlime->tSlimeHP = 200.0f;
    tpSlime->tSlimeAP = 500.0f; 

    cout << "표인터 변수의 크기: " << sizeof(tpSlime) << endl;

    char tMoveDir = 'd';

   
    DoDamage tDoDamage = NULL;

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
            if (tBrave.tBraveX > 0)
            {
                tBrave.tBraveX = tBrave.tBraveX - 1;
                cout << "<--move left" << endl;
            }
            else
            {
                cout << "Brave can not move any more." << endl;
            }
        }

        if ('d' == tMoveDir)
        {
            if (tBrave.tBraveX < 4)
            {
                tBrave.tBraveX = tBrave.tBraveX + 1;

                cout << "-->move right" << endl;
            }
            else
            {
                cout << "Brave can not move any more." << endl;
            }
        }

        int tAttrib = 0;
        tAttrib = tWorld[tBrave.tBraveX];
        switch (tAttrib)
        {
        case 0: //아무것도 없음
        {
            cout << "No one here." << "(You are on" << tBrave.tBraveX << "Tile)" << endl;
        }
        break;
        case 1: //슬라임 있음
        {
            cout << "Slime is here." << "(You are on" << tBrave.tBraveX << "Tile)" << endl;

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
                        //void DoBraveDamage(Sbrave* tBrave, SSlime* tSlime)
                        //tBrave.tBraveHP = tBrave.tBraveHP - tSlime.tSlimeAP;
                        tDoDamage = DoBraveDamage;
                        cout << "Brave is damaged" << endl;
                    }
                    break;
                    case 4:
                    case 5:
                    case 6:
                    {
                        //void DoSlimeDamage(SBrave* tBrave, SSlime* tSlime)
                        //tSlime.tSlimeHP = tSlime.tSlimeHP - tBrave.tBraveAP;
                        tDoDamage = DoSlimeDamage; 
                        cout << "Slime is damaged." << endl;
                    }
                    break;
                    }

                    tDoDamage(&tBrave, tpSlime);
                    cout << "Brave is damaged" << tBrave.tBraveHP << endl;
                    cout << "Slime is damaged." << tpSlime->tSlimeHP << endl;

                    if (tpSlime->tSlimeHP <= 0)
                    {
                        cout << "Slime is very tired." << endl;

                        break;
                    }
                    if (tBrave.tBraveHP <= 0)
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
            cout << "Brave is in home." << "(You are on" << tBrave.tBraveX << "Tile)" << endl;
        }
        break;
        case 200:
        {
            cout << "Brave is in End of world." << "(You are on" << tBrave.tBraveX << "Tile)" << endl;
        }
        break;
        }
    }


    cout << "슬라임은 심심하다." << endl << "어서 빨리 일어나라! 용사!" << endl;


    if (NULL != tpSlime)
    {
        free(tpSlime);
        tpSlime = NULL;
    }

    return 0;
}

void DoBraveDamage(SBrave* tBrave, SSlime* tSlime)
{
    (* tBrave).tBraveHP = tBrave->tBraveHP - tSlime->tSlimeAP;
}
void DoSlimeDamage(SBrave* tBrave, SSlime* tSlime)
{
    tSlime->tSlimeHP = tSlime->tSlimeHP - tBrave->tBraveAP;
}