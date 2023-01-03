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

#include "CPiece.h"
#include "CSelect.h"

#include <list>
using namespace std;

//소스코드상에서 설정
//winAPIEngine.lib를 링킹과정에서 링크하겠다 라고 컴파일 옵션 지정
#pragma comment(lib, "winAPIEngine.lib")

/*
    이번 스텝에서는 '게임보드'를 만들고 셀들에 퍼즐 피스를 배치하자.

    이 예시는 3컬러 매치 퍼즐 알고리즘 테스트를 위해

    '격자 형태로 퍼즐 피스를 나열하고(셀들에) 플레이어의 선택 UI를 표시하는 기능을 가진다'

    요구사항 가정

    게임보드는 Grid라고 칭하고 5 by 5 크기를 가정한다.
    셀(타일) 1개의 픽셀 단위의 크기는 96 by 96 로 가정

    게임보드의 시작위치는 lefr, top 100, 100에서 시작


    다음의 두 클래스를 준비하자.

    CPiece

        퍼즐 조각 <-- 퍼즐 조각은 색상별로 준비

        <--퍼즐 피스가 그리드에 배치된 상태에서
           대기애니메이션을 수행한다는 요구사항이 있다고 가정하고
           퍼즐  피스 하나에 애니메이션 시퀀스 하나를 대응시켜 제작하겠다. ( 물론 다르게 설계도 가능하다. )

    CSelect

        임의의 셀을 선택했다는 표시

*/

class CRyuEngine : public CAPIEngine
{
    //자원 (외부 자원 파일 데이터)
    //대표 이미지
    CTexture* mpTexPiece = nullptr;
    CTexture* mpTexUISelect = nullptr;
        
    //원본 객체  
    //퍼즐 피스 원본 객체, UISelect 원본 객체
    CUnit* PFPiece = nullptr;
    CUnit* PFUISelect = nullptr;

    //실제 객체
    
    //눈에 보이지 않는 데이터
    //각각의 색상의 퍼즐피스는 애니메이션 시퀀스에 대응시키기로 가정하였다.
    //애니메이션 시퀀스의 식별자는 문자열이다.
    //그래서 해당 값들을 문자열 타입으로 설계했다.
    string mColor[6] = { "BLACK", "PINK", "RED", "GREEN","BLUE", "YELLOW" };

    //임의의 색상의 퍼즐 피스 25개 배치된 게임보드 속성
    unsigned int mBoardAttrib[5][5] =
    {
        5,5,1,1,3,
        5,2,2,2,3,
        5,4,2,3,2,
        4,4,2,3,2,
        4,1,1,3,3
    };

    //선택 UI의 위치정보. 행,열기준 좌표
    int mCurX = 0;
    int mCurY = 0;

    //눈에 보이는 데이터
    //퍼즐 피스 객체
    CPiece* mPieceBoard[5][5] =
    {
        nullptr
    };

    //선택 UI객체
    CSelect* mpUISelect = nullptr;

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
        mpTexPiece = new CTexture();
        mpTexPiece->LoadTexture(hInst, mhDC, L"resources/block_0.bmp");

        mpTexUISelect = new CTexture();
        mpTexUISelect->LoadTexture(hInst, mhDC, L"resources/select_0.bmp");

        //퍼즐 피스의 색상종류를 애니메이션 시퀀스에 대응시킴
        PFPiece = CreatePrefab<CPiece>(mpTexPiece, 0.5f, 0.5f, SVector2D(0.0f, 0.0f));
        CAnimator* tpAnimPiece = PFPiece->CreateAnimation("AnimPiece", this);
        tpAnimPiece->AddAniSeq("BLACK", 0.0f, 1, L"resources/block_0", ANI_PO::LOOP, ANI_SO::SHEET_FILE);
        tpAnimPiece->AddAniSeq("PINK", 0.0f, 1, L"resources/block_1", ANI_PO::LOOP, ANI_SO::SHEET_FILE);
        tpAnimPiece->AddAniSeq("RED", 0.0f, 1, L"resources/block_2", ANI_PO::LOOP, ANI_SO::SHEET_FILE);
        tpAnimPiece->AddAniSeq("GREEN", 0.0f, 1, L"resources/block_3", ANI_PO::LOOP, ANI_SO::SHEET_FILE);
        tpAnimPiece->AddAniSeq("BLUE", 0.0f, 1, L"resources/block_4", ANI_PO::LOOP, ANI_SO::SHEET_FILE);
        tpAnimPiece->AddAniSeq("YELLOW", 0.0f, 1, L"resources/block_5", ANI_PO::LOOP, ANI_SO::SHEET_FILE);
        tpAnimPiece->SetDefaultAniSeq("BLACK");

        PFUISelect = CreatePrefab<CSelect>(mpTexUISelect, 0.5f, 0.5f, SVector2D(0.0f, 0.0f));

