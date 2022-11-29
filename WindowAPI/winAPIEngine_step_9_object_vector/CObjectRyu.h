#pragma once

#include "SVector2D.h"

class CObjectRyu
{
public:
	CObjectRyu();
	~CObjectRyu();

	CObjectRyu(const CObjectRyu& t);
	void operator=(const CObjectRyu& t);
	
	inline void SetPosition(SVector2D tPositon)
	{
		mPosition = tPositon;
	}
	inline SVector2D GetPosition()
	{
		return mPosition;
	}

public:
	//위치 기능
	SVector2D mPosition;
};

