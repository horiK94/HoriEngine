#pragma once
#include <iostream>
#include <cstdint>

namespace HoriEngine
{
	struct Color
	{
		uint8_t r = 0;
		uint8_t g = 0;
		uint8_t b = 0;
		uint8_t a = 0;

		struct NothingInit {};
		static constexpr unsigned char MAX_VALUE = 255;

		constexpr Color() : r(0), g(0), b(0), a(0) {}
		constexpr Color(NothingInit);
		constexpr Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b), a(MAX_VALUE) {}
		constexpr Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}
		constexpr Color(const Color& c) = default;

		bool operator==(const Color& c) const
		{
			return r == c.r && g == c.g && b == c.b && a == c.a;
		}

		bool operator!=(const Color& c) const
		{
			return r != c.r || g != c.g || b != c.b || a != c.a;
		}

		float GetRRate() const { return (float)r / MAX_VALUE; }
		float GetGRate() const { return (float)g / MAX_VALUE; }
		float GetBRate() const { return (float)b / MAX_VALUE; }
		float GetARate() const { return (float)a / MAX_VALUE; }
	};
	static constexpr Color Red = Color{ 255, 0, 0 };
	static constexpr Color Green = Color{ 0, 255, 0 };
	static constexpr Color Blue = Color{ 0, 0, 255 };
	static constexpr Color White = Color{ 255, 255, 255 };
	static constexpr Color Black = Color{ 0, 0, 0 };

	inline std::ostream& operator<<(std::ostream& stream, const Color& c)
	{
		stream << "Color(" << (int)c.r << ", " << (int)c.g << ", " << (int)c.b << ", " << (int)c.a << ")";
		return stream;
	}
}
