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
			Matrix current = 
			{
				static_cast<Col>(search_start.col.value + j),
				static_cast<Row>(search_start.row.value + i)
			};

			if (map[current.row.value][current.col.value] != 0)
			{
				vec2.x.value = current.col.value * MapChipInfo::chip_size;
				vec2.y.value = current.row.value * MapChipInfo::chip_size;
				mapdata.push_back(vec2);
			}
		}
	}
	return mapdata;
}


void Collision::CheckBlock(Hero& hero, Vec2 previous, Size size, Vec2 vec, std::vector<Vec2> blocksPosition)
{
	Vec2 vector =
	{
		previous.x.value - vec.x.value,
		previous.y.value - vec.y.value
	};

	// 修正する方向を入れる変数

	for (auto blockPosition: blocksPosition)
	{
		if ((blockPosition.x.value < vec.x.value + size.width.value) &&
			(vec.x.value < blockPosition.x.value + MapChipInfo::chip_size) &&
			(blockPosition.y.value < vec.y.value + size.height.value) &&
			(vec.y.value < blockPosition.y.value + MapChipInfo::chip_size))
		{
			Direction correction;

			if (HitCheckEdge(&correction,previous, size, vector, blockPosition))
			{
				hero.CorrectCoordinate(correction, blockPosition);
			}
		}
	}

}

bool Collision::HitCheckEdge(Direction* direction, Vec2 previous, Size size, Vec2 vector, const Vec2& blockPosition)
{
	float characterTop = previous.y.value;
	float characterBottom = characterTop + size.height.value;
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
