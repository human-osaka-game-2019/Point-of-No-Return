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
	float before_x;
	float before_y;

	// 仮置き
	float x_move_speed;
	float y_move_speed;

	float x = 0;
	float y = 0;
	float x_size = 100;
	float y_size = 120;

	float tu = 0;
	float tu_size  =1;
	float tv = 0;
	float tv_size = 1;

	float gravity =0;

	void InputBefore();



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
