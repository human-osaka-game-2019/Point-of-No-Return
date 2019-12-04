#ifndef ACTIONUI_H
#define ACTIONUI_H

#include"../UI.h"

namespace ActionUI
{
	enum class State
	{
		HP,
		MP,
		IP
	};

	/**
	 * @brief BerBaseクラス
	 */
	class BarBase
	{
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

	public:

		DX::DirectX& dx = DX::DirectX::GetInstance();

		virtual void Initialize() {};
		virtual void UpDate() {};
		virtual void Draw() {};
		BarBase() {};
		virtual ~BarBase() {};


	};

	/**
	 * @brief FrameBaseクラス
	 */
	class FrameBase
	{
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

	public:

		DX::DirectX& dx = DX::DirectX::GetInstance();

		virtual void Initialize() {};
		virtual void Draw() {};
		FrameBase() {};
		virtual ~FrameBase() {};

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

	};

	/**
	 * @brief MoneyUIクラス
	 */
	class MoneyUI : public GameUI
	{
	private:

		void Initialize();

	public:

		MoneyUI() 
		{
			Initialize();
		}

		~MoneyUI() {};

		void Draw();

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
