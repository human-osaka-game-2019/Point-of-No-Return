#include "Ending.h"
#include "Load.h"


void Ending::Load() 
{
	SceneBase::Load();
}

void Ending::Update()
{
	if (dx.GetKeyState(DIK_SPACE) == dx.PUSH)
	{
		SceneManager::ChangeScene(SceneManager::TitleID);

	}
}

void Ending::Draw()
{
	dx.DrawEx(0, 0, 0, 1920, 1080, 0, 1, 0, "ending_back", 0, 0, 1, 1);
}

void Ending::Release()
{
	dx.ReleaseTexture("ending_back");
}

HANDLE Ending::CreateLoadThread()
{
	return CreateThread(0, 0, (LPTHREAD_START_ROUTINE)EndingThread, NULL, 0, NULL);
}


