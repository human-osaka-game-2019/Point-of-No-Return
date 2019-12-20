#include "Scene.h"
#include "Title.h"
#include "Game.h"
#include "Load.h"
#include "Help.h"
#include "Ending.h"

void SceneManager::CreateScene(SceneID sceneID)
{
	SceneManager::DeleteScene();
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
	SceneManager::CreateScene(scene_id);
}

void SceneBase::Load()
{
	dx.LoadTexture("仮Load.png", "load");
	HANDLE thread = CreateLoadThread();
	
	if (thread == nullptr)
	{
		return;
	}

	DWORD Prev = timeGetTime();
	DWORD Curr;

	DWORD result;

	int framecount = 0;

	timeBeginPeriod(1);


	//Thread関数が処理している間のループ
	while (true)
	{
		Curr = timeGetTime();
		if (Curr - Prev >= 1000 / 60) {

			dx.BeginScene();
			
			framecount++;

			dx.DrawEx(100.f, 100.f, 0.f, 200.f, 200.f, 0.f, 1.f, 0.f, "load", 0.f, 0.f, 1.f, 0.25f);

			GetExitCodeThread(thread, &result);
			if (STILL_ACTIVE != result && framecount == 60*1)
			{
				CloseHandle(thread);
				break;
			}

			if (framecount == 60)
			{
				framecount = 0;
			}
			
			dx.EndScene();
			Prev = Curr;
		}
		Sleep(1);
	}
	dx.ReleaseTexture("load");
	timeEndPeriod(1);
}

