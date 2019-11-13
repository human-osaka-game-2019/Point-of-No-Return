#include "Character.h"
#include <vector>
#include "Mapchip.h"

void Hero::InputBefore()
{
	previous_x = x;
	previous_y = y;
}

void Hero::HitBlock(Hero* hero, std::vector<Vec2> vec2)
{

	int number = 0;

	float vector_x = hero->previous_x - hero->x;
	float vector_y = hero->previous_y - hero->y;


	for (auto i = vec2.begin(); i != vec2.end(); i++) 
	{
		//
		if ((vec2[number].x.var < hero->x + hero->x_size) &&
			(hero->x < vec2[number].x.var + chip_size_) &&
			(vec2[number].y.var < hero->y + hero->y_size) &&
			(hero->y < vec2[number].y.var + chip_size_))
		{
			if ((hero->previous_y + hero->y_size <= vec2[number].y.var) || (hero->previous_y >= vec2[number].y.var + chip_size_))
			{
				if (vector_y < 0)
				{
					hero->y = vec2[number].y.var - hero->y_size;
				}
				else if (vector_y > 0)
				{
					hero->y = vec2[number].y.var + chip_size_;
				}
			}
			else
			{
				if (vector_x < 0)
				{
					hero->x = vec2[number].x.var - hero->x_size;
				}
				else if (vector_x > 0)
				{
					hero->x = vec2[number].x.var + chip_size_;
				}
			}
		}
		number++;
	}
}
