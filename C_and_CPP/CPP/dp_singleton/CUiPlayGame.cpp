#include "CUiPlayGame.h"
#include "CRyuMgr.h"

#include <iostream>
using namespace std;

void CUiPlayGame::DisPlay()
{
	//���� ǥ�� ���
	cout << "player`s score : " << CRyuMgr::GetInstance()->mScore << endl;
}