        //'대기', '선택' 두 경우의 애니메이션 시퀀스를 만든다.
        CAnimator* tpAnimSelect = PFUISelect->CreateAnimation("AnimSelect", this);
        tpAnimSelect->AddAniSeq("IDLE", 0.0f, 1, L"resources/select_0", ANI_PO::LOOP, ANI_SO::SHEET_FILE);
        tpAnimSelect->AddAniSeq("SELECT", 0.3f, 2, L"resources/select", ANI_PO::LOOP, ANI_SO::FRAME_FILE);
        //tpAnimSelect->AddAniSeq("SELECT", 0.3f, 2, L"resources/select", ANI_PO::ONCE, ANI_SO::FRAME_FILE);
        //tpAnimSelect->SetDefaultAniSeq("IDLE");
        tpAnimSelect->SetDefaultAniSeq("SELECT");

        //실제 객체 생성
        for (int tRow =0;tRow<5; ++tRow)
        {
            for (int tCol =0;tCol < 5; ++tCol)
            {
                mPieceBoard[tRow][tCol] = InstantObject<CPiece>(PFPiece);
                mPieceBoard[tRow][tCol]->AddRef();
            }
        }
        
        mpUISelect = InstantObject<CSelect>(PFUISelect);
        mpUISelect->AddRef();

        //키입력 매핑값 등록
        CInputMgr::GetInstance()->AddKey("OnMoveLt", VK_LEFT);
        CInputMgr::GetInstance()->AddKey("OnMoveRt", VK_RIGHT);
        CInputMgr::GetInstance()->AddKey("OnMoveUp", VK_UP);
        CInputMgr::GetInstance()->AddKey("OnMoveDown", VK_DOWN);

        CInputMgr::GetInstance()->AddKey("OnSelectHit", VK_SPACE);
    }
    virtual void OnDestroy() override
    {
       
       
        //실제 객체 소멸        
        DestroyObject(mpUISelect);

        for (int tRow = 0;tRow < 5; ++tRow)
        {
            for (int tCol = 0 ;tCol < 5; ++tCol)
            {
                DestroyObject(mPieceBoard[tRow][tCol]);
            }
        }


        //원본 객체 소멸       
        DestroyPrefab(PFUISelect);
        DestroyPrefab(PFPiece);
       
        //자원 해제 
        SAFE_DELETE(mpTexUISelect)
        SAFE_DELETE(mpTexPiece)

        CAPIEngine::OnDestroy();
    }
    virtual void OnUpdate(float tDeltaTime) override
    {
        CAPIEngine::OnUpdate(tDeltaTime);
        
        //키입력에 따른 조작       
        if (CInputMgr::GetInstance()->KeyUp("OnMoveLt"))
        {
            mCurX = mCurX - 1;
        }
        if (CInputMgr::GetInstance()->KeyUp("OnMoveRt"))
        {
            mCurX = mCurX + 1;
        }
        if (CInputMgr::GetInstance()->KeyUp("OnMoveUp"))
        {
            mCurY = mCurY - 1;
        }
        if (CInputMgr::GetInstance()->KeyUp("OnMoveDown"))
        {
            mCurY = mCurY + 1;
        }

        if (CInputMgr::GetInstance()->KeyUp("OnSelectHit"))
        {
            OutputDebugString(L"=============OnSelectHit!=============\n");
        }
                

        //update
        int tBoardStartX = 100;
        int tBoardStartY = 100;


        for (int tRow = 0;tRow < 5; ++tRow)
        {
            for (int tCol = 0;tCol < 5; ++tCol)
            {
                //행, 열 단위의 위치값을 픽셀 단위의 위치값으로 변환
                int tX = tCol * 96 + tBoardStartX;
                int tY = tRow * 96 + tBoardStartY;

                //해당 퍼즐 피스가 위치할 셀의 위치값을 픽셀 단위로 구하여 설정
                mPieceBoard[tRow][tCol]->SetPosition(SVector2D((float)tX, (float)tY));

                //어느 색상의 퍼즐 피스인가 결정
                int tColorIndex = mBoardAttrib[tRow][tCol];
                string tColorString = mColor[tColorIndex];

                mPieceBoard[tRow][tCol]->PlayAni(tColorString);
            }
        }

        int tX = mCurX * 96 + tBoardStartX;    //<-- mCurX : 열
        int tY = mCurY * 96 + tBoardStartY;    //<-- mCurY : 행
        mpUISelect->SetPosition(SVector2D(tX, tY));
        mpUISelect->Update(tDeltaTime);

        //render
        this->Clear(0.1f, 0.1f, 0.3f);        
                
        //셀들에 배치된 퍼즐 피스들 랜더
        for (int tRow = 0;tRow < 5; ++tRow)
        {
            for (int tCol =0 ;tCol < 5; ++tCol)
            {
                mPieceBoard[tRow][tCol]->Render();
            }
        }
        //선택UI 랜더
        mpUISelect->Render();

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


