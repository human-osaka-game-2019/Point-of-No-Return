#ifndef GRAVITY_H_
#define GRAVITY_H_

#include "Object.h"

namespace Accelerator 
{

//! 加速度の最大値
const float MAX_VALUE = 5.f;

//! 加速度に加算する値
const float ADD_VALUE = 0.07f;

/**
* @class Acceleration
* @brief 加速度のラッパークラス
*/
class Acceleration 
{
public:
	explicit Acceleration(float value) :value(value) {}

	~Acceleration() {}

	float GetValue() { return value; }

	/**
	* @brief 加速度を0に戻す
	*/
	void Reset();

	/**
	* @brief 重力を加速運動させる
	*/
	void Accelerate();

	/**
	 * @brief 重力を加速運動させる
	 */
	void Jump();

private:
	float value;
};
}

/**
* @class Gravity
* @brief 重力クラス
*/
class Gravity {
public:

	explicit Gravity(Position* characterPosition) :characterPosition(characterPosition) {}

	~Gravity() {}

	/**
	* @brief 重力を適用する 
	*/
	void Apply();

	/**
	* @brief 加速度を0に戻す
	*/
	inline void AccelerationReset() 
	{
		acceleration.Reset();
	};

	/**
	* @brief ジャンプする
	*/
	inline void Jump()
	{
		if (can_jump)
		{
			acceleration.Jump();
		}
		can_jump = false;
	}

	/**
	* @brief ジャンプをできる状態に戻す
	*/
	inline void JumpReset()
	{
		can_jump = true;
	}

private:

	//! accelerationのインスタンス
	Accelerator::Acceleration acceleration{ 0.f };

	//! コンストラクタで受け取ったcharacterPositionのアドレス
	Position* characterPosition;

	//! ジャンプできるか判断する
	bool can_jump = true;
};

#endif
