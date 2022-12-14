#include "CUnit.h"

#include "CAPIEngine.h"  //클래스 전방선언
#include "CTexture.h"

CUnit::CUnit()
	:mX(0.0f), mY(0.0f), mRadius(0.0f)
{
	mDisplayX = 0.0f;
	mDisplayY = 0.0f;
	
	mAnchorX = 0.0f;
	mAnchorY = 0.0f;
	
	mWidth = 0.0f;
	mHeight = 0.0f;
	
	mpTexture = nullptr;
}
CUnit::~CUnit()
{

}

CUnit::CUnit(const CUnit& t)
{
	mX = t.mX;
	mY = t.mY;
	mRadius = t.mRadius;

	mDisplayX = t.mDisplayX;
	mDisplayY = t.mDisplayY;

	mAnchorX = t.mAnchorX;
	mAnchorY = t.mAnchorY;

	mWidth = t.mWidth;
	mHeight = t.mHeight;

	//앝은 복사
	//비트맵 이미지 데이터는 shared resource로 다루겠다.
	//어차피 같은 외관을 가지는 비행기들이므로
	mpTexture = t.mpTexture;
}
void CUnit::operator=(const CUnit& t)
{
	mX = t.mX;
	mY = t.mY;
	mRadius = t.mRadius;

	mDisplayX = t.mDisplayX;
	mDisplayY = t.mDisplayY;

	mAnchorX = t.mAnchorX;
	mAnchorY = t.mAnchorY;

	mWidth = t.mWidth;
	mHeight = t.mHeight;

	//앝은 복사
	//비트맵 이미지 데이터는 shared resource로 다루겠다.
	//어차피 같은 외관을 가지는 비행기들이므로
	mpTexture = t.mpTexture;
}

//CAPIEngine 과의 관계를 매개변수로 표현했다.
//<--CUnit클래스가 CAPIEngine클래스에 의존하는 관계이다.
void CUnit::Render(CAPIEngine* tpEngine)
{

	//피벗을 고려하여 출력하기
	mWidth = mpTexture->mBitmapInfo.bmWidth;
	mHeight = mpTexture->mBitmapInfo.bmHeight;

	//mDisplayX, mDisplayY 결정식
	mDisplayX = mX - mWidth * mAnchorX;
	mDisplayY = mY - mHeight * mAnchorY;

	tpEngine->DrawTexture(mDisplayX, mDisplayY, mpTexture);


	//DEBUG DRAW
	//tpEngine->DrawCircle(mX, mY, mRadius);
}