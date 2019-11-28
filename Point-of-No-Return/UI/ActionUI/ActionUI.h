#ifndef ACTIONUI_H
#define ACTIONUI_H

#include"../UI.h"

namespace ActionUI
{

	/**
	 * @brief SatatusUIクラス
	 */
	class StatusUI : public GameUI
	{
	protected:



	public:

		float ゲージを減らす関数(const Status& status, Size size);

	};

	/**
	 * @brief ItemUIクラス
	 */
	class ItemUI : public GameUI
	{
	private:

		void Initialize() {};

	public:


	};

	/**
	 * @brief MoneyUIクラス
	 */
	class MoneyUI : public GameUI
	{
	private:

		void Initialize();

	public:

	};

	/**
	 * @brief HpUIクラス
	 */
	class HpUI : public StatusUI
	{
	private:

		void Initialize();

	public:

		
	
	};

	/**
	 * @brief MpUIクラス
	 */
	class MpUI : public StatusUI
	{
	private:

		void Initialize();

	public:

	};

	/**
	 * @brief IpUIクラス
	 */
	class IpUI : public StatusUI
	{
	private:

		void Initialize();

	public:

	};

}

#endif
