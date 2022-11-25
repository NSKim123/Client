#include "CAPIEngine.h"

#include "Resource.h"

#include "CTexture.h"

HINSTANCE CAPIEngine::hInst = nullptr;

CAPIEngine::CAPIEngine()
{
    //멤버변수 초기화
    memset(szTitle, 0, sizeof(WCHAR) * MAX_LOADSTRING);
    memset(szWindowClass, 0, sizeof(WCHAR) * MAX_LOADSTRING);
}
CAPIEngine::~CAPIEngine()
{

}

BOOL CAPIEngine::Create(HINSTANCE hInstance, int nCmdShow)
{
    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPIENGINE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    return TRUE;
}
/*
MSG CAPIEngine::Run()
{
    OnCreate(); //<-- 상속구조에 다형성을 이용한다.


    HACCEL hAccelTable = LoadAccelerators(hInst, MAKEINTRESOURCE(IDC_WINAPIENGINE));

    MSG msg = {0};  //MSG구조체 타입의 지역변수 초기화

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    
    OnDestroy(); //<-- 상속구조에 다형성을 이용한다.

    return msg;
}
*/
MSG CAPIEngine::Run()
{
    mhDC = GetDC(mhWnd);    //현재 화면 DC를 얻는다
                            //GetDC는 어디서든 현재 화면 DC를 얻는 window api함수이다.

    mpBackBuffer = new CTexture();
    mpBackBuffer->CreateBackBuffer(hInst, mhDC);

    OnCreate(); //<-- 상속구조에 다형성을 이용한다.


    MSG msg = { 0 };  //MSG구조체 타입의 지역변수 초기화
        

    //'게임루프 game loop'를 고려한 구조로 개조
    //            <---게임루프 패턴을 적용했다.
    while (WM_QUIT != msg.message)    //<--종료 메시지가 아니라면 처리, 종료메시지이면 종료
    {
        
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            //참
            //윈도우 데스크탑 응용프로그램 처리
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            //거짓
            //IDLE_TIME
            //게임 프로그램의 처리
            //game loop

            OnUpdate();
        }
    }

    OnDestroy(); //<-- 상속구조에 다형성을 이용한다.

    if (nullptr != mpBackBuffer)
    {
        delete mpBackBuffer;
        mpBackBuffer = nullptr;
    }

    ReleaseDC(mhWnd, mhDC);  //<-- 현재 화면 DC의 핸들의 제어권을 해제한다.

    return msg;
}

void CAPIEngine::OnCreate()
{
    OutputDebugString(L"CAPIEngine::OnCreate\n");
}
void CAPIEngine::OnDestroy()
{
    OutputDebugString(L"CAPIEngine::OnDestroy\n");
}
void CAPIEngine::OnUpdate()
{
    //OutputDebugString(L"CAPIEngine::OnUpdate\n");

    /*
    //문자열
    TextOut(mhDC, 0, 0, TEXT("Good Boy."), 9);
    TextOut(mhDC, 0, 25, TEXT("0102345%$*&^HJKJBBHKfggfJU가ㄱ"), 28);
    TextOut(mhDC, 0, 50, TEXT("안녕하세요.김남석입니다."), 13);

    LPCWSTR tszwStr = L"이건 한글판visual studio community";
    int tCount = lstrlenW(tszwStr);   //wide string 글자 갯수 세기 함수
    TextOut(mhDC, 0, 75, tszwStr, tCount);

    //사각형
    Rectangle(mhDC, 200, 200, 200 + 100, 200 + 50);

    //선분 그리기
    MoveToEx(mhDC, 550, 200, nullptr);
    LineTo(mhDC, 600, 300);

    //삼각형 그리기
    MoveToEx(mhDC, 350, 200, nullptr);
    LineTo(mhDC, 450, 300);
    LineTo(mhDC, 500, 200);
    LineTo(mhDC, 350, 200);

    //타원
    Ellipse(mhDC, 400, 100, 400 + 100, 100 + 50);

    //원
    Ellipse(mhDC, 0, 400, 0 + 100, 400 + 100);
    */
}

