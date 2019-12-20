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

//------------operator-CoordinateX----------------------------------------------

/**
 * @brief		引数の値を比べる
 * @param	lhs	比べる値
 * @param	rhs	比べる値
 * @return		引数のrhsの値が大きかったらtrueを返す
 */
inline bool operator <(const CoordinateX& lhs, const CoordinateX& rhs)
{
	return lhs.value < rhs.value;
}

/**
 * @brief		引数の値を比べる
 * @param	lhs	比べる値
 * @param	rhs	比べる値
 * @return		引数のrhsの値が0以上ならtrueを返す
 */
inline bool operator <=(const CoordinateX& lhs,const CoordinateX& rhs)
{
	return lhs.value <= rhs.value;
}

/**
 * @brief		引数の値を比べる
 * @param	lhs	比べる値
 * @param	rhs	比べる値
 * @return		引数の値が等しかったらtrueを返す
 */
inline bool operator ==(const CoordinateX& lhs, const CoordinateX& rhs)
{
	return lhs.value == rhs.value;
}
/**
 * @brief		引き算する
 * @param	lhs	引かれる値
 * @param	rhs	引く値
 * @return		計算された値
 */
inline float operator -(const CoordinateX& lhs, const CoordinateX& rhs)
{
	return lhs.value - rhs.value;
}
/**
 * @brief		引き算してlhsに代入する
 * @param	lhs	引かれる値
 * @param	rhs	引く値
 * @return		計算された値
 */
inline float operator -=(CoordinateX& lhs, const CoordinateX& rhs)
{
	return lhs.value -= rhs.value;
}
/**
 * @brief		足し算してlhsに代入する
 * @param	lhs	足される値
 * @param	rhs	足す値
 * @return		計算された値
 */
inline float operator +=(CoordinateX& lhs, const CoordinateX& rhs)
{
	return lhs.value += rhs.value;
}
//------------operator-CoordinateX----------------------------------------------

//! Y座標
struct CoordinateY
{
	explicit CoordinateY(float value) :value(value) {}
	float value;
};

//------------operator-CoordinateY----------------------------------------------

/**
 * @brief		引数の値を比べる
 * @param	lhs	比べる値
 * @param	rhs	比べる値
 * @return		引数のrhsの値が大きかったらtrueを返す
 */
inline bool operator <(const CoordinateY& lhs, const CoordinateY& rhs)
{
	return lhs.value < rhs.value;
}

/**
 * @brief		引数の値を比べる
 * @param	lhs	比べる値
 * @param	rhs	比べる値
 * @return		引数のrhsの値が0以上ならtrueを返す
 */
inline bool operator <=(const CoordinateY& lhs, const CoordinateY& rhs)
{
	return lhs.value <= rhs.value;
}

/**
 * @brief		引数の値を比べる
 * @param	lhs	比べる値
 * @param	rhs	比べる値
 * @return		引数の値が等しかったらtrueを返す
 */
inline bool operator ==(const CoordinateY& lhs, const CoordinateY& rhs)
{
	return lhs.value == rhs.value;
}

/**
 * @brief		引き算する
 * @param	lhs	引かれる値
 * @param	rhs	引く値
 * @return		計算された値
 */
inline float operator -(const CoordinateY& lhs, const CoordinateY& rhs)
{
	return lhs.value - rhs.value;
}
/**
 * @brief		引き算してlhsに代入する
 * @param	lhs	引かれる値
 * @param	rhs	引く値
 * @return		計算された値
 */
inline float operator -=(CoordinateY& lhs, const CoordinateY& rhs)
{
	return lhs.value -= rhs.value;
}
/**
 * @brief		足し算してlhsに代入する
 * @param	lhs	足される値
 * @param	rhs	足す値
 * @return		計算された値
 */
inline float operator +=(CoordinateY& lhs, const CoordinateY& rhs)
{
	return lhs.value += rhs.value;
}
//------------operator-CoordinateY----------------------------------------------



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
	explicit HP(int value,int max_value) :value(value),max_value(max_value) {}
	int max_value;
	int value;
};

//! マジックポイント
struct MP
{
	explicit MP(int value, int max_value) :value(value), max_value(max_value) {}
	int max_value;
	int value;
};

//! イマジナリーポイント/想像力
struct IP
{
	explicit IP(int value, int max_value) :value(value), max_value(max_value) {}
	int max_value;
	int value;
};

//! 攻撃力
struct Attack
{
	explicit Attack(int value, int max_value) :value(value), max_value(max_value) {}
	int max_value;
	int value;
};

//! 防御力
struct Defense
{
	explicit Defense(int value, int max_value) :value(value), max_value(max_value) {}
	int max_value;
	int value;
};

//! 素早さ
struct Speed
{
	explicit Speed(int value, int max_value) :value(value), max_value(max_value) {}
	int max_value;
	int value;
};

//! 魔法攻撃力
struct MagicAttack
{
	explicit MagicAttack(int value, int max_value) :value(value), max_value(max_value) {}
	int max_value;
	int value;
};

//! 運
struct Luck
{
	explicit Luck(int value, int max_value) :value(value), max_value(max_value) {}
	int max_value;
	int value;
};

//! 愛情
struct Love
{
	explicit Love(int value, int max_value) :value(value), max_value(max_value) {}
	int max_value;
	int value;
};

//! 時間
struct Time
{
	explicit Time(int value, int max_value) :value(value), max_value(max_value) {}
	int max_value;
	int value;
};

//! お金
struct Gold
{
	explicit Gold(int value, int max_value) :value(value), max_value(max_value) {}
	int max_value;
	int value;
};

//! 年齢
struct Age
{
	explicit Age(int value, int max_value) :value(value), max_value(max_value) {}
	int max_value;
	int value;
};

//! 名前
struct Name
{
	explicit Name(std::string value) :value(value) {}
	std::string value;
};

struct Status
{
	Status(HP hp, MP mp, IP ip, Attack at, Defense df, Speed speed, MagicAttack magic_at) : hp(hp), mp(mp), ip(ip), at(at), df(df), speed(speed), magic_at(magic_at) {};
	HP hp;
	MP mp;
	IP ip;
	Attack at;
	Defense df;
	Speed speed;
	MagicAttack magic_at;
};

struct Parameter
{
	Parameter(Luck luck, Love love, Time time, Gold gold, Age age) : luck(luck), love(love), time(time), gold(gold), age(age) {};
	Luck luck;
	Love love;
	Time time;
	Gold gold;
	Age age;

};

struct TextureName
{
	explicit TextureName(std::string value) :value(value) {}
	std::string value;
};

struct Position
{
	Position(CoordinateX x, CoordinateY y) : x(x),y(y) {};

	CoordinateX x;
	CoordinateY y;
};

struct Vec2
{
	Vec2(Position start,Position end): x(start.x - end.x),y(start.y - end.y) {}
	float x;
	float y;
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


//------------operator-CoordinateY-and-Size--------------------------------------------

inline float operator +(CoordinateX lhs,Width rhs)
{
	return lhs.value + rhs.value;
}

inline float operator -(CoordinateX lhs, Width rhs)
{
	return lhs.value - rhs.value;
}

inline float operator +(CoordinateY lhs, Height rhs)
{
	return lhs.value + rhs.value;
}

inline float operator -(CoordinateY lhs, Height rhs)
{
	return lhs.value - rhs.value;
}

//------------operator-CoordinateY-and-Size--------------------------------------------





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

	const Position GetPos() const
	{
		return position;
	}

	const Size& GetSize() const 
	{
		return size;
	}

protected:

	DX::DirectX& dx = DX::DirectX::GetInstance();

	Position position =
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
