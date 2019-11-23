#include "State.h"

bool State::Search(Vec2& player_pos, IsReverse& is_reverse)
{

	if (is_reverse.value == false)
	{

		search.left = enemy_pos.x.value;
		search.right = enemy_pos.x.value + (enemy_size.width.value + search.width);
		search.top = (enemy_pos.y.value - search.height);
		search.bottom = (enemy_pos.y.value + enemy_size.height.value);
		if (search.left <= player_pos.x.value && player_pos.x.value < search.right && search.top <= player_pos.y.value && player_pos.y.value <= search.bottom)
		{
			return true;
		}
	}
	else
	{

		search.left = (enemy_pos.x.value - search.width);
		search.right = (enemy_pos.x.value + enemy_size.width.value);
		search.top = (enemy_pos.y.value - search.height);
		search.bottom = (enemy_pos.y.value + enemy_size.height.value);
		if (search.left <= player_pos.x.value && search.right > player_pos.x.value && search.top <= player_pos.y.value && search.bottom > player_pos.y.value)
		{
			return true;
		}
	}


	return false;

}

State::State(): enemy_pos(0,0), enemy_size(0,0),search()
{

}

State::State(Vec2 &enemy_pos, const Size enemy_size):enemy_pos(enemy_pos.x.value,enemy_pos.x.value), enemy_size(enemy_size), search()
{

}

State::~State()
{

}

Stay::Stay(Vec2& enemy_pos, const Size enemy_size)
{

	this->enemy_pos = enemy_pos;
	
	this->enemy_size = enemy_size;

}

Stay::~Stay()
{

}

Chase::Chase(Vec2& enemy_pos, const Size enemy_size)
{

	this->enemy_pos = enemy_pos;

	this->enemy_size = enemy_size;

}

Chase::~Chase()
{

}