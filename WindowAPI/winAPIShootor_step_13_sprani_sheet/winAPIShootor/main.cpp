// winAPIEngine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "winAPIEngine.h"


#include "CAPIEngine.h"
#include "CUnit.h"
#include "CTexture.h"
#include "ryumacro.h"
#include "CInputMgr.h"
#include "CActor.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "config.h"
#include "CRyuTimer.h"
#include "CCollider.h"
#include "CCollisionMgr.h"
#include "CAniSeq.h"
#include "CAnimator.h"

#include "CExplosion.h"

//test
#include <list>
using namespace std;

//소스코드상에서 설정
//winAPIEngine.lib를 링킹과정에서 링크하겠다 라고 컴파일 옵션 지정
#pragma comment(lib, "winAPIEngine.lib")

/*
    이번 예시에서는 다음의 사항들을 만들어보자.

    1) 투명 컬러키 적용

        전통적인 2D 게임에서 사용하는 투명 컬러키는 자홍색(255,0,255)이다.
        이 예시에서는 하얀색(255,255,255)을 투명 컬러키로 사용하였다.

        Win API에서 제공하는 'TransparentBit'함수를 이용하겠다.

    2) 스프라이트 시트 개념을 고려하여 적용하겠다.
       
       n개의 스프라이트 프레임이 하나의 파일에 담겨있는 이미지 파일 ---> sprite sheet

       스프라이트 시트를 구성하는 방법은 크게 두가지이다.
       i) 각각의 프레임의 위치, 크기가 제각각인 경우
        장점 : 스프라이트 시트의 빈 공간이 소모되지 않게 채울 수 있다.
        단점 : 임의의 프레임을 가져오기 위해 별도의 정보(위치, 크키(너비,높이)) 구성 파일이 필요하다.

       ii) 프레임의 크기를 통일하여 작성하는 경우
        장점 : 부가정보가 필요없다.
        단점 : 해당 규격을 지켜야만 한다.

        -->우리는 ii)의 방법을 이용하겠다.


        explosionFull.bmp 리소스를 이용한다.
        2048*1024 의 크기를 가진다.
        4행 8열의 스프라이트 프레임들이 하나의 이미지 파일로 구성되어있다.(4 * 8 = 32 프레임의 구성

        
*/

class CRyuEngine : public CAPIEngine
{
    //test
    CRyuTimer mTimerForEnemy;

    //test
    //CObjectRyu* testObject = nullptr;



    //자원resource
    CTexture* mpTexture = nullptr;
    CTexture* mpTexBullet = nullptr;    //탄환 비트맵 이미지 데이터 자원
    CTexture* mpTexEnemy = nullptr;     //적 비트맵 데이터 자원

    CTexture* mpTexExplosion = nullptr;

    //스프라이트 애니메이션 테스트
    //CTexture* mTexs[2] = { nullptr, nullptr };
    /*
    float mTimeInterval = 0.0f;   //스프라이트 프레임 시간 간격

    int mTotalFrameCount = 0;  //스프라이트 프레임 총 갯수

    int mCurFrameIndex = 0;   //현재 스프라이트 프레임 번호
    float mAniTime = 0.0f;  //애니메이션 진행시간 <- 델타 타임을 누적할 것임
    */

    //prefab
    //원본 객체( 주인공 기체의 원본 객체 )
    CUnit* PFActor = nullptr;
    CUnit* PFBullet = nullptr;          //탄환 원본 객체
    CUnit* PFEnemy = nullptr;           //적 원본 객체
    CUnit* PFExplosion = nullptr;

    //object
    CActor* mpActor = nullptr;
    vector<CBullet*> mBullets;      //실제 주인공 기체가 사용할 탄환객체들 

    CEnemy* mpEnemy = nullptr;      //적 객체
    vector<CBullet*> mBulletsEnemy;      //실제 적 기체가 사용할  일반탄환객체들    

    /*
    CEnemy* mpEnemyAimed = nullptr;
    vector<CBullet*> mBulletsEnemyAimed;    //조준탄환 객체들

    CEnemy* mpEnemyCircled = nullptr;  //원형탄환을 발사할 적 객체
    vector<CBullet*> mBulletsEnemyCircled;
    */
    
