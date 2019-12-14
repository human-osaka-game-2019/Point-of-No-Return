#ifndef HERO_H_
#define HERO_H_

#include "Character.h"


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
	Hero(const std::string& name) :Character(name)
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
	virtual void CorrectCoordinate(Direction direction, const Position& blockPosition) override;

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
};


#endif // !HERO_H_


