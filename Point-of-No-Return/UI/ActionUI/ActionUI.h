#ifndef ACTIONUI_H
#define ACTIONUI_H

#include "../../Observer/IObserver.h"
#include "../UI.h"
#include "../../Hero.h"
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
	public:

		ItemUI()
		{
			Initialize();
		}

		/**
		 * @brief 描画関数
		 */
		void Draw();

		/**
		 * @brief 表示しているアイテムを更新する
		 */
		void UpDate();

	private:

		/**
		 * @brief 初期化関数
		 */
		void Initialize();

	};

	/**
	 * @brief GoldUIクラス
	 */
	class GoldUI : public GameUI, public IGoldObserver
	{
	public:

		GoldUI(Hero& hero) 
		{
			Initialize(hero);
		}

		/**
		 * @brief 描画関数
		 */
		void UIDraw();

		/**
		 * @brief 所持金描画関数
		 */
		void DrawNumber();

		void UpdateNumber(const Gold& gold);

		/**
		 * @brief 表示している金額を更新する
		 */
		void OnGoldChanged(const Gold& gold);

		class GoldFrame : public FrameBase
		{
		public:

			GoldFrame()
			{
				Initialize();
			}

			void Initialize();

			/**
			 * @brief 描画関数
			 */
			void Draw();
		};

		class GoldIcon : public IconBase
		{
		public:

			GoldIcon()
			{
				Initialize();
			}

			void Initialize();

			/**
			 * @brief 描画関数
			 */
			void Draw();
		
		};


	private:

		std::vector<int> Digit;

		/**
		 * @brief 初期化関数
		 */
		void Initialize(Hero& hero);

		GoldIcon goldIcon;

		GoldFrame goldFrame;
	};

	/**
	 * @brief HpGaugeクラス
	 */
	class HpGauge : public GameUI
	{
	public:

		HpGauge(Hero& hero) 
		{
			Initialize(hero);
		};

		/**
		 * @brief 描画関数
		 */
		void Draw();

		class HpBar : public BarBase, public IHpObserver
		{
		public:

			/**
			 * @brief 初期化関数
			 */
			void Initialize();

			/**
			 * @brief Widthの値を更新する
			 */
			void OnHpChanged(const HP& hp);

			/**
			 * @brief 描画関数
			 */
			void Draw();
		};

		class HpFrame : public FrameBase
		{
		public:

			/**
			 * @brief 初期化関数
			 */
			void Initialize();

			/**
			 * @brief 描画関数
			 */
			void Draw();

		};

	private:

		/**
		 * @brief 初期化関数
		 */
		void Initialize(Hero& hero);

		HpBar hpBar;
		HpFrame hpFrame;
	};

	/**
	 * @brief MpGaugeクラス
	 */
	class MpGauge : public GameUI
	{
	public:

		MpGauge(Hero& hero) 
		{
			Initialize(hero);
		};

		/**
		 * @brief 描画関数
		 */
		void Draw();

		class MpBar : public BarBase, public IMpObserver
		{
		public:

			/**
			 * @brief 初期化関数
			*/
			void Initialize();

			/**
			 * @brief Widthの値を更新する
			 */
			void OnMpChanged(const MP& mp);

			/**
			 * @brief 描画関数
			 */
			void Draw();

		};

		class MpFrame : public FrameBase
		{
		public:

			/**
			 * @brief 初期化関数
			 */
			void Initialize();

			/**
			 * @brief 描画関数
			 */
			void Draw();

		};

	private:

		/**
		 * @brief 初期化関数
		 */
		void Initialize(Hero& hero);

		MpBar mpBar;
		MpFrame mpFrame;
	};

	/**
	 * @brief IpGaugeクラス
	 */
	class IpGauge : public GameUI
	{
	public:

		IpGauge(Hero& hero) 
		{
			Initialize(hero);
		};

		/**
		 * @brief 描画関数
		 */
		void Draw();

		/**
		 * @brief IpBarクラス
		 */
		class IpBar : public BarBase, public IIpObserver
		{
		public:

			IpBar() {};

			/**
			 * @brief 初期化関数
			*/
			void Initialize();

			/**
			 * @brief Widthの値を更新する
			 */
			void OnIpChanged(const IP& ip);

			/**
			 * @brief 描画関数
			 */
			void Draw();

		};

		/**
		 * @brief IpFrameクラス
		 */
		class IpFrame : public FrameBase
		{
		public:

			/**
			 * @brief 初期化関数
			 */
			void Initialize();

			/**
			 * @brief 描画関数
			 */
			void Draw();

		};

	private:

		/**
		 * @brief 初期化
		 */
		void Initialize(Hero& hero);

		IpFrame ipFrame;
		IpBar ipBar;
		

	};

}

#endif
