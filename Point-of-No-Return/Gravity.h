#ifndef GRAVITY_H_
#define GRAVITY_H_

#include "Object.h"

namespace Accelerator 
{

//! 加速度の最大値
const float MaxValue = 5.0f;

//! 加速度に加算する値
const float AddValue = 0.5f;

/**
* @class Acceleration
* @brief 加速度のラッパークラス
*/
class Acceleration {
public:
	explicit Acceleration(float value) :value(value) {};
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

	explicit Gravity(Vec2* vec):vec(vec) {}

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

	inline void Jump()
	{
		acceleration.Jump();
	}

private:
	Accelerator::Acceleration acceleration{ 0 };
	Vec2* vec;
};

#endif
