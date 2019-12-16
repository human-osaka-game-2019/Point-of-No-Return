#ifndef RPGUI_H
#define RPGUI_H

#include"../UI.h"

namespace RPGUI
{
	/**
	 * @brief TextWindowUIクラス
	 */
	class TextWindow : public GameUI
	{
    private:


	public:


	};

	/**
	 * @brief CharacterWindowUIクラス
	 */
	class CharacterWindow : public GameUI
	{
	protected:


	public:


	}

	/**
	 * @brief HeroWindowUIクラス
	 */
	class HeroWindow : public CharacterWindow
	{
	private:



	public:

	};

	/**
	 * @brief HeroineWindowUIクラス
	 */
	class HeroineWindow : public CharacterWindow
	{
	private:



	public:

	};

	/**
	 * @brief SonWindowUIクラス
	 */
	class SonWindow : public CharacterWindow
	{
	private:



	public:

	};


	/**
	 * @brief DaughterWindowUIクラス
	 */
	class DaughterWindow : public CharacterWindow
	{
	private:



	public:

	};



}

#endif RPGUI_H
