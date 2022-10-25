#include "Brave.h"
#include "Slime.h"

void CBrave::DoMove(int tVelocity)
{
    this->mX = this->mX + tVelocity;
}

void CBrave::DoDamage(CSlime* tSlime)
{
    this->mHP = this->mHP - tSlime->GetAP();
}
