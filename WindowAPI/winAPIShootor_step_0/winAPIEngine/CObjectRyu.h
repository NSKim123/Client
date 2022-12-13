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
	//위치 기능
	//이동고려 x
	SVector2D mPosition;

public:
	//순수 가상 함수
	//clone이라는 형태로 형태를 강제하여 구현하는 것이다.
	virtual CObjectRyu* clone() = 0;
};

