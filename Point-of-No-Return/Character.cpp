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
	CustomVertex hero;
};

//NPCクラス
class NPC :public Character
{

};

//敵クラス
class Enemy :public Character
{

};
