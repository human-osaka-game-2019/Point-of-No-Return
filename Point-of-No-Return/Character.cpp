#include "Character.h"

#include <vector>

#include "Mapchip.h"

void Hero::Initialize() 
{
	position = { 500.f, 500.f };
	size = { 64.f,128.f };
	uv = { 0.0f,0.0f };
	texture_size = { 1.0f, 1.0f };
	texture_name = {"Player"};
	degree = 0;
	zoom = 1.0;
	is_reverse = false;
}

void Hero::Update() 
{
	previous = position;

	if (dx.GetKeyState(DIK_D) == dx.ON)
	{
		position.x.value += 10.0f;
	}

	if (dx.GetKeyState(DIK_A) == dx.ON)
	{
		position.x.value -= 10.0f;
	}

	if (dx.GetKeyState(DIK_W) == dx.ON)
	{
		position.y.value -= 10.0f;
	}

	if (dx.GetKeyState(DIK_S) == dx.ON)
	{
		position.y.value += 10.0f;

	}
}

//void Hero::HitBlock(std::vector<Vec2> vec2)
//{	
//	float vector_x = previous.x.value - vec.x.value;
//	float vector_y = previous.y.value - vec.y.value;
//
//	for (int i = 0; i < vec2.size(); i++) 
//	{
//		//
//		if ((vec2[i].x.value < vec.x.value + size.width.value) &&
//			(vec.x.value < vec2[i].x.value + CHIP_SIZE) &&
//			(vec2[i].y.value < vec.y.value + size.height.value) &&
//			(vec.y.value < vec2[i].y.value + CHIP_SIZE))
//		{
//			if ((previous.y.value + size.height.value <= vec2[i].y.value) || (previous.y.value >= vec2[i].y.value + CHIP_SIZE))
//			{
//				if (vector_y < 0)
//				{
//					vec.y.value = vec2[i].y.value - size.height.value;
//				}
//				else if (vector_y > 0)
//				{
//					vec.y.value = vec2[i].y.value + CHIP_SIZE;
//				}
//			}
//			else
//			{
//				if (vector_x < 0)
//				{
//					vec.x.value = vec2[i].x.value - size.width.value;
//				}
//				else if (vector_x > 0)
//				{
//					vec.x.value = vec2[i].x.value + CHIP_SIZE;
//				}
//			}
//		}
//	}
//}

void Hero::CorrectCoordinate(Direction direction, const Vec2& blockPosition)
{
	switch (direction)
	{
	case Direction::Up:
		position.y.value = blockPosition.y.value - size.height.value;
		break;			  
	case Direction::Down:
		position.y.value = blockPosition.y.value + Mapchip::CHIP_SIZE;
		break;			  
	case Direction::Left:
		position.x.value = blockPosition.x.value - size.width.value;
		break;			  
	case Direction::Right:
		position.x.value = blockPosition.x.value + Mapchip::CHIP_SIZE;
		break;
	default:

		break;
	}
}

