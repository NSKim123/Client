#include "CAPIEngine.h"

#include "Resource.h"

HINSTANCE CAPIEngine::hInst = nullptr;

CAPIEngine::CAPIEngine()
{
    //������� �ʱ�ȭ
    memset(szTitle, 0, sizeof(WCHAR) * MAX_LOADSTRING);
    memset(szWindowClass, 0, sizeof(WCHAR) * MAX_LOADSTRING);
}
CAPIEngine::~CAPIEngine()
{

}

BOOL CAPIEngine::Create(HINSTANCE hInstance, int nCmdShow)
{
    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPIENGINE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���ø����̼� �ʱ�ȭ�� �����մϴ�:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    return TRUE;
}
/*
MSG CAPIEngine::Run()
{
    OnCreate(); //<-- ��ӱ����� �������� �̿��Ѵ�.


    HACCEL hAccelTable = LoadAccelerators(hInst, MAKEINTRESOURCE(IDC_WINAPIENGINE));

    MSG msg = {0};  //MSG����ü Ÿ���� �������� �ʱ�ȭ

    // �⺻ �޽��� �����Դϴ�:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    
    OnDestroy(); //<-- ��ӱ����� �������� �̿��Ѵ�.

    return msg;
}
*/
MSG CAPIEngine::Run()
{
    OnCreate(); //<-- ��ӱ����� �������� �̿��Ѵ�.


    //HACCEL hAccelTable = LoadAccelerators(hInst, MAKEINTRESOURCE(IDC_WINAPIENGINE));

    MSG msg = { 0 };  //MSG����ü Ÿ���� �������� �ʱ�ȭ


    // �⺻ �޽��� �����Դϴ�:
    /*
        �޽��� ť���� �޽����� ��´�(�޽����� ���ٸ� '���'�Ѵ�.)
        �޽����� ����ٸ� ����Ű Accelerator ó���� �Ѵ� TranslateAccelerator
        ����Ű Accelerator ó���� ���ٸ� '�޽��� �ؼ�'�� �Ѵ�
        �ؼ��� �޽����� �˸��� �޽����� ó���� �� �ֵ��� ������ ���ν����� �����´� Dispatch
    */
    /*while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }*/

    //'���ӷ��� game loop'�� ������ ������ ����
    while (WM_QUIT != msg.message)    //<--���� �޽����� �ƴ϶�� ó��, ����޽����̸� ����
    {
        //�޽��� ť���� �޽����� ������ ó��

        //��, ������ �������α׷��� ���� ó���� if������
        //�� �ܿ� idle time�� '���Ӽ����� ���� ó��'�� ���ڴٶ�� ���̴�. <-- idle time�̶�� ���� �߿��ϴ�.

        //PeekMessage�� �޽���ť�� �޽����� �ִٸ� �ٷ� '��'�� �����Ѵ�.
        //�޽���ť�� �޽����� ���ٸ� ������� �ʰ� �ٷ� '����'�� �����Ѵ�.
        //          �ι�° �Ű������� ������ �ڵ��ε� nullptr�� �־��ָ� �ȴ�.
        //          ����°, �׹�°�� Ű����, ���콺�� �Է��� ���� ������ ������������ ���� ���ε� ���⼭�� �⺻���� �ִ´�.
        //          PM_REMOVE �ɼ��� �޽����� �о���̰� ���� �޽���ť���� �ش�޽����� �����ϰڴٴ� �ɼ��̴�.
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            //��
            //������ ����ũž �������α׷� ó��
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            //����
            //IDLE_TIME
            //���� ���α׷��� ó��
            //game loop

            OnUpdate();
        }
    }

    OnDestroy(); //<-- ��ӱ����� �������� �̿��Ѵ�.

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
}


ATOM CAPIEngine::MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;    //<-- WndProc�� static�� �����Ͽ� �����Լ�ȭ�Ͽ���. �ֳ��ϸ�, lpfnWndProc �� �����Լ� ������ ���ϱ� �����̴�
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
    hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    //Ŭ���̾�Ʈ ����client rect�� ũ�� ���� (��ũ��-������-Ŭ���̾�Ʈ)
    RECT tRect = {0, 0, 800, 600};  //left, top, right, bottom
    //���� �Լ��� ȣ���ϸ� Ÿ��Ʋ��, �޴� ����� �����Ͽ� �ٽ� window rect�� ������ش�.
    AdjustWindowRect(&tRect, WS_OVERLAPPEDWINDOW, FALSE);

    //���Ӱ� ���ŵ� window rect �����͸� ������ �������� ��ġ ����
    SetWindowPos(hWnd, HWND_TOPMOST, 0,0,tRect.right-tRect.left, tRect.bottom-tRect.top, SWP_NOMOVE|SWP_NOZORDER);


    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �뵵: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���ø����̼� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK CAPIEngine::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // �޴� ������ ���� �м��մϴ�:
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
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
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

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
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