#include "Character.h"

#include <vector>

#include "Mapchip.h"

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

void Hero::Update()
{
	// 移動させる前に、現在の座標を退避させておく
	previous = position;

	// ひとまず移動
	Move();


}

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

void Hero::Move()
{
	// TODO: ここ、もうちょっと抽象化したい
	//		 HeroクラスがDirectInputKeyのようなlayerを意識すべきでは無い

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
