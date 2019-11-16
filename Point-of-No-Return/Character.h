#ifndef CHARCTER_H_
#define CHARCTER_H_

#include "Object.h"


enum class Direction
{
	Up,
	Down,
	Right,
	Left
};

//キャラクタークラス
class Character :public Object
{
public:
	explicit Character(const std::string& name):name(name) {}
private:
	Name name = { "None" };
};

//主人公クラス
class Hero :public Character
{
public:
	
/**
* @brief 主人公の前の座標を更新する
* @detail キャラクターを移動させる前にcallする
*/
	void UpdatePreviousVertex();

	// void HitBlock(std::vector<Vec2> vec2);

	Hero(const std::string& name):Character(name)
	{
		
		Initialize();
	}
	

	void Update();

/**
* @brief 座標を修正する関数
* @param 座標修正する方向
* @param 当たっているブロックの座標
* @param イテレータ
* @detail HitCheckの中で呼び出す
*/
	void CorrectCoodinate(Direction correction, std::vector<Vec2> vec2, int i);

/**
* @brief previousをとってくる関数
*/
	inline Vec2 GetPrevious()
	{
		return previous;
	};

private:
	/**
	* @brief 主人公の初期化
	* @detail コンストラクタで呼び出す
	*/
	void Initialize();

	//コピーコンストラクタと演算子オーバーロードの隠蔽
	Hero(const Hero&);
	Hero& operator=(const Hero&);
	Hero(const Hero&&);
	Hero& operator=(const Hero&&);

protected:
	//! 前の座標を保存する変数
	Vec2 previous = {0,0};
	//あとでprimitive型wrapします
	float gravity = 0;
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

//NPCクラス
class NPC :public Character
{

};

//敵クラス
class Enemy :public Character
{

};



#endif // !CHARCTER_H_
