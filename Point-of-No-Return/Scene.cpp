#include "Scene.h"
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

void SceneManager::Initialize()
{
	sceneID = TitleID;
	save_sceneID = TitleID;
	SceneManager::basescene = new Title();
}

void SceneManager::ChangeScene()
{
	if (SceneManager::Changed())
	{
		SceneManager::DeleteScene();
		SceneManager::MakeSnece(SceneManager::sceneID);
	}
	SceneManager::save_sceneID = SceneManager::sceneID;
}

bool SceneManager::Changed()
{
	if (sceneID != save_sceneID)
	{
			return true;
	}
	return false;
}

