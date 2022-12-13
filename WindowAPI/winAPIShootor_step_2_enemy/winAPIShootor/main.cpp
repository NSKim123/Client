// winAPIEngine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "winAPIEngine.h"
#include "CAPIEngine.h"
#include "CUnit.h"
#include "CTexture.h"
#include <list>
#include "ryumacro.h"
#include "CInputMgr.h"
#include "CActor.h"
#include "CBullet.h"

#include "CEnemy.h"

using namespace std;

//소스코드상에서 설정
//winAPIEngine.lib를 링킹과정에서 링크하겠다라고 컴파일 옵션 지정
#pragma comment(lib, "winAPIEngine.lib")

/*
    이번 예시에서는 다음의 사항들을 만들어보자.

    1) 적 기체 생성

        CEnemy클래스 

    2) 적 기체 일반탄환 발사

    3) 적 기체 좌우 이동, 좌우 경계 처리

*/


class CRyuEngine : public CAPIEngine
{
    //자원 resource
    CTexture* mpTexture = nullptr;
    CTexture* mpTexBullet = nullptr; //탄환 비트맵 이미지 데이터 자원
    CTexture* mpTexEnemy = nullptr; //적 비트맵 데이터 자원

    //원본 객체 ( 주인공 기체의 원본 객체 ) prefab
    CUnit* PFActor = nullptr;
    CUnit* PFBullet = nullptr;  //탄환 원본 객체
    CUnit* PFEnemy = nullptr;  //적 원본 객체

    //실제 객체 object
    CActor* mpActor = nullptr;  
    vector<CBullet*> mBullets;  //실제 주인공 기체가 사용할 탄환객체들

    CEnemy* mpEnemy = nullptr;

    //test
    //CObjectRyu* testObject = nullptr;

public:
    CRyuEngine() {};
    virtual ~CRyuEngine() {};

    //delete는 해당 함수의 구현을 막는 문법
private:
    CRyuEngine(const CRyuEngine& t) = delete;
    CRyuEngine& operator=(const CRyuEngine& t) = delete;

public:

