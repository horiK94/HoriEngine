#pragma once
#include <iostream>
#include <cstdint>

#include "Unicode.hpp"

namespace HoriEngine
{
	struct Color
	{
		uint8_t r = 0;
		uint8_t g = 0;
		uint8_t b = 0;
		uint8_t a = 0;

		struct NothingInit {};
		static constexpr uint8_t MAX_VALUE = 255;

		constexpr Color() : r(0), g(0), b(0), a(0) {}
		constexpr Color(NothingInit);
		constexpr Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b), a(MAX_VALUE) {}
		constexpr Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}
		constexpr Color(const Color& c) = default;

		bool operator==(const Color& c) const;
		bool operator!=(const Color& c) const;

		float GetRRate() const;
		float GetGRate() const;
		float GetBRate() const;
		float GetARate() const;
	};
	static constexpr Color Red = Color{ 255, 0, 0 };
	static constexpr Color Green = Color{ 0, 255, 0 };
	static constexpr Color Blue = Color{ 0, 0, 255 };
	static constexpr Color White = Color{ 255, 255, 255 };
	static constexpr Color Black = Color{ 0, 0, 0 };

	inline std::ostream& operator<<(std::ostream& stream, const Color& c)
	{
		stream << "Color("
		<< String::ToUtf8(String::ToString(c.r)) << ", "
		<< String::ToUtf8(String::ToString(c.g)) << ", "
		<< String::ToUtf8(String::ToString(c.b)) << ", "
		<< String::ToUtf8(String::ToString(c.a)) << ")";
		return stream;
	}
}
