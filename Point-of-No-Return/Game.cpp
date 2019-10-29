#include "Load.h"
#include "Game.h"


void Game::Load()
{
	BaseScene::Load();
}

void Game::Update()
{
	if (dx.GetKeyState(DIK_SPACE) == dx.PUSH)
	{
		SceneManager::ChangeScene(SceneManager::EndingID);

	}
}

void Game::Draw()
{
	dx.DrawEx(0, 0, 0, 1920, 1080, 0, 1, 0, "game_back", 0, 0, 1/16, 1);
}

void Game::Release()
{
	dx.ReleaseTexture("game_back");
}

HANDLE Game::CreateLoadThread()
{
	return CreateThread(0, 0, (LPTHREAD_START_ROUTINE)GameThread, NULL, 0, NULL);
}
