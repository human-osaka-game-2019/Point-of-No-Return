﻿#ifndef SCENE_H_
#define SCENE_H_

#include "Main.h"
#include <windows.h>

class SceneBase
{
public:

	void Load();

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Release() = 0;

	virtual HANDLE CreateLoadThread() = 0;

	SceneBase() {}

	virtual ~SceneBase() {}

protected:
	DirectX& dx = DirectX::GetInstance();
};

class SceneManager
{
public:

	enum SceneID
	{
		TitleID,
		GameID,
		HelpID,
		LoadID,
		EndingID,
	};

	static void Initialize(SceneID sceneID);

	inline static void Update()
	{
		scene->Update();
	}

	inline static void Draw()
	{
		scene->Draw();
	}

	static void ChangeScene(SceneID sceneID);
	
private:
	static SceneBase* scene;

	static void CreateScene(SceneID sceneID);

	inline static void DeleteScene()
	{
		delete scene;
		SceneManager::scene = nullptr;
	}

	SceneManager();

};



#endif //! SCENE_H_
