
#include <Windows.h>

//step_0
//윈도우 데스크탑 응용프로그램의 시작점은 WinMain함수이다.

//매개변수들
//      HINSTANCE hInstance  <--- 윈도우 응용프로그램 식별자 핸들. 같은 윈도우 종류라면 모두 같다. // 이 응용프로그램의 원본
//      HINSTANCE hPrevInstance   <--- 이 윈도우가 만들어진 원래 윈도우의 핸들  // 이전 응용프로그램 인스턴스
//      LPWSTR    lpCmdLine   <--- 응용프로그램이 시작될때 주어지는 옵션   lp long pointer    LPWSTR long pointer wide string
//      int       nCmdShow   <--- 해당 윈도우 응용프로그램이 어떤 상태로 보여질 것인지에 대한 옵션   
// 
//매개변수로 주어지는 인자들은 '윈도우를 생성하는데 필요한 준비된 자원들'로
//운영체제가 WinMain을 호출하면서 알아서 넘겨준다.

//접두사 h가 붙은 것은 '핸들 handle'이라는 개념의 변수이다.
//<-- 윈도우 응용프로그램은 직접적으로 자원에 대한 주소를 접근하여 사용할 수 없다.
//    그러므로 포인터 대신 '핸들'이란 개념을 사용하여 자원resource에 간접적으로 접근한다.

/*
int APIENTRY wWinMain(HINSTANCE hInstance,
     HINSTANCE hPrevInstance,
     LPWSTR    lpCmdLine,
     int       nCmdShow)
{
    return 0;
}
*/

/*
    이렇게 응용 프로그램 계층과
    시스템 커널 계층(운영체제)이  분리된 이유는
    현대 운영체제가 '멀티테스킹' 프로그램인 이유도 한 몫 한다.
    즉, 임의의 한 응용프로그램이 잘못된 동작을 취했다고 해서
    운영체제가 잘못된 행동을 보이면 안되므로
    응용 프로그램의 자원 제어권을 제한하고 있는 개념이다.

    콘솔 응용프로그램과의 차이점이다.

    ---------운영체제가 제공하는 자원들. '핸들handle'이란 개념으로 다룬다.-------------

                    물론, 윈도우에서 제공하는 콘솔은 원래의 고전적인 콘솔이 아니라 윈도우프로그램으로서의 콘솔 에뮬레이터 이다.

*/


//step_1
//<----------- 윈도우 클래스
//                      <--사용자 정의 타입 클래스가 아니다. '분류'의 한 항목이란 의미이다.

/*
    즉, 윈도우 클래스란 윈도우응용프로그램의 정보 중 '일부'를 나타내는 용어이다.

    '윈도우 클래스'라는 개념이 있는 이유는
    윈도우들에서 동일하게 다루어지는 즉, '중복된 데이터들'을 공유하여 관리하기 위한 개념이다.
    그러면, 운영체제 입장에서 보다 효율적으로 자원이 관리되기 때문이다.(예 : 메모리가 절약)

    이를테면 형태는 갖고 데이터만 다른 윈도우의 경우 형태에 대한 윈도우 클래스 정보를 공유함으로써
    보다 효율적으로(메모리관점에서) 전체 프로그램들을 관리할 수 있다.
    예) 크롬 브라우저 창 여러개 띄우는 경우
    
*/



