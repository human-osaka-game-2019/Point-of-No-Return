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
		return Direction::Right;
	}
	else if (vec_x > 0)
	{
		return Direction::Left;
	}
}

 Direction Collision::HorizontalDirectionCheck(Hero hero)
 {
	 // Yの移動量
	 vec_y = hero.customVertex.y.var - hero.before_y.var;

	 if (vec_y < 0)
	 {
		 return Direction::Down;
	 }
	 else if (vec_y > 0)
	 {
		 return Direction::Up;
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

	if (save_char_move_direction[X] == Right && save_char_move_direction[Y] == Up)
	{
		if (TopLeftHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, Down);
		}

		if (BottomRightHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, Left);
		}
		
		if (TopRightHasHit(hero, map) == true)
		{
			if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, UpRight) == Down)
			{
				CoordinateCorrection(hero, Down);
			}
			else if(HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, UpRight) == Left)
			{
				CoordinateCorrection(hero, Left);
			}
			else if(HitVectorJudge(hero.customVertex.x.var,hero.customVertex.y.var,UpRight) == UpRight)
			{
				CoordinateCorrection(hero, UpRight);
			}
		}


	}
	else if (save_char_move_direction[X] == Right && save_char_move_direction[Y] == Down)
	{
		if (TopRightHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, Left);
		}

		if (BottomLeftHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, Up);
		}

		if (BottomRightHasHit(hero, map) == true)
		{
			if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, DownRight) == Up)
			{
				CoordinateCorrection(hero, Up);
			}
			else if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, DownRight) == Left)
			{
				CoordinateCorrection(hero, Left);
			}
			else if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, DownRight) == DownRight)
			{
				CoordinateCorrection(hero, DownRight);
			}

		}


	}

	if (save_char_move_direction[X] == Left && save_char_move_direction[Y] == Up)
	{
		if (TopRightHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, Down);
		}

		if (BottomLeftHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, Right);
		}

		if (TopLeftHasHit(hero, map) == true)
		{
			if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, UpLeft) == Down)
			{
				CoordinateCorrection(hero, Down);
			}
			else if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, UpLeft) == Right)
			{
				CoordinateCorrection(hero, Right);
			}
			else if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, UpLeft) == UpLeft)
			{
				CoordinateCorrection(hero,UpLeft);
			}
		}
	}
	else if (save_char_move_direction[X] == Left && save_char_move_direction[Y] == Down)
	{

		if (BottomRightHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, Up);
		}

		if (TopLeftHasHit(hero, map) == true)
		{
			CoordinateCorrection(hero, Right);
		}
		
		if (BottomLeftHasHit(hero, map) == true)
		{
			if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, DownLeft) == Up)
			{
				CoordinateCorrection(hero, Up);
			}
			else if(HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, DownLeft) == Right)
			{
				CoordinateCorrection(hero, Right);
			}
			else if (HitVectorJudge(hero.customVertex.x.var, hero.customVertex.y.var, DownLeft) == DownLeft)
			{
				CoordinateCorrection(hero, DownLeft);
			}
		}
	}

	if (save_char_move_direction[X] == Right)
	{
		CoordinateCorrection(hero, Right);
	}
	else if (save_char_move_direction[X] == Left)
	{
		CoordinateCorrection(hero, Left);
	}

	if (save_char_move_direction[Y] == Up)
	{
		CoordinateCorrection(hero, Up);
	}
	else if (save_char_move_direction[Y] == Down)
	{
		CoordinateCorrection(hero, Down);
	}

}

