#ifndef COLLISION_H_
#define COLLISION_H_

#include <vector>

#include "Mapchip.h"
#include "Object.h"

// TODO: Character.hとの相互参照によるコンパイルエラーを回避するためにDirectionをここに持ってきた。あくまでも暫定対応。
/**
 * @brief 方向
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
 * @brief 当たり判定をする関数を纏めた名前空間
 */
namespace Collision
{
/**
 * @brief	衝突時のコールバックインターフェイス
 */
class ICollisionCallback {
public:
	/**
	 * @brief	衝突時のコールバック関数
	 *
	 * @param	direction　　　座標修正する方向
	 * @param	blockPosition　当たっているブロックの座標
	 */
	virtual void OnCollided(Direction direction, const Vec2& blockPosition) = 0;
};

/**
 * @brief	衝突判定クラス
 */
class CollisionChecker
{
public:

	/**
	 * @brief	コンストラクタ
	 * @param	mapchip	マップチップクラスのインスタンスのアドレス
	 */
	explicit CollisionChecker(Mapchip* mapchip) :mapchip(mapchip) {}

	/**
	 * @brief 主人公周りのブロックで当たり判定があるかどうか探す
	 * @param  vec  キャラクターの位置
	 * @param  size キャラクターのサイズ
	 * @param  map  マップの情報のアドレス
	 * @return 当たり判定をとるブロックの座標の集まり
	 */
	std::vector<Vec2> SearchBlock(const Vec2& vec, const Size& size, int** map);
	
	// TODO: collision引数Hero修正しないといけない
	/**
	 * @brief	ブロックに当たっているかどうかの確認関数
	 * @param	character              キャラクター情報
	 * @param	characterPrevious      キャラクターの前の位置
	 * @param	characterSize          キャラクターのサイズ
	 * @param	characterPosition      キャラクターの位置
	 * @param	blockPositions         当たり判定をとるブロックの座標の集まり
	 */
	void CheckBlock(Character& character, Vec2 characterPrevious, Size characterSize, Vec2 characterPosition, std::vector<Vec2> blockPositions);

private:
	Mapchip* mapchip;
};
}

#endif
