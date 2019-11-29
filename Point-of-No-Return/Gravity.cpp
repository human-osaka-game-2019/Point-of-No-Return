﻿#include "Gravity.h"

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

}

void Gravity::Apply() 
{
	vec->y.value += acceleration.GetValue();
	acceleration.Accelerate();
}

