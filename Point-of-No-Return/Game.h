#ifndef GAME_H_
#define GAME_H_

#include "Scene.h"
#include "Mapchip.h"
#include "Help.h"
#include "Character.h"
#include "Hero.h"
#include "Collision.h"
#include "..//Point-of-No-Return/UI/ActionUI/ActionUI.h"



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
	
	ActionUI::HpGauge hpGauge{ hero };
	ActionUI::MpGauge mpGauge{ hero };
	ActionUI::IpGauge ipGauge{ hero };
	ActionUI::ItemUI itemUI;
	ActionUI::GoldUI moneyUI;
};



#endif // !CHARCTER_H_
