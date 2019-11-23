#include "Collision.h"

#include <vector>

#include "Object.h"

namespace
{

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
bool HitCheckEdge(Direction* direction, Vec2 characterPrevious, Size characterSize, Vec2 vector, const Vec2& blockPosition)
{
	float characterTop = characterPrevious.y.value;
	float characterBottom = characterTop + characterSize.height.value;
	float blockTop = blockPosition.y.value;
	float blockBottom = blockTop + Mapchip::CHIP_SIZE;

	// キャラクターが前のフレームでブロックの上下にいるとき
	if ((characterBottom <= blockTop) || (characterTop >= blockBottom))
	{
		//キャラクターがy方向に動いていないとき
		if (vector.y == CoordinateY(0))
		{
			return false;
		}

		*direction = (vector.y < CoordinateY(0)) ? Direction::Up : Direction::Down;

		return true;
	}

	//キャラクターがx方向に動いていないとき
	if (vector.x == CoordinateX(0))
	{
		return false;
	}

	*direction = (vector.x < CoordinateX(0)) ? Direction::Left : Direction::Right;

	return true;

}

/**
 * @brief	キャラクターがブロックと当たっているか判定する関数
 * @param	characterPrevious キャラクターの前の位置
 * @param	characterSize     キャラクターのサイズ
 * @param	blockPosition     当たり判定をとるブロックの座標
 * @return 当たっているかどうか
 */
bool isHItBlock(Vec2 characterPrevious, Size characterSize, Vec2 characterPosition, const Vec2& blockPosition)
{
	float characterLeft = characterPosition.x.value;
	float characterRight = characterLeft + characterSize.width.value;
	float characterTop = characterPosition.y.value;
	float characterBottom = characterTop + characterSize.height.value;

	float blockLeft = blockPosition.x.value;
	float blockRight = blockLeft + Mapchip::CHIP_SIZE;
	float blockTop = blockPosition.y.value;
	float blockBottom = blockTop + Mapchip::CHIP_SIZE;

	return (blockLeft < characterRight) &&
		(characterLeft < blockRight) &&
		(blockTop < characterBottom) &&
		(characterTop < blockBottom);
}


}



namespace Collision
{

std::vector<Vec2> SearchBlock(const Vec2& character_pos, const Size& size, int** map)
{
	Vec2 vec2(0, 0);
	std::vector<Vec2> mapdata;

	int center_x = character_pos.x.value + size.width.value / 2;
	int center_y = character_pos.y.value + size.height.value / 2;

	Matrix search_start =
	{
		Col(center_x / Mapchip::CHIP_SIZE - 2),
		Row(center_y / Mapchip::CHIP_SIZE - 2)
	};

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int current_col = search_start.col.value + j;
			int current_row = search_start.row.value + i;

			if (map[current_row][current_col] != 0)
			{
				vec2.x.value = current_col * Mapchip::CHIP_SIZE;
				vec2.y.value = current_row * Mapchip::CHIP_SIZE;
				mapdata.push_back(vec2);
			}
		}
	}
	return mapdata;
}


void CheckBlock(Character& character, Vec2 characterPrevious, Size characterSize, Vec2 characterPosition, std::vector<Vec2> blockPositions)
{
	Vec2 vector =
	{
		characterPrevious.x.value - characterPosition.x.value,
		characterPrevious.y.value - characterPosition.y.value
	};

	// 修正する方向を入れる変数

	for (auto blockPosition : blockPositions)
	{
		if (isHItBlock(characterPrevious, characterSize, characterPosition, blockPosition))
		{
			Direction correction;

			if (HitCheckEdge(&correction, characterPrevious, characterSize, vector, blockPosition))
			{
				character.CorrectCoordinate(correction, blockPosition);
			}
		}
	}
}

}

