#ifndef COLLISION_H_
#define COLLISION_H_

#include "Character.h"
#include "Mapchip.h"

/**
 * @brief 当たり判定をする関数を纏めた名前空間
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
 * @brief	ブロックに当たっているかどうかの確認関数
 * @param	character              キャラクター情報
 * @param	characterPrevious      キャラクターの前の位置
 * @param	characterSize          キャラクターのサイズ
 * @param	characterPosition      キャラクターの位置
 * @param	blockPositions         当たり判定をとるブロックの座標の集まり
 */
void CheckBlock(Character& character, Vec2 characterPrevious, Size characterSize, Vec2 characterPosition, std::vector<Vec2> blockPositions);

// TODO: collision引数Hero修正しないといけない
/**
 * @brief	どの辺で当たっているのかの確認関数
 * @param	direction         座標修正する方向
 * @param	characterPrevious キャラクターの前の位置
 * @param	characterSize     キャラクターのサイズ
 * @param	vector            キャラクターの移動量や方向
 * @param	blockPosition     当たり判定をとるブロックの座標
 * @return キャラクターが動いているか
 */
bool HitCheckEdge(Direction* direction, Vec2 characterPrevious, Size characterSize, Vec2 vector, const Vec2& blockPosition);

/**
 * @brief	キャラクターがブロックと当たっているか判定する関数
 * @param	characterPrevious キャラクターの前の位置
 * @param	characterSize     キャラクターのサイズ
 * @param	blockPosition     当たり判定をとるブロックの座標
 * @return 当たっているかどうか
 */
bool  isHItBlock(Vec2 characterPrevious, Size characterSize, Vec2 characterPosition, const Vec2& blockPosition);

}

#endif
