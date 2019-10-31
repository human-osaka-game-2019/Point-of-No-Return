#include "Scene.h"
#include "Title.h"
#include "Game.h"
#include "Load.h"
#include "Help.h"
#include "Ending.h"

void SceneManager::CreateScene(SceneID sceneID)
{
	SceneManager::scene = nullptr;
	//シーン分け
	switch (sceneID)
	{
	case SceneManager::TitleID:
		SceneManager::scene = new Title();
		break;
	case SceneManager::HelpID:
		SceneManager::scene = new Help();
		break;
	case SceneManager::GameID:
		SceneManager::scene = new Game();
		break;
	case SceneManager::EndingID:
		SceneManager::scene = new Ending();
		break;
	}
}

void SceneManager::Initialize(SceneID scene_id)
{
	SceneManager::CreateScene(scene_id);
}

void SceneManager::ChangeScene(SceneID scene_id)
{
	SceneManager::DeleteScene();
	SceneManager::CreateScene(scene_id);
}

void SceneBase::Load()
{

	HANDLE thread = CreateLoadThread();

	thread = this->CreateLoadThread();

	
	if (thread == nullptr)
	{
		return;
	}

	DWORD Prev = timeGetTime();
	DWORD Curr;

	DWORD result;

	int framecount = 0;

	timeBeginPeriod(1);
	dx.LoadTexture("仮Load.png", "load");

	//Thread関数が処理している間のループ
	while (true)
	{
		Curr = timeGetTime();
		if (Curr - Prev >= 1000 / 60) {
			dx.BeginScene();
			
			framecount++;
			dx.DrawEx(100, 100, 0, 200, 200, 0, 1, 0, "load", 0, 0, 1, 0.25);
			

			
			

			//スレッドが終わったかチェック
			GetExitCodeThread(thread, &result);
			//終わったかどうか返す関数
			if (STILL_ACTIVE != result && framecount == 60*5)
			{
				//closehandleで閉じる。
				CloseHandle(thread);
				//ループを抜ける。
				break;
			}
			dx.EndScene();
			Prev = Curr;
		}
		Sleep(1);
	}
	dx.ReleaseTexture("load");
	timeEndPeriod(1);
}

