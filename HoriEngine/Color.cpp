#include "Color.hpp"

bool HoriEngine::Color::operator==(const Color& c) const
{
	return r == c.r && g == c.g && b == c.b && a == c.a;
}

bool HoriEngine::Color::operator!=(const Color& c) const
{
	return r != c.r || g != c.g || b != c.b || a != c.a;
}

float HoriEngine::Color::GetRRate() const
{
	return static_cast<float>(r) / MAX_VALUE;
}

float HoriEngine::Color::GetGRate() const
{
	return static_cast<float>(g) / MAX_VALUE;
}

float HoriEngine::Color::GetBRate() const
{
	return static_cast<float>(b) / MAX_VALUE;
}

float HoriEngine::Color::GetARate() const
{
	return static_cast<float>(a) / MAX_VALUE;
}