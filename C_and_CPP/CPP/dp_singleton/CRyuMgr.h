#pragma once

/*

	singleton pattern�� ����� ���

	���� ������ �������� �����
	i) �ش� Ŭ���� Ÿ���� ������ ���� mpInstance �� static���� �����
	ii) �����ڴ� public�� �ƴϾ�� �Ѵ�.
	iii) GetInstance() �Լ��� ���ǿ��� �ִ� ���������� 1���� �����ϴ� �Ǵ�������� ��ġ�Ѵ�.

*/

class CRyuMgr
{
private:
	/*
		static ����--->�������� ������ ���.
		static ���� ������ ������ '������ �޸� ����'�� ��ġ�Ѵ�.
		�ڵ�����δ� �������������. �޸� �������� ������ ���������̹Ƿ�
		��ü�� ������ �� ��������� ������ �ƴϴ�.

		�׷��Ƿ� ���⼭ �ʱ�ȭ ǥ���� �Ұ����ϴ�.
	*/
	//static CRyuMgr* mpInstance = nullptr;
	static CRyuMgr* mpInstance;

private:
	//�ܺο����� ������ ���� ���ؼ���
	CRyuMgr();
	~CRyuMgr();

public:
	//ǥ��� ����������� �����Լ��� ������ ����.
	//static ������ �ٷ�����ؼ��� static�Լ����� �Ѵ�.
	static CRyuMgr* GetInstance();
	static void ReleaseInstance();

	//���� �÷��̾��� ������ ���������� �����ϰڴٰ� ����
public:
	int mScore = 0;
};

