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

	//���� ����
	//�ִϸ����ʹ� �� ���� ��ü���� ���� �������ϹǷ� ���� ���縦 �����Ͽ���.
	mAniSeqs.clear();
	unordered_map<string, CAniSeq*>::const_iterator tItor;
	for (tItor = t.mAniSeqs.begin();tItor != t.mAniSeqs.end();++tItor)
	{
		//������ ������ü��ŭ �ִϸ��̼ǽ����� ������ �����.
		CAniSeq* tpAniSeq = new CAniSeq();

		*tpAniSeq = *(tItor->second);
		mAniSeqs.insert(make_pair(tpAniSeq->mId, tpAniSeq));
	}

	//shallow copy
	//������ �������� ���Ǵ� �ڿ��̴�.
	mpEngine = t.mpEngine;
	//�� �κ��� SetOwnerObject���� �缳���� ���̴�.
	mpObject = t.mpObject;
}
void CAnimator::operator=(const CAnimator& t)
{
	mId = t.mId;
	mpCurAniSeq = t.mpCurAniSeq;   //??
	mStrKeyCurAniSeq = t.mStrKeyCurAniSeq;

	//���� ����
	//�ִϸ����ʹ� �� ���� ��ü���� ���� �������ϹǷ� ���� ���縦 �����Ͽ���.
	mAniSeqs.clear();
	unordered_map<string, CAniSeq*>::const_iterator tItor;
	for (tItor = t.mAniSeqs.begin();tItor != t.mAniSeqs.end();++tItor)
	{
		//������ ������ü��ŭ �ִϸ��̼ǽ����� ������ �����.
		CAniSeq* tpAniSeq = new CAniSeq();

		*tpAniSeq = *(tItor->second);
		mAniSeqs.insert(make_pair(tpAniSeq->mId, tpAniSeq));
	}
	//shallow copy
	//������ �������� ���Ǵ� �ڿ��̴�.
	mpEngine = t.mpEngine;
	//�� �κ��� SetOwnerObject���� �缳���� ���̴�.
	mpObject = t.mpObject;
}

bool CAnimator::AddAniSeq(const string& tId, float tTimeInterval, int tTotalFrameCount, LPCWSTR tpFileName)
{
	//CAniSeq* Ÿ���� ��ü�� ����� ���� �����Ѵ�.
	CAniSeq* tpAniSeq = new CAniSeq();

	tpAniSeq->mId = tId;
	tpAniSeq->mTimeInterval = tTimeInterval;
	tpAniSeq->mTotalFrameCount = tTotalFrameCount;

	//�� ������ ������ŭ ������ ������ �����Ͽ� �߰��Ѵ�.
	for (int ti = 0;ti < tTotalFrameCount;++ti)
	{
		CTexture* tpTex = nullptr;
		tpTex = new CTexture();
		tpTex->AddRef();

		//bongbong_0.bmp , bongbong_1.bmp
		//�̸� ���ص� �����̸� ��Ģ�� �ٰ��Ͽ� �ۼ��ߴ�.
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
	//���� �ִϸ��̼� ��������
	int tIndex = mpCurAniSeq->mCurFrameIndex;
	//������ ���� �������� �����Ѵ�.
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