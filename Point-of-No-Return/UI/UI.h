#ifndef UI_H
#define UI_H

#include "../Object.h"
#include "../Observer/IObserver.h"

/**
 * @brief UIクラス
 */
class UI :public Object
{

};

/**
 * @brief TitleUIクラス
 */
class TitleUI : public UI
{

};

/**
 * @brief SelectUIクラス
 */
class SelectUI : public UI
{

};

/**
 * @brief GameUIクラス
 */
class GameUI : public UI
{
public:

	virtual void UpDate() {};
	virtual void Draw() {};

protected:

	virtual void Initialize() {};


};

/**
 * @brief HelpUIクラス
 */
class HelpUI : public UI
{

};

#endif
