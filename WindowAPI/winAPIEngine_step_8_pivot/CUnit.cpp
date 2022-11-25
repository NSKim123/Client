#include "CUnit.h"

#include "CAPIEngine.h"  //Ŭ���� ���漱��

CUnit::CUnit()
	:mX(0.0f), mY(0.0f), mRadius(0.0f)
{

}
CUnit::~CUnit()
{

}

CUnit::CUnit(const CUnit& t)
{
	mX = t.mX;
	mY = t.mY;
	mRadius = t.mRadius;
}
void CUnit::operator=(const CUnit& t)
{

}

//CAPIEngine ���� ���踦 �Ű������� ǥ���ߴ�.
//<--CUnitŬ������ CAPIEngineŬ������ �����ϴ� �����̴�.
void CUnit::Render(CAPIEngine* tpEngine)
{
	tpEngine->DrawCircle(mX, mY, mRadius);
}