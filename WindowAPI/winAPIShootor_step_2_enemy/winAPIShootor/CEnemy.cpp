#include "CEnemy.h"
#include "CBullet.h"
#include <Windows.h>

CEnemy::CEnemy()
{
    mCurIndexBullet = 0;
    mTimeTick = 0.0f;
}
CEnemy::~CEnemy()
{

}

CEnemy::CEnemy(const CEnemy& t)
    :CUnit(t)
{
    mCurIndexBullet = t.mCurIndexBullet;
    mTimeTick = t.mTimeTick;
}
void CEnemy::operator=(const CEnemy& t)
{
    CUnit::operator=(t);

    mCurIndexBullet = t.mCurIndexBullet;
    mTimeTick = t.mTimeTick;
}
void CEnemy::DoFire(vector<CBullet*>& tBulletsEnemy)
{
    
    WCHAR tszTemp[256] = { 0 };
    wsprintf(tszTemp, L"DoFire Enemy %d\n", mCurIndexBullet);
    OutputDebugString(tszTemp);

    

    tBulletsEnemy[mCurIndexBullet]->SetPosition(this->GetPosition()); 
    tBulletsEnemy[mCurIndexBullet]->SetVelocity(SVector2D(0.0f, 1.0f) * 200.0f);  
    tBulletsEnemy[mCurIndexBullet]->SetIsActive(true);

    


    if (mCurIndexBullet < tBulletsEnemy.size() - 1)
    {
        //탄환 순번 증가
        ++mCurIndexBullet;
    }
    else
    {
        mCurIndexBullet = 0;
    }

}
void CEnemy::OnTimer()
{
    OutputDebugString(L"OnTimer Enemy Fire!\n");
}