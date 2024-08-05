#pragma once
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
	return (float)r / MAX_VALUE;
}

float HoriEngine::Color::GetGRate() const
{
	return (float)g / MAX_VALUE;
}

float HoriEngine::Color::GetBRate() const
{
	return (float)b / MAX_VALUE;
}

float HoriEngine::Color::GetARate() const
{
	return (float)a / MAX_VALUE;
}