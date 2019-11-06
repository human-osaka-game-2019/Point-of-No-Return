#include "Collision.h"

int Collision::CheckMapNumber(int x, int y, int** map)
{
		
	return map[y / chip_size_][x / chip_size_];
	
}

Direction Collision::VerticalDirectionCheck(int x,int before_x)
{
	// Xの移動量
	vec_x = x - before_x;

	if (vec_x < 0)
	{
		return Direction::Right;
	}
	else if (vec_x > 0)
	{
		return Direction::Left;
	}
}

 Direction Collision::HorizontalDirectionCheck(int y, int before_y)
 {
	 // Yの移動量
	 vec_y = y - before_y;

	 if (vec_y < 0)
	 {
		 return Direction::Down;
	 }
	 else if (vec_y > 0)
	 {
		 return Direction::Up;
	 }
 }
 
void Collision::ブロックとの(int x, int x_size, int y, int y_size, int before_x, int before_y, int** map)
{
	if (HitPointCheck(x,x_size,y,y_size, map) == true)
	{
		DirectionCheck(x,x_size,y,y_size,before_x,before_y,map);
	}

}

bool Collision::HitPointCheck(int x,int x_size,int y , int y_size,int** map)
{
	//	右上 左上 右下 左下
	if (TopRightHasHit(x, x_size, y, map) == true || TopLeftHasHit(x,y,map) == true || BottomRightHasHit(x, x_size, y, y_size, map) == true || BottomLeftHasHit(x, y, y_size, map) == true)
	{	
		return true;
	}
    
	return false;

}

void Collision::DirectionCheck(int x,int x_size,int y,int y_size,int before_x,int before_y,int** map)
{

	save_char_move_direction[X] = VerticalDirectionCheck(x,before_x);
	save_char_move_direction[Y] = HorizontalDirectionCheck(y,before_y);

	if (save_char_move_direction[X] == Right && save_char_move_direction[Y] == Up)
	{
		if (TopLeftHasHit(x,y, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Down);
		}

		if (BottomRightHasHit(x,x_size,y,y_size, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Left);
		}
		
		if (TopRightHasHit(x,x_size,y, map) == true)
		{
			if (HitVectorJudge(x, y, UpRight) == Down)
			{
				CoordinateCorrection(x, x_size, y, y_size, Down);
			}
			else if(HitVectorJudge(x,y, UpRight) == Left)
			{
				CoordinateCorrection(x, x_size, y, y_size, Left);
			}
			else if(HitVectorJudge(x,y,UpRight) == UpRight)
			{
				CoordinateCorrection(x, x_size, y, y_size, UpRight);
			}
		}


	}
	else if (save_char_move_direction[X] == Right && save_char_move_direction[Y] == Down)
	{
		if (TopRightHasHit(x,x_size,y, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Left);
		}

		if (BottomLeftHasHit(x, y, y_size, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Up);
		}

		if (BottomRightHasHit(x, x_size, y, y_size, map) == true)
		{
			if (HitVectorJudge(x,y, DownRight) == Up)
			{
				CoordinateCorrection(x, x_size, y, y_size, Up);
			}
			else if (HitVectorJudge(x,y, DownRight) == Left)
			{
				CoordinateCorrection(x, x_size, y, y_size, Left);
			}
			else if (HitVectorJudge(x,y, DownRight) == DownRight)
			{
				CoordinateCorrection(x, x_size, y, y_size, DownRight);
			}

		}


	}

	if (save_char_move_direction[X] == Left && save_char_move_direction[Y] == Up)
	{
		if (TopRightHasHit(x,x_size,y, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Down);
		}

		if (BottomLeftHasHit(x, y, y_size, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Right);
		}

		if (TopLeftHasHit(x,y, map) == true)
		{
			if (HitVectorJudge(x,y, UpLeft) == Down)
			{
				CoordinateCorrection(x, x_size, y, y_size, Down);
			}
			else if (HitVectorJudge(x,y, UpLeft) == Right)
			{
				CoordinateCorrection(x, x_size, y, y_size, Right);
			}
			else if (HitVectorJudge(x, y, UpLeft) == UpLeft)
			{
				CoordinateCorrection(x, x_size, y, y_size,UpLeft);
			}
		}
	}
	else if (save_char_move_direction[X] == Left && save_char_move_direction[Y] == Down)
	{

		if (BottomRightHasHit(x, x_size, y, y_size, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Up);
		}

		if (TopLeftHasHit(x,y, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Right);
		}
		
		if (BottomLeftHasHit(x,y,y_size, map) == true)
		{
			if (HitVectorJudge(x,y, DownLeft) == Up)
			{
				CoordinateCorrection(x, x_size, y, y_size, Up);
			}
			else if(HitVectorJudge(x,y, DownLeft) == Right)
			{
				CoordinateCorrection(x, x_size, y, y_size, Right);
			}
			else if (HitVectorJudge(x,y, DownLeft) == DownLeft)
			{
				CoordinateCorrection(x, x_size, y, y_size, DownLeft);
			}
		}
	}

	if (save_char_move_direction[X] == Right)
	{
		CoordinateCorrection(x, x_size, y, y_size, Right);
	}
	else if (save_char_move_direction[X] == Left)
	{
		CoordinateCorrection(x, x_size, y, y_size, Left);
	}

	if (save_char_move_direction[Y] == Up)
	{
		CoordinateCorrection(x, x_size, y, y_size, Up);
	}
	else if (save_char_move_direction[Y] == Down)
	{
		CoordinateCorrection(x,x_size,y,y_size, Down);
	}

}

void Collision::CoordinateCorrection(int x,int x_size,int y,int y_size, int char_move_direction)
{
	switch (char_move_direction)
	{
	case Up: // 当たり判定はブロックのBottom

		y = (y / chip_size_) * chip_size_ + chip_size_;

		break;

	case Down:// 当たり判定はブロックのTop

		y = (y / chip_size_) * chip_size_ - y_size;

		break;

	case Right: // 当たり判定はブロックのLeft

		x = (x / chip_size_) * chip_size_ - x_size;

		break;

	case Left: // 当たり判定はブロックのRight

		x = (x / chip_size_) * chip_size_ + chip_size_;

		break;

	case UpRight:

		//							元の座標 / チップサイズ * チップサイズ - キャラテクスチャの幅
		x = (x / chip_size_ ) * chip_size_;
		y = (y / chip_size_ + 1) * chip_size_;

		break;

	case UpLeft:

		x = (x / chip_size_ + 1) * chip_size_;
		y = (y / chip_size_ + 1) * chip_size_;

		break;

	case DownRight:

		x = (x / chip_size_) * chip_size_;
		y = (y / chip_size_) * chip_size_;

		break;

	case DownLeft:
		
		x = (x / chip_size_ + 1) * chip_size_;
		y = (y / chip_size_) * chip_size_;

		break;
	}


};


bool Collision::TopRightHasHit(int x,int x_size,int y, int** map)
{
	if (CheckMapNumber((x + x_size), y, map) == Road)
	{
		return true;
	}

	return false;
}

bool Collision::TopLeftHasHit(int x,int y, int** map)
{
	if (CheckMapNumber(x, y, map) == Road)
	{
		return true;
	}

	return false;
}

bool Collision::BottomRightHasHit(int x,int x_size,int y,int y_size, int** map)
{
	if (CheckMapNumber((x + x_size), (y + y_size), map) == Road)
	{
		return true;
	}

	return false;
}

bool Collision::BottomLeftHasHit(int x,int y,int y_size, int** map)
{
	if (CheckMapNumber(x,(y + y_size), map) == Road)
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


