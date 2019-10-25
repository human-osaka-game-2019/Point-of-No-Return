﻿#include "Scene.h"
#include "Title.h"
#include "Game.h"
#include "Load.h"
#include "Help.h"
#include "Ending.h"

void SceneManager::MakeSnece(SceneID sceneID)
{
	//シーン分け
	switch (sceneID)
	{
	case SceneManager::TitleID:
		SceneManager::basescene = new Title();
		break;
	case SceneManager::HelpID:
		SceneManager::basescene = new Help();
		break;
	case SceneManager::GameID:
		SceneManager::basescene = new Game();
		break;
	case SceneManager::EndingID:
		SceneManager::basescene = new Ending();
		break;
	}
}

void SceneManager::Initialize(SceneID sceneID_)
{
	sceneID = sceneID_;
	save_sceneID = sceneID_;
	SceneManager::MakeSnece(sceneID_);
}

void SceneManager::ChangeScene()
{
	if (SceneManager::Changed())
	{
		SceneManager::DeleteScene();
		SceneManager::MakeSnece(SceneManager::sceneID);
	}
	SetSaveScene();
}

bool SceneManager::Changed()
{
	if (sceneID != save_sceneID)
	{
			return true;
	}
	return false;
}




void BaseScene::Load()
{
	HANDLE th;

	this->CreateLoadThread(th);

	
	if (th == NULL)
	{
		return;
	}

	DWORD Prev = timeGetTime();
	DWORD Curr;

	DWORD result;

	timeBeginPeriod(1);

	//Thread関数が処理している間のループ
	while (true)
	{
		Curr = timeGetTime();
		if (Curr - Prev >= 1000 / 60) {





			//スレッドが終わったかチェック
			GetExitCodeThread(th, &result);
			//終わったかどうか返す関数
			if (STILL_ACTIVE != result)
			{
				//closehandleで閉じる。
				CloseHandle(th);
				//ループを抜ける。
				break;
			}
			Prev = Curr;
		}
		Sleep(1);
	}
	timeEndPeriod(1);
}

