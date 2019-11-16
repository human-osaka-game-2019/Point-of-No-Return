#include "Collision.h"

#include <vector>

#include "Object.h"

std::vector<Vec2> Collision::SearchBlock(const Vec2& vec,const Size& size,int** map)
{
	Vec2 vec2(0,0);
	std::vector<Vec2> mapdata;

	int center_x = vec.x.value + size.width.value / 2;
	int center_y = vec.y.value + size.height.value / 2;

	Matrix search_start = 
	{
		static_cast<Col>(center_x / chip_size - 2),
		static_cast<Row>(center_y / chip_size - 2) 
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
				vec2.x.value = current.col.value * chip_size;
				vec2.y.value = current.row.value * chip_size;
				mapdata.push_back(vec2);
			}
		}
	}
	return mapdata;
}

void Collision::CheckBlock(Hero& hero, Vec2 previous, Vec2 vec, Size size, std::vector<Vec2> vec2)
{
	Vec2 vector =
	{
		previous.x.value - vec.x.value,
		previous.y.value - vec.y.value
	};

	for (int i = 0; i < vec2.size(); i++)
	{
		//
		if ((vec2[i].x.value < vec.x.value + size.width.value) &&
			(vec.x.value < vec2[i].x.value + chip_size) &&
			(vec2[i].y.value < vec.y.value + size.height.value) &&
			(vec.y.value < vec2[i].y.value + chip_size))
		{
			HitCheckEdge(hero, previous, size, vector, vec2, i);
		}
	}
}

void Collision::HitCheckEdge(Hero& hero, Vec2 previous, Size size, Vec2 vector, std::vector<Vec2> vec2, int i)
{
	//! 修正する方向を入れる変数
	Direction correction;

	if ((previous.y.value + size.height.value <= vec2[i].y.value) || (previous.y.value >= vec2[i].y.value + chip_size))
	{
		if (vector.y.value < 0)
		{
			correction = Direction::Up;
			hero.CorrectCoodinate(correction, vec2, i);
		}
		else if (vector.y.value > 0)
		{
			correction = Direction::Down;
			hero.CorrectCoodinate(correction, vec2, i);
		}
	}
	else
	{
		if (vector.x.value < 0)
		{
			correction = Direction::Left;
			hero.CorrectCoodinate(correction, vec2, i);
		}
		else if (vector.x.value > 0)
		{
			correction = Direction::Right;
			hero.CorrectCoodinate(correction, vec2, i);
		}
	}
}

