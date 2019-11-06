#ifndef GAME_H_
#define GAME_H_

#include "Scene.h"
#include "Mapchip.h"
#include "Character.h"

class Game : public SceneBase
{
public:
	Game()
	{
		Load();
	};

	~Game()
	{
		Release();
	};

	void Load();

	void Update();

	void Draw();

	void Release();

	HANDLE CreateLoadThread();
private:
	Mapchip mapchip;
	Hero hero{ "Player" };
};



#endif // !CHARCTER_H_
