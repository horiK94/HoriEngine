#pragma once
#include <cstdint>

namespace HoriEngine::Math
{
	static bool InRange(size_t val, size_t min, size_t max)
	{
		return min <= val && val < max;
	}

	static size_t Clamp(size_t val, size_t min, size_t max)
	{
		if (val < min)
		{
			return min;
		}
		if (val > max)
		{
			return max;
		}
		return val;
	}
}