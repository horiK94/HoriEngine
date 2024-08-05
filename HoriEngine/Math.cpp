#include "Math.hpp"

namespace HoriEngine::Math
{
	template <typename T>

	bool InRange(T val, T min, T max)
	{
		return min <= val && val < max;
	}

	bool InRange(int8_t val, int8_t min, int8_t max)
	{
		return InRange<int8_t>(val, min, max);
	}

	bool InRange(uint8_t val, uint8_t min, uint8_t max)
	{
		return InRange<uint8_t>(val, min, max);
	}

	bool InRange(int16_t val, int16_t min, int16_t max)
	{
		return InRange<int16_t>(val, min, max);
	}

	bool InRange(uint16_t val, uint16_t min, uint16_t max)
	{
		return InRange<uint16_t>(val, min, max);
	}

	bool InRange(int32_t val, int32_t min, int32_t max)
	{
		return InRange<int32_t>(val, min, max);
	}

	bool InRange(uint32_t val, uint32_t min, uint32_t max)
	{
		return InRange<uint32_t>(val, min, max);
	}

	bool InRange(int64_t val, int64_t min, int64_t max)
	{
		return InRange<int64_t>(val, min, max);
	}

	bool InRange(uint64_t val, uint64_t min, uint64_t max)
	{
		return InRange<uint64_t>(val, min, max);
	}

	bool InRange(float val, float min, float max)
	{
		return InRange<float>(val, min, max);
	}

	bool InRange(double val, double min, double max)
	{
		return InRange<double>(val, min, max);
	}

	bool InRange(long double val, long double min, long double max)
	{
		return InRange<long double>(val, min, max);
	}

	template <typename T>
	static T Clamp(T val, T min, T max)
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

	int8_t Clamp(int8_t val, int8_t min, int8_t max)
	{
		return Clamp<int8_t>(val, min, max);
	}

	uint8_t Clamp(uint8_t val, uint8_t min, uint8_t max)
	{
		return Clamp<uint8_t>(val, min, max);
	}

	int16_t Clamp(int16_t val, int16_t min, int16_t max)
	{
		return Clamp<int16_t>(val, min, max);
	}

	uint16_t Clamp(uint16_t val, uint16_t min, uint16_t max)
	{
		return Clamp<uint16_t>(val, min, max);
	}

	int32_t Clamp(int32_t val, int32_t min, int32_t max)
	{
		return Clamp<int32_t>(val, min, max);
	}

	uint32_t Clamp(uint32_t val, uint32_t min, uint32_t max)
	{
		return Clamp<uint32_t>(val, min, max);
	}

	int64_t Clamp(int64_t val, int64_t min, int64_t max)
	{
		return Clamp<int64_t>(val, min, max);
	}

	uint64_t Clamp(uint64_t val, uint64_t min, uint64_t max)
	{
		return Clamp<uint64_t>(val, min, max);
	}

	float Clamp(float val, float min, float max)
	{
		return Clamp<float>(val, min, max);
	}

	double Clamp(double val, double min, double max)
	{
		return Clamp<double>(val, min, max);
	}

	long double Clamp(long double val, long double min, long double max)
	{
		return Clamp<long double>(val, min, max);
	}
}