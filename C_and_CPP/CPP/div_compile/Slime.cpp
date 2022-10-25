#include "Slime.h"
#include "Brave.h"
void CSlime::DoDamage(CBrave* tBrave)
{
    this->mHP = this->mHP - tBrave->GetAP();
}