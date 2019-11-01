#include "Collision.h"

int Collision::CheckMapNumber(int x, int y, int** map, int CharDirection)
{
		
	return map[y / chip_size_][x / chip_size_];
	
}

void Collision::DirectionCheck(Hero hero)
{
	// X差分
	vec_x = hero.customVertex.x.var - hero.before_x.var;

	// Y差分
	vec_y = hero.customVertex.y.var - hero.before_y.var;

	if (vec_x > 0)
	{
		direction_x = RIGHT;
	}
	else if(vec_x < 0)
	{
		direction_x = LEFT;
	}

	if (vec_y > 0)
	{
		direction_y = DOWN;
	}
	else if(vec_y < 0)
	{
		direction_y = UP;
	}

	

}

void Collision::HeroAndBlock(Hero hero, int** map)
{
	if(CheckMapNumber != AIR)
	{//右下に移動中/右下の頂点
		hero.customVertex.x.var - ((int)(hero.customVertex.x.var + hero.customVertex.width.var) / chip_size_) * chip_size_;
		hero.customVertex.y.var - ((int)(hero.customVertex.y.var + hero.customVertex.height.var) / chip_size_) * chip_size_;
	}
	switch (Direction)
	{
	case UP:

	

		break;
	
	case DOWN:

		break;
	case RIGHT:

		break;
	case LEFT:

		break;
	}


}