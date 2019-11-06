#include "Collision.h"

int Collision::CheckMapNumber(int x, int y, int** map)
{
		
	return map[y / chip_size_][x / chip_size_];
	
}

Direction Collision::VerticalDirectionCheck(Hero hero)
{
	// Xの移動量
	vec_x = hero.customVertex.x.var - hero.before_x.var;

	if (vec_x < 0)
	{
		return RIGHT;
	}
	else if (vec_x > 0)
	{
		return LEFT;
	}
}

 Direction Collision::HorizontalDirectionCheck(Hero hero)
 {
	 // Yの移動量
	 vec_y = hero.customVertex.y.var - hero.before_y.var;

	 if (vec_y < 0)
	 {
		 return DOWN;
	 }
	 else if (vec_y > 0)
	 {
		 return UP;
	 }
 }
 
void Collision::HeroAndBlock(Hero hero, int** map)
{
	if (HitPointCheck(hero, map) == true)
	{
		DirectionCheck(hero,map);
	}

}

bool Collision::HitPointCheck(Hero hero,int** map)
{
	//	右上 左上 右下 左下
	if (TopRightHasHit(hero,map) == true || TopLeftHasHit(hero,map) == true || BottomRightHasHit(hero, map) == true || BottomLeftHasHit(hero, map) == true)
	{	
		return true;
	}
    
	return false;

}

void Collision::DirectionCheck(Hero hero,int** map)
{

	save_char_move_direction[X] = VerticalDirectionCheck(hero);
	save_char_move_direction[Y] = HorizontalDirectionCheck(hero);

	if (save_char_move_direction[X] == RIGHT && save_char_move_direction[Y] == UP)
	{
		if (TopLeftHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, DOWN);
		}

		if (BottomRightHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, LEFT);
		}
		
		if (TopRightHasHit(hero, map) == true)
		{
			if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, UPRIGHT) == DOWN)
			{
				CoordinateCorrection(hero, DOWN);
			}
			else if(HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, UPRIGHT) == LEFT)
			{
				CoordinateCorrection(hero, LEFT);
			}
		}


	}
	else if (save_char_move_direction[X] == RIGHT && save_char_move_direction[Y] == DOWN)
	{
		if (TopRightHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, LEFT);
		}

		if (BottomLeftHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, UP);
		}

		if (BottomRightHasHit(hero, map) == true)
		{
			if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, DOWNRIGHT) == UP)
			{
				CoordinateCorrection(hero, UP);
			}
			else if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, DOWNRIGHT) == LEFT)
			{
				CoordinateCorrection(hero, LEFT);
			}

		}


	}

	if (save_char_move_direction[X] == LEFT && save_char_move_direction[Y] == UP)
	{
		if (TopRightHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, DOWN);
		}

		if (BottomLeftHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, RIGHT);
		}

		if (TopLeftHasHit(hero, map) == true)
		{
			if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, UPLEFT) == DOWN)
			{
				CoordinateCorrection(hero, DOWN);
			}
			else if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, UPLEFT) == RIGHT)
			{
				CoordinateCorrection(hero, RIGHT);
			}
		}
	}
	else if (save_char_move_direction[X] == LEFT && save_char_move_direction[Y] == DOWN)
	{

		if (BottomRightHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, UP);
		}

		if (TopLeftHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, RIGHT);
		}
		
		if (BottomLeftHasHit(hero, map) == true)
		{
			if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, DOWNLEFT) == UP)
			{
				CoordinateCorrection(hero, UP);
			}
			else if(HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, DOWNLEFT) == RIGHT)
			{
				CoordinateCorrection(hero, RIGHT);
			}
		}
	}

	if (save_char_move_direction[X] == RIGHT)
	{
		CoordinateCorrection(hero, RIGHT);
	}
	else if (save_char_move_direction[X] == LEFT)
	{
		CoordinateCorrection(hero, LEFT);
	}

	if (save_char_move_direction[Y] == UP)
	{
		CoordinateCorrection(hero, UP);
	}
	else if (save_char_move_direction[Y] == DOWN)
	{
		CoordinateCorrection(hero, DOWN);
	}

}

void Collision::CoordinateCorrection(Hero hero, int char_move_direction)
{
	switch (char_move_direction)
	{
	case UP: // 当たり判定はブロックのBottom

		hero.customVertex.y.var = (hero.customVertex.y.var / chip_size_) * chip_size_ + chip_size_;

		break;

	case DOWN:// 当たり判定はブロックのTop

		hero.customVertex.y.var = (hero.customVertex.y.var / chip_size_) * chip_size_ - hero.customVertex.height.var;

		break;

	case RIGHT: // 当たり判定はブロックのLeft

		hero.customVertex.x.var = (hero.customVertex.x.var / chip_size_) * chip_size_ - hero.customVertex.width.var;

		break;

	case LEFT: // 当たり判定はブロックのRight

		hero.customVertex.x.var = (hero.customVertex.x.var / chip_size_) * chip_size_ + chip_size_;

		break;
	}


};


bool Collision::TopRightHasHit(Hero hero, int** map)
{
	if (CheckMapNumber((int)(hero.customVertex.x.var + hero.customVertex.width.var), hero.customVertex.y.var, map) == ROAD)
	{
		return true;
	}

	return false;
}

bool Collision::TopLeftHasHit(Hero hero, int** map)
{
	if (CheckMapNumber(hero.customVertex.x.var, hero.customVertex.y.var, map) == ROAD)
	{
		return true;
	}

	return false;
}

bool Collision::BottomRightHasHit(Hero hero, int** map)
{
	if (CheckMapNumber((int)(hero.customVertex.x.var + hero.customVertex.width.var), (int)(hero.customVertex.y.var + hero.customVertex.height.var), map) == ROAD)
	{
		return true;
	}

	return false;
}

bool Collision::BottomLeftHasHit(Hero hero, int** map)
{
	if (CheckMapNumber(hero.customVertex.x.var, (int)(hero.customVertex.y.var + hero.customVertex.height.var), map) == ROAD)
	{
		return true;
	}

	return false;
}

int Collision::HitVectorJudge(int X, int Y, int move_deflection)
{
	float x, y;

	map_x = (X / chip_size_) * chip_size_;
	map_y = (Y / chip_size_) * chip_size_;

	switch (move_deflection)
	{
	case UPRIGHT:

		x = ((X - map_x ) / X) * 100;
		y = ((Y - (map_y - chip_size_)) / Y) * 100;

		if (x < y)
		{
			return LEFT;
		}
		if (x > y)
		{
			return DOWN;
		}
		if (x == y)
		{
			//処理書く
		}

		return NoHit;

	case UPLEFT:

		x = (((map_x + 64) - X) / X) * 100;
		y = ((Y - (map_y - 64)) / Y) * 100;

		if (x < y)
		{
			return RIGHT;
		}
		if (x > y)
		{
			return DOWN;
		}
		if (x == y)
		{
			//処理書く
		}

		return NoHit;


	case DOWNRIGHT:

		x = ((X - map_x) / X) * 100;
		y = ((Y - map_y) / Y) * 100;

		if (x < y)
		{
			return LEFT;
		}
		if (x > y)
		{
			return UP;
		}
		if (x == y)
		{
			//処理書く
		}

		return NoHit;

	case DOWNLEFT:

		x = (((map_x + 64) - X) / X) * 100;
		y = ((Y - map_y) / Y) * 100;

		if (x < y)
		{
			return RIGHT;
		}
		if (x > y)
		{
			return UP;
		}
		if (x == y)
		{
			//処理書く
		}

		return NoHit;
	}
}