void CAPIEngine::DrawCircle(float tX, float tY, float tRadius)
{
    //Ellipse(mhDC, tX - tRadius, tY - tRadius, tX + tRadius, tY + tRadius);

    //이제 후면 버퍼에 그린다.
    Ellipse(mpBackBuffer->mhDCMem, tX - tRadius, tY - tRadius, tX + tRadius, tY + tRadius);
}

void CAPIEngine::DrawTexture(float tX, float tY, CTexture* tpTexture)
{
    BitBlt(this->mpBackBuffer->mhDCMem,
        tX, tY,
        tpTexture->mBitmapInfo.bmWidth, tpTexture->mBitmapInfo.bmWidth,
        tpTexture->mhDCMem,
        0, 0,
        SRCCOPY);
}

void CAPIEngine::Clear()
{
    RECT tRect = { 0 };
    //클라이언트 영역에 크기를 얻어오는 window api
    GetClientRect(mhWnd, &tRect);

    //Rectangle(mhDC, 0, 0, tRect.right, tRect.bottom);
    Rectangle(mpBackBuffer->mhDCMem, 0, 0, tRect.right, tRect.bottom);
}

//double buffer pattern 적용
void CAPIEngine::Present()
{
    BitBlt(mhDC,        //전면버퍼 : 현재화면 DC
        0, 0,
        800, 600,
        this->mpBackBuffer->mhDCMem,      //후면버퍼 : 별도로 준비한 memoryDC
        0, 0,
        SRCCOPY);
}

ATOM CAPIEngine::MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;    //<-- WndProc에 static을 적용하여 전역함수화하였다. 왜냐하면, lpfnWndProc 가 전역함수 형식을 원하기 떄문이다
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPIENGINE));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPIENGINE);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL CAPIEngine::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }
    //멤버변수에 기억
    mhWnd = hWnd;

    //클라이언트 영역client rect의 크기 지정 (스크린-윈도우-클라이언트)
    RECT tRect = {0, 0, 800, 600};  //left, top, right, bottom
    //다음 함수를 호출하면 타이틀바, 메뉴 등까지 고려하여 다시 window rect를 계산해준다.
    AdjustWindowRect(&tRect, WS_OVERLAPPEDWINDOW, FALSE);

    //새롭게 갱신된 window rect 데이터를 가지고 윈도우의 위치 지정
    SetWindowPos(hWnd, HWND_TOPMOST, 0,0,tRect.right-tRect.left, tRect.bottom-tRect.top, SWP_NOMOVE|SWP_NOZORDER);


    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK CAPIEngine::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        //BeginPaint ~ EndPaint 는 WM_PAINT 메시지부에서만 유효하다.

        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);  //DC의 handle을 얻는다. Device Context(WindowOS에서 제공하는 추상화된 그리기장치도구)
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

        /*
        //문자열
        TextOut(hdc, 0, 0, TEXT("Good Boy."), 9);
        TextOut(hdc, 0, 25, TEXT("0102345%$*&^HJKJBBHKfggfJU가ㄱ"), 28);
        TextOut(hdc, 0, 50, TEXT("안녕하세요.김남석입니다."), 13);

        LPCWSTR tszwStr = L"이건 한글판visual studio community";
        int tCount = lstrlenW(tszwStr);   //wide string 글자 갯수 세기 함수
        TextOut(hdc, 0, 75, tszwStr, tCount);

        //사각형
        Rectangle(hdc, 200, 200, 200 + 100, 200 + 50);

        //선분 그리기
        MoveToEx(hdc, 550, 200, nullptr);
        LineTo(hdc, 600, 300);

        //삼각형 그리기
        MoveToEx(hdc, 350, 200, nullptr);
        LineTo(hdc, 450, 300);
        LineTo(hdc, 500, 200);
        LineTo(hdc, 350, 200);

        //타원
        Ellipse(hdc, 400, 100, 400 + 100, 100 + 50);

        //원
        Ellipse(hdc, 0, 400, 0 + 100, 400 + 100);
        */
        
        EndPaint(hWnd, &ps);   //DC를 해제
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK CAPIEngine::About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
