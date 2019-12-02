#include"../ActionUI/ActionUI.h"

namespace ActionUI
{

	//void Gauge::Update(State state)
	//{
	//	float value;

	//	Status status = hero.GetStatus();

	//	switch (state)
	//	{
	//	case State::HP:
	//		value = status.hp.value;
	//		break;
	//	case State::MP:
	//		value = status.mp.value;
	//		break;
	//	case State::IP:
	//		value = status.ip.value;
	//		break;
	//	default:
	//		break;
	//	}

	//	float drow_size = (size.width.value / 100) * value;


	//}

	void ItemUI::Initialize()
	{
		position =
		{
			CoordinateX(0),
			CoordinateY(0)
		};

		size =
		{
			Width(512),
			Height(128)
		};

		float tu = 130.f / 2048.f;
		float tv = 100.f / 514.f;

		uv =
		{
			TextureU(tu),
			TextureV(tv)
		};


		float tu_size = 642.f / 2048.f;
		float tv_size = 228.f / 514.f;

		texture_size =
		{
			Width(tu_size),
			Height(tv_size)
		};

		texture_name = TextureName("Action");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);
	}

	void MoneyUI::Initialize()
	{
		position =
		{
			CoordinateX(0),
			CoordinateY(0)
		};

		size =
		{
			Width(128),
			Height(128)
		};

		float tv = 100.f / 514.f;

		uv =
		{
			TextureU(0),
			TextureV(tv)
		};

		float tu_size = 128.f / 2048.f;
		float tv_size = 228.f / 2048.f;

		texture_size =
		{
			Width(tu_size),
			Height(tv_size)
		};

		texture_name = TextureName("Action");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);
	}

	void HpUI::Initialize()
	{
		position =
		{
			CoordinateX(0),
			CoordinateY(0)
		};

		size =
		{
			Width(576),
			Height(48)
		};

		uv =
		{
			TextureU(0),
			TextureV(0)
		};

		float tu_size = 576.f / 2048.f;
		float tv_size = 48.f / 514;

		texture_size =
		{
			Width(tu_size),
			Height(tv_size)
		};

		texture_name = TextureName("Action");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);

	}

	void MpUI::Initialize()
	{
		position =
		{
			CoordinateX(0),
			CoordinateY(48)
		};

		size =
		{
			Width(576),
			Height(48)
		};

		float tu = 578.f / 2048.f;

		uv =
		{
			TextureU(tu),
			TextureV(0)
		};

		float tu_size = 1154.f / 2048.f;
		float tv_size = 48.f / 514;

		texture_size =
		{
			Width(tu_size),
			Height(tv_size)
		};

		texture_name = TextureName("Action");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);
	}

	void IpUI::Initialize()
	{
		position =
		{
			CoordinateX(0),
			CoordinateY(96)
		};

		size =
		{
			Width(576),
			Height(48)
		};

		float tu = 1156.f / 2048.f;

		uv =
		{
			TextureU(tu),
			TextureV(0)
		};

		float tu_size = 1732.f / 2048.f;
		float tv_size = 48.f / 514;

		texture_size =
		{
			Width(tu_size),
			Height(tv_size)
		};

		texture_name = TextureName("Action");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);
	}
}
