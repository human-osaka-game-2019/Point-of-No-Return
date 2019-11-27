#ifndef GAME_H_
#define GAME_H_

#include "Scene.h"
#include "Mapchip.h"
#include "Help.h"
#include "Character.h"
#include "Collision.h"

/**
 * @brief ゲームシーン
 */
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
	Collision::CollisionChecker collision_checker = Collision::CollisionChecker(&mapchip);
	Hero hero{ "Player" };
};



#endif // !CHARCTER_H_
