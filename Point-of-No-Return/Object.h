#ifndef OPBJECT_H_
#define OPBJECT_H_

#include "../Point-of-No-Return///Include/DirectX.h"
#include <iostream>
#include <vector>
#include <string>



//X座標
class VertexX
{
public:
	float var;
};
//Y座標
class VertexY
{
public:
	float var;
};
//TU座標
class VertexTU
{
private:
	float var;
};
//TV座標
class VertexTV
{
private:
	float var;
};
//Color座標
class VertexColor
{
private:
	unsigned long color;
};
class Width
{
public:
	float var;
};

class Height
{
public:
	float var;
};

//ヒットポイント
class HP
{
private:
	int var;
};
//マジックポイント
class MP
{
private:
	int var;
};
//イマジナリーポイント/想像力
class IP
{
private:
	int var;
};
//攻撃力
class Attack
{
private:
	int var;
};
//防御力
class Defense
{
private:
	int var;
};
//素早さ
class Speed
{
private:
	int var;
};
//魔法攻撃力
class MagicAttack
{
private:
	int var;
};
//運
class Luck
{
private:
	int var;
};
//愛情
class Love
{
	int var;
};
//時間
class Timer
{
private:
	float var;
};
//お金
class Gold
{
private:
	int var;
};
//年齢
class Age
{
private:
	int var;
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
		Width width;
		Height height;
		VertexColor color;
		VertexTU tu;
		VertexTV tv;
	};

	

};



struct Vec2
{
	VertexX x;
	VertexY y;
};

#endif


