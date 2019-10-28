#include "Main.h"
#include "Load.h"



//スレッド関数
DWORD WINAPI TitleThread(HWND hWnd, LPVOID* data)
{
	DirectX& dx = DirectX::GetInstance();

	//Load中に裏でしたい処理

	//dx.LoadTexture();

	ExitThread(0);
}


DWORD WINAPI GameThread(HWND hWnd, LPVOID* data)
{

	DirectX& dx = DirectX::GetInstance();

	//Load中に裏でしたい処理

	dx.LoadTexture("world_bg_仮.jpg","world_bg");
	dx.LoadTexture("unified_block.png", "blocks");
	ExitThread(0);
}

DWORD WINAPI HelpThread(HWND hWnd, LPVOID* data)
{

	DirectX& dx = DirectX::GetInstance();

	//Load中に裏でしたい処理

	//dx.LoadTexture();

	ExitThread(0);
}


DWORD WINAPI EndingThread(HWND hWnd, LPVOID* data)
{
	DirectX& dx = DirectX::GetInstance();

	//Load中に裏でしたい処理

	//dx.LoadTexture();

	ExitThread(0);
}

