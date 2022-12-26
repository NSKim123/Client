#pragma once

#include <windows.h>
#include <unordered_map>
#include <string>

using namespace std;

class CAniSeq;
class CAPIEngine;

class CAnimator
{
public:
	CAnimator();
	~CAnimator();

	CAnimator(const CAnimator& t);
	void operator=(const CAnimator& t);


public:
	//�ִϸ��̼� �������� �߰��ϴ� �Լ�
	bool AddAniSeq(const string& tId, float tTimeInterval, int tTotalFrameCount, LPCWSTR tpFileName);
	//���� �ִϸ��̼� �������� ���� ������ ����
	void UpdateAnimation(float tDeltaTime);
	//���� �ִϸ��̼� �������� ��� ��� ������
	void Render(float tX, float tY);

	void Create(CAPIEngine* tpEngine);
	void Destroy();
	inline void SetId(string tId)
	{
		mId = tId;
	}

public:
	//Animation �� �ĺ���
	string mId = "";



	//�����߿� ���ϴ� �ִϸ��̼� �������� �˻��Ͽ� �÷��̸� �����ϱ� ���� �ڷᱸ��
	//���� �˻��ӵ��� �߿��ϹǷ� O(1)�� �ؽ��ڷᱸ���� �̿��ϱ����
	//  N���� �ִϸ��̼� �������� ����
	unordered_map<string, CAniSeq*> mAniSeqs;

	//���� �÷��̵ǰ� �ִ� ���ϸ��̼� ������ ��ü ����
	CAniSeq* mpCurAniSeq = nullptr;
	string mStrKeyCurAniSeq;  //���� �÷��̵ǰ� �ִ� �ִϸ��̼� �������� ���ڿ� �ĺ���

	//���� ���� ����
	CAPIEngine* mpEngine = nullptr;
};
