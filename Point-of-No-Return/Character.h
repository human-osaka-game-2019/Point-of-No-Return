#ifndef CHARCTER_H_
#define CHARCTER_H_

#include "Object.h"

//キャラクタークラス
class Character :public Object
{

};

//UIクラス
class UI :public Object
{

};

//スクロールステージクラス
class ScrollStage :public Object
{

};

//ステージクラス
class Stage :public Object
{

};




//主人公クラス
class Hero :public Character
{
public:
	CustomVertex customVertex;
	VertexX before_x;
	VertexX before_y;

	// 仮置き
	int x_move_speed;
	int y_move_speed;

};

//NPCクラス
class NPC :public Character
{

};

//敵クラス
class Enemy :public Character
{

};



#endif // !CHARCTER_H_
