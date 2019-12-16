#ifndef ACTIONUI_H
#define ACTIONUI_H

#include"../UI.h"
#include"../Object.h"

namespace ActionUI
{

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


	public:


	};

	/**
	 * @brief MoneyUIクラス
	 */
	class MoneyUI : public GameUI
	{
	private:



	public:

	};

	/**
	 * @brief HpUIクラス
	 */
	class HpUI : public StatusUI
	{
	private:


	public:

	
	};

	/**
	 * @brief MpUIクラス
	 */
	class MpUI : public StatusUI
	{
	private:


	public:

	};

	/**
	 * @brief IpUIクラス
	 */
	class IpUI : public StatusUI
	{
	private:


	public:

	};

}

#endif
