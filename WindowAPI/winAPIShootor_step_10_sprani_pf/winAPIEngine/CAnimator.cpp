#include "CAnimator.h"
#include "ryumacro.h"
#include "CAniSeq.h"
#include "CAPIEngine.h"

#include "CTexture.h"

CAnimator::CAnimator()
{
	mId = "";
	mpCurAniSeq = nullptr;
	mStrKeyCurAniSeq = "";

	mAniSeqs.clear();

	mpEngine = nullptr;
	mpObject = nullptr;
}
CAnimator::~CAnimator()
{
	unordered_map<string, CAniSeq*>::iterator tItor;
	for (tItor = mAniSeqs.begin();tItor != mAniSeqs.end();++tItor)
	{
		SAFE_DELETE(tItor->second);
	}
	mAniSeqs.clear();
}

CAnimator::CAnimator(const CAnimator& t)
{
	mId = t.mId;
	mpCurAniSeq = t.mpCurAniSeq;   //??
	mStrKeyCurAniSeq = t.mStrKeyCurAniSeq;

	//깊은 복사
	//애니메이터는 각 유닛 객체마다 따로 가져야하므로 깊은 복사를 수행하였다.
	mAniSeqs.clear();
	unordered_map<string, CAniSeq*>::const_iterator tItor;
	for (tItor = t.mAniSeqs.begin();tItor != t.mAniSeqs.end();++tItor)
	{
		//복사의 원본객체만큼 애니메이션시퀀스 갯수를 만든다.
		CAniSeq* tpAniSeq = new CAniSeq();

		*tpAniSeq = *(tItor->second);
		mAniSeqs.insert(make_pair(tpAniSeq->mId, tpAniSeq));
	}

	//shallow copy
	//엔진은 공용으로 사용되는 자원이다.
	mpEngine = t.mpEngine;
	//이 부분은 SetOwnerObject에서 재설정될 것이다.
	mpObject = t.mpObject;
}
void CAnimator::operator=(const CAnimator& t)
{
	mId = t.mId;
	mpCurAniSeq = t.mpCurAniSeq;   //??
	mStrKeyCurAniSeq = t.mStrKeyCurAniSeq;

	//깊은 복사
	//애니메이터는 각 유닛 객체마다 따로 가져야하므로 깊은 복사를 수행하였다.
	mAniSeqs.clear();
	unordered_map<string, CAniSeq*>::const_iterator tItor;
	for (tItor = t.mAniSeqs.begin();tItor != t.mAniSeqs.end();++tItor)
	{
		//복사의 원본객체만큼 애니메이션시퀀스 갯수를 만든다.
		CAniSeq* tpAniSeq = new CAniSeq();

		*tpAniSeq = *(tItor->second);
		mAniSeqs.insert(make_pair(tpAniSeq->mId, tpAniSeq));
	}
	//shallow copy
	//엔진은 공용으로 사용되는 자원이다.
	mpEngine = t.mpEngine;
	//이 부분은 SetOwnerObject에서 재설정될 것이다.
	mpObject = t.mpObject;
}

bool CAnimator::AddAniSeq(const string& tId, float tTimeInterval, int tTotalFrameCount, LPCWSTR tpFileName)
{
	//CAniSeq* 타입의 객체를 만들고 값을 설정한다.
	CAniSeq* tpAniSeq = new CAniSeq();

	tpAniSeq->mId = tId;
	tpAniSeq->mTimeInterval = tTimeInterval;
	tpAniSeq->mTotalFrameCount = tTotalFrameCount;

	//총 프레임 갯수만큼 프레임 정보를 생성하여 추가한다.
	for (int ti = 0;ti < tTotalFrameCount;++ti)
	{
		CTexture* tpTex = nullptr;
		tpTex = new CTexture();
		tpTex->AddRef();

		//bongbong_0.bmp , bongbong_1.bmp
		//미리 정해둔 파일이름 규칙에 근거하여 작성했다.
		WCHAR szTemp[256] = { 0 };
		wsprintf(szTemp, L"%s_%d.bmp", tpFileName, ti);

		tpTex->LoadTexture(mpEngine->GetHInstance(), mpEngine->GetHDC(), szTemp);
		tpAniSeq->mTexs.push_back(tpTex);
	}

	mAniSeqs.insert(make_pair(tId, tpAniSeq));

	return true;
}
void CAnimator::UpdateAnimation(float tDeltaTime)
{
	//test data
	mStrKeyCurAniSeq = "ani_idle_actor";

	unordered_map<string, CAniSeq*>::const_iterator tItor = mAniSeqs.find(mStrKeyCurAniSeq);

	if (tItor != mAniSeqs.end())
	{
		mpCurAniSeq = tItor->second;

		mpCurAniSeq->Update(tDeltaTime);
	}
}
void CAnimator::Render(float tX, float tY)
{
	//현재 애니메이션 시퀀스에
	int tIndex = mpCurAniSeq->mCurFrameIndex;
	//임의의 현재 프레임을 랜더한다.
	CTexture* tpTex = nullptr;
	tpTex = mpCurAniSeq->mTexs[tIndex];
	
	if (tpTex)
	{
		mpEngine->DrawTexture(tX, tY, tpTex);
	}

}

void CAnimator::Create(CAPIEngine* tpEngine)
{
	mpEngine = tpEngine;
}
void CAnimator::Destroy()
{

}