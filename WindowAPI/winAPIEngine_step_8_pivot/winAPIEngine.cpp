// winAPIEngine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "winAPIEngine.h"

#include "CAPIEngine.h"
#include "CUnit.h"

#include "CTexture.h"


/*
    여기에서는 CUnit에 Pivot 기능을 추가해보자

*/


class CRyuEngine : public CAPIEngine
{
    CUnit* mpUnit = nullptr;
    CTexture* mpTexture = nullptr;

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

        //todo
        mpUnit = new CUnit();
        mpUnit->SetPosition(800 * 0.5f, 600 - 50 - 100.0f);
        mpUnit->SetRadius(50.0f);

        mpTexture = new CTexture();
        mpTexture->LoadTexture(hInst, mhDC, L"resources/bongbong_0.bmp");

    }
    virtual void OnDestroy() override
    {
        if (nullptr != mpTexture)
        {
            delete mpTexture;
            mpTexture = nullptr;
        }
        //todo
        if (nullptr != mpUnit)
        {
            delete mpUnit;
            mpUnit = nullptr;
        }
        CAPIEngine::OnDestroy();
    }
    virtual void OnUpdate() override
    {
        CAPIEngine::OnUpdate();

        //update

        //& 비트연산의 이유
        //GetAsyncKeyState 의 리턴값은 다음과 같다.
        /*
            0x0000: 이전에 눌림 없음. 호출시점에 눌림 없음 <-- 안눌림
            0x0001: 이전에 눌림 있음. 호출시점에 눌림 없음 <-- 떼어짐

            0x8000: 이전에 눌림 없음. '호출시점에 눌림' 없음 <-- 새롭게 눌림
            0x0001: 이전에 눌림 있음. '호출시점에 눌림' 있음 <-- 눌리고 있음

            이것을 알아오기 위함이다.

            비트연산으로 계산하므로 밑에 두가지 경우가 참이 된다.
        */

        //A키가 눌리고 있다면
        if (GetAsyncKeyState('A') & 0x8000)   //<--GetAsyncKeyState함수가 호출되는 시점에 A키 눌림이 있다.
        {
            //현재 위치 = 이전위치 + 속도
            mpUnit->mX = mpUnit->mX - 0.1f;
        }
        //D키가 눌리고 있다면
        if (GetAsyncKeyState('D') & 0x8000)   //<--GetAsyncKeyState함수가 호출되는 시점에 D키 눌림이 있다.
        {
            mpUnit->mX = mpUnit->mX + 0.1f;
        }



        //render
        this->Clear(1.0f, 0.0f, 0.0f);
                        
        mpUnit->Render(this);

        if (mpTexture)
        {
            /*BitBlt(mhDC, mpUnit->mX, mpUnit->mY,
                mpTexture->mBitmapInfo.bmWidth, mpTexture->mBitmapInfo.bmWidth,
                mpTexture->mhDCMem,
                0, 0,
                SRCCOPY);*/

            //DrawTexture
            /*BitBlt(this->mpBackBuffer->mhDCMem,
                mpUnit->mX, mpUnit->mY,
                mpTexture->mBitmapInfo.bmWidth, mpTexture->mBitmapInfo.bmWidth,
                mpTexture->mhDCMem,
                0, 0,
                SRCCOPY);*/
            this->DrawTexture(mpUnit->mX, mpUnit->mY, mpTexture);
        }

        /*BitBlt(mhDC,        //전면버퍼 : 현재화면 DC
            0,0,
            800,600,
            this->mpBackBuffer->mhDCMem,      //후면버퍼 : 별도로 준비한 memoryDC
            0, 0,
            SRCCOPY);*/

        this->Present();

        //test
        //window api를 이용하여 비트맵 출력해보기

        //비트맵은 '현재화면DC'에 직접적으로 출력할 수 없다.
        //<-- 현재화면 DC에 출력할 수 없으므로 현재화면 DC와 호환되는 memoryDC를 만들어 그곳에 비트맵을 설정한다.

        //비트맵을 현재화면DC에 출력하는 절차
        // i) memory dc를 만든다.
        // ii) 비트맵을 로드한다('파일'에서 데이터를 로드하여 '메모리'에 생성한다) 리턴값은 '비트맵 핸들'이다.
        // iii) 비트맵 핸들을 memory dc에 설정한다.

        //              그린다.
        //              <--- memoryDC에 설정된 비트맵(픽셀의 2차원 배열로 표현된 이미지 데이터)데이터를 현재화면DC로 복사

        // i) memory dc의 비트맵 핸들 설정을 해제한다.
        // ii) 비트맵 핸들을 삭제한다(생성한 비트맵 자원 해제)
        // iii) memory dc도 삭제한다.

        /*
        
        HDC thDCMem = CreateCompatibleDC(mhDC);   //<-- memory dc를 만든다.

        HBITMAP thBitmap = (HBITMAP)LoadImage(hInst, L"resources/bongbong_0.bmp",
            IMAGE_BITMAP,
            0,0, 
            LR_LOADFROMFILE);   //<-- LR~ Load Resource


        HBITMAP thOldBitmap = (HBITMAP)SelectObject(thDCMem, thBitmap);

            //비트맵 정보를 얻어오자
            BITMAP tBitmapInfo;
            GetObject(thBitmap, sizeof(tBitmapInfo), &tBitmapInfo);

        //비트맵 데이터 전송함수
        BitBlt(mhDC,    //현재화면 DC
            100, 100,   //<-- 출력위치
            tBitmapInfo.bmWidth, tBitmapInfo.bmHeight,   //<--너비, 높이
            thDCMem,
            0, 0,
            SRCCOPY);


        SelectObject(thDCMem, thOldBitmap);   //이전에 사용하던 비트맵으로 설정을 되돌린다.
        DeleteObject(thBitmap);

        DeleteDC(thDCMem);    //memory DC를 삭제한다.

        //현재 화면 DC와는 동작방식이 다르다.
        //현재 화면 DC는 얻어오고, 놓아주는 개념이다.
        //반면에 여기서 사용하고 있는 memoryDC는 생성하고 해제하는 개념이다.

        */
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

/*
    //복사생성자  (막아놨음)
    CRyuEngine tA = tEngine;
        
    CRyuEngine tB;
    //복사대입연산자  (막아놨음)
    tB = tEngine;    
*/

    MSG msg = { 0 };
    msg = tEngine.Run();

    return (int)msg.wParam;
}



