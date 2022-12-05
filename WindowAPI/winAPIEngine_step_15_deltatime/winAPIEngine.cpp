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

using namespace std;
/*
    이번 예시에서는 '시간 기반 진행'을 위한 구조를 작성해보자.

        프레임 기반 진행 vs 시간 기반 진행

        this->mPosition = this->mPosition + mVelocity;
        현재위치 = 이전위치 + 속도*시간간격
        시간간격 <--- 1프레임

        초당 프레임 : 1초에 프레임의 갯수가 몇개이냐

        프레임 기반 진행의 문제점 
        :컴퓨터의 성능에 따라 게임월드의 진행 속도가 달라진다.
        --> 실제 시간 기반 진행으로 만드려면 무슨 개념이 필요한가?
        --> N프레임 : 1초 = 1프레임 : x초
            x =1/N (여기서 N은 초당 프레임) 
            즉, 실제 시간기반으로 진행하려면 
            시간 간격의 기준이 프레임이 아니라 1초를 잘게 쪼갠 실제 시간이 필요하다.
            -->즉, '한 프레임에 걸리는 시간'을 측정하면 된다.


        -프레임 기반으로 진행되는 게임 속에서의 예
        
            예) 60fps    Frames per second
                
                현재위치 = 이전위치 + 50*1프레임

                1초에 3000픽셀 움직임
       
       -시간 기반으로 진행되는 게임 속에서의 예

            예) 60fps    Frames per second

                현재위치 = 이전위치 + 50*(1/60)

                50*(1/60)*60 = 50 <--1초에 실제로 진행된 수치

            예) 100fps    Frames per second

                현재위치 = 이전위치 + 50*(1/100)

                50*(1/100)*100 = 50 <--1초에 실제로 진행된 수치

        ------------------------------------------------------------------------------------------

        TimeTick : 시스템이 구동되고 나서부터 시스템은 일정 카운트를 센다. 이것을 tick이라고 한다.
                    <--- 이 tick을 가지고 시간측정을 하자.

        timeGetTime()
        GetTickCount()
        <---정밀도가 1/1000초 정도이다. 이것은 비교적 부정확하므로 사용하지 않겠다.
            클럭장치에 의해 틱을 센다.

        QueryPerformanceCounter
        <---정밀도가 1/1,000,000초 정도이다. 이것은 비교적 정확하므로 이것을 사용하겠다.
            CPU의 주파수에 기반하여 틱을 센다.
*/


class CRyuEngine : public CAPIEngine
{
    CUnit* mpUnit = nullptr;
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

        mpUnit = new CUnit();
        mpUnit->Addref();
        mpUnit->SetPosition(800 * 0.5f, 600 - 50 - 100.0f);
        mpUnit->SetRadius(50.0f);
        //pivot
        mpUnit->SetAnchorPoint(0.5f, 0.5f);
        mpUnit->SetTexture(mpTexture);
                
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
        SAFE_DELETE(mpTexture);
        //todo
        /*
        if (nullptr != mpUnit)
        {
            //delete mpUnit;
            mpUnit->Release();
            mpUnit = nullptr;
        }
        */
        SAFE_RELEASE(mpUnit);

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
        mpUnit->SetVelocity(tVelocity);
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
            mpUnit->SetVelocity(tVelocity * 350.0f);   //초당 350 픽셀

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
            mpUnit->SetVelocity(tVelocity * 350.0f);

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
        mpUnit->Update(tDeltaTime);

        //render
        this->Clear(1.0f, 0.0f, 0.0f);
                        
        mpUnit->Render(this);
           
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



