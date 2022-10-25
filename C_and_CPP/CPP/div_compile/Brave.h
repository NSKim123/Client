#pragma once
//<-- include guard 컴파일 옵션 지정 
//해당 헤더파일의 내용은 한번만 include한다. 라는 의미이다.
// 
//(지우지 말 것.)
#include "CUnit.h"


//헤더파일에는 되도록 헤더파일을 포함하지 않는다.

//#include "Slime.h"

//클래스 전방 선언
class CSlime;

class CBrave :public CUnit
{
//private:
      int mX = 0;
//    float mHP = 0.0f;
//    float mAP = 0.0f;


public:
    CBrave()
    {
        mX = 0;
        mHP = 1000.0f;
        mAP =100.0f;
    }

    void DoMove(int tVelocity);
    void DoDamage(CSlime* tSlime);

    inline int GetX()
    {
        return mX;
    }

   /* inline float GetHP()
    {
        return mHP;
    }

    inline float GetAP()
    {
        return mAP;
    }*/
};

