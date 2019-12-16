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

	ActionUI::HpGauge hpGauge;
	ActionUI::MpGauge mpGauge;
	ActionUI::IpGauge ipGauge;
	ActionUI::ItemUI itemUI;
	ActionUI::GoldUI moneyUI;

	Mapchip mapchip;

	Hero hero{ "Player" };
};



#endif // !CHARCTER_H_
