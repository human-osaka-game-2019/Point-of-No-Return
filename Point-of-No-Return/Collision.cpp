#include "Collision.h"

int Collision::CheckMapNumber(float* x, float* y, int** map)
{
	int X = *x / chip_size_;
	int Y = *y / chip_size_;
	
	int map_number = map[Y][X];
	return map_number;
	
}

Direction Collision::VerticalDirectionCheck(float* x,int before_x)
{
	// Xの移動量
	vec_x = *x - before_x;

	if (vec_x < 0)
	{
		return Direction::Left;
	}
	else if (vec_x > 0)
	{
		return Direction::Right;
	}

	return Direction::Stop;
}

 Direction Collision::HorizontalDirectionCheck(float* y, int before_y)
 {
	 // Yの移動量
	 vec_y = *y - before_y;

	 if (vec_y < 0)
	 {
		 return Direction::Up;
	 }
	 else if (vec_y > 0)
	 {
		 return Direction::Down;
	 }
	 
	 return Direction::Stop;
 }
 
void Collision::ブロックとの(float* x, float* x_size, float* y, float* y_size, float before_x, float before_y, int** map)
{
	if (HitPointCheck(x,x_size,y,y_size, map) == true)
	{
		DirectionCheck(x,x_size,y,y_size,before_x,before_y,map);
	}

}

bool Collision::HitPointCheck(float* x, float* x_size, float* y , float* y_size,int** map)
{
	//	右上 左上 右下 左下
	if (TopRightHasHit(x, x_size, y, map) == true || TopLeftHasHit(x,y,map) == true || BottomRightHasHit(x, x_size, y, y_size, map) == true || BottomLeftHasHit(x, y, y_size, map) == true)
	{	
		return true;
	}
    
	return false;

}

void Collision::DirectionCheck(float* x, float* x_size, float* y, float* y_size, float before_x, float before_y, int** map)
{

	save_char_move_direction[X] = VerticalDirectionCheck(x,before_x);
	save_char_move_direction[Y] = HorizontalDirectionCheck(y,before_y);

	if (save_char_move_direction[X] == Right && save_char_move_direction[Y] == Up)
	{
		if (TopLeftHasHit(x,y, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Up);
		}

		if (BottomRightHasHit(x,x_size,y,y_size, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Right);
		}
		
		if (TopRightHasHit(x,x_size,y, map) == true)
		{
			if (HitVectorJudge(x, y,x_size,y_size,UpRight) == Down)
			{
				CoordinateCorrection(x, x_size, y, y_size, Up);
			}
			else if(HitVectorJudge(x,y, x_size, y_size, UpRight) == Left)
			{
				CoordinateCorrection(x, x_size, y, y_size, Right);
			}
			else if(HitVectorJudge(x,y, x_size, y_size, UpRight) == UpRight)
			{
				CoordinateCorrection(x, x_size, y, y_size, UpRight);
			}
		}

		//return true;
	}
	else if (save_char_move_direction[X] == Right && save_char_move_direction[Y] == Down)
	{
		if (TopRightHasHit(x,x_size,y, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Right);
		}

		if (BottomLeftHasHit(x, y, y_size, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Down);
		}

		if (BottomRightHasHit(x, x_size, y, y_size, map) == true)
		{
			if (HitVectorJudge(x,y, x_size, y_size, DownRight) == Up)
			{
				CoordinateCorrection(x, x_size, y, y_size, Down);
			}
			else if (HitVectorJudge(x,y, x_size, y_size, DownRight) == Left)
			{
				CoordinateCorrection(x, x_size, y, y_size, Right);
			}
			else if (HitVectorJudge(x,y, x_size, y_size, DownRight) == DownRight)
			{
				CoordinateCorrection(x, x_size, y, y_size, DownRight);
			}

		}

		//return true;
	}

	if (save_char_move_direction[X] == Left && save_char_move_direction[Y] == Up)
	{
		if (TopRightHasHit(x,x_size,y, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Up);
		}

		if (BottomLeftHasHit(x, y, y_size, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Left);
		}

		if (TopLeftHasHit(x,y, map) == true)
		{
			if (HitVectorJudge(x,y, x_size, y_size, UpLeft) == Down)
			{
				CoordinateCorrection(x, x_size, y, y_size, Up);
			}
			else if (HitVectorJudge(x,y, x_size, y_size, UpLeft) == Right)
			{
				CoordinateCorrection(x, x_size, y, y_size, Left);
			}
			else if (HitVectorJudge(x, y, x_size, y_size, UpLeft) == UpLeft)
			{
				CoordinateCorrection(x, x_size, y, y_size,UpLeft);
			}
		}

		//return true;
	}
	else if (save_char_move_direction[X] == Left && save_char_move_direction[Y] == Down)
	{

		if (BottomRightHasHit(x, x_size, y, y_size, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Down);
		}

		if (TopLeftHasHit(x,y, map) == true)
		{
			CoordinateCorrection(x, x_size, y, y_size, Left);
		}
		
		if (BottomLeftHasHit(x,y,y_size, map) == true)
		{
			if (HitVectorJudge(x,y, x_size, y_size, DownLeft) == Up)
			{
				CoordinateCorrection(x, x_size, y, y_size, Down);
			}
			else if(HitVectorJudge(x,y, x_size, y_size, DownLeft) == Right)
			{
				CoordinateCorrection(x, x_size, y, y_size, Left);
			}
			else if (HitVectorJudge(x,y, x_size, y_size, DownLeft) == DownLeft)
			{
				CoordinateCorrection(x, x_size, y, y_size, DownLeft);
			}
		}
		//return true;
	}

	if (save_char_move_direction[X] == Right)
	{
		CoordinateCorrection(x, x_size, y, y_size, Right);

		//return true;
	}
	else if (save_char_move_direction[X] == Left)
	{
		CoordinateCorrection(x, x_size, y, y_size, Left);

		//return true;
	}

	if (save_char_move_direction[Y] == Up)
	{
		CoordinateCorrection(x, x_size, y, y_size, Up);

		//return true;
	}
	else if (save_char_move_direction[Y] == Down)
	{
		CoordinateCorrection(x,x_size,y,y_size, Down);

		//return true;
	}


	//return false;
}

