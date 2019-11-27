#include "Character.h"

void Hero::Initialize()
{
	position =
	{
		CoordinateX(500.f),
		CoordinateY(500.f)
	};

	size =
	{
		Width(64.f),
		Height(128.f)
	};

	uv =
	{
		TextureU(0.0f),
		TextureV(0.0f)
	};
	texture_size =
	{
		Width(1.0f),
		Height(1.0f)
	};

	texture_name = TextureName("Player");
	degree = Degree(0);
	zoom = Zoom(1.0);
	is_reverse = IsReverse(false);
}

void Hero::Update() {
	if (dx.GetKeyState(DIK_D) == dx.ON) {
		vec.x.value += 1.0f;
	}
	if (dx.GetKeyState(DIK_A) == dx.ON) {
		vec.x.value -= 1.0f;
	}
}
