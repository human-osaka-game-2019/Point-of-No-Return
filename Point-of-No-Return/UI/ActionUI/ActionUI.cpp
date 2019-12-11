#include"../ActionUI/ActionUI.h"
#include "../../Character.h"

namespace ActionUI
{

	// ----------- ItemUI ---------------------------------------------------------------------------------------------------------

	void ItemUI::Initialize()
	{
		position =
		{
			CoordinateX(576 + 48),
			CoordinateY(0)
		};

		size =
		{
			Width(64 * 10),
			Height(64 * 2)
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

	void GoldUI::Initialize()
	{
		position =
		{
			CoordinateX(1920 - 480),
			CoordinateY(14)
		};

		size =
		{
			Width(480),
			Height(100)
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

	void GoldUI::Draw()
	{
		dx.DrawEx(position.x.value, position.y.value, 0, size.width.value, size.height.value, degree.value, zoom.value, is_reverse.value, texture_name.value, uv.tu.value, uv.tv.value, texture_size.width.value, texture_size.height.value);

		moneyIcon.Draw();
	}

    void GoldUI::Update(const Gold& gold)
	{

	}

	void GoldUI::MoneyIcon::Initialize()
	{
		position =
		{
			CoordinateX(1920 - 608),
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

	void GoldUI::MoneyIcon::Draw()
	{
		dx.DrawEx(position.x.value, position.y.value, 0, size.width.value, size.height.value, degree.value, zoom.value, is_reverse.value, texture_name.value, uv.tu.value, uv.tv.value, texture_size.width.value, texture_size.height.value);
	}

	// ----------- HpGauge ---------------------------------------------------------------------------------------------------------

	void HpGauge::Initialize(Hero& hero)
	{
		hpBar.Initialize();
		hpFrame.Initialize();
		hero.AddHpChangeObserver(&hpBar);
	}

	void HpGauge::Draw()
	{
		hpFrame.Draw();
		hpBar.Draw();
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
			Width(MAX_WIDTH),
			Height(HEIGHT)
		};

		float tv = 50.f / 514.f;

		uv =
		{
			TextureU(0),
			TextureV(tv)
		};

		float tu_width = 576.f / 2048.f;
		float tv_height = 48.f / 514.f;

		texture_size =
		{
			Width(tu_width),
			Height(tv_height)
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

	void HpGauge::HpBar::Update(const HP& hp)
	{
		size.width.value = (MAX_WIDTH / hp.max_value) * hp.value;
	}

	// ----------- MpGauge ---------------------------------------------------------------------------------------------------------

	void MpGauge::Initialize(Hero& hero)
	{
		mpFrame.Initialize();
		mpBar.Initialize();
		hero.AddMpChangeObserver(&mpBar);
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
			Width(64 * 9),
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
			Width(MAX_WIDTH),
			Height(HEIGHT)
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

	void MpGauge::MpBar::Update(const MP& mp)
	{
		size.width.value = (MAX_WIDTH / mp.max_value) * mp.value;
	}

	// ----------- IpGauge ---------------------------------------------------------------------------------------------------------

	void IpGauge::Initialize(Hero& hero)
	{
		ipFrame.Initialize();
		ipBar.Initialize();
		hero.AddIpChangeObserver(&ipBar);
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
			Width(MAX_WIDTH),
			Height(HEIGHT)
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

	void IpGauge::IpBar::Update(const IP& ip)
	{
		size.width.value = (MAX_WIDTH / ip.max_value) * ip.value;
	}

}
