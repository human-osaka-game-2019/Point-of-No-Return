#ifndef COLLISION
#define COLLISION

#include "Character.h"
#include "Mapchip.h"

namespace Collision
{
	/**
	 * @brief 主人公周りのブロックで当たり判定があるかどうか探す
	 * @param  vec  キャラクターの位置
	 * @param  size キャラクターのサイズ
	 * @param  map  マップの情報のアドレス
	 * @return 当たり判定をとるブロックの座標の集まり
	 * @details 
	 */
	std::vector<Vec2> SearchBlock(const Vec2& vec, const Size& size, int** map);


	/**
	 * @brief ブロックに当たっているかどうかの確認関数
	 * @param hero     主人公の情報
	 * @param previous キャラクターの前の位置
	 * @param size     キャラクターのサイズ
	 * @param vec      キャラクターの移動量や方向
	 * @param vec2     当たり判定をとるブロックの座標の集まり
	 * @details 
	 */
	void CheckBlock(Hero& hero, Vec2 previous, Size size, Vec2 vec, std::vector<Vec2> vec2);

	/**
     * @brief どの辺で当たっているのかの確認関数
     * @param hero     主人公の情報
     * @param previous キャラクターの前の位置
     * @param size     キャラクターのサイズ
	 * @param vector   キャラクターの移動量や方向
     * @param vec2     当たり判定をとるブロックの座標の集まり
	 * @param i        当たり判定をとるブロックを判断する
	 * @details 
     */
	void HitCheckEdge(Hero& hero, Vec2 previous, Size size, Vec2 vector, std::vector<Vec2> vec2, int i);
}

#endif
