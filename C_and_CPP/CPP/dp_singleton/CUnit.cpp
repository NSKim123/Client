#include "CUnit.h"
#include "CRyuMgr.h"

void CUnit::DoPlay()
{
	//���� ȹ�� ���
	CRyuMgr::GetInstance()->mScore += 11;
}