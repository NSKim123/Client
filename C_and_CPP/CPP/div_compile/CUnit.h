#pragma once
class CUnit
{
protected:
	float mHP = 0;
	float mAP = 0;


public:
    inline float GetHP()
    {
        return mHP;
    }

    inline float GetAP()
    {
        return mAP;
    }
};

