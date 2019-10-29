#include "Title.h"
#include "Load.h"

void Title::Load()
{

	BaseScene::Load();

}

void Title::Update()
{
	if (dx.GetKeyState(DIK_SPACE) == dx.PUSH)
	{
		SceneManager::ChangeScene(SceneManager::GameID);

	}
	/*if (dx.GetKeyState(DIK_RETURN) == dx.PUSH)
	{
		SceneManager::ChangeScene(SceneManager::HelpID);

	}*/


}

void Title::Draw()
{
	dx.DrawEx(0, 0, 0, 1920, 1080, 0, 1, 0, "title_back", 0, 0, 1, 1);
}

void Title::Release()
{



}

HANDLE Title::CreateLoadThread()
{
	//スレッドを作成
	return CreateThread(0, 0, (LPTHREAD_START_ROUTINE)TitleThread, NULL, 0, NULL);

}