    virtual void OnCreate() override
    {
        CAPIEngine::OnCreate();

        //test
        /*
        RYU_INT tA = 3;
        RYU_INT tB = 2;
        RYU_INT tResult = 0;

        tResult = tA + tB;

        char tszTemp[256] = { 0 };
        sprintf_s(tszTemp, "tResult: %d\n", tResult);
        OutputDebugStringA(tszTemp);
        //~A 가 붙은 OutputDebugString은 아스키코드용
        */

        /*
        //ref test
        testObject = new CObjectRyu();
        testObject->Addref();

        list<CObjectRyu*> testObjectList;
        testObjectList.push_back(testObject); //testObject의 값이 복사되어 리스트로 들어간다. 그래서 참조가 하나 증가해야한다.
        testObject->Addref();

        testObject->Release(); //리스트가 지역변수이므로 해당 지역을 벗어나면 소멸된다. 이를 고려하여 참조를 다시 감소시킨다.
        */

        //자원 로드 부분
        //todo
        mpTexture = new CTexture();
        mpTexture->LoadTexture(hInst, mhDC, L"resources/bongbong_0.bmp");
        mpTexBullet = new CTexture();
        mpTexBullet->LoadTexture(hInst, mhDC, L"resources/bongbullet.bmp");

        mpTexEnemy = new CTexture();
        mpTexEnemy->LoadTexture(hInst, mhDC, L"resources/bongenemy.bmp");

        //원본객체 생성
        /*
        PFActor = new CActor();
        //PFActor->Addref();
        PFActor->SetPosition(800 * 0.5f, 600 - 50 - 100.0f);
        PFActor->SetRadius(50.0f);
        //pivot
        PFActor->SetAnchorPoint(0.5f, 0.5f);
        PFActor->SetTexture(mpTexture);
        */
        PFActor = CreatePrefab<CActor>(mpTexture, 0.5f, 0.5f, SVector2D(800 * 0.5f, 600 - 50 - 100.0f));
        PFBullet = CreatePrefab<CBullet>(mpTexBullet, 0.5f, 0.5f, SVector2D(800 * 0.5f, 600 - 50 - 100.0f));

        PFEnemy = CreatePrefab<CEnemy>(mpTexEnemy, 0.5f, 0.5f, SVector2D(800 * 0.5f, 100.0f));
        //실제 객체 생성
        //mpActor = static_cast<CActor*>(PFActor->clone());   
        mpActor = InstantPrefab<CActor>(PFActor);      
        //<--복제하여 생성. 부모클래스는 자식클래스 포인터 타입으로 다룰 수 없기 때문에 형변환을 하였다.
        mpActor->Addref();

        CBullet* tpBullet = nullptr;
        for (int ti  = 0; ti < 10; ++ti)
        {
            tpBullet = InstantPrefab<CBullet>(PFBullet);            
            tpBullet->Addref();

            tpBullet->SetIsActive(false);   //탄환객체들은 비활성으로 생성

            mBullets.push_back(tpBullet);
            tpBullet->Addref();

            tpBullet->Release();
            tpBullet = nullptr;
        }
         //
        mpEnemy = InstantPrefab<CEnemy>(PFEnemy);        
        mpEnemy->Addref();


        //입력 매핑 등록
        CInputMgr::GetInstance()->AddKey("OnMoveLt", 'A');
        CInputMgr::GetInstance()->AddKey("OnMoveRt", 'D');
        CInputMgr::GetInstance()->AddKey("OnFire", VK_SPACE);

        CInputMgr::GetInstance()->AddKey("OnTest", VK_LCONTROL, 'H');
    }
    virtual void OnDestroy() override
    {
        /*if (nullptr != mpTexture)
        {
            delete mpTexture;
            mpTexture = nullptr;
        }*/
        
        //todo
        /*
          if (nullptr != mpUnit)
          {
              //delete mpUnit;
              mpUnit->Release();
              mpUnit = nullptr;
          }
          */
        //실제 객체 소멸
        //SAFE_RELEASE(mpActor)
        DestroyObject<CEnemy>(mpEnemy);
        DestroyObject<CActor>(mpActor);
        vector<CBullet*>::iterator tItor;
        for (tItor = mBullets.begin(); tItor != mBullets.end(); tItor++)
        {
            SAFE_RELEASE((*tItor))  //(*tItor)->~~   이런 형태로 표현하기 위해 괄호를 써야한다.
        }




        //원본 객체 소멸
        DestroyPrefab(PFEnemy);
        DestroyPrefab(PFBullet);
        DestroyPrefab(PFActor);
        //SAFE_DELETE(PFActor)

        /*
        //ref test
        if (nullptr != testObject)
        {
            testObject->Release();
            testObject = nullptr;
        }
        */

        //자원 해제 코드
        //매크로함수를 사용하여 호출하는 측에 코드가 간략화되었다.
        //단, 디버깅이 안 된다.
        SAFE_DELETE(mpTexture)
        SAFE_DELETE(mpTexBullet)
        SAFE_DELETE(mpTexEnemy)

        CAPIEngine::OnDestroy();
    }