void Collision::CoordinateCorrection(float* x, float* x_size, float* y, float* y_size, int char_move_direction)
{
	switch (char_move_direction)
	{
	case Up: // 当たり判定はブロックのBottom

		*y = ((int)*y / chip_size_) * chip_size_ + chip_size_;

		break;

	case Down:// 当たり判定はブロックのTop

		*y = ((int)(*y + *y_size) / chip_size_) * chip_size_ - *y_size;

		break;

	case Right: // 当たり判定はブロックのLeft

		*x = ((int)(*x + *x_size)/ chip_size_) * chip_size_ - *x_size;

		break;

	case Left: // 当たり判定はブロックのRight

		*x = ((int)*x / chip_size_) * chip_size_ + chip_size_;

		break;

	case UpRight:

		//							元の座標 / チップサイズ * チップサイズ - キャラテクスチャの幅
		*x = (*x / chip_size_) * chip_size_;
		*y = (*y / chip_size_ + 1) * chip_size_;

		break;

	case UpLeft:

		*x = (*x / chip_size_ + 1) * chip_size_;
		*y = (*y / chip_size_ + 1) * chip_size_;

		break;

	case DownRight:

		*x = (*x / chip_size_) * chip_size_;
		*y = (*y / chip_size_) * chip_size_;

		break;

	case DownLeft:
		
		*x = (*x / chip_size_ + 1) * chip_size_;
		*y = (*y / chip_size_) * chip_size_;

		break;
	}


};


bool Collision::TopRightHasHit(float* x, float* x_size, float* y, int** map)
{
	float X = *x + *x_size - 1;

	if (CheckMapNumber(&X, y, map) == Road)
	{
		return true;
	}

	return false;
}

bool Collision::TopLeftHasHit(float* x,float* y, int** map)
{

	if (CheckMapNumber(x, y, map) == Road)
	{
		return true;
	}

	return false;
}

bool Collision::BottomRightHasHit(float* x,float* x_size,float* y,float* y_size, int** map)
{
	float X = *x + *x_size - 1;
	float Y = *y + *y_size - 1;

	if (CheckMapNumber(&X, &Y, map) == Road)
	{
		return true;
	}

	return false;
}

bool Collision::BottomLeftHasHit(float* x,float* y,float* y_size, int** map)
{
	float Y = *y + *y_size - 1;

	if (CheckMapNumber(x,&Y, map) == Road)
	{
		return true;
	}

	return false;
}

int Collision::HitVectorJudge(float* X, float* Y,float* X_size, float* Y_size, int move_deflection)
{
	float x, y;

	map_x = ((int)*X / chip_size_) * chip_size_;
	map_y = ((int)*Y / chip_size_) * chip_size_;

	switch (move_deflection)
	{
	case UpRight:

		x = ((*X - map_x) / *X_size) * 100;
		y = ((*Y - (map_y - chip_size_)) / *Y_size) * 100;

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

		x = (((map_x + chip_size_) - *X) / *X_size) * 100;
		y = ((*Y - (map_y - chip_size_)) / *Y_size) * 100;

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

		x = ((*X - map_x) / *X_size) * 100;
		y = ((*Y - map_y) / *Y_size) * 100;

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

		x = (((map_x + chip_size_) - *X) / *X_size) * 100;
		y = ((*Y - map_y) / *Y_size) * 100;

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


