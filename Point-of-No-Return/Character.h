#ifndef CHARCTER_H_
#define CHARCTER_H_

#include "Collision.h"
#include "Object.h"

/**
 * @brief キャラクタークラス
 */
class Character : public Object
{
public:
	/**
	 * @brief コンストラクタ
	 * @param name キャラクターの名前
	 */
	explicit Character(const std::string& name) :name(name) {}

	/**
	 * @brief	座標を修正する
	 * @param	direction　　　座標修正する方向
	 * @param	blockPosition　当たっているブロックの座標
	 * @details	HitCheckの中で呼び出す
	 */
	virtual void CorrectCoordinate(Direction direction, const Vec2& blockPosition) {};
protected:

	//! 前の座標を保存する
	Vec2 previous =
	{
		CoordinateX(0),
		CoordinateY(0)
	};

	// TODO: あとでprimitive型wrapします
	float gravity = 0;

private:

	//! キャラクターの名前
	Name name = Name("None");
};

/**
 * @brief 主人公クラス
 * @details コピーコンストラクタと演算子オーバーロードの隠蔽
 */
class Hero : public Character
{
public:
	/**
	 * @brief コンストラクタ
	 * @param name 主人公の名前
	 */
	Hero(const std::string& name):Character(name)
	{
		Initialize();
	}

	/**
	 * @brief  主人公の情報を更新する
	 */
	void Update();

	/**
	 * @brief	座標を修正する
	 * @param	direction　　　座標修正する方向
	 * @param	blockPosition　当たっているブロックの座標
	 * @details	HitCheckの中で呼び出す
	 */
	virtual void CorrectCoordinate(Direction direction, const Vec2& blockPosition) override;

	/**
	 * @brief	previousを取得する
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

	void Move();

	//コピーコンストラクタと演算子オーバーロードの隠蔽
	Hero(const Hero&);
	Hero& operator=(const Hero&);
	Hero(const Hero&&);
	Hero& operator=(const Hero&&);
};


/**
 * @brief UIクラス
 */
class UI : public Object
{

};

/**
 * @brief スクロールステージクラス
 */
class ScrollStage : public Object
{

};

/**
 * @brief ステージクラス
 */
class Stage : public Object
{

};

/**
 * @brief NPCクラス
 */
class NPC : public Character
{

};

/**
 * @brief 敵クラス
 */
class Enemy : public Character
{

};

#endif // !CHARCTER_H_