    CExplosion* mpExplosion = nullptr;

public:
    CRyuEngine() {};
    virtual ~CRyuEngine() {};

    //delete는 해당 함수의 구현을 막는 문법
private:
    CRyuEngine(const CRyuEngine& t) = delete;
    CRyuEngine& operator=(const CRyuEngine& t) = delete;


public:

    static VOID CALLBACK OnTimer_0(HWND thWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
    {
        //OutputDebugString(L"==========OnTimer_0, Enemy Fire!!!=======\n");

        //정적static함수에서 비정적 멤버변수에 접근이 불가하다.
        //mpEnemy->DoFire(mBulletsEnemy);

        //이런 것은 가능
        //CInputMgr::GetInstance();
    }




    virtual void OnCreate() override
    {
        CAPIEngine::OnCreate();

            //test
        RYU_INT tA = 3;
        RYU_INT tB = 2;
        RYU_INT tResult = 0;

        tResult = tA + tB;
        
        char tszTemp[256] = { 0 };      //c style 문자열
        sprintf_s(tszTemp, "tResult: %d\n", tResult);
        OutputDebugStringA(tszTemp);
        //~A 가 붙은 OutputDebugString은 아스키코드용


            //test
            //testObject = new CObjectRyu();
            //testObject->AddRef();

            //list<CObjectRyu*> testObjectList;
            //testObjectList.push_back(testObject);   //주소값이 복사되었으므로 참조가 하나 증가되어야 한다.
            //testObject->AddRef();


            //testObject->Release();      //리스트가 지역변수이므로 해당 지역을 벗어나면 소멸된다. 이를 고려하여 참조 감소


        //자원 로드 부분
        //todo
        mpTexture = new CTexture();
        mpTexture->LoadTexture(hInst, mhDC, L"resources/bongbong_0.bmp");

        mpTexBullet = new CTexture();
        mpTexBullet->LoadTexture(hInst, mhDC, L"resources/bongbullet.bmp");

        mpTexEnemy = new CTexture();
        //대표 이미지 교체
        //mpTexEnemy->LoadTexture(hInst, mhDC, L"resources/bongenemy.bmp");
        mpTexEnemy->LoadTexture(hInst, mhDC, L"resources/paladin_idle_0.bmp");

        mpTexExplosion = new CTexture();
        mpTexExplosion->LoadTexture(hInst, mhDC, L"resources/explosionFull.bmp");

        /*mTexs[0] = new CTexture();
        mTexs[0]->LoadTexture(hInst, mhDC, L"resources/bongbong_0.bmp");
        mTexs[1] = new CTexture();
        mTexs[1]->LoadTexture(hInst, mhDC, L"resources/bongbong_1.bmp");*/


        //원본객체(주인공 기체에 대한 원본 객체 ) 생성
        //PFActor = new CActor();        
        //PFActor->SetPosition(800 * 0.5f, 600 - 50 - 100.0f);
        //    PFActor->SetRadius(50.0f);
        ////pivot
        //PFActor->SetAnchorPoint(0.5f, 0.5f);
        //PFActor->SetTexture(mpTexture);
        PFActor = CreatePrefab<CActor>(mpTexture, 0.5f, 0.5f, SVector2D(800 * 0.5f, 600 - 50 - 100.0f));
        //이제 Animator객체를 추가하는 것을 프리팹 쪽으로 옮겼다.
        CAnimator* tpAnimActor = PFActor->CreateAnimation("AnimActor", this);
        tpAnimActor->AddAniSeq("ani_idle_actor", 1.0f, 2, L"resources/bongbong");
        tpAnimActor->AddAniSeq("ani_super_actor", 0.5f, 2, L"resources/bongbong_super");   //테스트용 애니 시퀀스

        //기본 애니메이션 시퀀스 지정
        //tpAnimActor->mStrKeyCurAniSeq = "ani_idle_actor";
        tpAnimActor->SetDefaultAniSeq("ani_idle_actor");

        PFBullet = CreatePrefab<CBullet>(mpTexBullet, 0.5f, 0.5f, SVector2D(800 * 0.5f, 600 - 50 - 100.0f));

        PFEnemy = CreatePrefab<CEnemy>(mpTexEnemy, 0.5f, 0.5f, SVector2D(800 * 0.5f, 100.0f));
        CAnimator* tpAnimEnemy = PFEnemy->CreateAnimation("AnimEnemy", this);
        tpAnimEnemy->AddAniSeq("ani_idle_enemy", 0.08f, 7, L"resources/paladin_idle");
        tpAnimEnemy->AddAniSeq("ani_attack_enemy", 0.2f, 11, L"resources/paladin_attack", ANI_PO::ONCE);
               

        //tpAnimEnemy->mStrKeyCurAniSeq = "ani_idle_enemy";  //현재
        //tpAnimEnemy->mStrKeyPrevAniSeq = "ani_idle_enemy";  //이전
        tpAnimEnemy->SetDefaultAniSeq("ani_idle_enemy");
        
        PFExplosion = CreatePrefab<CExplosion>(mpTexExplosion, 0.5f, 0.5f, SVector2D(0.0f, 0.0f));
        CAnimator* tpAnimExplosion = PFExplosion->CreateAnimation("AnimExplosion", this);
        tpAnimExplosion->AddAniSeq("ani_explosion", 0.08f, 4*8, L"resources/explosionFull", ANI_PO::ONCE, ANI_SO::SHEET_FILE, 4, 8);
        //한번만 재생, 스프라이트 시트 이용 옵션, 4행 8열

        tpAnimExplosion->SetDefaultAniSeq("ani_explosion");




        //실제 객체 생성
        //mpActor = static_cast<CActor*>(PFActor->clone());               //원본객체를 복제하여 객체를 생성
        //mpActor->AddRef();

        mpActor = InstantObject<CActor>(PFActor);               //원본객체를 복제하여 객체를 생성
        mpActor->AddRef();

        //테스트용 애니메이터
        //애니메이터를 만들고 애니메이션 시퀀스를 하나 추가
        /*CAnimator* tpAnimator= mpActor->CreateAnimation("AnimActor", this);
        tpAnimator->AddAniSeq("ani_idle_actor", 1.0f, 2, L"resources/bongbong");*/


        CBullet* tpBullet = nullptr;
        for (int ti = 0; ti < BULLET_COUNT_MAX; ++ti)
        {
            tpBullet = InstantObject<CBullet>(PFBullet);               //원본객체를 복제하여 객체를 생성
                tpBullet->AddRef();

                //CCollisionMgr::GetInstance()->AddUnit(tpBullet);
                tpBullet->SetTag("tagActorBullet");

            tpBullet->SetIsActive(false);           //탄환객체들은 비활성으로 생성

            mBullets.push_back(tpBullet);
            tpBullet->AddRef();

                tpBullet->Release();
                tpBullet = nullptr;
        }

        mpEnemy = InstantObject<CEnemy>(PFEnemy);               //원본객체를 복제하여 객체를 생성
        mpEnemy->AddRef();

        //CCollisionMgr::GetInstance()->AddUnit(mpEnemy);
        mpEnemy->SetTag("tagEnemy");

        //적 기체의 일반탄환들
        tpBullet = nullptr;
        for (int ti = 0; ti < BULLET_COUNT_MAX; ++ti)
        {
            tpBullet = InstantObject<CBullet>(PFBullet);               //원본객체를 복제하여 객체를 생성
            tpBullet->AddRef();

            tpBullet->SetIsActive(false);           //탄환객체들은 비활성으로 생성

            mBulletsEnemy.push_back(tpBullet);
            tpBullet->AddRef();

            tpBullet->Release();
            tpBullet = nullptr;
        }

        mpExplosion = InstantObject<CExplosion>(PFExplosion);               //원본객체를 복제하여 객체를 생성
        mpExplosion->AddRef();                
        mpExplosion->SetTag("tagExplosion");

/*
        mpEnemyAimed = InstantObject<CEnemy>(PFEnemy);               //원본객체를 복제하여 객체를 생성
        mpEnemyAimed->AddRef();

        for (int ti = 0; ti < BULLET_COUNT_MAX; ++ti)
        {
            tpBullet = InstantObject<CBullet>(PFBullet);               //원본객체를 복제하여 객체를 생성
            tpBullet->AddRef();

            tpBullet->SetIsActive(false);           //탄환객체들은 비활성으로 생성

            mBulletsEnemyAimed.push_back(tpBullet);
            tpBullet->AddRef();

            tpBullet->Release();
            tpBullet = nullptr;
        }

        mpEnemyCircled = InstantObject<CEnemy>(PFEnemy);               //원본객체를 복제하여 객체를 생성
        mpEnemyCircled->AddRef();

        //8발씩 BULLET_COUNT_MAX벌 준비
        for (int ti = 0; ti < 8 * BULLET_COUNT_MAX; ++ti)
        {
            tpBullet = InstantObject<CBullet>(PFBullet);               //원본객체를 복제하여 객체를 생성
            tpBullet->AddRef();

            tpBullet->SetIsActive(false);           //탄환객체들은 비활성으로 생성

            mBulletsEnemyCircled.push_back(tpBullet);
            tpBullet->AddRef();

            tpBullet->Release();
            tpBullet = nullptr;
        }
        */
        //입력 매핑 등록
        CInputMgr::GetInstance()->AddKey("OnMoveLt", 'A');
        CInputMgr::GetInstance()->AddKey("OnMoveRt", 'D');
        CInputMgr::GetInstance()->AddKey("OnFire", VK_SPACE);        

        CInputMgr::GetInstance()->AddKey("OnTest",  VK_LCONTROL, 'H');




        //test
        //테스트로 한발만 발사해본다.
        //mpEnemy->DoFire(mBulletsEnemy);

        //3초 간격으로 작동하는 윈도우 타이머를 하나 만들고 설정했다.
        //3초 를 가정한다
        // 마지막 인자를 널로 하면, 윈도우 메시지를 이용하여 처리하겠다 의 의미
        //SetTimer(this->mhWnd, 0, 3000, nullptr);

        //SetTimer(this->mhWnd, 0, 3000, OnTimer_0);


        //mTimerForEnemy.SetTimer(3.0f, &CUnit::OnTimer, mpEnemy);


        //게임 프로그램 시작시, 오른쪽 방향으로 이동 시작
        //mpEnemy->SetVelocity(SVector2D(+1.0f, 0.0f) * 100.0f);
        //mpEnemyCircled->SetVelocity(SVector2D(-1.0f, 0.0f) * 50.0f);


    }
    virtual void OnDestroy() override
    {
        //0번 타이머 해제
        //KillTimer(this->mhWnd, 0);


        /*if (nullptr != mpTexture)
        {
            delete mpTexture;
            mpTexture = nullptr;
        }*/
        /*
        for (vector<CBullet*>::iterator tItor = mBulletsEnemyCircled.begin(); tItor != mBulletsEnemyCircled.end(); ++tItor)
        {
            SAFE_RELEASE((*tItor));       //(*tItor)-> 이런 형태로 치환하기 위해 괄호를 써줬다.            
        }

        DestroyObject<CEnemy>(mpEnemyCircled);

        //적기체의 조준탄환 객체들 해제
        for (vector<CBullet*>::iterator tItor = mBulletsEnemyAimed.begin(); tItor != mBulletsEnemyAimed.end(); ++tItor)
        {
            SAFE_RELEASE((*tItor));       //(*tItor)-> 이런 형태로 치환하기 위해 괄호를 써줬다.            
        }

        DestroyObject<CEnemy>(mpEnemyAimed);
        */
        //적기체의 일반탄환 객체들 해제
        for (vector<CBullet*>::iterator tItor = mBulletsEnemy.begin(); tItor != mBulletsEnemy.end(); ++tItor)
        {
            SAFE_RELEASE((*tItor));       //(*tItor)-> 이런 형태로 치환하기 위해 괄호를 써줬다.            
        }

        
        DestroyObject<CEnemy>(mpEnemy);

        //실제 객체 소멸        
        for (vector<CBullet*>::iterator tItor = mBullets.begin(); tItor != mBullets.end(); ++tItor)
        {
            SAFE_RELEASE( (*tItor) );       //(*tItor)-> 이런 형태로 치환하기 위해 괄호를 써줬다.            
        }

        DestroyObject<CActor>(mpActor);
        DestroyObject<CExplosion>(mpExplosion);

        //원본 객체 소멸
        DestroyPrefab(PFEnemy);
        DestroyPrefab(PFBullet);
        DestroyPrefab(PFActor);
        DestroyPrefab(PFExplosion);


        /*SAFE_DELETE(mTexs[1])
        SAFE_DELETE(mTexs[0])*/

        //자원 해제 
        SAFE_DELETE(mpTexEnemy)
        SAFE_DELETE(mpTexBullet)
        SAFE_DELETE(mpTexture)
        SAFE_DELETE(mpTexExplosion)

        CAPIEngine::OnDestroy();
    }
    virtual void OnUpdate(float tDeltaTime) override
    {
        CAPIEngine::OnUpdate(tDeltaTime);

        //충돌 게임 알고리즘 테스트 : 주인공 기체의 일반탄환들 vs 적 기체 1개 
        //원 대 원

        /*
            D > A.r + B.r     충돌이 아니다
            D == A.r + B.r    충돌이다
            D < A.r + B.r     충돌이다        
        */
        /*
        for (vector<CBullet*>::iterator tItor = mBullets.begin(); tItor != mBullets.end(); ++tItor)
        {
            //둘다 활성화 된 상태인 경우
            if ((*tItor)->GetIsActive())
            {
                if (mpEnemy->GetIsActive())
                {
                    //tDistance 두 중심점 사이의 거리

                    //여기서는 두 점사이의 거리 구하기 공식으로 하였다.(내적을 이용한 방법도 있다.)
                    //어차피 양수끼리의 비교이므로, 양변을 제곱하여 제곱근을 없앴다.
                    float tAdd = ((*tItor)->GetRadius() + mpEnemy->GetRadius()) * ((*tItor)->GetRadius() + mpEnemy->GetRadius());
                    float tDistance = ((*tItor)->GetPosition().mX - mpEnemy->GetPosition().mX)* ((*tItor)->GetPosition().mX - mpEnemy->GetPosition().mX)+
                    ((*tItor)->GetPosition().mY - mpEnemy->GetPosition().mY)* ((*tItor)->GetPosition().mY - mpEnemy->GetPosition().mY);

                    if (tDistance <= tAdd)
                    {
                        OutputDebugString(L"Collision!!! \n");

                        //탄환제거
                        (*tItor)->SetIsActive(false);

                        //적 제거
                        mpEnemy->SetIsActive(false);

                        break;
                    }
                }
            }
        }
        */

        //AABB
        /*
        for (vector<CBullet*>::iterator tItor = mBullets.begin(); tItor != mBullets.end(); ++tItor)
        {
            if ((*tItor)->GetIsActive())
            {
                if (mpEnemy->GetIsActive())
                {
                    bool tIsCollision = (*tItor)->Intersects((*mpEnemy));

                    if (tIsCollision)
                    {
                        //탄환제거
                        (*tItor)->SetIsActive(false);

                        //적 제거
                        mpEnemy->SetIsActive(false);
                        break;
                    }
                }
            }
        }
        */
        /*
        for (vector<CBullet*>::iterator tItor = mBullets.begin(); tItor != mBullets.end(); ++tItor)
        {
            if ((*tItor)->GetIsActive())
            {
                if (mpEnemy->GetIsActive())
                {
                    bool tIsCollision = (*tItor)->mpCollider->DoCollision(mpEnemy->mpCollider);

                    if (tIsCollision)
                    {
                        //탄환제거
                        (*tItor)->SetIsActive(false);

                        //적 제거
                        mpEnemy->SetIsActive(false);
                        break;
                    }
                }
            }
        }*/




        //mTimerForEnemy.Update(tDeltaTime);


        //update

         //&비트연산의 이유
        // GetAsyncKeyState 의 리턴값은 다음과 같다.
        /*
            0x0000: 이전에 눌림 없음. 호출시점에 눌림 없음 <-- 안눌림
            0x0001: 이전에 눌림 있음. 호출시점에 눌림 없음 <-- 떼어짐

            0x8000: 이전에 눌림 없음. '호출시점에 눌림' 있음 <-- 새롭게 눌림
            0x8001: 이전에 눌림 있음. '호출시점에 눌림' 있음 <-- 눌리고있음

            이것을 알아오기 위함이다.

            비트연산으로 계산하므로 밑에 두가지경우가 참이된다.
        */

        //A키가 눌리고 있다면
        //SVector2D tVelocity;
        //mpUnit->SetVelocity(tVelocity);
        //if (GetAsyncKeyState('A') & 0x8000)     
        //{
        //    //순수한 방향의 속도 설정 (-1,0)
        //    tVelocity.mX = -1.0f;
        //    tVelocity.mY = 0.0f;            
        //    mpUnit->SetVelocity(tVelocity*0.1f);

        //    OutputDebugString(L"key input A\n");
        //}        
        //if (GetAsyncKeyState('D') & 0x8000) 
        //{
        //    //순수한 방향의 속도 설정 (+1,0)
        //    tVelocity.mX = +1.0f;
        //    tVelocity.mY = 0.0f;
        //    
        //    mpUnit->SetVelocity(tVelocity*0.1f);

        //    OutputDebugString(L"key input D\n");
        //}

        //if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        //{
        //    OutputDebugString(L"Fire Bullet!.........VK_SPACE\n");
        //}

        //mpUnit->Update();



        SVector2D tVelocity;
        mpActor->SetVelocity(tVelocity);
       if( CInputMgr::GetInstance()->KeyPress("OnMoveLt") )
        {
            //순수한 방향의 속도 설정 (-1,0)
            tVelocity.mX = -1.0f;
            tVelocity.mY = 0.0f;
            //mpUnit->SetVelocity(tVelocity * 0.1f);
            mpActor->SetVelocity(tVelocity * 350.0f);    //초당 350PIXEL

            OutputDebugString(L"key input A\n");
        }
       if (CInputMgr::GetInstance()->KeyPress("OnMoveRt"))
        {
            //순수한 방향의 속도 설정 (+1,0)
            tVelocity.mX = +1.0f;
            tVelocity.mY = 0.0f;

            //mpUnit->SetVelocity(tVelocity * 0.1f);
            mpActor->SetVelocity(tVelocity * 350.0f);    //초당 350PIXEL

            OutputDebugString(L"key input D\n");
        }

       if (CInputMgr::GetInstance()->KeyUp("OnFire"))
        {
            OutputDebugString(L"Fire Bullet!.........VK_SPACE\n");

            mpActor->DoFire(mBullets);

            //test
            //super 애니메이션 플레이
            //mpActor->mpAnimator->mStrKeyCurAniSeq = "ani_super_actor";
            //mpActor->mpAnimator->PlayAni("ani_super_actor");
            mpActor->PlayAni("ani_super_actor");
        }

       if (CInputMgr::GetInstance()->KeyUp("OnTest"))
       {
           OutputDebugString(L"OnTest!.........VK_LCONTROL      'H'\n");

           //test
           //idle 애니메이션 플레이
           //mpActor->mpAnimator->mStrKeyCurAniSeq = "ani_idle_actor";
           //mpActor->mpAnimator->PlayAni("ani_idle_actor");
           mpActor->PlayAni("ani_idle_actor");
       }

       //시간기반진행
        mpActor->Update(tDeltaTime);
        for (vector<CBullet*>::iterator tItor = mBullets.begin(); tItor != mBullets.end(); ++tItor)
        {
            (*tItor)->Update(tDeltaTime);
        }




        mpEnemy->Update(tDeltaTime);

        //적 기체가 일반탄환을 일정시간 간격으로 발사
        
        if ( mpEnemy->mTimeTick >= 14.0f )
        {
            //todo 일정시간 간격으로 실행할 코드
            mpEnemy->DoFire(mBulletsEnemy);

            //test
            /*mpEnemy->mpAnimator->mStrKeyPrevAniSeq = mpEnemy->mpAnimator->mStrKeyCurAniSeq;
            mpEnemy->mpAnimator->mStrKeyCurAniSeq = "ani_attack_enemy";

            mpEnemy->mpAnimator->mpCurAniSeq->mCurFrameIndex = 0;
            mpEnemy->mpAnimator->mpCurAniSeq->mAniTime = 0;*/

            //mpEnemy->mpAnimator->PlayAni("ani_attack_enemy");
            mpEnemy->PlayAni("ani_attack_enemy");

            //time tick을 초기 상태로 되돌려줌
            mpEnemy->mTimeTick = 0.0f;
        }
        else
        {
            //delta time 을 누적
            mpEnemy->mTimeTick = mpEnemy->mTimeTick + tDeltaTime;
        }

        for (vector<CBullet*>::iterator tItor = mBulletsEnemy.begin(); tItor != mBulletsEnemy.end(); ++tItor)
        {
            (*tItor)->Update(tDeltaTime);
        }
        /*
        mpEnemyAimed->Update(tDeltaTime);

        //적 기체가 일반탄환을 일정시간 간격으로 발사

        if (mpEnemyAimed->mTimeTick >= 1.0f)
        {
            //todo 일정시간 간격으로 실행할 코드
            mpEnemyAimed->DoFireAimed(mBulletsEnemyAimed, mpActor);

            //time tick을 초기 상태로 되돌려줌
            mpEnemyAimed->mTimeTick = 0.0f;
        }
        else
        {
            //delta time 을 누적
            mpEnemyAimed->mTimeTick = mpEnemyAimed->mTimeTick + tDeltaTime;
        }


        for (vector<CBullet*>::iterator tItor = mBulletsEnemyAimed.begin(); tItor != mBulletsEnemyAimed.end(); ++tItor)
        {
            (*tItor)->Update(tDeltaTime);
        }
        

        mpEnemyCircled->Update(tDeltaTime);
        
        //적 기체가 일반탄환을 일정시간 간격으로 발사

        if (mpEnemyCircled->mTimeTick >= 3.0f)
        {
            //todo 일정시간 간격으로 실행할 코드
            mpEnemyCircled->DoFireCircled(mBulletsEnemyCircled);

            //time tick을 초기 상태로 되돌려줌
            mpEnemyCircled->mTimeTick = 0.0f;
        }
        else
        {
            //delta time 을 누적
            mpEnemyCircled->mTimeTick = mpEnemyCircled->mTimeTick + tDeltaTime;
        }

        for (vector<CBullet*>::iterator tItor = mBulletsEnemyCircled.begin(); tItor != mBulletsEnemyCircled.end(); ++tItor)
        {
            (*tItor)->Update(tDeltaTime);
        }
        */



        //render
        this->Clear(0.1f, 0.1f, 0.3f);        
        
        mpActor->Render();        
        for (vector<CBullet*>::iterator tItor = mBullets.begin(); tItor != mBullets.end(); ++tItor)
        {
            (*tItor)->Render();
        }
        mpEnemy->Render();
        for (vector<CBullet*>::iterator tItor = mBulletsEnemy.begin(); tItor != mBulletsEnemy.end(); ++tItor)
        {
            (*tItor)->Render();
        }

        mpExplosion->Render();

        /*
        mpEnemyAimed->Render();
        for (vector<CBullet*>::iterator tItor = mBulletsEnemyAimed.begin(); tItor != mBulletsEnemyAimed.end(); ++tItor)
        {
            (*tItor)->Render();
        }
        mpEnemyCircled->Render();
        for (vector<CBullet*>::iterator tItor = mBulletsEnemyCircled.begin(); tItor != mBulletsEnemyCircled.end(); ++tItor)
        {
            (*tItor)->Render();
        }
        */

        //test data setting
        /*
        mTimeInterval = 0.2f;
        mTotalFrameCount = 2;

        //애니메이션 프레임 진행 루틴
        if (mAniTime >= mTimeInterval)
        {
            //todo
            //스프라이트 프레임의 번호를 하나씩 증가시킨다.
            if (mCurFrameIndex < mTotalFrameCount - 1)
            {
                mCurFrameIndex++;
            }
            else
            {
                mCurFrameIndex = 0;
            }

            mAniTime = 0.0f;
        }
        else
        {
            mAniTime = mAniTime + tDeltaTime;
        }


        this->DrawTexture(800.0f * 0.5f, 600.0f * 0.5f, mTexs[mCurFrameIndex]);
        */

        this->Present();
    }
};




int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    
    //CAPIEngine tEngine;
    CRyuEngine tEngine;
    tEngine.Create(hInstance, nCmdShow);


    //복사생성자
    //CRyuEngine tA = tEngine;

    //CRyuEngine tB;
    //복사대입연산자
    //tB = tEngine;





    MSG msg = { 0 };
    msg = tEngine.Run();

    return (int)msg.wParam;
}


