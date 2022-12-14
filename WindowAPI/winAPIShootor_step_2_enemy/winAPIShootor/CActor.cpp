#include "CActor.h"
#include "CBullet.h"
#include <Windows.h>

CActor::CActor()
{
    mCurIndexBullet = 0;
}
CActor::~CActor()
{

}

CActor::CActor(const CActor& t)
	:CUnit(t)
{
    mCurIndexBullet = t.mCurIndexBullet;
}
void CActor::operator=(const CActor& t)
{
	CUnit::operator=(t);

    mCurIndexBullet = t.mCurIndexBullet;
}
/*
void CActor::DoFire(vector<CBullet*>& tBullets)
{
    //�߻� ��ƾ
        //  źȯ �߻�
        // i) źȯ�� '�߻��������'�� �����Ѵ�.
        // ii) źȯ�� '�ӵ�'�� �����Ѵ�.
        // iii) źȯ�� 'Ȱ��ȭ'��Ų��.

    tBullets[0]->SetPosition(this->GetPosition()); //i)
    tBullets[0]->SetVelocity(SVector2D(0.0f, -1.0f) * 200.0f);  //ii)
    tBullets[0]->SetIsActive(true);
}
*/
void CActor::DoFire(vector<CBullet*>& tBullets)
{
    //
    WCHAR tszTemp[256] = { 0 };
    wsprintf(tszTemp, L"DoFire %d\n", mCurIndexBullet);
    OutputDebugString(tszTemp);

    //�߻� ��ƾ
        //  źȯ �߻�
        // i) źȯ�� '�߻��������'�� �����Ѵ�.
        // ii) źȯ�� '�ӵ�'�� �����Ѵ�.
        // iii) źȯ�� 'Ȱ��ȭ'��Ų��.

    tBullets[mCurIndexBullet]->SetPosition(this->GetPosition()); //i)
    tBullets[mCurIndexBullet]->SetVelocity(SVector2D(0.0f, -1.0f) * 200.0f);  //ii)
    tBullets[mCurIndexBullet]->SetIsActive(true);

    //�Ʒ��� źȯ�̶�� ��ü�� ��Ȱ���̶�� �� �� �ִ�.
    //�̷��� �̸� �����ΰ� ��Ȱ���ϴ� ������ object pooling �̶�� �Ѵ�( object pool )
    //�����ϴ� ����� ���������ε�
    //���⼭�� ������ �����迭�� �̿��Ͽ���.

    //�޸� ����ȭ : ��ü ����ִ� �޸� �뷮�� ����ѵ� �޸𸮰� ����ȭ�Ǿ� ���� ������ �ʿ��� �������� �޸� ������ ������ ����
    //              <- �����Ҵ� �������� ���뼺 ������ �Ͼ�� �����̴�.
    //                 �׷��Ƿ�, �ذ��Ϸ��� ���뼺�� �����Ѵ�.


    if (mCurIndexBullet < tBullets.size() - 1)
    {
        //źȯ ���� ����
        ++mCurIndexBullet;                
    }
    else
    {
        mCurIndexBullet = 0;
    }
   
}

//CUnit::Update�� override �� ���̴�.
//��ġ�� ������ �Ǿ�� �ϹǷ� CUnit::Update�� ������ �Ǿ���Ѵ�.
void CActor::Update(float tDeltaTime)
{
    //�θ�Ŭ������ ����� �״�� ������ ����Ѵ�.
    CUnit::Update(tDeltaTime);

    //�߰��� ����� ��������.
    //step_0 : �߽����� ���
    /*if (this->mPosition.mX <= 0.0f)
    {
        this->mPosition.mX = 0.0f;
    }

    if (this->mPosition.mX >= 800.0f)
    {
        this->mPosition.mX = 800.0f;
    }*/

    //step_1 : �ʺ� ���
    float tDiff = GetWidth() * GetAnchorX();
    if (this->mPosition.mX - tDiff <= 0.0f )
    {
        this->mPosition.mX = 0.0f + tDiff;
    }

    if (this->mPosition.mX + tDiff >= 800.0f )
    {
        this->mPosition.mX = 800.0f - tDiff;
    }
}
