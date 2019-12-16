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
std::vector<Position> SearchBlock(Character& character, int** map);

// TODO: collision引数Hero修正しないといけない
/**
 * @brief	ブロックに当たっているかどうかの確認関数
 * @param	character              キャラクター情報
 * @param	characterPrevious      キャラクターの前の位置
 * @param	characterSize          キャラクターのサイズ
 * @param	characterPosition      キャラクターの位置
 * @param	blockPositions         当たり判定をとるブロックの座標の集まり
 */
void CheckBlock(Character* character,std::vector<Position> blockPositions);

}

#endif
