#ifndef COLLISION
#define COLLISION

#include "Mapchip.h"
#include "Character.h"

enum Direction
{
	Stop,
	Up,
	Down,
	Right,
	Left,
	UpRight,
	UpLeft,
	DownRight,
	DownLeft
};

enum 
{ 
	Air,
	Road,

};

enum
{
	X,
	Y
};

enum HitPoint
{
	TopRight,
	TopLeft,
	BottomRight,
	BottomLeft,
	NoHit,

};



class Collision
{
private:				


public:

	/**
	 * 主人公周りのブロックで当たりア判定があるかどうか探す
	 * @param hero
	 * @param map
	 * @param map情報のアドレス
	 * @return　マップチップの二次元配列の中身
	 */
	std::vector<Vec2> SearchBlock(const Hero& hero, int** map);

};



#endif
