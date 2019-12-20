﻿#include "Load.h"
#include "Game.h"

void Game::Load()
{
	SceneBase::Load();
	mapchip.InitMap();
}

void Game::Update()
{
	hero.Update();

	// 当たり判定を取るブロックを取得する
	auto mapData = Collision::SearchBlock(hero,mapchip.map_);

	Collision::CheckBlock(&hero, mapData);

	background.Update(hero);

	if (dx.GetKeyState(DIK_SPACE) == dx.PUSH)
	{
		SceneManager::ChangeScene(SceneManager::EndingID);
	}
}

void Game::Draw()
{
	// 今のoffset値を取得する
	auto currentOffset = hero.GetOffset();

	float  game_back_tu = 1.f / 16.f;

	background.Draw();
	mapchip.DrawMapchip(-currentOffset.x.value, -currentOffset.y.value, "blocks", mapchip.map_);


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

	mapchip.map_[0][50] = 1;
	mapchip.map_[1][50] = 1;
	mapchip.map_[2][50] = 1;
	mapchip.map_[3][50] = 1;
	mapchip.map_[4][50] = 1;
	mapchip.map_[5][50] = 1;
	mapchip.map_[6][50] = 1;

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
