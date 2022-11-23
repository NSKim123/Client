#pragma once

class CAPIEngine; //Ŭ���� ���漱��

class CUnit
{
public:
	CUnit();
	~CUnit();

	//���������
	CUnit(const CUnit& t);
	//������Կ�����
	void operator=(const CUnit& t);  //���� ������ ������� �ʰڴ�.

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
public:
	//2����, �������� ������ �����Ͽ� �����Ϳ� Ÿ���� �������ߴ�.
	float mX = 0.0f;
	float mY = 0.0f;

	float mRadius = 0.0f;
};