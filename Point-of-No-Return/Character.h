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
	

	float gravity =0;

	void InputBefore();

	// void HitBlock(std::vector<Vec2> vec2);

	Hero(const std::string& name):Character(name)
	{
		Initialize();
	}

	void Update();

	void CrrectCodinate(int Direction, std::vector<Vec2> vec2, int i);

	Vec2 GetPrevious();

private:

	void Initialize();

	Hero(const Hero&);
	Hero& operator=(const Hero&);
	Hero(const Hero&&);
	Hero& operator=(const Hero&&);

protected:
	Vec2 previous = {0,0};


};

//UIクラス
class UI :public Object
{

};

//スクロールステージクラス
class ScrollStage :public Object
{

};

//ステージクラス
class Stage :public Object
{

};

//NPCクラス
class NPC :public Character
{

};

//敵クラス
class Enemy :public Character
{

};



#endif // !CHARCTER_H_
