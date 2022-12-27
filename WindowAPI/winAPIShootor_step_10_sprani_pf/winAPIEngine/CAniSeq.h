#pragma once
#include <vector>
#include <string>
using namespace std;

class CTexture;

class CAniSeq
{
public:
    CAniSeq();
    ~CAniSeq();
    CAniSeq(const CAniSeq& t);
    void operator=(const CAniSeq& t);

    //�ִϸ��̼� ������ ����
    void Update(float tDeltaTime);
    
public:
//private:
    //�ִϸ��̼� �������� ������ �ĺ���
    string mId = "";

    //��������Ʈ �ִϸ��̼� �׽�Ʈ
    vector<CTexture*> mTexs;

    float mTimeInterval = 0.0f;   //��������Ʈ ������ �ð� ����

    int mTotalFrameCount = 0;  //��������Ʈ ������ �� ����

    int mCurFrameIndex = 0;   //���� ��������Ʈ ������ ��ȣ
    float mAniTime = 0.0f;  //�ִϸ��̼� ����ð� <- ��Ÿ Ÿ���� ������ ����
};