void Collision::CoordinateCorrection(Hero hero, int char_move_direction)
{
	switch (char_move_direction)
	{
	case Up: // 当たり判定はブロックのBottom

		hero.customVertex.y.var = (hero.customVertex.y.var / chip_size_) * chip_size_ + chip_size_;

		break;

	case Down:// 当たり判定はブロックのTop

		hero.customVertex.y.var = (hero.customVertex.y.var / chip_size_) * chip_size_ - hero.customVertex.height.var;

		break;

	case Right: // 当たり判定はブロックのLeft

		hero.customVertex.x.var = (hero.customVertex.x.var / chip_size_) * chip_size_ - hero.customVertex.width.var;

		break;

	case Left: // 当たり判定はブロックのRight

		hero.customVertex.x.var = (hero.customVertex.x.var / chip_size_) * chip_size_ + chip_size_;

		break;

	case UpRight:

		//							元の座標 / チップサイズ * チップサイズ - キャラテクスチャの幅
		hero.customVertex.x.var = (hero.customVertex.x.var / chip_size_ ) * chip_size_;
		hero.customVertex.y.var = (hero.customVertex.y.var / chip_size_ + 1) * chip_size_;

		break;

	case UpLeft:

		hero.customVertex.x.var = (hero.customVertex.x.var / chip_size_ + 1) * chip_size_;
		hero.customVertex.y.var = (hero.customVertex.y.var / chip_size_ + 1) * chip_size_;

		break;

	case DownRight:

		hero.customVertex.x.var = (hero.customVertex.x.var / chip_size_) * chip_size_;
		hero.customVertex.y.var = (hero.customVertex.y.var / chip_size_) * chip_size_;

		break;

	case DownLeft:
		
		hero.customVertex.x.var = (hero.customVertex.x.var / chip_size_ + 1) * chip_size_;
		hero.customVertex.y.var = (hero.customVertex.y.var / chip_size_) * chip_size_;

		break;
	}


};


bool Collision::TopRightHasHit(Hero hero, int** map)
{
	if (CheckMapNumber((int)(hero.customVertex.x.var + hero.customVertex.width.var), hero.customVertex.y.var, map) == Road)
	{
		return true;
	}

	return false;
}

bool Collision::TopLeftHasHit(Hero hero, int** map)
{
	if (CheckMapNumber(hero.customVertex.x.var, hero.customVertex.y.var, map) == Road)
	{
		return true;
	}

	return false;
}

bool Collision::BottomRightHasHit(Hero hero, int** map)
{
	if (CheckMapNumber((int)(hero.customVertex.x.var + hero.customVertex.width.var), (int)(hero.customVertex.y.var + hero.customVertex.height.var), map) == Road)
	{
		return true;
	}

	return false;
}

bool Collision::BottomLeftHasHit(Hero hero, int** map)
{
	if (CheckMapNumber(hero.customVertex.x.var, (int)(hero.customVertex.y.var + hero.customVertex.height.var), map) == Road)
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
	case UpRight:

		x = ((X - map_x ) / X) * 100;
		y = ((Y - (map_y - chip_size_)) / Y) * 100;

		if (x < y)
		{
			return Left;
		}
		if (x > y)
		{
			return Down;
		}
		if (x == y)
		{
			// ひとまず同じ方向を返す
			return UpRight;
		}

		return NoHit;

	case UpLeft:

		x = (((map_x + chip_size_) - X) / X) * 100;
		y = ((Y - (map_y - chip_size_)) / Y) * 100;

		if (x < y)
		{
			return Right;
		}
		if (x > y)
		{
			return Down;
		}
		if (x == y)
		{
			// ひとまず同じ方向を返す
			return UpLeft;
		}

		return NoHit;


	case DownRight:

		x = ((X - map_x) / X) * 100;
		y = ((Y - map_y) / Y) * 100;

		if (x < y)
		{
			return Left;
		}
		if (x > y)
		{
			return Up;
		}
		if (x == y)
		{
			// ひとまず同じ方向を返す
			return DownRight;
		}

		return NoHit;

	case DownLeft:

		x = (((map_x + chip_size_) - X) / X) * 100;
		y = ((Y - map_y) / Y) * 100;

		if (x < y)
		{
			return Right;
		}
		if (x > y)
		{
			return Up;
		}
		if (x == y)
		{
			// ひとまず同じ方向を返す
			return DownLeft;
		}

		return NoHit;
	}
}


