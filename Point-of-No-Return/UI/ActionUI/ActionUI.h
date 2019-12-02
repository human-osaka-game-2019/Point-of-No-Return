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
	class BerBase
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

		virtual void Initialize();
		virtual void Update();
		virtual void Draw();
		BerBase() {};
		virtual ~BerBase() {};


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

		virtual void Initialize();
		virtual void Update();
		virtual void Draw();
		FrameBase() {};
		virtual ~FrameBase() {};

	};

	/**
	 * @brief SatatusUIクラス
	 */
	class StatusUI : public GameUI
	{
	protected:



	public:


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

	};

	/**
	 * @brief HpUIクラス
	 */
	class HpUI : public StatusUI
	{
	private:

		void Initialize();

	public:

		HpUI() 
		{
			Initialize();
		}
		
		~HpUI() {};

		class HpBer : public BerBase
		{
		private:


		public:


		};

		class HpFrame : public FrameBase
		{
		private:


		public:


		};
	
	};

	/**
	 * @brief MpUIクラス
	 */
	class MpUI : public StatusUI
	{
	private:

		void Initialize();

	public:

		MpUI()
		{
			Initialize();
		}

		~MpUI() {};

		class MpBer : public BerBase
		{
		private:



		public:



		};

		class MpFrame : public FrameBase
		{
		private:



		public:



		};
	};

	/**
	 * @brief IpUIクラス
	 */
	class IpUI : public StatusUI
	{
	private:

		void Initialize();

	public:

		IpUI()
		{
			Initialize();
		}

		~IpUI() {};

		class IpBer : public BerBase
		{
		private:



		public:



		};

		class IpFrame : public FrameBase
		{
		private:



		public:



		};
	};

}

#endif
