#ifndef COLLISION
#define COLLISION

#include"Mapchip.h"
#include"Character.h"

enum Direction
{
	STOP,
	UP,
	DOWN,
	RIGHT,
	LEFT,
	
};

enum 
{ 
	AIR,
	ROAD,

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

	int vec_x;
	int vec_y;
	// 配列の0番目にUPかDOWNが入り、配列の1番目にRIGHNTかLEFTが入る
	int save_char_move_direction[2] = {0};

     // マップチップの中身(数)を返す関数
	int CheckMapNumber(int x,int y, int** map);

public:
	

	// Xの方向を算出する関数
	Direction DirectionCheckX(Hero hero);
	// Yの方向を算出する関数
	Direction DirectionCheckY(Hero hero);

	// 当たり判定関数
	void HeroAndBlock(Hero hero, int** map);

	// 当たったかの確認関数
	// 当たっていればtureを、当たっていなければ false を返す
	bool HitPointCheck(Hero hero,int** map);

	void CoordinateCorrection(Hero hero,int** map);

	bool TopRightHasHit(Hero hero, int** map);

	bool TopLeftHasHit(Hero hero, int** map);

	bool BottomRightHasHit(Hero hero, int** map);

	bool BottomLeftHasHit(Hero hero,int** map);
};



#endif
