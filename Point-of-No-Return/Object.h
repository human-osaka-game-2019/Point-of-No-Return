#ifndef OPBJECT_H_
#define OPBJECT_H_

#include "../Point-of-No-Return///Include/DirectX.h"
#include <iostream>
#include <vector>
#include <string>



//X座標
class VertexX
{
private:
	float x;
};
//Y座標
class VertexY
{
private:
	float y;
};
//TU座標
class VertexTU
{
private:
	float tu;
};
//TV座標
class VertexTV
{
private:
	float tv;
};
//Color座標
class VertexColor
{
private:
	unsigned long color;
};


//ヒットポイント
class HP
{
private:
	int hp;
};
//マジックポイント
class MP
{
private:
	int mp;
};
//イマジナリーポイント/想像力
class IP
{
private:
	int IP;
};
//攻撃力
class Attack
{
private:
	int attack;
};
//防御力
class Defense
{
private:
	int defense;
};
//素早さ
class Speed
{
private:
	int speed;
};
//魔法攻撃力
class MagicAttack
{
private:
	int magic_attack;
};
//運
class Luck
{
private:
	int luck;
};
//愛情
class Love
{
	int love;
};
//時間
class Timer
{
private:
	float time;
};
//お金
class Gold
{
private:
	int gold;
};
//年齢
class Age
{
private:
	int age;
};
//名前
class Name
{
private:
	std::vector<std::string> name;
};


//オブジェクトクラス
class Object
{
public:
	
	/*
	virtual directx.Draw()
	{
	
	};
	*/

protected:

	struct CustomVertex
	{
		VertexX x;
		VertexY y;
		VertexColor color;
		VertexTU tu;
		VertexTV tv;
	};

	struct Vec2
	{
		VertexX x;
		VertexY y;	
	};

};





#endif


