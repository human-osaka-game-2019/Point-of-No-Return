#include "Collision.h"

#include <vector>

#include "Object.h"

namespace
{
	//! 当たり判定する列の順番を保存する配列
	const int COLLISION_JUDGEMENT_ORDER[5] = { 2,1,3,0,4 };


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
bool HitCheckEdge(Direction* direction, Position characterPrevious, Size characterSize, Vec2 characterVector, const Position& blockPosition)
{
	float characterTop = characterPrevious.y.value;
	float characterBottom = characterTop + characterSize.height.value;
	float blockTop = blockPosition.y.value;
	float blockBottom = blockTop + Mapchip::CHIP_SIZE;

	// キャラクターが前のフレームでブロックの上下にいるとき
	if ((characterBottom <= blockTop) || (characterTop >= blockBottom))
	{
		//キャラクターがy方向に動いていないとき
		if (characterVector.y == 0.f)
		{
			return false;
		}

		*direction = (characterVector.y < 0.f) ? Direction::Up : Direction::Down;

		return true;
	}

	//キャラクターがx方向に動いていないとき
	if (characterVector.x == 0.f)
	{
		return false;
	}

	*direction = (characterVector.x < 0.f) ? Direction::Left : Direction::Right;

	return true;

}

/**
 * @brief	キャラクターがブロックと当たっているか判定する関数
 * @param	characterPrevious キャラクターの前の位置
 * @param	characterSize     キャラクターのサイズ
 * @param	blockPosition     当たり判定をとるブロックの座標
 * @return 当たっているかどうか
 */
bool CharacterCollidesWithBlock(Position characterPrevious, Size characterSize, Position characterPosition, const Position& blockPosition)
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

std::vector<Position> SearchBlock(Character& character, int** map)
{
	auto characterPosition = character.GetPos();
	auto characterSize = character.GetSize();
	auto offset = character.GetOffset();

	Position blockPosition(CoordinateX(0), CoordinateY(0));
	std::vector<Position> mapdata;

	int center_x = characterPosition.x.value + characterSize.width.value / 2;
	int center_y = characterPosition.y.value + characterSize.height.value / 2;

	Position center =
	{
		CoordinateX(center_x),
		CoordinateY(center_y)
	};

	Matrix search_start = Mapchip::CalcMapMatrix(center,offset);
	
	search_start.col.value -= 2;
	search_start.row.value -= 2; 

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int current_col = search_start.col.value + j;
			int current_row = search_start.row.value + COLLISION_JUDGEMENT_ORDER[i];

			if (map[current_row][current_col] != 0)
			{
				Matrix current_matrix =
				{
					Col(current_col),
					Row(current_row)
				};

				blockPosition = Mapchip::CalcMapPosition(current_matrix,offset);

				mapdata.push_back(blockPosition);
			}
		}
	}
	return mapdata;
}


void CheckBlock(Character* character, std::vector<Position> blockPositions)
{
	auto characterPrevious = character->GetPreviousPosition();
	auto characterSize = character->GetSize();
	auto vector = character->GetVector();

	for (auto blockPosition : blockPositions)
	{
		// キャラクターの位置だけ毎回更新する
		auto characterPosition = character->GetPos();

		if (CharacterCollidesWithBlock(characterPrevious, characterSize, characterPosition, blockPosition))
		{
			Direction correction;

			if (HitCheckEdge(&correction, characterPrevious, characterSize, vector, blockPosition))
			{
				character->CorrectCoordinate(correction, blockPosition);
			}
		}
	}
}

}

