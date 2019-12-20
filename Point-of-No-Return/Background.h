#ifndef BACKGROUND_H_
#define BACKGROUND_H_


#include "Object.h"
#include "Character.h"

//背景クラス
class Background :public Object
{
public:
	
	/**
	 * @brief	背景のUpdate
	 * @param	character characterのinstance
	 */
	void Update(const Character& character);

	/**
	 * @brief	背景の描画
	 */
	void Draw();

private:

	/**
	 * @brief	背景をスクロールさせる
	 * @param	rightscroll 右に動くか判断する
	 * @details	引数がtrueなら右に、falseなら左に動く
	 */
	void ScrollBackground(bool& rightscroll);

	/**
	 * @brief	待機しているか判断する
	 * @param	character キャラクターのインスタンス
	 * @param	rightscroll 右に動くか判断する
	 */
	bool isIdle(const Character& character,bool* rightscroll);

};

#endif // !BACKGROUND_H_S
