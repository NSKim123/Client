// winAPIEngine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"



//#include "CAPIEngine.h"
//#include "CUnit.h"
//#include "CTexture.h"
//#include "ryumacro.h"
//#include "CInputMgr.h"
//#include "CCollider.h"
//#include "CCollisionMgr.h"
//#include "CAniSeq.h"
//#include "CAnimator.h"

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
    //자원resource   

    //prefab
    
    //원본 객체   

    //object
    
   

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

       
        //자원 로드 부분
        

        //실제 객체 생성
        
                
        //입력 매핑 등록
        CInputMgr::GetInstance()->AddKey("OnMoveLt", 'A');
        CInputMgr::GetInstance()->AddKey("OnMoveRt", 'D');
        CInputMgr::GetInstance()->AddKey("OnFire", VK_SPACE);        

        CInputMgr::GetInstance()->AddKey("OnTest",  VK_LCONTROL, 'H');

             


    }
    virtual void OnDestroy() override
    {
       
       
        //실제 객체 소멸        
        

        //원본 객체 소멸
        
       
        //자원 해제 
        

        CAPIEngine::OnDestroy();
    }
    virtual void OnUpdate(float tDeltaTime) override
    {
        CAPIEngine::OnUpdate(tDeltaTime);

       



        //render
        this->Clear(0.1f, 0.1f, 0.3f);        
                

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

    
   
    CRyuEngine tEngine;
    tEngine.Create(hInstance, nCmdShow);


    MSG msg = { 0 };
    msg = tEngine.Run();

    return (int)msg.wParam;
}


