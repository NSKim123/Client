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

using namespace std;
/*
    이번 예시에서부터는 '프로토타입 패턴'을 적용해보기로 한다.
        <-- 객체 생성 문제에 관한 패턴 중 하나이다.
    

    Prototype Pattern 

        'Prefab 원본객체' 라는 개념을 만들고
        이것을 '복제'하여 새로운 객체를 생성하는 형태를 취하는 패턴
    
        clone() 함수를 만드는 특징이 드러난다.


    프로토타입 패턴의 목적
    i) 임의의 데이터 값들을 가지는 객체를 '손쉽게' 만들어내는 것이 가능하다.(가장 중요한 목적)
    ii) 또한, 객체를 생성하는 부분의 코드를 보다 일반화하여 표현하는 것이 가능하다.

*/


class CRyuEngine : public CAPIEngine
{
    //원본 객체 ( 주인공 기체의 원본 객체 )
    CUnit* PFActor = nullptr;




    CActor* mpActor = nullptr;
    CTexture* mpTexture = nullptr;

    //test
    //CObjectRyu* testObject = nullptr;

public:
    CRyuEngine() {};
    virtual ~CRyuEngine() {};

    //delete는 해당 함수의 구현을 막는 문법 ( 사실 싱글톤 패턴을 이용해도 된다. )
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

        //todo
        mpTexture = new CTexture();
        mpTexture->LoadTexture(hInst, mhDC, L"resources/bongbong_0.bmp");

        //원본객체 생성
        PFActor = new CActor();
        //PFActor->Addref();
        PFActor->SetPosition(800 * 0.5f, 600 - 50 - 100.0f);
        PFActor->SetRadius(50.0f);
        //pivot
        PFActor->SetAnchorPoint(0.5f, 0.5f);
        PFActor->SetTexture(mpTexture);
        

        //실제 객체 생성
        mpActor = static_cast<CActor*>(PFActor->clone());   
        //<--복제하여 생성. 부모클래스는 자식클래스 포인터 타입으로 다룰 수 없기 때문에 형변환을 하였다.
        mpActor->Addref();



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
        //매크로함수를 사용하여 호출하는 측에 코드가 간략화되었다.
        //단, 디버깅이 안 된다.
        SAFE_DELETE(mpTexture)
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
        SAFE_RELEASE(mpActor)




        //원본 객체 소멸
        SAFE_DELETE(PFActor)
        /*
        //ref test
        if (nullptr != testObject)
        {
            testObject->Release();
            testObject = nullptr;
        }
        */



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
        }
        if (CInputMgr::GetInstance()->KeyUp("OnTest"))
        {
            OutputDebugString(L"On Test!....VK_LCONTROL & 'H'\n");
        }

        //속도에 의한 이동 코드
        mpActor->Update(tDeltaTime);

        //render
        this->Clear(1.0f, 0.0f, 0.0f);
                        
        mpActor->Render(this);
           
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



