#include "stdafx.h"
#include "GameMain.h"



LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Color");



int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstnce, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,CW_USEDEFAULT
		, CW_USEDEFAULT, 1280, 1024,
		NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);


	GameMain* game = new GameMain(hWnd);
	game->CreateGame(hWnd);
	

	while (TRUE)
	{
		if (PeekMessageA(&Message, NULL, 0, 0, PM_REMOVE))
		{
			if (Message.message == WM_QUIT)
			{
				game->ExitGame(hWnd);
				break;
			}

			TranslateMessage(&Message);
			DispatchMessage(&Message);


		}
		else
		{

			game->RunningGame(hWnd);
		}
	}



}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	switch (iMessage)
	{
	case WM_CREATE:
	{
		return 0;
	}

	case WM_PAINT:
	{
		
		break;
	}


	case WM_COMMAND:
	{
		break;
	}

	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}


	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);



}


