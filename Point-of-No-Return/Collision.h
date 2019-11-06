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
	UPRIGHT,
	UPLEFT,
	DOWNRIGHT,
	DOWNLEFT
	
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

	int map_x;
	int map_y;

	// 配列の0番目にUPかDOWNが入り、配列の1番目にRIGHNTかLEFTが入る
	int save_char_move_direction[2] = {0};

     // マップチップの中身(数)を返す関数
	int CheckMapNumber(int x,int y, int** map);

public:
	

	// Xの方向を算出する関数
	Direction VerticalDirectionCheck(Hero hero);
	// Yの方向を算出する関数
	Direction HorizontalDirectionCheck(Hero hero);

	// 当たり判定関数
	void HeroAndBlock(Hero hero, int** map);

	// 当たったかの確認関数
	// 当たっていればtureを、当たっていなければ false を返す
	bool HitPointCheck(Hero hero,int** map);

	// ブロックにめり込んでいた場合、
	void DirectionCheck(Hero hero,int** map);

	// 座標を修正する関数
	void CoordinateCorrection(Hero hero,int direction);
	
	// 右上の頂点がブロックにあたっているかどうか
	bool TopRightHasHit(Hero hero, int** map);

	// 左上の頂点がブロックにあたっているかどうか
	bool TopLeftHasHit(Hero hero, int** map);

	// 右下の頂点がブロックにあたっているかどうか
	bool BottomRightHasHit(Hero hero, int** map);

	// 左下の頂点がブロックにあたっているかどうか
	bool BottomLeftHasHit(Hero hero,int** map);

	int HitVectorJudge(int X, int Y, int move_deflection);
};



#endif
