#include "Collision.h"

#include <vector>

#include "Object.h"

std::vector<Vec2> Collision::SearchBlock(const Vec2& character_pos,const Size& size,int** map)
{
	Vec2 vec2(0,0);
	std::vector<Vec2> mapdata;

	int center_x = character_pos.x.value + size.width.value / 2;
	int center_y = character_pos.y.value + size.height.value / 2;

	Matrix search_start = 
	{
		static_cast<Col>(center_x / MapChipInfo::chip_size - 2),
		static_cast<Row>(center_y / MapChipInfo::chip_size - 2)
	};
	
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			int current_col = search_start.col.value + j;
			int current_row = search_start.row.value + i;

			if (map[current_row][current_col] != 0)
			{
				vec2.x.value = current_col * MapChipInfo::chip_size;
				vec2.y.value = current_row * MapChipInfo::chip_size;
				mapdata.push_back(vec2);
			}
		}
	}
	return mapdata;
}

//
void Collision::CheckBlock(Character& character, Vec2 characterPrevious, Size characterSize, Vec2 characterPosition, std::vector<Vec2> blockPositions)
{
	Vec2 vector =
	{
		characterPrevious.x.value - characterPosition.x.value,
		characterPrevious.y.value - characterPosition.y.value
	};

	// 修正する方向を入れる変数

	for (auto blockPosition: blockPositions)
	{
		float characterLeft = characterPosition.x.value;
		float characterRight = characterPosition.x.value + characterSize.width.value;
		float characterTop = characterPosition.y.value;
		float characterBottom = characterPosition.y.value + characterSize.height.value;
	
		float blockLeft = blockPosition.x.value;
		float blockRight = blockPosition.x.value + MapChipInfo::chip_size;
		float blockTop = blockPosition.y.value;
		float blockBottom = blockPosition.y.value + MapChipInfo::chip_size;


		if ((blockLeft < characterRight) &&
			(characterLeft < blockRight) &&
			(blockTop < characterBottom) &&
			(characterTop < blockBottom))
		{
			Direction correction;

			if (HitCheckEdge(&correction, characterPrevious, characterSize, vector, blockPosition))
			{
				character.CorrectCoordinate(correction, blockPosition);
			}
		}
	}

}

bool Collision::HitCheckEdge(Direction* direction, Vec2 characterPrevious, Size characterSize, Vec2 vector, const Vec2& blockPosition)
{
	float characterTop = characterPrevious.y.value;
	float characterBottom = characterTop + characterSize.height.value;
	float blockTop = blockPosition.y.value;
	float blockBottom = blockTop + MapChipInfo::chip_size;

	// キャラクターとブロックがY軸方向に重なっているとき
	if ((characterBottom <= blockTop) || (characterTop >= blockBottom))
	{
		if (vector.y == CoordinateY(0))
		{
			return false;
		}
		
		*direction = (vector.y < CoordinateY(0)) ? Direction::Up : Direction::Down;
	
		return true;
	}
	
	if (vector.x == CoordinateX(0))
	{
		return false;
	}
	
	*direction = (vector.x < CoordinateX(0)) ? Direction::Left : Direction::Right;

	return true;
	
}
