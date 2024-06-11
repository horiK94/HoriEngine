#pragma once
#include <iostream>

namespace HoriEngine::Color
{
	class Color
	{
	public:
		unsigned short r = 0;
		unsigned short g = 0;
		unsigned short b = 0;
		unsigned short a = 0;

		struct NothingInit {};
		static const unsigned short MAX_VALUE = 255;

		Color() : r(0), g(0), b(0), a(0) {}
		Color(NothingInit);
		Color(unsigned short r, unsigned short g, unsigned short b) : r(r), g(g), b(b), a(MAX_VALUE) {}
		Color(unsigned short r, unsigned short g, unsigned short b, unsigned short a) : r(r), g(g), b(b), a(a) {}
		Color(const Color& c) = default;

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
	std::ostream& operator<<(std::ostream& stream, const Color& c)
	{
		stream << "Color(" << c.r << ", " << c.g << ", " << c.b << ", " << c.a << ")";
		return stream;
	}
}
