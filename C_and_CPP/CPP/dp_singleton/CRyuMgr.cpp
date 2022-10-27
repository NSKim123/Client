#include "CRyuMgr.h"

//static ���� ����� ������ �ʱ�ȭ
//���� �������� �����ߴ�.
CRyuMgr* CRyuMgr::mpInstance = nullptr;

CRyuMgr::CRyuMgr()
{
	//���� �����Ϸ��� �̰͵� ����Ѵ�
	//mpInstance = nullptr;
}
CRyuMgr::~CRyuMgr()
{

}

CRyuMgr* CRyuMgr::GetInstance()
{
	//mpInstance�� null�� ��쿡�� �����.
	//�� �Ѱ��� �����.
	if (nullptr == mpInstance)
	{
		mpInstance = new CRyuMgr();
	}

	return mpInstance;
}
void CRyuMgr::ReleaseInstance()
{
	if (nullptr != mpInstance)
	{
		delete mpInstance;
		mpInstance = nullptr;
	}
}