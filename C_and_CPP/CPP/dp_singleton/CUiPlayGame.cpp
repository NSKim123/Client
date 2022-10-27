#include "CUiPlayGame.h"
#include "CRyuMgr.h"

#include <iostream>
using namespace std;

void CUiPlayGame::DisPlay()
{
	//점수 표시 기능
	cout << "player`s score : " << CRyuMgr::GetInstance()->mScore << endl;
}