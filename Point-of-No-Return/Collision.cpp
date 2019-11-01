#include "Collision.h"

int Collision::CheckMapNumber(int x, int y, int** map)
{
		
	return map[y / chip_size_][x / chip_size_];
	
}

Direction Collision::DirectionCheckX(Hero hero)
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

 Direction Collision::DirectionCheckY(Hero hero)
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
		CoordinateCorrection(hero,map);
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

void Collision::CoordinateCorrection(Hero hero,int** map)
{

	save_char_move_direction[X] = DirectionCheckX(hero);
	save_char_move_direction[Y] = DirectionCheckY(hero);

	if (save_char_move_direction[X] == RIGHT && save_char_move_direction[Y] == UP)
	{
		if (TopLeftHasHit(hero, map) == true)
		{

		}

		if (BottomRightHasHit(hero, map) == true)
		{

		}
		
		if (TopRightHasHit(hero, map) == true)
		{

		}


	}
	else if (save_char_move_direction[X] == RIGHT && save_char_move_direction[Y] == DOWN)
	{

	}

	if (save_char_move_direction[X] == LEFT && save_char_move_direction[Y] == UP)
	{

	}
	else if (save_char_move_direction[X] == LEFT && save_char_move_direction[Y] == DOWN)
	{

	}

	if (save_char_move_direction[X] == RIGHT)
	{
		hero.customVertex.x.var = (hero.customVertex.x.var / chip_size_) * chip_size_ - hero.customVertex.width.var;
	}
	else if (save_char_move_direction[X] == LEFT)
	{
		hero.customVertex.x.var = (hero.customVertex.x.var / chip_size_) * chip_size_ + chip_size_;
	}

	if (save_char_move_direction[Y] == UP)
	{
		hero.customVertex.y.var = (hero.customVertex.y.var / chip_size_)* chip_size_  + chip_size_;
	}
	else if (save_char_move_direction[Y] == DOWN)
	{
		hero.customVertex.y.var = (hero.customVertex.y.var / chip_size_) * chip_size_ - hero.customVertex.height.var;
	}

}

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


