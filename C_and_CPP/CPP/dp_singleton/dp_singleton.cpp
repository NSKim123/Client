/*
    디자인 패턴 Design Pattern : OOP의 모범답안집
    
        clean code <-- simple + flexible

    디자인 패턴의 분류
        생성 패턴 : '객체'의 '생성'을 어떻게 하느냐에 대한 패턴
        구조 패턴 : 클래스나 객체를 어떻게 조합해서 임의의 프로그램 구조를 작성할 것이냐에 대한 패턴
        행위 패턴 : 알고리즘이나 작업을 어느 객체에 어떻게 작업분담할지에 대한 패턴





        싱글톤 패턴 Singleton Pattern
            
            주목적 : 객체의 최대 생성 갯수를 1개로 제한
            (부목적 : 전역적인 데이터의 관리를 위해서도 사용할 수 있다. 단, 결합도가 높이짐을 주의하여야 한다.)


*/

#include <iostream>

#include "CRyuMgr.h"
#include "CUnit.h"
#include "CUiPlayGame.h"

using namespace std;

int main()
{
    //관리자 객체 생성
    CRyuMgr::GetInstance();

    CUiPlayGame* tpUiPlayGame = nullptr;
    tpUiPlayGame = new CUiPlayGame();

    CUnit* tpUnit = nullptr;
    tpUnit = new CUnit();

    tpUnit->DoPlay();
    tpUiPlayGame->DisPlay();
    tpUnit->DoPlay();
    tpUiPlayGame->DisPlay();
    tpUnit->DoPlay();
    tpUiPlayGame->DisPlay();

    if (nullptr != tpUnit)
    {
        delete tpUnit;
        tpUnit = nullptr;
    }

    if (nullptr != tpUiPlayGame)
    {
        delete tpUiPlayGame;
        tpUiPlayGame = nullptr;
    }

    //관리자 객체 해제
    CRyuMgr::ReleaseInstance();

    return 0;
}


