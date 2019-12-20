#include "Background.h"


namespace 
{
	float back_tu = 0.f;
	const float BACK_TV = 1920.f;
	const float SCROLL_SPEED = 2.f;
	const float BACK_MAX = 13440.f;
}


void Background::Update(const Character& character)
{
	bool rightscroll = true;
	

	if (isIdle(character,&rightscroll))
	{
		return;
	}

	ScrollBackground(rightscroll);
}


void Background::Draw()
{

	dx.DrawEx(0.f, 0.f, 0.f, 1920.f, 1080.f, 0.f, 1.f, 0.f, "game_back", back_tu / BACK_MAX, 0.f, BACK_TV / BACK_MAX, 1.f);

}


void Background::ScrollBackground(bool& rightscroll)
{
	if (rightscroll)
	{
		back_tu += SCROLL_SPEED;
		return;
	}

	back_tu -= SCROLL_SPEED;
}


bool Background::isIdle(const Character& character, bool* rightscroll)
{
	auto offset = character.GetOffset();
	auto previousOffset = character.GetPreviousOffset();

	if (offset.x < previousOffset.x)
	{
		*rightscroll = false;
		return false;
	}
	else if (previousOffset.x < offset.x)
	{
		*rightscroll = true;
		return false;
	}

	return true;
}



