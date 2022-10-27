#include "CUnit.h"
#include "CRyuMgr.h"

void CUnit::DoPlay()
{
	//Á¡¼ö È¹µæ ±â´É
	CRyuMgr::GetInstance()->mScore += 11;
}