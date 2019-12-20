﻿#include "Hero.h"

#include "Main.h"
#include "Mapchip.h"

namespace
{
	//! Displayに入る横のブロックの個数
	const int DISPLAY_HORIZONTAL_NUM = 30;
	//! Displayの横の真ん中
	const float DISPLAY_CENTER_X = Display::WIDTH / 2.f;
	//! offsetの最小値
	const float MIN_OFFSET_X = 0.f;
	//! offsetの最大値
	const float MAX_OFFSET_X = (Mapchip::WORLD_HORIZONTAL_NUM - DISPLAY_HORIZONTAL_NUM) * Mapchip::CHIP_SIZE;
}

void Hero::Initialize()
{
	position =
	{
		CoordinateX(500.f),
		CoordinateY(500.f)
	};

	size =
	{
		Width(75.52f),
		Height(128.f)
	};

	uv =
	{
		TextureU(0.f),
		TextureV(0.f)
	};

	float tu_size = 190.f / 2048.f;
	float tv_size = 320.f / 1024.f;

	texture_size =
	{
		Width(tu_size),
		Height(tv_size)
	};

	time = Time(0);

	texture_name = TextureName("Player");
	degree = Degree(0.f);
	zoom = Zoom(1.f);
	is_reverse = IsReverse(false);
}

void Hero::Update()
{
	previousPosition = position;
	previousOffset = offset;

	if (dx.GetKeyState(DIK_D) == dx.ON)
	{
		// TODO: if文の長さはリファクタリング時に変数化したりします。
		if (position.x <= CoordinateX(DISPLAY_CENTER_X) ||
			(CoordinateX(DISPLAY_CENTER_X) < position.x && offset.x == CoordinateX(MAX_OFFSET_X)) && position.x + size.width < Display::WIDTH)
		{
			position.x += CoordinateX(3.f);
		}
		else
		{
			offset.x += CoordinateX(3.f);
		}
		if (CoordinateX(MAX_OFFSET_X) < offset.x)
		{
			offset.x = CoordinateX(MAX_OFFSET_X);
		}
	}

	if (dx.GetKeyState(DIK_A) == dx.ON)
	{
		// TODO: if文の長さはリファクタリング時に変数化したりします。
		if (position.x + size.width >= DISPLAY_CENTER_X ||
			(position.x + size.width < DISPLAY_CENTER_X && offset.x == CoordinateX(MIN_OFFSET_X)) && CoordinateX(MIN_OFFSET_X) < position.x)
		{
			position.x -= CoordinateX(3.f);
		}
		else
		{
			offset.x -= CoordinateX(3.f);
		}

		if (offset.x < CoordinateX(0.f))
		{
			offset.x = CoordinateX(0.f);
		}
	}

	if (dx.GetKeyState(DIK_W) == dx.PUSH)
	{
		gravity.Jump();
	}
	gravity.Apply();

}

void Hero::CorrectCoordinate(Direction direction, const Position& blockPosition)
{
	switch (direction)
	{
	case Direction::Up:
		position.y.value = blockPosition.y.value - size.height.value;
		gravity.AccelerationReset();
		gravity.JumpReset();
		break;
	case Direction::Down:
		position.y.value = blockPosition.y.value + Mapchip::CHIP_SIZE;
		gravity.AccelerationReset();
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

