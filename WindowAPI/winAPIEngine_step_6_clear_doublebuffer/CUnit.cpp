#include "CUnit.h"

#include "CAPIEngine.h"  //클래스 전방선언

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

//CAPIEngine 과의 관계를 매개변수로 표현했다.
//<--CUnit클래스가 CAPIEngine클래스에 의존하는 관계이다.
void CUnit::Render(CAPIEngine* tpEngine)
{
	tpEngine->DrawCircle(mX, mY, mRadius);
}