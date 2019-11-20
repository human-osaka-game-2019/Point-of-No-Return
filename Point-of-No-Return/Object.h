#ifndef OPBJECT_H_
#define OPBJECT_H_

#include "Include/DirectX.h"
#include <iostream>
#include <vector>
#include <string>


//! X座標
struct CoordinateX
{
	CoordinateX(const float value) :value(value) {}
	float value;
};

//! Y座標
struct CoordinateY
{
	CoordinateY(const float value) :value(value) {}
	float value;
};

/**
 * @brief		自身のX座標の値と引数の値を比べる
 * @param	lhs	自身のX座標
 * @param	rhs	比べる値
 * @return		引数の値が大きかったらtrueを返す
 */
inline bool operator <(const CoordinateX& lhs, const CoordinateX& rhs)
{
	return lhs.value < rhs.value;
}

/**
 * @brief		自身のX座標の値と引数の値を比べる
 * @param	lhs	自身のX座標
 * @param	rhs	比べる値
 * @return		引数の値が大きかったらtrueを返す
 */
inline bool operator ==(const CoordinateX& lhs, const CoordinateX& rhs)
{
	return lhs.value == rhs.value;
}

/**
 * @brief		自身のX座標の値と引数の値を比べる
 * @param	lhs	自身のY座標
 * @param	rhs	比べる値
 * @return		引数の値が大きかったらtrueを返す
 */
inline bool operator <(const CoordinateY& lhs, const CoordinateY& rhs)
{
	return lhs.value < rhs.value;
}

/**
 * @brief		自身のX座標の値と引数の値を比べる
 * @param	lhs	自身のY座標
 * @param	rhs	比べる値
 * @return		引数の値が大きかったらtrueを返す
 */
inline bool operator ==(const CoordinateY& lhs, const CoordinateY& rhs)
{
	return lhs.value == rhs.value;
}

//! 横幅
struct Width
{
	Width(const float value) :value(value) {}
	float value;
};

//! 縦幅
struct Height
{
	Height(const float value) :value(value) {}
	float value;
};

//! TU座標
struct TextureU
{
	TextureU(const float value) :value(value) {}
	float value;
};

//! TV座標
struct TextureV
{
	TextureV(const float value) :value(value) {}
	float value;
};

struct Col
{
	Col(const float value) :value(value) {}
	int value;
};

struct Row
{
	Row(const float value) :value(value) {}
	int value;
};

struct Degree 
{
	Degree(const float value) :value(value) {}
	float value;
};

struct Zoom
{
	Zoom(const float value) :value(value) {}
	float value;
};

struct IsReverse
{
	IsReverse(const bool value) :value(value) {}
	bool value;
};

//! ヒットポイント
struct HP
{
	HP(const int value) :value(value) {}
	int value;
};

//! マジックポイント
struct MP
{
	MP(const int value) :value(value) {}
	int value;
};

//! イマジナリーポイント/想像力
struct IP
{
	IP(const int value) :value(value) {}
	int value;
};

//! 攻撃力
struct Attack
{
	Attack(const int value) :value(value) {}
	int value;
};

//! 防御力
struct Defense
{
	Defense(const int value) :value(value) {}
	int value;
};

//! 素早さ
struct Speed
{
	Speed(const int value) :value(value) {}
	int value;
};

//! 魔法攻撃力
struct MagicAttack
{
	MagicAttack(const int value) :value(value) {}
	int value;
};

//! 運
struct Luck
{
	Luck(const int value) :value(value) {}
	int value;
};

//! 愛情
struct Love
{
	Love(const int value) :value(value) {}
	int value;
};

//! 時間
struct Time
{
	Time(const int value) :value(value) {}
	int value;
};

//! お金
struct Gold
{
	Gold(const int value) :value(value) {}
	int value;
};

//! 年齢
struct Age
{
	Age(const int value) :value(value) {}
	int value;
};

//! 名前
struct Name
{
	Name(const std::string value) :value(value) {}
	std::string value;
};


struct TextureName
{
	TextureName(const std::string value) :value(value) {}
	std::string value;
};

struct Vec2
{
	Vec2(const CoordinateX x, const CoordinateY y) : x(x),y(y) {};

	CoordinateX x;
	CoordinateY y;
};

struct Matrix
{
	Matrix(const Col col, const Row row) : col(col), row(row) {};
	Col col;
	Row row;
};

struct Size
{
	Size(const Width width,const Height height) : width(width), height(height) {};

	Width width;
	Height height;
};

struct TextureUV
{
	TextureUV(const TextureU tu,const TextureV tv) : tu(tu), tv(tv) {};
	TextureU tu;
	TextureV tv;
};

struct TextureSize
{
	TextureSize(const Width width,const Height height) : width(width), height(height) {};

	Width width;
	Height height;
};

//リファクタリング時によりまとめるために使用
//struct Rect
//{
//	Vec2 vec;
//	Size size;
//};
//
//struct Texture 
//{
//	TextureUV uv;
//	TextureSize texture_size;
//};
//
//struct PolygonInfo
//{
//	Rect rect;
//	Texture texture;
//
//	PolygonInfo(Rect rect, Texture texture) : rect(rect), texture(texture)
//	{
//
//	};
//
//};

//オブジェクトクラス
class Object
{
public:

	virtual void Draw();

	virtual void Update() {}

	Object() {};

	virtual ~Object() {};

	Object(const Object&);
	Object& operator =(const Object&);
	Object(const Object&&);
	Object& operator =(const Object&&);

	Vec2 GetPos()
	{
		return position;
	}

	Size GetSize()
	{
		return size;
	}


protected:

	DX::DirectX& dx = DX::DirectX::GetInstance();
	Vec2 position = { 0,0 };
	Size size = { 0,0 };
	TextureUV uv = {0, 0};
	TextureSize texture_size = { 0,0 };
	TextureName texture_name = {"None"};
	Degree degree = 0;
	Zoom zoom = 0;
	IsReverse is_reverse = false;
};

#endif
