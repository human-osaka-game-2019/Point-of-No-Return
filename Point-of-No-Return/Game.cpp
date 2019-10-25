#include "Load.h"
#include "Game.h"


void Game::Load()
{

}

void Game::Update()
{

}

void Game::Draw()
{

}

void Game::Release()
{

}

void Game::CreateLoadThread(HANDLE thread)
{
	thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)GameThread, NULL, 0, NULL);
}
