#include "Character.h"
#include <vector>
#include "Mapchip.h"

void Hero::Initialize() {
	vec = { 500.f, 500.f };
	size = { 100.f,100.f };
	uv = { 0.0f,0.0f };
	texture_size = { 1.0f, 1.0f };
	texture_name = {"Player"};
	degree = 0;
	zoom = 1.0;
	is_reverse = false;
}

void Hero::InputBefore()
{
	previous_x = x;
	previous_y = y;
}


void Hero::Update() {
	if (dx.GetKeyState(DIK_D) == dx.ON) {
		vec.x.value += 1.0f;
	}
	if (dx.GetKeyState(DIK_A) == dx.ON) {
		vec.x.value -= 1.0f;
    }
}

void Hero::HitBlock(Hero* hero, std::vector<Vec2> vec2)
{	
    int number = 0;
	float vector_x = hero->previous_x - hero->x;
	float vector_y = hero->previous_y - hero->y;

	for (auto i = vec2.begin(); i != vec2.end(); i++) 
	{
		//
		if ((vec2[number].x.value < hero->x + hero->x_size) &&
			(hero->x < vec2[number].x.value + chip_size) &&
			(vec2[number].y.value < hero->y + hero->y_size) &&
			(hero->y < vec2[number].y.value + chip_size))
		{
			if ((hero->previous_y + hero->y_size <= vec2[number].y.value) || (hero->previous_y >= vec2[number].y.value + chip_size))
			{
				if (vector_y < 0)
				{
					hero->y = vec2[number].y.value - hero->y_size;
				}
				else if (vector_y > 0)
				{
					hero->y = vec2[number].y.value + chip_size;
				}
			}
			else
			{
				if (vector_x < 0)
				{
					hero->x = vec2[number].x.value - hero->x_size;
				}
				else if (vector_x > 0)
				{
					hero->x = vec2[number].x.value + chip_size;
				}
			}
		}
		number++;
	}
}

