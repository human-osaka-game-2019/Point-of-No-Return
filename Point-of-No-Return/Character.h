#ifndef CHARCTER_H_
#define CHARCTER_H_

#include "Object.h"

/**
 * @enum Direction
 * 方向
 */
enum class Direction
{
	//! 上
	Up,
	//! 下
	Down,
	//! 右
	Right,
	//! 左
	Left
};

/**
* @brief キャラクタークラス
* @details 
*/class Character :public Object
{
public:
	/**
	 * @brief メンバ変数のnameに文字列の代入
	 */
	explicit Character(const std::string& name):name(name) {}
private:
	//! キャラクターの名前
	Name name = { "None" };
};

/**
* @brief 主人公クラス
* @details コピーコンストラクタと演算子オーバーロードの隠蔽
*/
class Hero :public Character
{
public:
	
	/**
	 * @brief  主人公の前の座標を更新する
	 * @details キャラクターを移動させる前にcallする
	 */
	void UpdatePreviousVertex();

	// void HitBlock(std::vector<Vec2> vec2);

	/**
	 * @brief 主人公の名前を代入、主人公の初期化
	 */
	Hero(const std::string& name):Character(name)
	{
		
		Initialize();
	}
	
	/**
	 * @brief  主人公の情報を更新する
	 * @details 
	 */
	void Update();

	/**
	 * @brief  座標を修正する関数
	 * @param  座標修正する方向
	 * @param  当たっているブロックの座標
	 * @param  当たり判定をとるブロックを判断する
	 * @details HitCheckの中で呼び出す
	 */
	void CorrectCoordinate(Direction correction, std::vector<Vec2> vec2, int i);

	/**
	 * @brief previousをとってくる関数
	 */
	inline Vec2 GetPrevious()
	{
		return previous;
	};

private:
	/**
	 * @brief  主人公の初期化
	 * @details コンストラクタで呼び出す
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
	// TODO: あとでprimitive型wrapします
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
