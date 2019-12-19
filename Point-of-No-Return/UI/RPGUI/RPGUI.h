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
	};

	/**
	 * @brief CharacterWindowUIクラス
	 */
	class CharacterWindow : public GameUI
	{
	};

	/**
	 * @brief HeroWindowUIクラス
	 */
	class HeroWindow : public CharacterWindow
	{
	};

	/**
	 * @brief HeroineWindowUIクラス
	 */
	class HeroineWindow : public CharacterWindow
	{
	};

	/**
	 * @brief SonWindowUIクラス
	 */
	class SonWindow : public CharacterWindow
	{
	};


	/**
	 * @brief DaughterWindowUIクラス
	 */
	class DaughterWindow : public CharacterWindow
	{
	};



}

#endif RPGUI_H
