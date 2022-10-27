#include "CRyuMgr.h"

//static 예약어가 적용된 변수의 초기화
//전역 공간에서 수행했다.
CRyuMgr* CRyuMgr::mpInstance = nullptr;

CRyuMgr::CRyuMgr()
{
	//요즘 컴파일러는 이것도 허용한다
	//mpInstance = nullptr;
}
CRyuMgr::~CRyuMgr()
{

}

CRyuMgr* CRyuMgr::GetInstance()
{
	//mpInstance가 null인 경우에만 만든다.
	//딱 한개만 만든다.
	if (nullptr == mpInstance)
	{
		mpInstance = new CRyuMgr();
	}

	return mpInstance;
}
void CRyuMgr::ReleaseInstance()
{
	if (nullptr != mpInstance)
	{
		delete mpInstance;
		mpInstance = nullptr;
	}
}