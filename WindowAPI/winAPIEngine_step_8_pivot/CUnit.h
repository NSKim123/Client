#pragma once

class CAPIEngine; //클래스 전방선언
class CTexture;

class CUnit
{
public:
	CUnit();
	~CUnit();

	//복사생성자
	CUnit(const CUnit& t);
	//복사대입연산자
	void operator=(const CUnit& t);  //연쇄 대입은 고려하지 않겠다.

public:
	void Render(CAPIEngine* tpEngine);
	
	inline void SetPosition(float tX, float tY)
	{
		mX = tX;
		mY = tY;
	}
	inline void SetRadius(float tRadius)
	{
		mRadius = tRadius;
	}
	inline void SetAnchorPoint(float tAnchorX, float tAnchorY)
	{
		mAnchorX = tAnchorX;
		mAnchorY = tAnchorY;
	}
	inline void SetTexture(CTexture* tpTexture)
	{
		mpTexture = tpTexture;
	}

public:
	//2차원, 연속적인 공간을 가정하여 데이터와 타입을 디자인했다.
	float mX = 0.0f;
	float mY = 0.0f;

	float mRadius = 0.0f;

	//pivot
	//피벗개념을 달성하기 위해 필요한 데이터들을 멤버변수로 만들었다.
	//실제 출력 위치
	float mDisplayX = 0.0f;
	float mDisplayY = 0.0f;
	//[0,1]로 정규화된 기준에서의 위치
	float mAnchorX = 0.0f;
	float mAnchorY = 0.0f;
	//비트맵의 너비, 높이
	float mWidth = 0.0f;
	float mHeight = 0.0f;
	//외관을 나타낼 비트맵 데이터
	CTexture* mpTexture = nullptr;
};