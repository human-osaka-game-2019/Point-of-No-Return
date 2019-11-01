#ifndef COLLISION
#define COLLISION

#include"Mapchip.h"
#include"Character.h"

enum 
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	STOP,
};

enum 
{ 
	AIR,
	ROAD,

};

class Collision
{
private:

	int vec_x;
	int vec_y;
	int direction_x;	
	int direction_y;


public:
	// マップチップの中身(数)を返す関数
	int CheckMapNumber(int x,int y, int** map, int CharDirection);

	// 方向を算出する関数
	void DirectionCheck(Hero hero);

	// 当たり判定関数
	void HeroAndBlock(Hero hero, int** map);
};



#endif
