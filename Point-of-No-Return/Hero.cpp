#include "Hero.h"

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
	const float MAX_OFFSET_X = (Mapchip::WORLD_HORIZONTAL_NUM - DISPLAY_SIZE_NUM) * Mapchip::CHIP_SIZE;
}


void Hero::Notify()
{
	if (previousStatus.hp.value != status.hp.value)
	{
		Character::HpChangeNotify(status.hp);
	}

	if (previousStatus.mp.value != status.mp.value)
	{
		Character::MpChangeNotify(status.mp);
	}

	if (previousStatus.ip.value != status.ip.value)
	{
		Character::IpChangeNotify(status.ip);
	}

	if (previousParameter.gold.value != parameter.gold.value)
	{
		Character::GoldChangeNotify(parameter.gold);
	}
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
		Width(192.f),
		Height(192.f)
	};

	uv =
	{
		TextureU(0.f),
		TextureV(0.f)
	};

	texture_size =
	{
		Width(1.f),
		Height(1.f)
	};

	status =
	{
		HP(100,100),
		MP(0,0),
		IP(0,0),
		Attack(0,0),
		Defense(0,0),
		Speed(0,0),
		MagicAttack(0,0)
	};

	texture_name = TextureName("Player");
	degree = Degree(0.f);
	zoom = Zoom(1.f);
	is_reverse = IsReverse(false);
}

void Hero::Update()
{
	Notify();
	
	previousPosition = position;
	previousOffset = offset;
    previousStatus = status;
	previousParameter = parameter;

	if (dx.GetKeyState(DIK_D) == dx.ON)
	{
		// TODO: if文の長さはリファクタリング時に変数化したりします。
		if (position.x <= CoordinateX(DISPLAY_CENTER_X) ||
			(CoordinateX(DISPLAY_CENTER_X) < position.x && offset.x == CoordinateX(MAX_OFFSET_X)) && position.x + size.width < Display::WIDTH)
		{
			position.x += CoordinateX(10.f);
		}
		else
		{
			offset.x += CoordinateX(10.f);
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
			position.x -= CoordinateX(10.f);
		}
		else
		{
			offset.x -= CoordinateX(10.f);
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

	// TODO : 動作確認用
	// -------------------------------------------
	if (dx.GetKeyState(DIK_LEFT) == dx.ON)
	{
		status.hp.value -= 1;
	}

	if (dx.GetKeyState(DIK_RIGHT) == dx.ON)
	{
		status.hp.value += 1;
	}

	if (dx.GetKeyState(DIK_DOWN) == dx.ON)
	{
		status.hp.max_value -= 1;
	}

	if (dx.GetKeyState(DIK_UP) == dx.ON)
	{
		status.hp.max_value += 1;
	}
	// --------------------------------------------


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

