#pragma once
#include <vector>
#include <string>
using namespace std;

class CTexture;

//열거형 문법
//열거형 <-- 값을 미리 지정하여 나열해둔 타입 type 
enum ANI_PO    //play option
{
    LOOP,      //반복 플레이 옵션
    ONCE       //한번만 플레이하는 옵션
};


class CAniSeq
{
public:
    CAniSeq();
    ~CAniSeq();
    CAniSeq(const CAniSeq& t);
    void operator=(const CAniSeq& t);

    //애니메이션 시퀀스 진행
    void Update(float tDeltaTime);
    
public:
//private:
    //애니메이션 시퀀스를 구별할 식별자
    string mId = "";

    //스프라이트 애니메이션 테스트
    vector<CTexture*> mTexs;

    float mTimeInterval = 0.0f;   //스프라이트 프레임 시간 간격

    int mTotalFrameCount = 0;  //스프라이트 프레임 총 갯수

    int mCurFrameIndex = 0;   //현재 스프라이트 프레임 번호
    float mAniTime = 0.0f;  //애니메이션 진행시간 <- 델타 타임을 누적할 것임

    //애니 시퀀스 플레이 옵션 변수
    //기본은 반복재생으로 설정
    ANI_PO mPlayOption = ANI_PO::LOOP;

};

