#pragma once

#include "SVector2D.h"
#include "CRef.h"

class CObjectRyu : public CRef
{
public:
	CObjectRyu();
	virtual ~CObjectRyu();

	CObjectRyu(const CObjectRyu& t);
	void operator=(const CObjectRyu& t);
	
	/*inline void SetPosition(SVector2D tPositon)
	{
		mPosition = tPositon;
	}
	inline SVector2D GetPosition()
	{
		return mPosition;
	}*/

//public:
//private:
protected:
	//��ġ ���
	//�̵���� x
	SVector2D mPosition;

public:
	//���� ���� �Լ�
	//clone�̶�� ���·� ���¸� �����Ͽ� �����ϴ� ���̴�.
	virtual CObjectRyu* clone() = 0;
};

