#pragma once
#include <cstdint>
namespace HoriEngine::Math
{
	bool InRange(int8_t val, int8_t min, int8_t max);
	bool InRange(uint8_t val, uint8_t min, uint8_t max);
	bool InRange(int16_t val, int16_t min, int16_t max);
	bool InRange(uint16_t val, uint16_t min, uint16_t max);
	bool InRange(int32_t val, int32_t min, int32_t max);
	bool InRange(uint32_t val, uint32_t min, uint32_t max);
	bool InRange(int64_t val, int64_t min, int64_t max);
	bool InRange(uint64_t val, uint64_t min, uint64_t max);

	bool InRange(float val, float min, float max);
	bool InRange(double val, double min, double max);
	bool InRange(long double val, long double min, long double max);

	int8_t Clamp(int8_t val, int8_t min, int8_t max);
	uint8_t Clamp(uint8_t val, uint8_t min, uint8_t max);
	int16_t Clamp(int16_t val, int16_t min, int16_t max);
	uint16_t Clamp(uint16_t val, uint16_t min, uint16_t max);
	int32_t Clamp(int32_t val, int32_t min, int32_t max);
	uint32_t Clamp(uint32_t val, uint32_t min, uint32_t max);
	int64_t Clamp(int64_t val, int64_t min, int64_t max);
	uint64_t Clamp(uint64_t val, uint64_t min, uint64_t max);
	float Clamp(float val, float min, float max);
	double Clamp(double val, double min, double max);
	long double Clamp(long double val, long double min, long double max);
}