#include "Character.h"
#include <vector>
#include "Mapchip.h"

void Hero::Initialize() {
	vec = { 500.f, 500.f };
	size = { 64.f,128.f };
	uv = { 0.0f,0.0f };
	texture_size = { 1.0f, 1.0f };
	texture_name = {"Player"};
	degree = 0;
	zoom = 1.0;
	is_reverse = false;
}

void Hero::InputBefore()
{
	previous.x.value = vec.x.value;
	previous.y.value = vec.y.value;
}


void Hero::Update() {
	if (dx.GetKeyState(DIK_D) == dx.ON) {
		vec.x.value += 1.0f;
	}
	if (dx.GetKeyState(DIK_A) == dx.ON) {
		vec.x.value -= 1.0f;
	}
	if (dx.GetKeyState(DIK_D) == dx.ON)
	{
		vec.x.value += 3.0f;
	}

	if (dx.GetKeyState(DIK_A) == dx.ON)
	{
		vec.x.value -= 3.0f;
	}

	if (dx.GetKeyState(DIK_W) == dx.ON)
	{
		vec.y.value -= 3.0f;
	}

	if (dx.GetKeyState(DIK_S) == dx.ON)
	{
		vec.y.value += 3.0f;

	}
}

void Hero::HitBlock(std::vector<Vec2> vec2)
{	
	float vector_x = previous.x.value - vec.x.value;
	float vector_y = previous.y.value - vec.y.value;

	for (int i = 0; i < vec2.size(); i++) 
	{
		//
		if ((vec2[i].x.value < vec.x.value + size.width.value) &&
			(vec.x.value < vec2[i].x.value + chip_size) &&
			(vec2[i].y.value < vec.y.value + size.height.value) &&
			(vec.y.value < vec2[i].y.value + chip_size))
		{
			if ((previous.y.value + size.height.value <= vec2[i].y.value) || (previous.y.value >= vec2[i].y.value + chip_size))
			{
				if (vector_y < 0)
				{
					vec.y.value = vec2[i].y.value - size.height.value;
				}
				else if (vector_y > 0)
				{
					vec.y.value = vec2[i].y.value + chip_size;
				}
			}
			else
			{
				if (vector_x < 0)
				{
					vec.x.value = vec2[i].x.value - size.width.value;
				}
				else if (vector_x > 0)
				{
					vec.x.value = vec2[i].x.value + chip_size;
				}
			}
		}
	}
}

