#pragma once

#include "CObjectRyu.h"

class CAPIEngine; //Ŭ���� ���漱��
class CTexture;

class CUnit : public CObjectRyu
{
public:
	CUnit();
	virtual ~CUnit();

	//���������
	CUnit(const CUnit& t);
	//������Կ�����
	void operator=(const CUnit& t);  //���� ������ �������� �ʰڴ�.

public:
	virtual void Create(CAPIEngine* tpEngine);
	virtual void Destroy();

	virtual void Render();
	
	virtual void Update(float tDeltaTime);

	inline void SetPosition(SVector2D tPositon)
	{
		mPosition = tPositon;
	}
	inline SVector2D GetPosition()
	{
		return mPosition;
	}
	inline void SetPosition(float tX, float tY)
	{
		//mX = tX;
		//mY = tY;
		SVector2D tVector(tX, tY);
		mPosition = tVector;
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
	inline void SetVelocity(SVector2D tVelocity)
	{
		mVelocity = tVelocity;
	}

	inline void SetIsActive(bool tIsActive)
	{
		mIsActive = tIsActive;
	}
	inline const bool GetIsActive()
	{
		return mIsActive;
	}


	inline float GetAnchorX()
	{
		return mAnchorX;
	}
	inline float GetAnchorY()
	{
		return mAnchorY;
	}
	inline float GetWidth()
	{
		return mWidth;

	}
	inline float GetHeight()
	{
		return mHeight;
	}

private:
	//2����, �������� ������ �����Ͽ� �����Ϳ� Ÿ���� �������ߴ�.
	/*float mX = 0.0f;
	float mY = 0.0f;*/
	SVector2D mVelocity;

	float mRadius = 0.0f;

	//pivot
	//�ǹ������� �޼��ϱ� ���� �ʿ��� �����͵��� ��������� �������.
	//���� ��� ��ġ
	float mDisplayX = 0.0f;
	float mDisplayY = 0.0f;
	//[0,1]�� ����ȭ�� ���ؿ����� ��ġ
	float mAnchorX = 0.0f;
	float mAnchorY = 0.0f;
	//��Ʈ���� �ʺ�, ����
	float mWidth = 0.0f;
	float mHeight = 0.0f;
	//�ܰ��� ��Ÿ�� ��Ʈ�� ������
	CTexture* mpTexture = nullptr;

	//Ȱ�� ��Ȱ�� ���� ����
	bool mIsActive = false;

	//���� ���� ����
	CAPIEngine* mpEngine = nullptr;

public:
	
	virtual CObjectRyu* clone() = 0;
};