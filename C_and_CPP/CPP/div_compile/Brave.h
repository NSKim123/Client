#pragma once
//<-- include guard ������ �ɼ� ���� 
//�ش� ��������� ������ �ѹ��� include�Ѵ�. ��� �ǹ��̴�.
// 
//(������ �� ��.)
#include "CUnit.h"


//������Ͽ��� �ǵ��� ��������� �������� �ʴ´�.

//#include "Slime.h"

//Ŭ���� ���� ����
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

