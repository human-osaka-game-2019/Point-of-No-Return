#include "Gravity.h"

namespace
{
	const float jump = 10;
}

namespace Accelerator
{

void Acceleration::Accelerate() 
{
	if (value > MaxValue)
	{
		return;
	}

	value += Accelerator::AddValue;
}

void Acceleration::Reset()
{
	value = 0.0f;
}

void Acceleration::Jump()
{
	value = -jump;
}

}

void Gravity::Apply()
{
	characterPosition->y.value += acceleration.GetValue();
	acceleration.Accelerate();
}

