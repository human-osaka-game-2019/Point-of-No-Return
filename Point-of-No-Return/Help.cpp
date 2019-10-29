#include "Help.h"
#include "Load.h"



void Help::Load()
{
	BaseScene::Load();
}

void Help::Update()
{
	if (dx.GetKeyState(DIK_SPACE) == dx.PUSH)
	{
		SceneManager::ChangeScene(SceneManager::TitleID);

	}
}

void Help::Draw()
{
	dx.DrawEx(0, 0, 0, 1920, 1080, 0, 1, 0, "help_back", 0, 0, 1, 1);
}

void Help::Release()
{
	dx.ReleaseTexture("help_back");
}

HANDLE Help::CreateLoadThread()
{
	return CreateThread(0, 0, (LPTHREAD_START_ROUTINE)HelpThread, NULL, 0, NULL);
}

