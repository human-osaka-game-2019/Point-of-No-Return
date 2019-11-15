#ifndef COLLISION
#define COLLISION

#include "Mapchip.h"
#include "Character.h"

class Collision
{
private:				


public:

	/**
	 * 主人公周りのブロックで当たりア判定があるかどうか探す
	 * @param hero
	 * @param map
	 * @param map情報のアドレス
	 * @return　マップチップの二次元配列の中身
	 */
	std::vector<Vec2> SearchBlock(const Vec2& vec, const Size& size, int** map);

};


#endif
