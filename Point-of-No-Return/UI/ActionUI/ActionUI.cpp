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

	// ----------- ItemUI ---------------------------------------------------------------------------------------------------------

	void ItemUI::Initialize()
	{
		position =
		{
			CoordinateX(576),
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


		float tu_size = 512.f / 2048.f;
		float tv_size = 128.f / 514.f;

		texture_size =
		{
			Width(tu_size),
			Height(tv_size)
		};

		texture_name = TextureName("ActionUI");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);
	}

	void ItemUI::Draw()
	{
		dx.DrawEx(position.x.value, position.y.value, 0, size.width.value, size.height.value, degree.value, zoom.value, is_reverse.value, texture_name.value, uv.tu.value, uv.tv.value, texture_size.width.value, texture_size.height.value);
	}

	void ItemUI::UpDate()
	{

	}

	// ----------- MoneyUI ---------------------------------------------------------------------------------------------------------

	void MoneyUI::Initialize()
	{
		position =
		{
			CoordinateX(1188),
			CoordinateY(0)
		};

		size =
		{
			Width(416),
			Height(64)
		};

		float tu = 644.f / 2048.f;
		float tv = 100.f / 514.f;

		uv =
		{
			TextureU(tu),
			TextureV(tv)
		};

		float tu_size = 416.f / 2048.f;
		float tv_size = 64.f / 514.f;

		texture_size =
		{
			Width(tu_size),
			Height(tv_size)
		};

		texture_name = TextureName("ActionUI");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);
	}

	void MoneyUI::Draw()
	{
		dx.DrawEx(position.x.value, position.y.value, 0, size.width.value, size.height.value, degree.value, zoom.value, is_reverse.value, texture_name.value, uv.tu.value, uv.tv.value, texture_size.width.value, texture_size.height.value);

		moneyIcon.Draw();
	}

	void MoneyUI::MoneyIcon::Initialize()
	{
		position =
		{
			CoordinateX(1088),
			CoordinateY(0)
		};

		size =
		{
			Width(100),
			Height(100)
		};

		float tv = 100.f / 514.f;

		uv =
		{
			TextureU(0),
			TextureV(tv)
		};

		float tu_size = 128.f / 2048.f;
		float tv_size = 128.f / 514.f;

		texture_size =
		{
			Width(tu_size),
			Height(tv_size)
		};

		texture_name = TextureName("ActionUI");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);
	}

	void MoneyUI::MoneyIcon::Draw()
	{
		dx.DrawEx(position.x.value, position.y.value, 0, size.width.value, size.height.value, degree.value, zoom.value, is_reverse.value, texture_name.value, uv.tu.value, uv.tv.value, texture_size.width.value, texture_size.height.value);
	}

	// ----------- HpGauge ---------------------------------------------------------------------------------------------------------

	void HpGauge::Initialize()
	{
		hpBar.Initialize();
		hpFrame.Initialize();
	}

	void HpGauge::UpDate()
	{
		hpBar.UpDate();
	}

	void HpGauge::Draw()
	{
		hpBar.Draw();
		hpFrame.Draw();
	}

	void HpGauge::HpFrame::Initialize()
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

		texture_name = TextureName("ActionUI");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);

	}

	void HpGauge::HpFrame::Draw()
	{
		dx.DrawEx(position.x.value, position.y.value, 0, size.width.value, size.height.value, degree.value, zoom.value, is_reverse.value, texture_name.value, uv.tu.value, uv.tv.value, texture_size.width.value, texture_size.height.value);
	}

	void HpGauge::HpBar::Initialize()
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

		float tv = 50.f / 514.f;

		uv =
		{
			TextureU(0),
			TextureV(tv)
		};

		float tu_size = 576.f / 2048.f;
		float tv_size = 48.f / 514.f;

		texture_size =
		{
			Width(tu_size),
			Height(tv_size)
		};

		texture_name = TextureName("ActionUI");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);
	}

	void HpGauge::HpBar::Draw()
	{
		dx.DrawEx(position.x.value, position.y.value, 0, size.width.value, size.height.value, degree.value, zoom.value, is_reverse.value, texture_name.value, uv.tu.value, uv.tv.value, texture_size.width.value, texture_size.height.value);
	}

	void HpGauge::HpBar::UpDate()
	{
		// float drow_size = (size.width.value / 100) * status.hp.value;
	}

	// ----------- MpGauge ---------------------------------------------------------------------------------------------------------

	void MpGauge::Initialize()
	{
		mpFrame.Initialize();
		mpBar.Initialize();
	}

	void MpGauge::UpDate()
	{
		mpBar.UpDate();
	}

	void MpGauge::Draw()
	{
		mpBar.Draw();
		mpFrame.Draw();
	}

	void MpGauge::MpFrame::Initialize()
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

		float tu_size = 576.f / 2048.f;
		float tv_size = 48.f / 514;

		texture_size =
		{
			Width(tu_size),
			Height(tv_size)
		};

		texture_name = TextureName("ActionUI");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);
	}

	void MpGauge::MpFrame::Draw()
	{
		dx.DrawEx(position.x.value, position.y.value, 0, size.width.value, size.height.value, degree.value, zoom.value, is_reverse.value, texture_name.value, uv.tu.value, uv.tv.value, texture_size.width.value, texture_size.height.value);
	}

	void MpGauge::MpBar::Initialize()
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
		float tv = 50.f / 514.f;

		uv =
		{
			TextureU(tu),
			TextureV(tv)
		};

		float tu_size = 576.f / 2048.f;
		float tv_size = 48.f / 514.f;

		texture_size =
		{
			Width(tu_size),
			Height(tv_size)
		};

		texture_name = TextureName("ActionUI");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);
	}

	void MpGauge::MpBar::Draw()
	{
		dx.DrawEx(position.x.value, position.y.value, 0, size.width.value, size.height.value, degree.value, zoom.value, is_reverse.value, texture_name.value, uv.tu.value, uv.tv.value, texture_size.width.value, texture_size.height.value);
	}

	void MpGauge::MpBar::UpDate()
	{
		// float drow_size = (size.width.value / 100) * status.mp.value;
	}

	// ----------- IpGauge ---------------------------------------------------------------------------------------------------------

	void IpGauge::Initialize()
	{
		ipFrame.Initialize();
		ipBar.Initialize();
	}

	void IpGauge::UpDate()
	{
		ipBar.UpDate();
	}

	void IpGauge::Draw()
	{
		ipBar.Draw();
		ipFrame.Draw();
	}

	void IpGauge::IpFrame::Initialize()
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

		float tu_size = 576.f / 2048.f;
		float tv_size = 48.f / 514;

		texture_size =
		{
			Width(tu_size),
			Height(tv_size)
		};

		texture_name = TextureName("ActionUI");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);
	}

	void IpGauge::IpFrame::Draw()
	{
		dx.DrawEx(position.x.value, position.y.value, 0, size.width.value, size.height.value, degree.value, zoom.value, is_reverse.value, texture_name.value, uv.tu.value, uv.tv.value, texture_size.width.value, texture_size.height.value);
	}

	void IpGauge::IpBar::Initialize()
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
		float tv = 50.f / 514.f;

		uv =
		{
			TextureU(tu),
			TextureV(tv)
		};

		float tu_size = 576.f / 2048.f;
		float tv_size = 48.f / 514;

		texture_size =
		{
			Width(tu_size),
			Height(tv_size)
		};

		texture_name = TextureName("ActionUI");
		degree = Degree(0);
		zoom = Zoom(1.0);
		is_reverse = IsReverse(false);
	}

	void IpGauge::IpBar::Draw()
	{
		dx.DrawEx(position.x.value, position.y.value, 0, size.width.value, size.height.value, degree.value, zoom.value, is_reverse.value, texture_name.value, uv.tu.value, uv.tv.value, texture_size.width.value, texture_size.height.value);
	}

	void IpGauge::IpBar::UpDate()
	{
		// float drow_size = (size.width.value / 100) * status.ip.value;
	}

}
