#ifndef SCENE_H_
#define SCENE_H_

class Scene
{
public:
private:

	virtual void Loading();

	virtual void Process();

	virtual void Release();

};

void ReleaseScene(Scene* secne);

enum SceneID
{
	TitleID,
	GameID,
	HelpID,
	LoadID,
   	EndingID,
};



#endif // !SCENE_H_
