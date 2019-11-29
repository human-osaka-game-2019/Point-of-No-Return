#include "Gravity.h"

namespace
{
	const float jump = 5;
}

namespace Accelerator
{

void Acceleration::Accelerate() 
{
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
	vec->y.value += acceleration.GetValue();
	acceleration.Accelerate();
}

