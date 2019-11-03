#ifndef OPBJECT_H_
#define OPBJECT_H_

#include "../Point-of-No-Return///Include/DirectX.h"
#include <iostream>
#include <vector>
#include <string>



//X座標
struct VertexX
{
	VertexX(float value) :value(value) {}
	float value;
};

//Y座標
struct VertexY
{
	VertexY(float value) :value(value) {}
	float value;
};

//横幅
struct Width
{
	Width(float value) :value(value) {}
	float value;
};
//縦幅
struct Height
{
	Height(float value) :value(value) {}
	float value;
};

//TU座標
struct VertexTU
{
	VertexTU(float value) :value(value) {}
	float value;
};

//TV座標
struct VertexTV
{
	VertexTV(float value) :value(value) {}
	float value;
};

//ヒットポイント
struct HP
{
	HP(int value) :value(value) {}
	int value;
};

//マジックポイント
struct MP
{
	MP(int value) :value(value) {}
	int value;
};

//イマジナリーポイント/想像力
struct IP
{
	IP(int value) :value(value) {}
	int value;
};

//攻撃力
struct Attack
{
	Attack(int value) :value(value) {}
	int value;
};

//防御力
struct Defense
{
	Defense(int value) :value(value) {}
	int value;
};

//素早さ
struct Speed
{
	Speed(int value) :value(value) {}
	int value;
};

//魔法攻撃力
struct MagicAttack
{
	MagicAttack(int value) :value(value) {}
	int value;
};

//運
struct Luck
{
	Luck(int value) :value(value) {}
	int value;
};

//愛情
struct Love
{
	Love(int value) :value(value) {}
	int value;
};

//時間
struct Time
{
	Time(int value) :value(value) {}
	int value;
};

//お金
struct Gold
{
	Gold(int value) :value(value) {}
	int value;
};

//年齢
struct Age
{
	Age(int value) :value(value) {}
	int value;
};

//名前
struct Name
{
	Name(std::string value) :value(value) {}
	std::string value;
};

struct Vec2
{
	VertexX x;
	VertexY y;

	Vec2(float x, float y) : x(x),y(y) {};
};

struct Size
{
	Width width;
	Height height;

	Size(float width,float height) : width(width), height(height) {};
};

struct TextureUV
{
	VertexTU tu;
	VertexTV tv;

	TextureUV(float tu,float tv) : tu(tu), tv(tv) {};
};

struct TextureSize
{
	Width width;
	Height height;

	TextureSize(float width,float height) : width(width), height(height) {};
};



//オブジェクトクラス
class Object
{
public:

	virtual void Draw() = 0;

protected:
	DX::DirectX& dx = DX::DirectX::GetInstance();

	struct CustomVertex
	{
		Vec2 vec;
		Size size;
		TextureUV uv;
		TextureSize texture_size;

		CustomVertex(float x, float y, float width, float hieght, float tu, float tv, float texture_width, float texture_height) : vec(x, y), size(100, 100), uv(0, 0), texture_size(1.0, 1.0) {};

	};

};





#endif


