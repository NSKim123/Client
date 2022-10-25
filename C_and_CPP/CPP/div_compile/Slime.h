#pragma once

#include "CUnit.h"

//#include "Brave.h"
class CBrave;

class CSlime : public CUnit
{
//private:
//    float mHP = 0;
//    float mAP = 0;

public:
    CSlime()
    {
        mHP = 200.0f;
        mAP = 500.0f;
    }

    void DoDamage(CBrave* tBrave);
    /*
    inline float GetHP()
    {
        return mHP;
    }

    inline float GetAP()
    {
        return mAP;
    }*/
};
