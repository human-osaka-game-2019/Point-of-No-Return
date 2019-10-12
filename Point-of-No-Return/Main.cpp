﻿#include "Main.h"

#pragma comment(lib,"../Point-of-No-Return/Lib/DirectX.lib")

DirectX dx;

INT WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE PrevInstance,
	_In_ LPSTR CmdLine,
	_In_ INT nCmdShow)
{
	const TCHAR AppName[] = _T("Point of No Return");

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	DWORD PrevSync = timeGetTime();
	DWORD CurrSync;

	WNDCLASS WndClass;
	WndClass.hInstance = hInstance;
	WndClass.lpszClassName = AppName;
	WndClass.lpfnWndProc = WndProc;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.lpszMenuName = NULL;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	RegisterClass(&WndClass);

	HWND hWnd = CreateWindow(
		AppName,
		AppName,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0,
		0,
		DISPLAY_WIDTH,
		DISPLAY_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	dx.InitDirectX(hWnd, DISPLAY_WIDTH, DISPLAY_HEIGHT);

	timeBeginPeriod(1);

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			CurrSync = timeGetTime();
			if (CurrSync - PrevSync >= 1000 / 60)
			{
				dx.BeginScene();



				dx.EndScene();
			}
		}
		Sleep(1);
	}
	timeEndPeriod(1);

	dx.AllRelease();

	return (INT)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_SYSKEYDOWN:
		switch (wp)
		{
		case VK_RETURN:
			return 0;
		case VK_F4:
			PostMessage(hWnd, WM_CLOSE, 0, 0);
			return 0;
		}
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}