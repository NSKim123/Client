#pragma once
#include "CUnit.h"

class CEnemy : public CUnit
{
public:
	CEnemy();
	virtual ~CEnemy();

	CEnemy(const CEnemy& t);
	void operator=(const CEnemy& t);

public:	
	virtual CObjectRyu* clone() override
	{
		return new CEnemy(*this);
	}
};