/*

int APIENTRY wWinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR    lpCmdLine,
    int       nCmdShow)
{
    
     //   운영체제의 시스템 커널에 의해 관리되는 영역에 속한 '자원'이므로 포인터로 참조하는 것이 아닌
     //   이렇게 별도의 정해진 규칙의 데이터를 설정함으로써 운영체제에서 제공하는 '윈도우'라는 자원을
     //   만들고 관리하게 된다
     //   <-- window api가 만들어진 형태대로 가이드하는대로 한다.
    


    //윈도우 클래스 데이터 설정
    WNDCLASSEXW wcex;    //윈도우 클래스 구조체 타입의 변수

    wcex.cbSize = sizeof(WNDCLASSEXW);   //cb~ class buffer

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = nullptr; //WndProc;          //함수포인터 lpfnWndProc 에 함수를 등록 lpfn~ long pointer function의 의미
    wcex.cbClsExtra = 0;        //윈도우 클래스를 위한 여분의 메모리
    wcex.cbWndExtra = 0;        //윈도우를 위한 여분의 메모리
    wcex.hInstance = hInstance;     //해당 윈도우의 식별자
    //wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hIcon = LoadIcon(hInstance, nullptr);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    //wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);      //lpsz~ long pointer string zero
    wcex.lpszMenuName = nullptr;   
    wcex.lpszClassName = L"winFirst"; //szWindowClass;          //윈도우 클래스 이름  , L을 붙여 유니코드(2Byte문자 표현 방식)로 인지시킨다.
    wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr); //MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcex);     //윈도우 클래스 정보를 설정하여 운영체제에 등록

    return 0;
}
*/


//step_2
//<-----윈도우 생성

/*
int APIENTRY wWinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR    lpCmdLine,
    int       nCmdShow)
{
    
     //   운영체제의 시스템 커널에 의해 괸리되는 영역에 속한 '자원'이므로 포인터로 참조하는 것이 아닌
     //   이렇게 별도의 정해진 규칙의 데이터를 설정함으로써 운영체제에서 제공하는 '윈도우'라는 자원을
     //   만들고 관리하게 된다
     //   <-- window api가 만들어진 형태대로 가이드하는대로 한다.
    
    HINSTANCE hInst;
    LPCWSTR szWindowClass = L"winFirst";
    LPCTSTR szTitle = L"I am a Good Boy";

    //윈도우 클래스 데이터 설정
    WNDCLASSEXW wcex;    //윈도우 클래스 구조체 타입의 변수

    wcex.cbSize = sizeof(WNDCLASSEXW);   //cb~ class buffer

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = nullptr; //WndProc;          //함수포인터 lpfnWndProc 에 함수를 등록 lpfn~ long pointer function의 의미
    wcex.cbClsExtra = 0;        //윈도우 클래스를 위한 여분의 메모리
    wcex.cbWndExtra = 0;        //윈도우를 위한 여분의 메모리
    wcex.hInstance = hInstance;     //해당 윈도우의 식별자
    //wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hIcon = LoadIcon(hInstance, nullptr);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    //wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);      //lpsz~ long pointer string zero
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = szWindowClass;          //윈도우 클래스 이름  , L을 붙여 유니코드(2Byte문자 표현 방식)로 인지시킨다.
    wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr); //MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcex);     //윈도우 클래스 정보를 설정하여 운영체제에 등록







    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    //실제로 윈도우를 생성한다.
    //윈도우 핸들 hWnd (윈도우 식별자) 을 리턴
    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);    //CW~ CreateWindow

    //hInstance는 창이 달라도 동일한 창 종류이면 하나이다.
    //hWnd는 동일한 종류라 하더라도 창마다 만들어지는 것이다.



    //CreateWindowW는 윈도우를 만든다. 이 함수를 호출하면 WM_CREATE 메시지가 보내진다
    // 아직 메시지루프 코드에 도달하지 못했다.
    //즉, WM_CREATE는 메시지 루프 코드가 작동하기 전에 보내진다
    //'메시지큐'에 담길 것이다.

    //이 코드는 에러를 낼 것이다.

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);  //윈도우 보이기(보이냐/안보이냐)
    UpdateWindow(hWnd);          //윈도우 화면을 갱신한다.

    


    return 0;
}
*/


//step_3

//<-------이벤트 드리븐event driven,
//          메시지Message, 메시지루프Message loop, 윈도우 프로시저window procedure, 메시지큐Message Queue
//여기서는 '윈도우 프로그램은 이벤트 기반으로 동작한다' 라는 개념을 살펴본다
//이를 위해 제공되는 '윈도우 프로시저'개념을 살펴본다

//"'윈도우 프로시저'를 정의하고 '윈도우클래스 정보'에 설정하였다"

