#include "Main.h"
#include "Scene.h"
#include "Title.h"
#include "Game.h"
#include "Load.h"
#include "Help.h"
#include "Ending.h"


#pragma comment(lib,"../Point-of-No-Return/Lib/DirectX.lib")

BaseScene* SceneManager::basescene = nullptr;

INT WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE PrevInstance,
	_In_ LPSTR CmdLine,
	_In_ INT nCmdShow)
{
	DX::DirectX& dx = DX::DirectX::GetInstance();

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
		static_cast<int>(Display::DISPLAY_WIDTH),
		static_cast<int>(Display::DISPLAY_HEIGHT),
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	dx.InitDirectX(hWnd, Display::DISPLAY_WIDTH, Display::DISPLAY_HEIGHT);

	timeBeginPeriod(1);

	dx.LoadTexture("brick.png", "Tex");


	SceneManager::Initialize();

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


				SceneManager::ChangeScene();


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
	DirectX& dx = DirectX::GetInstance();

	switch (msg)
	{
	case WM_DESTROY:
		dx.AllRelease();
		PostQuitMessage(0);
		break;
	case WM_SYSKEYDOWN:
		switch (wp)
		{
		case VK_RETURN:
			dx.ChangeDisplayMode(hWnd, Display::DisplayRect);
			return 0;
		case VK_F4:
			PostMessage(hWnd, WM_CLOSE, 0, 0);
			return 0;
		}
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}
