#include "Load.h"
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