//윈도우 프로시저의 정의는 window api가 요구하는 형식을 맞춰야만 한다
//------------호출은 운영체제가 하기 때문이다!!!!!!!------------

//message : 윈도우 메시지 식별자이다. WM_접두사가 붙어있다.
//wParam Word PARAMETER 32비트 응용앱에서는 32비트 크기이다.
//lParam LONG PARAMETER 32비트 크기이다.

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);  //hdc device context에 대한 핸들
        // device context 그리기 장치 ( 그리기에 대한 여러가지 장치와 소프트웨어를 추상화해놓은 것 )
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

        EndPaint(hWnd, &ps);
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


int APIENTRY wWinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR    lpCmdLine,
    int       nCmdShow)
{

    //   운영체제의 시스템 커널에 의해 괸리되는 영역에 속한 '자원'이므로 포인터로 참조하는 것이 아닌
    //   이렇게 별도의 정해진 규칙의 데이터를 설정함으로써 운영체제에서 제공하는 '윈도우'라는 자원을
    //   만들고 관리하게 된다
    //   <-- window api가 만들어진 형태대로 가이드하는대로 한다.

    HINSTANCE hInst;
    LPCWSTR szWindowClass = L"winFirst";
    LPCTSTR szTitle = L"I am a Good Boy";

    //윈도우 클래스 데이터 설정
    WNDCLASSEXW wcex;    //윈도우 클래스 구조체 타입의 변수

    wcex.cbSize = sizeof(WNDCLASSEX);   //cb~ class buffer

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;          //함수포인터 lpfnWndProc 에 함수를 등록 lpfn~ long pointer function의 의미
    wcex.cbClsExtra = 0;        //윈도우 클래스를 위한 여분의 메모리
    wcex.cbWndExtra = 0;        //윈도우를 위한 여분의 메모리
    wcex.hInstance = hInstance;     //해당 윈도우의 식별자
    //wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hIcon = LoadIcon(hInstance, nullptr);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    //wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);      //lpsz~ long pointer string zero
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = szWindowClass;          //윈도우 클래스 이름  , L을 붙여 유니코드(2Byte문자 표현 방식)로 인지시킨다.
    wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr); //MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcex);     //윈도우 클래스 정보를 설정하여 운영체제에 등록







    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    //실제로 윈도우를 생성한다.
    //윈도우 핸들 hWnd (윈도우 식별자) 을 리턴
    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);    //CW~ CreateWindow

    //hInstance는 창이 달라도 동일한 창 종류이면 하나이다.
    //hWnd는 동일한 종류라 하더라도 창마다 만들어지는 것이다.



    //CreateWindowW는 윈도우를 만든다. 이 함수를 호출하면 WM_CREATE 메시지가 보내진다
    // 아직 메시지루프 코드에 도달하지 못했다.
    //즉, WM_CREATE는 메시지 루프 코드가 작동하기 전에 보내진다
    //'메시지큐'에 담길 것이다.

    //이 코드는 에러를 낼 것이다.  

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);  //윈도우 보이기(nCmdShow : 보이냐/안보이냐)
    UpdateWindow(hWnd);          //윈도우 화면을 갱신한다.



    HACCEL hAccelTable = LoadAccelerators(hInstance, nullptr); //MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;   //<-- 윈도우 메시지 구조체 : 이벤트를 윈도우에서 메시지라고 칭하고 있다.
               //이벤트: 명령어와 데이터를 묶어 추상화해놓은 개념

    // 기본 메시지 루프입니다:
    //  Get~ : 블럭block 대기함수
    //  Post~ : 넌블럭nonblock 비대기함수
    while (GetMessage(&msg, nullptr, 0, 0)) //GetMessage 윈도우 메시지 큐로부터 메시지를 얻어온다
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))   //엑셀러레이터 처리를 우선으로 한다.
        {
            TranslateMessage(&msg);         //메시지를 해석(번역)한다.
            DispatchMessage(&msg);          //윈도우 프로시저에 넘겨 처리를 위임한다.
        }
    }

    return (int)msg.wParam;


    return 0;
}