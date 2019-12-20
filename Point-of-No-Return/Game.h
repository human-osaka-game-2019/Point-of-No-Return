#ifndef GAME_H_
#define GAME_H_

#include "Scene.h"
#include "Mapchip.h"
#include "Help.h"
#include "Character.h"
#include "Hero.h"
#include "Collision.h"
#include "ActionUI.h"



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

	Hero hero{ "Player" };
	Character character{ "player" };

	ActionUI::HpGauge hpGauge{ &character };
	ActionUI::MpGauge mpGauge{ &character };
	ActionUI::IpGauge ipGauge{ &character };
	ActionUI::ItemUI itemUI;
	ActionUI::GoldUI goldUI{ &character };
};



#endif // !CHARCTER_H_
