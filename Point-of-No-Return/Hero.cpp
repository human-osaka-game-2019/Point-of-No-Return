#include "Hero.h"

#include "Main.h"
#include "Mapchip.h"


namespace
{
	const int DISPLAY_SIZE_WIDTH = 30;
	const float WINDOW_CENTER_X = Display::DISPLAY_WIDTH / 2;
	const float MIN_OFFSET_X = 0;
	const float MAX_OFFSET_X = (Mapchip::WORLD_SIZE_WIDTH - DISPLAY_SIZE_WIDTH) * Mapchip::CHIP_SIZE;
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
		TextureU(0.0f),
		TextureV(0.0f)
	};

	texture_size =
	{
		Width(1.0f),
		Height(1.0f)
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
	degree = Degree(0);
	zoom = Zoom(1.0);
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
		if (position.x <= CoordinateX(WINDOW_CENTER_X) || 
			(CoordinateX(WINDOW_CENTER_X) < position.x && offset.x == CoordinateX(MAX_OFFSET_X)) && position.x + size.width < Display::DISPLAY_WIDTH)
		{
			position.x += CoordinateX(10.0f);
		}
		else
		{
			offset.x += CoordinateX(10.0f);
		}
		if (CoordinateX(MAX_OFFSET_X) < offset.x)
		{
			offset.x = CoordinateX(MAX_OFFSET_X);
		}
	}

	if (dx.GetKeyState(DIK_A) == dx.ON)
	{
		// TODO: if文の長さはリファクタリング時に変数化したりします。
		if (position.x + size.width >= WINDOW_CENTER_X ||
			(position.x + size.width < WINDOW_CENTER_X && offset.x == CoordinateX(MIN_OFFSET_X)) && CoordinateX(MIN_OFFSET_X) < position.x)
		{
			position.x -= CoordinateX(10.0f);
		}
		else
		{
			offset.x -= CoordinateX(10.0f);
		}
		if (offset.x < CoordinateX(0))
		{
			offset.x = CoordinateX(0);
		}
	}

	// ----------------------------------------------
	if (dx.GetKeyState(DIK_W) == dx.ON)
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

