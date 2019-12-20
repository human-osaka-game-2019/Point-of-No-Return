﻿#include "Main.h"
#include "Load.h"

//スレッド関数
DWORD WINAPI TitleThread(HWND hWnd, LPVOID* data)
{
	DirectX& dx = DirectX::GetInstance();

	//Load中に裏でしたい処理

	dx.LoadTexture("仮Title_Back.png", "title_back");

	ExitThread(0);
}


DWORD WINAPI GameThread(HWND hWnd, LPVOID* data)
{

	DirectX& dx = DirectX::GetInstance();

	//Load中に裏でしたい処理

	dx.LoadTexture("仮Game_Back.jpg","game_back");
	dx.LoadTexture("character_motion.png", "Player");
	dx.LoadTexture("backillustration.png","game_back");
	dx.LoadTexture("足場ブロック整理後.png", "blocks");
	ExitThread(0);
}

DWORD WINAPI HelpThread(HWND hWnd, LPVOID* data)
{

	DirectX& dx = DirectX::GetInstance();

	//Load中に裏でしたい処理

	dx.LoadTexture("仮Help_Back.jpg", "help_back");

	ExitThread(0);
}


DWORD WINAPI EndingThread(HWND hWnd, LPVOID* data)
{
	DirectX& dx = DirectX::GetInstance();

	//Load中に裏でしたい処理

	dx.LoadTexture("仮Ending_Back.png", "ending_back");

	ExitThread(0);
}

