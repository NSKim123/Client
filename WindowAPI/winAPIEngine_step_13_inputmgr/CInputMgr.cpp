#include "CInputMgr.h"
#include "ryumacro.h"

/*
CInputMgr* CInputMgr::mpInstance = nullptr;

CInputMgr* CInputMgr::GetInstance()
{
	if (nullptr == mpInstance)
	{
		mpInstance = new CInputMgr();
	}

	return mpInstance;
}
void CInputMgr::ReleaseInstance()
{
	if (nullptr != mpInstance)
	{
		delete mpInstance;
		mpInstance = nullptr;
	}
}
*/

SINGLETON_DEFINITION(CInputMgr);

CInputMgr::CInputMgr()
{
	mMapKeys.clear();
}
CInputMgr::~CInputMgr()
{
	unordered_map<string, SKeyInfo*>::iterator tItor;

	for (tItor = mMapKeys.begin(); tItor != mMapKeys.end(); ++tItor)
	{
		/*if (nullptr != tItor->second)
		{
			delete tItor->second;
			tItor->second = nullptr;
		}*/
		SAFE_DELETE(tItor->second);
	}

	mMapKeys.clear();
}

void CInputMgr::Update()
{
	unordered_map<string, SKeyInfo*>::iterator tItor;
	//등록된 입력데이터 들에 대해 순회
	for (tItor = mMapKeys.begin(); tItor != mMapKeys.end(); ++tItor)
	{
		//임의 입력에 대해 눌림이 있는지 검토
		int tPushCount = 0;
		if (GetAsyncKeyState(tItor->second->mKeyInput) & 0x8000)
		{
			++tPushCount; //눌림이 있다면 해당입력에 대해 카운트 하나 증가.
		}

		//해당 입력에 대해 눌림이 있다.
		if (1 == tPushCount)
		{
			//down도 아니고 press 도 아니다 ---> 처음 눌린 것이다.
			if (!tItor->second->mIsDown && !tItor->second->mIsPress)
			{

			}
			//down이고 press는 아니다 ---> 눌리고 있는 중이다.
			else if(tItor->second->mIsDown && !tItor->second->mIsPress)
			{

			}
		}
		//해당 입력에 대해 눌림이 없다.
		else
		{
			//down 이거나 press 이다 ---> 눌림이 있다가 떼어지는 것이다.
			if (tItor->second->mIsDown || tItor->second->mIsPress)
			{

			}
			//up 이다 -----> 아무 입력도 없는 상태이다.
			else if (tItor->second->mIsUp)
			{

			}
		}
	}

}

SKeyInfo* CInputMgr::FindKey(const string& tStrKey) const
{
	//해쉬는 검색에 특화된 자료구조다. O(1)
	//find 함수는 const_iterator를 리턴한다.
	unordered_map<string, SKeyInfo*>::const_iterator tItor = mMapKeys.find(tStrKey);

	if (tItor == mMapKeys.end())
	{
		//검색실패
		return nullptr;
	}
	

	return tItor->second;
}

//임의의 입력에 대한 상태여부
bool CInputMgr::KetDown(const string& tStrKey) const
{
	SKeyInfo* tpInfo = FindKey(tStrKey);

	if (nullptr == tpInfo)
	{
		return false;
	}

	return tpInfo->mIsDown;
}
bool CInputMgr::KetPress(const string& tStrKey) const
{
	SKeyInfo* tpInfo = FindKey(tStrKey);

	if (nullptr == tpInfo)
	{
		return false;
	}

	return tpInfo->mIsPress;
}
bool CInputMgr::KetUp(const string& tStrKey) const
{
	SKeyInfo* tpInfo = FindKey(tStrKey);

	if (nullptr == tpInfo)
	{
		return false;
	}

	return tpInfo->mIsUp;
}