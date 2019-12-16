#ifndef ACTIONUI_H
#define ACTIONUI_H

#include "../../Observer/IObserver.h"

#include "../UI.h"
#include "../ActionUI/BarBase.h"
#include "../ActionUI/FrameBase.h"
#include "../ActionUI/IconBase.h"

namespace ActionUI
{
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
	class GoldUI : public GameUI,public IGoldObserver
	{
	public:

		GoldUI() 
		{
			Initialize();
		}

		~GoldUI() {};

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

		void Update(const Gold& gold);


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

		class HpBar : public BarBase,public IHpObserver
		{
		public:

			void Initialize();
			void Update(const HP& hp);
			void Draw();
		};

		class HpFrame : public FrameBase
		{
		public:

			void Initialize();
			void Draw();

		};

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

		class MpBar : public BarBase,public IMpObserver
		{
		public:

			void Initialize();
			void Update(const MP& mp);
			void Draw();

		};

		class MpFrame : public FrameBase
		{
		public:

			void Initialize();
			void Draw();

		};

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

		class IpBar : public BarBase,public IIpObserver
		{
		public:

			IpBar() {};
			~IpBar() {};
			void Initialize();
			void Update(const IP& ip);
			void Draw();

		};

		class IpFrame : public FrameBase
		{
		public:

			void Initialize();
			void Draw();

		};

		void Draw();

	private:

		void Initialize();

		IpFrame ipFrame;
		IpBar ipBar;
		

	};

}

#endif
