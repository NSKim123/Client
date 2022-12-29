#include "CAniSeq.h"
#include "ryumacro.h"
#include "CTexture.h"

CAniSeq::CAniSeq()	
{
    mId = "";    
    mTexs.clear();
    mTimeInterval = 0.0f;
    mTotalFrameCount = 0;  
    mCurFrameIndex = 0;   
    mAniTime = 0.0f;
    mPlayOption = ANI_PO::LOOP;
    
    mSpriteOption = ANI_SO::FRAME_FILE;  //프레임 하나에 파일 하나가 기본

    mSpriteWidth = 0;  //스프라이트 프레임의 너비
    mSpriteHeight = 0; //스프라이트 프레임의 높이

    mRow = 0;   //행
    mCol = 0;   //열
    mFrameCOL = 0;
}
CAniSeq::~CAniSeq()
{
    vector<CTexture*>::iterator tItor;
    for (tItor = mTexs.begin();tItor != mTexs.end();++tItor)
    {
        //SAFE_DELETE((*tItor));        
        SAFE_RELEASE((*tItor));
    }
    mTexs.clear();
}
CAniSeq::CAniSeq(const CAniSeq& t)
{
    mId = t.mId;
    mTexs = t.mTexs;  //stl의 vector의 =연산자는 기본동작이 복사copy이다.
    mTimeInterval = t.mTimeInterval;
    mTotalFrameCount = t.mTotalFrameCount;
    mCurFrameIndex = t.mCurFrameIndex;
    mAniTime = t.mAniTime;
    mPlayOption = t.mPlayOption;

    mSpriteOption = t.mSpriteOption;

    mSpriteWidth = t.mSpriteWidth;
    mSpriteHeight = t.mSpriteHeight;

    mRow = t.mRow;   
    mCol = t.mCol;   
    mFrameCOL = t.mFrameCOL;
}
void CAniSeq::operator=(const CAniSeq& t)
{
    mId = t.mId;
    mTexs = t.mTexs;  //stl의 vector의 =연산자는 기본동작이 복사copy이다.
    mTimeInterval = t.mTimeInterval;
    mTotalFrameCount = t.mTotalFrameCount;
    mCurFrameIndex = t.mCurFrameIndex;
    mAniTime = t.mAniTime;
    mPlayOption = t.mPlayOption;

    mSpriteOption = t.mSpriteOption;

    mSpriteWidth = t.mSpriteWidth;
    mSpriteHeight = t.mSpriteHeight;

    mRow = t.mRow;
    mCol = t.mCol;
    mFrameCOL = t.mFrameCOL;
}
void CAniSeq::Update(float tDeltaTime)
{
    //애니메이션 프레임 진행 루틴
    if (mAniTime >= mTimeInterval)
    {
        //todo
        //스프라이트 프레임의 번호를 하나씩 증가시킨다.
        if (mCurFrameIndex < mTotalFrameCount - 1)
        {
            mCurFrameIndex++;
        }
        else
        {
            mCurFrameIndex = 0;
        }

        mAniTime = 0.0f;
    }
    else
    {
        mAniTime = mAniTime + tDeltaTime;
    }
}