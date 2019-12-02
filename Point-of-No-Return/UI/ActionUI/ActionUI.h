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
	 * @brief SatatusUIクラス
	 */
	class StatusUI : public GameUI
	{
	protected:



	public:


	};

	/**
	 * @brief Gaugeクラス
	 */
	class Gauge : public StatusUI
	{
	protected:

		void Initialize(float x, float y, float width, float height, float tu, float tv, float tu_size, float tv_size);

		Hero hero;

	public:

		Gauge(float x, float y, float width, float height, float tu, float tv, float tu_size, float tv_size);

		void Update(State state);

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

	};

}

#endif
