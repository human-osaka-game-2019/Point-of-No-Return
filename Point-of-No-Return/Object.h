#ifndef OPBJECT_H_
#define OPBJECT_H_

#include "Include/DirectX.h"
#include <iostream>
#include <vector>
#include <string>

//! X座標
struct CoordinateX
{
	explicit CoordinateX(float value) :value(value) {}
	float value;
};

//! Y座標
struct CoordinateY
{
	explicit CoordinateY(float value) :value(value) {}
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
	explicit Width(float value) :value(value) {}
	float value;
};

//! 縦幅
struct Height
{
	explicit Height(float value) :value(value) {}
	float value;
};

//! TU座標
struct TextureU
{
	explicit TextureU(float value) :value(value) {}
	float value;
};

//! TV座標
struct TextureV
{
	explicit TextureV(float value) :value(value) {}
	float value;
};

struct Col
{
	explicit Col(int value) :value(value) {}
	int value;
};

struct Row
{
	explicit Row(int value) :value(value) {}
	int value;
};

struct Degree 
{
	explicit Degree(float value) :value(value) {}
	float value;
};

struct Zoom
{
	explicit Zoom(float value) :value(value) {}
	float value;
};

struct IsReverse
{
	explicit IsReverse(bool value) :value(value) {}
	bool value;
};

//! ヒットポイント
struct HP
{
	explicit HP(int value) :value(value) {}
	int value;
};

//! マジックポイント
struct MP
{
	explicit MP(int value) :value(value) {}
	int value;
};

//! イマジナリーポイント/想像力
struct IP
{
	explicit IP(int value) :value(value) {}
	int value;
};

//! 攻撃力
struct Attack
{
	explicit Attack(int value) :value(value) {}
	int value;
};

//! 防御力
struct Defense
{
	explicit Defense(int value) :value(value) {}
	int value;
};

//! 素早さ
struct Speed
{
	explicit Speed(int value) :value(value) {}
	int value;
};

//! 魔法攻撃力
struct MagicAttack
{
	explicit MagicAttack(int value) :value(value) {}
	int value;
};

//! 運
struct Luck
{
	explicit Luck(int value) :value(value) {}
	int value;
};

//! 愛情
struct Love
{
	explicit Love(int value) :value(value) {}
	int value;
};

//! 時間
struct Time
{
	explicit Time(int value) :value(value) {}
	int value;
};

//! お金
struct Gold
{
	explicit Gold(int value) :value(value) {}
	int value;
};

//! 年齢
struct Age
{
	explicit Age(int value) :value(value) {}
	int value;
};

//! 名前
struct Name
{
	explicit Name(std::string value) :value(value) {}
	std::string value;
};

struct TextureName
{
	explicit TextureName(std::string value) :value(value) {}
	std::string value;
};

struct Vec2
{
	Vec2(CoordinateX x, CoordinateY y) : x(x),y(y) {};

	CoordinateX x;
	CoordinateY y;
};

struct Matrix
{
	Matrix(Col col, Row row) : col(col), row(row) {};
	Col col;
	Row row;
};

struct Size
{
	Size(Width width,Height height) : width(width), height(height) {};

	Width width;
	Height height;
};

struct TextureUV
{
	TextureUV(TextureU tu,TextureV tv) : tu(tu), tv(tv) {};
	TextureU tu;
	TextureV tv;
};

struct TextureSize
{
	TextureSize(Width width,Height height) : width(width), height(height) {};

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

protected:
	DX::DirectX& dx = DX::DirectX::GetInstance();

	Vec2 position =
	{
		CoordinateX(0),
		CoordinateY(0)
	};

	Size size =
	{
		Width(0),
		Height(0)
	};

	TextureUV uv =
	{
		TextureU(0),
		TextureV(0)
	};

	TextureSize texture_size =
	{
		Width(0),
		Height(0)
	};

	TextureName texture_name = TextureName("None") ;

	Degree degree = Degree(0);
	Zoom zoom = Zoom(0);
	IsReverse is_reverse = IsReverse(false);
};

#endif
