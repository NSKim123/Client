#pragma once

#include <windows.h>
#include <unordered_map>
#include <string>

using namespace std;

class CAniSeq;
class CAPIEngine;

class CAnimator
{
public:
	CAnimator();
	~CAnimator();

	CAnimator(const CAnimator& t);
	void operator=(const CAnimator& t);


public:
	//애니메이션 시퀀스를 추가하는 함수
	bool AddAniSeq(const string& tId, float tTimeInterval, int tTotalFrameCount, LPCWSTR tpFileName);
	//현재 애니메이션 시퀀스를 위해 데이터 갱신
	void UpdateAnimation(float tDeltaTime);
	//현재 애니메이션 시퀀스의 결과 포즈를 랜더링
	void Render(float tX, float tY);

	void Create(CAPIEngine* tpEngine);
	void Destroy();
	inline void SetId(string tId)
	{
		mId = tId;
	}

public:
	//Animation 의 식별자
	string mId = "";



	//실행중에 원하는 애니메이션 시퀀스를 검색하여 플레이를 수행하기 위한 자료구조
	//빠른 검색속도가 중요하므로 O(1)인 해쉬자료구조를 이용하기로함
	//  N개의 애니메이션 시퀀스의 집합
	unordered_map<string, CAniSeq*> mAniSeqs;

	//현재 플레이되고 있는 에니메이션 시퀀스 객체 참조
	CAniSeq* mpCurAniSeq = nullptr;
	string mStrKeyCurAniSeq;  //현재 플레이되고 있는 애니메이션 시퀀스의 문자열 식별자

	//엔진 참조 변수
	CAPIEngine* mpEngine = nullptr;
};

