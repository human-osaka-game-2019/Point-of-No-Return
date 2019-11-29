#include "Title.h"
#include "Load.h"

void Title::Load()
{

	SceneBase::Load();

}

void Title::Update()
{
	if (dx.GetKeyState(DIK_SPACE) == dx.PUSH)
	{
		SceneManager::ChangeScene(SceneManager::GameID);

	}
	


}

void Title::Draw()
{
	dx.DrawEx(0, 0, 0, 1920, 1080, 0, 1, 0, "title_back", 0, 0, 1, 1);
}

void Title::Release()
{

	dx.ReleaseTexture("title_back");

}

HANDLE Title::CreateLoadThread()
{
	//スレッドを作成
	return CreateThread(0, 0, (LPTHREAD_START_ROUTINE)TitleThread, NULL, 0, NULL);

}

