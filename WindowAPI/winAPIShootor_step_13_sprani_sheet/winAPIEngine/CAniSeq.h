#pragma once
#include <vector>
#include <string>
using namespace std;

class CTexture;

//������ ����
//������ <-- ���� �̸� �����Ͽ� �����ص� Ÿ�� type 
enum ANI_PO    //play option
{
    LOOP,      //�ݺ� �÷��� �ɼ�
    ONCE       //�ѹ��� �÷����ϴ� �ɼ�
};

enum ANI_SO
{
    FRAME_FILE = 0,    //��������Ʈ �������� ���� ������ ����
    SHEET_FILE         //��������Ʈ �����ӵ��� �ϳ��� ��������Ʈ ��Ʈ ���Ͼȿ� ����
};

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

    //�ִ� ������ �÷��� �ɼ� ����
    //�⺻�� �ݺ�������� ����
    ANI_PO mPlayOption = ANI_PO::LOOP;

};

