#include "Collision.h"

int Collision::CheckMapNumber(float* x, float* y, int** map)
{
	int X = *x / chip_size_;
	int Y = *y / chip_size_;
	
	int map_number = map[Y][X];

	return map_number;
	
}

Direction Collision::VerticalDirectionCheck(float* x,int previous_x)
{
	// Xの移動量
	vec_x = *x - previous_x;

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

 Direction Collision::HorizontalDirectionCheck(float* y, int previous_y)
 {
	 // Yの移動量
	 vec_y = *y - previous_y;

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

 Direction Collision::DirectionCheck(float* x, float* y, int previous_x, int previous_y)
 {
	 save_char_move_direction[X] = VerticalDirectionCheck(x, previous_x);
	 save_char_move_direction[Y] = HorizontalDirectionCheck(y, previous_y);

	 if (save_char_move_direction[X] == Right && save_char_move_direction[Y] == Up)
	 {
		 return Direction::UpRight;
	 }
	 else if (save_char_move_direction[X] == Right && save_char_move_direction[Y] == Down)
	 {
		 return Direction::DownRight;
	 }

	 if (save_char_move_direction[X] == Left && save_char_move_direction[Y] == Up)
	 {
		 return Direction::UpLeft;
	 }
	 else if (save_char_move_direction[X] == Left && save_char_move_direction[Y] == Down)
	 {
		 return Direction::DownLeft;
	 }

	 if (save_char_move_direction[X] == Left)
	 {
		 return Direction::Left;
	 }
	 else if (save_char_move_direction[X] == Right)
	 {
	 }

	 if (save_char_move_direction[Y] == Up)
	 {
		 return Direction::Up;
	 }
	 else if (save_char_move_direction[Y] == Down)
	 {
		 return Direction::Down;
	 }


	 return Direction::Stop;
 }

void Collision::ブロックとの(float* x, float* x_size, float* y, float* y_size, float previous_x, float previous_y, int** map)
{
	{
		値の修正呼出し(x,x_size,y,y_size,previous_x,previous_y,map);
	}

}

{
	switch (DirectionCheck(x,y,previous_x,previous_y))
	{
	case Up:

		if (TopRightHasHit(x, x_size, y, map,Up) == true || TopLeftHasHit(x, y, map,Up) == true)
		{
			return true;
		}

		break;

	case Down:
		
		if (BottomRightHasHit(x, x_size, y, y_size, map,Down) == true || BottomLeftHasHit(x, y,x_size, y_size, map,Down) == true)
		{
			return true;
		}

		break;
	
	case Right:

		if (BottomRightHasHit(x, x_size, y, y_size, map,Right) == true || TopRightHasHit(x, x_size, y, map,Right) == true)
		{
			return true;
		}

		break;

	case Left:

		if (TopLeftHasHit(x, y, map,Left) == true || BottomLeftHasHit(x, y,x_size, y_size, map,Left) == true)
		{
			return true;
		}

		break;

	case UpRight:

		if (TopLeftHasHit(x, y, map,Up) == true || BottomRightHasHit(x, x_size, y, y_size, map,Right) == true || TopRightHasHit(x, x_size, y, map,UpRight) == true)
		{
			return true;
		}

		break;

	case DownRight:

		if (TopRightHasHit(x, x_size, y, map,Right) == true || BottomLeftHasHit(x, y, x_size, y_size, map,Down) == true || BottomRightHasHit(x, x_size, y, y_size, map,DownRight) == true)
		{
			return true;
		}

		break;

	case UpLeft:

		if (TopRightHasHit(x, x_size, y, map,Up) == true || BottomLeftHasHit(x, y, x_size, y_size, map,Left) == true || TopLeftHasHit(x, y, map,UpLeft) == true)
		{
			return true;
		}

		break;

	case DownLeft:

		if (BottomRightHasHit(x, x_size, y, y_size, map,Down) == true || TopLeftHasHit(x, y, map,Left) == true || BottomLeftHasHit(x, y, x_size, y_size, map,DownLeft) == true)
		{
			return true;
		}

		break;
	}
    
	return false;

}

bool Collision::値の修正呼出し(float* x, float* x_size, float* y, float* y_size, float previous_x, float previous_y, int** map)
{
	if (DirectionCheck(x, y, previous_x, previous_y) == UpRight)
	{
		{
			CoordinateCorrect(x, x_size, y, y_size, Up);
		}

		{
			CoordinateCorrect(x, x_size, y, y_size, Right);
		}

		{
			if (HitVectorJudge(x, y, x_size, y_size, UpRight) == Down)
			{
				CoordinateCorrect(x, x_size, y, y_size, Up);
			}
			else if (HitVectorJudge(x, y, x_size, y_size, UpRight) == Left)
			{
				CoordinateCorrect(x, x_size, y, y_size, Right);
			}
			else if (HitVectorJudge(x, y, x_size, y_size, UpRight) == UpRight)
			{
				CoordinateCorrect(x, x_size, y, y_size, UpRight);
			}
		}

		return true;

	} else if (DirectionCheck(x, y, previous_x, previous_y) == DownRight)
	{
		{
			CoordinateCorrect(x, x_size, y, y_size, Right);
		}

		{
			CoordinateCorrect(x, x_size, y, y_size, Down);
		}

		{
			{
				CoordinateCorrect(x, x_size, y, y_size, Down);
			}
			{
				CoordinateCorrect(x, x_size, y, y_size, Right);
			}
			{
				CoordinateCorrect(x, x_size, y, y_size, DownRight);
			}

		}

		return true;

	if (DirectionCheck(x, y, previous_x, previous_y) == UpLeft)
	{
		{
			CoordinateCorrect(x, x_size, y, y_size, Up);
		}

		{
			CoordinateCorrect(x, x_size, y, y_size, Left);
		}

		{
			{
				CoordinateCorrect(x, x_size, y, y_size, Up);
			}
			{
				CoordinateCorrect(x, x_size, y, y_size, Left);
			}
			else if (HitVectorJudge(x, y, x_size, y_size, UpLeft) == UpLeft)
			{
				CoordinateCorrect(x, x_size, y, y_size,UpLeft);
			}
		}

		return true;
	}
	else if (DirectionCheck(x, y, previous_x, previous_y) == DownLeft)
	{

		{
			CoordinateCorrect(x, x_size, y, y_size, Down);
		}

		{
			CoordinateCorrect(x, x_size, y, y_size, Left);
		}
		
		{
			{
				CoordinateCorrect(x, x_size, y, y_size, Down);
			}
			{
				CoordinateCorrect(x, x_size, y, y_size, Left);
			}
			{
				CoordinateCorrect(x, x_size, y, y_size, DownLeft);
			}
		}
		return true;

	if (DirectionCheck(x, y, previous_x, previous_y) == Right)
	{
		CoordinateCorrect(x, x_size, y, y_size, Right);

		return true;
	}
	else if (DirectionCheck(x, y, previous_x, previous_y) == Left)
	{
		CoordinateCorrect(x, x_size, y, y_size, Left);

		return true;

	if (DirectionCheck(x, y, previous_x, previous_y) == Up)
	{
		CoordinateCorrect(x, x_size, y, y_size, Up);

		return true;
	}
	else if (DirectionCheck(x, y, previous_x, previous_y) == Down)
	{
		CoordinateCorrect(x,x_size,y,y_size, Down);

		return true;
	}


	return false;
}

void Collision::CoordinateCorrect(float* x, float* x_size, float* y, float* y_size, int char_move_direction)
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


{

	{

		break;
	}

	return false;
}

{

	{
	}

	return false;
}

{

	{
	}

	return false;
}

{

	{
	}
	return false;
}

int Collision::HitVectorJudge(float* X, float* Y,float* X_size, float* Y_size, int move_deflection)
{
	float x, y;


	switch (move_deflection)
	{
	case UpRight:


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


