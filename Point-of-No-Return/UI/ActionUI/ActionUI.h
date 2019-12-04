﻿#ifndef ACTIONUI_H
#define ACTIONUI_H

#include"../UI.h"

namespace ActionUI
{
	/**
	 * @brief BerBaseクラス
	 */
	class BarBase
	{
	public:

		DX::DirectX& dx = DX::DirectX::GetInstance();

		virtual void Initialize() {};
		virtual void UpDate() {};
		virtual void Draw() {};
		BarBase() {};
		virtual ~BarBase() {};


	protected:

		Vec2 position =
		{
			CoordinateX(0),
			CoordinateY(0)
		};

		Size size =
		{
			Width(0),
			Height(0)
		};

		TextureUV uv =
		{
			TextureU(0),
			TextureV(0)
		};

		TextureSize texture_size =
		{
			Width(0),
			Height(0)
		};

		TextureName texture_name = TextureName("Action");

		Degree degree = Degree(0);
		Zoom zoom = Zoom(0);
		IsReverse is_reverse = IsReverse(false);

	
	};

	/**
	 * @brief FrameBaseクラス
	 */
	class FrameBase
	{
	public:

		DX::DirectX& dx = DX::DirectX::GetInstance();

		virtual void Initialize() {};
		virtual void Draw() {};
		FrameBase() {};
		virtual ~FrameBase() {};

	protected:

		Vec2 position =
		{
			CoordinateX(0),
			CoordinateY(0)
		};

		Size size =
		{
			Width(0),
			Height(0)
		};

		TextureUV uv =
		{
			TextureU(0),
			TextureV(0)
		};

		TextureSize texture_size =
		{
			Width(0),
			Height(0)
		};

		TextureName texture_name = TextureName("Action");

		Degree degree = Degree(0);
		Zoom zoom = Zoom(0);
		IsReverse is_reverse = IsReverse(false);

	};

	/**
	 * @brief ItemIconBaseクラス
	 */
	class IconBase
	{
	public:

		DX::DirectX& dx = DX::DirectX::GetInstance();

		virtual void Initialize() {};
		virtual void Draw() {};

		IconBase() {};
		virtual ~IconBase() {};

	protected:

		Vec2 position =
		{
			CoordinateX(0),
			CoordinateY(0)
		};

		Size size =
		{
			Width(0),
			Height(0)
		};

		TextureUV uv =
		{
			TextureU(0),
			TextureV(0)
		};

		TextureSize texture_size =
		{
			Width(0),
			Height(0)
		};

		TextureName texture_name = TextureName("Action");

		Degree degree = Degree(0);
		Zoom zoom = Zoom(0);
		IsReverse is_reverse = IsReverse(false);


	};

	/**
	 * @brief ItemUIクラス
	 */
	class ItemUI : public GameUI
	{
	private:

		void Initialize();

	public:

		ItemUI()
		{
			Initialize();
		}

		~ItemUI() {};

		void Draw();

		void UpDate();

		IconBase ItemIcon;


	};

	/**
	 * @brief MoneyUIクラス
	 */
	class MoneyUI : public GameUI
	{
	public:

		MoneyUI() 
		{
			Initialize();
		}

		~MoneyUI() {};

		void Draw();

		class MoneyIcon : public IconBase
		{
		public:

			MoneyIcon()
			{
				Initialize();
			}

			~MoneyIcon() {}

			void Initialize();
			void Draw();
		
		};

	private:

		void Initialize();
		MoneyIcon moneyIcon;

	};

	/**
	 * @brief HpUIクラス
	 */
	class HpGauge : public GameUI
	{
	public:

		HpGauge() 
		{
			Initialize();
		};
		
		~HpGauge() {};

		class HpBar : public BarBase
		{
		public:

			void Initialize();
			void UpDate();
			void Draw();

		};

		class HpFrame : public FrameBase
		{
		public:

			void Initialize();
			void Draw();

		};

		void UpDate();
		void Draw();

	private:

		void Initialize();
		HpBar hpBar;
		HpFrame hpFrame;
	};

	/**
	 * @brief MpUIクラス
	 */
	class MpGauge : public GameUI
	{
	public:

		MpGauge() 
		{
			Initialize();
		};

		~MpGauge() {};

		class MpBar : public BarBase
		{
		public:

			void Initialize();
			void UpDate();
			void Draw();

		};

		class MpFrame : public FrameBase
		{
		public:

			void Initialize();
			void Draw();

		};

		void UpDate();
		void Draw();

	private:

		void Initialize();
		MpBar mpBar;
		MpFrame mpFrame;
	};

	/**
	 * @brief IpUIクラス
	 */
	class IpGauge : public GameUI
	{
	public:

		IpGauge() 
		{
			Initialize();
		};

		~IpGauge() {};

		class IpBar : public BarBase
		{
		public:

			void Initialize();
			void UpDate();
			void Draw();

		};

		class IpFrame : public FrameBase
		{
		public:

			void Initialize();
			void Draw();

		};

		void UpDate();
		void Draw();

	private:

		void Initialize();

		IpFrame ipFrame;
		IpBar ipBar;
		

	};

}

#endif