    virtual void OnUpdate(float tDeltaTime) override
    {
        CAPIEngine::OnUpdate(tDeltaTime);

        //update
               
        
        /*
        SVector2D tVelocity;//지역변수로 설정해서, 키입력이 없다면 영벡터가 되어 움직이지 않게 된다.
        //A키가 눌리고 있다면
        mpUnit->SetVelocity(tVelocity);
        //mpUnit->SetVelocity(tVelocity)
        if (GetAsyncKeyState('A') & 0x8000)   //<--GetAsyncKeyState함수가 호출되는 시점에 A키 눌림이 있다.
        {
            //현재 위치 = 이전위치 + 속도
            //'오일러 축차적 적분법'에 의한 위치 이동 코드
            //mpUnit->mPosition.mX = mpUnit->mPosition.mX - 0.1f;
            
            //속도 설정 (-1,0)
            tVelocity.mX = -1.0f;
            tVelocity.mY = 0.0f;

            mpUnit->SetVelocity(tVelocity * 0.1f);

            OutputDebugString(L"key input A\n");

        }
        //D키가 눌리고 있다면
        if (GetAsyncKeyState('D') & 0x8000)   //<--GetAsyncKeyState함수가 호출되는 시점에 D키 눌림이 있다.
        {
            //mpUnit->mPosition.mX = mpUnit->mPosition.mX + 0.1f;
            
            //속도 설정 (+1,0)
            tVelocity.mX = 1.0f;
            tVelocity.mY = 0.0f;

            mpUnit->SetVelocity(tVelocity * 0.1f);

            OutputDebugString(L"key input D\n");
        }
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) 
        {
            OutputDebugString(L"Fire Bullet!....VK_SPACE\n");
        }


        //속도에 의한 이동 코드
        mpUnit->Update();
        //mpUnit->mPosition = mpUnit->mPosition + tVelocity * 0.1f;
        */
        SVector2D tVelocity;//지역변수로 설정해서, 키입력이 없다면 영벡터가 되어 움직이지 않게 된다.
        //A키가 눌리고 있다면
        mpActor->SetVelocity(tVelocity);
        //mpUnit->SetVelocity(tVelocity)
        if (CInputMgr::GetInstance()->KeyPress("OnMoveLt"))   //<--GetAsyncKeyState함수가 호출되는 시점에 A키 눌림이 있다.
        {
            //현재 위치 = 이전위치 + 속도
            //'오일러 축차적 적분법'에 의한 위치 이동 코드
            //mpUnit->mPosition.mX = mpUnit->mPosition.mX - 0.1f;

            //속도 설정 (-1,0)
            tVelocity.mX = -1.0f;
            tVelocity.mY = 0.0f;

            //mpUnit->SetVelocity(tVelocity * 0.1f);
            mpActor->SetVelocity(tVelocity * 350.0f);   //초당 350 픽셀

            OutputDebugString(L"key input A\n");

        }
        //D키가 눌리고 있다면
        if (CInputMgr::GetInstance()->KeyPress("OnMoveRt"))   //<--GetAsyncKeyState함수가 호출되는 시점에 D키 눌림이 있다.
        {
            //mpUnit->mPosition.mX = mpUnit->mPosition.mX + 0.1f;

            //속도 설정 (+1,0)
            tVelocity.mX = 1.0f;
            tVelocity.mY = 0.0f;

            //mpUnit->SetVelocity(tVelocity * 0.1f);
            mpActor->SetVelocity(tVelocity * 350.0f);

            OutputDebugString(L"key input D\n");
        }
        if (CInputMgr::GetInstance()->KeyUp("OnFire"))
        {
            OutputDebugString(L"Fire Bullet!....VK_SPACE\n");

            mpActor->DoFire(mBullets);
        }
        if (CInputMgr::GetInstance()->KeyUp("OnTest"))
        {
            OutputDebugString(L"On Test!....VK_LCONTROL & 'H'\n");
        }

        //속도에 의한 이동 코드
        mpActor->Update(tDeltaTime);

        for (vector<CBullet*>::iterator tItor = mBullets.begin(); tItor != mBullets.end(); tItor++)
        {
            (*tItor)->Update(tDeltaTime);
        }
        mpEnemy->Update(tDeltaTime);

        //render
        this->Clear(1.0f, 0.0f, 0.0f);
                        
        mpActor->Render();

        
        for (vector<CBullet*>::iterator tItor = mBullets.begin(); tItor != mBullets.end(); tItor++)
        {
            (*tItor)->Render();
        }
        
        mpEnemy->Render();


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

    MSG msg = { 0 };
    msg = tEngine.Run();

    return (int)msg.wParam;
}



