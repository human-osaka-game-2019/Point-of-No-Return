#ifndef SCENE_H_
#define SCENE_H_

#include <windows.h>

class BaseScene
{
public:

	virtual void Load();

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Release() = 0;

	virtual void CreateLoadThread(HANDLE thread) = 0;

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
		basescene->Update();
	}

	inline static void Draw()
	{
		basescene->Draw();
	}

	static void ChangeScene(SceneID sceneID);
	
private:
	static BaseScene* basescene;

	static void MakeSnece(SceneID sceneID);

	inline static void DeleteScene()
	{
		delete basescene;
	}

};



#endif //! SCENE_H_
