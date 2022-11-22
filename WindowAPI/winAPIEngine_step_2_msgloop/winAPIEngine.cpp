// winAPIEngine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "winAPIEngine.h"

#include "CAPIEngine.h"

/*
    이번 예시에서의 주요목표는 '메시지루프'를
    게임프로그램의 핵심구조인
    ''게임루프'를 고려하여 구조변경'하는 것이다.
 
    결과적으로는 
        -게임 프로그램의 구조와
        -윈도우 데스크탑 응용 앱 프로그램 구조
    두 가지 경우를 모두 고려한 형태가 된다.

    i) '게임루프'를 고려한 구조로 '메시지루프를 변경'하고
        로그를 출력하여 테스트해본다.

    ii) 다음 API함수들을 호출하여 '적절한' 크기의 윈도우로 설정해준다.
        '클라이언트 영역'을 고려하여 '윈도우영역'을 정해주는 것이다.
    
    AdjustWindowRect();

    SetWindowPos();
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



