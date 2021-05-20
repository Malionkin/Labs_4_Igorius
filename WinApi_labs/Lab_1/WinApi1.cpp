// WinApi1.cpp : Определяет точку входа для приложения.
//
#define _USE_MATH_DEFINES
#include "framework.h"
#include "WinApi1.h"
#include <math.h>
#include <cmath>
#include <string>
#define MAX_LOADSTRING 100
const int R = 200;
// Глобальные переменные:
RECT rect;
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


void Line(HDC hdc, float x_1,float y_1, float x_2, float y_2) {
    MoveToEx(hdc, x_1, y_1, NULL);
    LineTo(hdc, x_2, y_2);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPI1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI1));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}






//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINAPI1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}







//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
 

    static double t;
    float X_0 = rect.right / 2;
    float Y_0 = rect.bottom / 2;
    float ball_x;
    float ball_y;


    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
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
    case WM_CREATE:
        SetTimer(hWnd, 1, 125, NULL);
        break;
    case WM_TIMER:
        
        t += 0.02;
        if (t >= M_PI * 2) {
            KillTimer(hWnd, 1);
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_PAINT:
        {
        GetClientRect(hWnd, &rect);
            PAINTSTRUCT ps;
            HPEN pen = CreatePen(PS_DASH, 1, RGB(0, 0, 0));
            HPEN rose_pen = CreatePen(PS_SOLID, 1, RGB(213, 0, 0));
            HDC hdc = BeginPaint(hWnd, &ps);
            SelectObject(hdc, pen);
            Line(hdc, rect.right / 2, 0, rect.right / 2, rect.bottom);
            Line(hdc, 0, rect.bottom/2, rect.right , rect.bottom / 2);
            float n = 30;
            for (int i = 0; i < n; i++) {
                Line(hdc, (rect.right * i) / n, (rect.bottom / 2) + 5, (rect.right * i) / n, (rect.bottom / 2) - 5);
                Line(hdc, (rect.right / 2) +5, (rect.bottom *(n - i)) / n, (rect.right / 2) -5, (rect.bottom * (n - i))/n);
            }
            POINT axe_X[3] = {
                {rect.right, rect.bottom / 2},
                {rect.right * (n - 1) / n, (rect.bottom / 2) + (rect.bottom / (2 * n)) },
                {rect.right * (n - 1) / n, (rect.bottom / 2) - (rect.bottom / (2 * n))}
            };
            Polygon(hdc, axe_X, 3);

            POINT axe_Y[3] = {
                {rect.right / 2, 0},
                {rect.right / 2 + (rect.right/(3*n)), rect.bottom/(0.8*n) },
                {rect.right / 2 - (rect.right / (3*n)), rect.bottom /( 0.8*n) }
            };
            Polygon(hdc, axe_Y, 3);

            SelectObject(hdc, rose_pen);
            for (float delta = 0.025; delta <= t; delta += 0.025) {
                Line(hdc,
                   X_0 + R * sin(5 *delta) * cos(delta),
                   Y_0 + R * sin(5 *delta) * sin(delta),
                   X_0 + R * sin(5 *(delta + 0.025)) * cos(delta + 0.025),
                   Y_0 + R * sin(5 * (delta + 0.025)) * sin(delta + 0.025));
            }

            DeleteObject(rose_pen);
            DeleteObject(pen);

            ball_x = X_0 + R * sin(5 * t) * cos(t);
            ball_y = Y_0 + R * sin(5 * t) * sin(t);
            SelectObject(hdc, GetStockObject(DC_BRUSH));
            SetDCBrushColor(hdc, RGB(0, 0, 255));
            Ellipse(hdc, ball_x - 20, ball_y - 20, ball_x + 20, ball_y + 20);

            SelectObject(hdc, CreateFont(20, 15, 0, 0, FW_DONTCARE, 6, 1, 0, RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Impact"));


            auto textRectangle = RECT{ 0, 0, rect.right + rect.right/2  , rect.bottom - rect.bottom/4 };
            std::wstring text = std::to_wstring(  R * sin(5 * t) * cos(t)) + L", " + std::to_wstring(- R * sin(5 * t) * sin(t));
            DrawText(hdc, text.c_str(), -1, &textRectangle, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
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

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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