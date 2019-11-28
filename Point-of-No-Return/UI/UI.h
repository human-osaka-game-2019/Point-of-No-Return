#ifndef UI_H
#define UI_H

#include "../Object.h"
#include"../Character.h"

/**
 * @brief UIクラス
 */
class UI :public Object
{
protected:


public:



};

/**
 * @brief TitleUIクラス
 */
class TitleUI : public UI
{
protected:


public:



};

/**
 * @brief SelectUIクラス
 */
class SelectUI : public UI
{
protected:


public:

};

/**
 * @brief GameUIクラス
 */
class GameUI : public UI
{
protected:

	virtual void Initialize() {};
	
	//Character character;

public:

	

};

/**
 * @brief HelpUIクラス
 */
class HelpUI : public UI
{
protected:


public:


};

#endif
