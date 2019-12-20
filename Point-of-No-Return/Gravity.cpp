#include "Gravity.h"

namespace
{
	//! 初速度
	const float INITIAL_VELOCITY = 10.f;
}

namespace Accelerator
{

void Acceleration::Accelerate() 
{
	if (value > MAX_VALUE)
	{
		return;
	}

	value += Accelerator::ADD_VALUE;
}

void Acceleration::Reset()
{
	value = 0.f;
}

void Acceleration::Jump()
{
	value = -INITIAL_VELOCITY;
}

}

void Gravity::Apply()
{
	characterPosition->y.value += acceleration.GetValue();
	acceleration.Accelerate();
}

