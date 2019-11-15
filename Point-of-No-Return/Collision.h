#ifndef COLLISION
#define COLLISION

#include "Mapchip.h"
#include "Character.h"

namespace Collision
{
	/**
	 * 主人公周りのブロックで当たりア判定があるかどうか探す
	 * @param hero
	 * @param map
	 * @param map情報のアドレス
	 * @return　マップチップの二次元配列の中身
	 */
	std::vector<Vec2> SearchBlock(const Vec2& vec, const Size& size, int** map);


	/**
	 * ブロックに当たっているかどうかの確認関数
	 * @param hero
	 * @param previous
	 * @param vec
	 * @param size
	 * @param vec2
	 */
	void BlockCheck(Hero& hero, Vec2 previous, Vec2 vec, Size size, std::vector<Vec2> vec2);

	/**
     * どの辺で当たっているのかの確認関数
     * @param hero
     * @param previous
     * @param size
	 * @param vector
     * @param vec2
	 * @param i 
     */
	void HitChecEdgek(Hero& hero, Vec2 previous, Size size, Vec2 vector, std::vector<Vec2> vec2, int i);
}

#endif
