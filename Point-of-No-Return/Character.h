#ifndef CHARCTER_H_
#define CHARCTER_H_

#include "Object.h"

//キャラクタークラス
class Character :public Object
{
public:
	explicit Character(const std::string& name):name(name) {}
private:
	Name name = { "None" };
};

//主人公クラス
class Hero :public Character
{
public:
	Hero(const std::string& name):Character(name)
	{
		Initialize();
	}

	void Update();

private:
	void Initialize();

	Hero(const Hero&);
	Hero& operator=(const Hero&);
	Hero(const Hero&&);
	Hero& operator=(const Hero&&);
};


/**
 * @brief UIクラス
 */
class UI : public Object
{

};

/**
 * @brief スクロールステージクラス
 */
class ScrollStage : public Object
{

};

/**
 * @brief ステージクラス
 */
class Stage : public Object
{

};

/**
 * @brief NPCクラス
 */
class NPC : public Character
{

};

/**
 * @brief 敵クラス
 */
class Enemy : public Character
{

};

#endif // !CHARCTER_H_
