#ifndef SCENE_H_
#define SCENE_H_



class BaseScene
{
public:

	virtual void Load() = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Release() = 0;
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

	inline static void DeleteScene()
	{
		delete basescene;
	}

	static void MakeSnece(SceneID sceneID);

	static void Initialize();

	static void ChangeScene();

	inline static void Update()
	{
		basescene->Update();
	}

	inline static void Draw()
	{
		basescene->Draw();
	}

	static bool Changed();

private:
	static SceneID sceneID;
	static SceneID save_sceneID;
	static BaseScene* basescene;

	inline void SetSaveScene(){
		save_sceneID = sceneID;
	}
};



#endif // !SCENE_H_
