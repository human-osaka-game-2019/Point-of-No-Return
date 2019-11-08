#include "Load.h"
#include "Game.h"

void Game::Load()
{
	SceneBase::Load();
	mapchip.InitMap();
}


void Game::Update()
{
	
	hero.InputBefore();

	if (dx.GetKeyState(DIK_D) == dx.ON) 
	{
		hero.x += 3.0f;
	}
	
	if (dx.GetKeyState(DIK_A) == dx.ON)
	{
		hero.x -= 3.0f;

	}

	if (dx.GetKeyState(DIK_W) == dx.ON)
	{
		hero.y -= 3.0f;

	}

	if (dx.GetKeyState(DIK_S) == dx.ON)
	{
		hero.y += 3.0f;

	}

	if (dx.GetKeyState(DIK_R) == dx.ON)
	{
		hero.x = 0;
		hero.y = 0;
	}
	collision.ブロックとの(&hero.x,&hero.x_size,&hero.y,&hero.y_size,hero.before_x,hero.before_y,mapchip.map_);
	
	int a;
	mapchip.map_[a / 64][2];

	if (dx.GetKeyState(DIK_SPACE) == dx.PUSH)
	{
		SceneManager::ChangeScene(SceneManager::EndingID);
	}
}

void Game::Draw()
{
	float a = 1.0f / 16.0f;
	dx.DrawEx(0, 0, 0, 1920, 1080, 0, 1, 0, "game_back", 0, 0, a, 1);
	mapchip.DrawMapchip(world_size_width, world_size_height, texture_width, texture_height, chip_width_num, chip_height_num, chip_size_, chip_size_, 0, 0, "blocks", mapchip.map_);
	dx.DrawEx(hero.x, hero.y,0, hero.x_size, hero.y_size, 0, 1, 0, "char", hero.tu, hero.tv, hero.tu_size, hero.tv_size, 1);

	// -----------
	mapchip.map_[11][10] = 1;
	mapchip.map_[11][11] = 1;
	mapchip.map_[10][10] = 1;
	mapchip.map_[10][11] = 1;

	mapchip.map_[3][13] = 1;
	mapchip.map_[4][12] = 1;
	mapchip.map_[5][11] = 1;
	// -----------

}

void Game::Release()
{
	dx.ReleaseTexture("char");
	dx.ReleaseTexture("blocks");
	dx.ReleaseTexture("game_back");
}

HANDLE Game::CreateLoadThread()
{
	return CreateThread(0, 0, (LPTHREAD_START_ROUTINE)GameThread, NULL, 0, NULL);
}
