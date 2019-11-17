#ifndef COLLISION_H_
#define COLLISION_H_

#include "Character.h"
#include "Mapchip.h"

/**
* @brief 当たり判定をする関数
*/
namespace Collision
{
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
	 * @brief ブロックに当たっているかどうかの確認関数
	 * @param hero     主人公の情報
	 * @param previous キャラクターの前の位置
	 * @param size     キャラクターのサイズ
	 * @param vec      キャラクターの移動量や方向
	 * @param vec2     当たり判定をとるブロックの座標の集まり
	 */
	void CheckBlock(Hero& hero, Vec2 previous, Size size, Vec2 vec, std::vector<Vec2> vec2);

	// TODO: collision引数Hero修正しないといけない
	/**
	 * @brief どの辺で当たっているのかの確認関数
	 * @param hero     主人公の情報
	 * @param previous キャラクターの前の位置
	 * @param size     キャラクターのサイズ
	 * @param vector   キャラクターの移動量や方向
	 * @param vec2     当たり判定をとるブロックの座標の集まり
	 * @param i        当たり判定をとるブロックを判断する
	 */
	void HitCheckEdge(Hero& hero, Vec2 previous, Size size, Vec2 vector, std::vector<Vec2> vec2, int i);


	/**
	 * @brief 自身のX座標の値と引数の値を比べる　
	 * @param lhs 自身のX座標
	 * @param rhs 比べる値
	 * return 引数の値が大きかったらtureを返す
	 */
	inline bool operator <(const CoordinateX& lhs, const float& rhs)
	{
		return lhs.value <= rhs;
	}

	/**
     * @brief 自身のX座標の値と引数の値を比べる　
     * @param lhs 自身のX座標
     * @param rhs 比べる値
     * return 自身の値が大きかったらtureを返す
     */
	inline bool operator >(const CoordinateX& lhs, const float& rhs)
	{
		return lhs.value >= rhs;
	}

	/**
　　 * @brief 自身のX座標の値と引数の値を比べる　
　　 * @param lhs 自身のY座標
　　 * @param rhs 比べる値
　　 * return 引数の値が大きかったらtureを返す
　　 */
	inline bool operator <(const CoordinateY& lhs, const float& rhs)
	{
		return lhs.value <= rhs;
	}

	/**
　　 * @brief 自身のX座標の値と引数の値を比べる　
　　 * @param lhs 自身のY座標
　　 * @param rhs 比べる値
　　 * return 自身の値が大きかったらtureを返す
　　 */
	inline bool operator >(const CoordinateY& lhs, const float& rhs)
	{
		return lhs.value >= rhs;
	}
}

#endif
