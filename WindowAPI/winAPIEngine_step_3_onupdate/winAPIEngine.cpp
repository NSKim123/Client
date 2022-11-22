// winAPIEngine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "winAPIEngine.h"

#include "CAPIEngine.h"

/*
    client rect에 임의의 물체들을 표시(출력 display)해보도록 하자

    i) 문자열, 도형( 사각형, 직선, 원 )등을 출력해보자.
        WM_PAINT를 이용해본다.

    ii) i)항목에서 수행했던 작업을
        게임루프 부분인 OnUpdate 함수의 정의 에서 수행하본다

    iii) DrawCircle 을 만들어 출력해본다.

*/


class CRyuEngine : public CAPIEngine
{
public:
    CRyuEngine() {};
    virtual ~CRyuEngine() {};

    //delete는 해당 함수의 구현을 막는 문법 ( 사실 싱클톤 패턴을 이용해도 된다. )
private:
    CRyuEngine(const CRyuEngine& t) = delete;
    CRyuEngine& operator=(const CRyuEngine& t) = delete;

public:

    virtual void OnCreate() override
    {
        CAPIEngine::OnCreate();

        //todo
    }
    virtual void OnDestroy() override
    {
        //todo

        CAPIEngine::OnDestroy();
    }
    virtual void OnUpdate() override
    {
        CAPIEngine::OnUpdate();

        //todo
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



