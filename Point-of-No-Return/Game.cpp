﻿#include "Load.h"
#include "Game.h"

void Game::Load()
{
	SceneBase::Load();
	mapchip.InitMap();
}

void Game::Update()
{
	hero.Update(Collision::CollisionChecker(&mapchip));

	if (dx.GetKeyState(DIK_SPACE) == dx.PUSH)
	{
		SceneManager::ChangeScene(SceneManager::EndingID);
	}
}

void Game::Draw()
{
	float a = 1.0f / 16.0f;
	dx.DrawEx(0, 0, 0, 1920, 1080, 0, 1, 0, "game_back", 0, 0, a, 1);
	mapchip.DrawMapchip(0, 0, "blocks", mapchip.map_);
	hero.Draw();

	// ----------- 当たり判定の為の仮置き --------------
	// TODO : 検証後削除
	mapchip.map_[11][10] = 1;
	mapchip.map_[11][11] = 1;
	mapchip.map_[10][10] = 1;
	mapchip.map_[10][11] = 1;

	mapchip.map_[3][13] = 1;
	mapchip.map_[4][12] = 1;
	mapchip.map_[5][11] = 1;
	// ---------------------------

}

void Game::Release()
{
	dx.ReleaseTexture("blocks");
	dx.ReleaseTexture("game_back");
}

HANDLE Game::CreateLoadThread()
{
	return CreateThread(0, 0, (LPTHREAD_START_ROUTINE)GameThread, NULL, 0, NULL);
}
