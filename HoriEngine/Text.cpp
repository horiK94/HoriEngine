#include "Text.hpp"
#include <algorithm>

namespace HoriEngine::String
{
	std::string Text::ToUtf8()
	{
		return String::ToUtf8(text);
	}

	std::string Text::ToUtf8() const
	{
		return String::ToUtf8(text);
	}

	std::wstring Text::ToUtf16()
	{
		return String::ToUtf16(text);
	}

	std::wstring Text::ToUtf16() const
	{
		return String::ToUtf16(text);
	}

	Text& Text::operator=(const std::string& s)
	{
		Text text = Text(s);
		return text;
	}

	Text Text::ToLower()
	{
		std::string data = ToUtf8();
		std::transform(data.begin(), data.end(), data.begin(),
			[](unsigned char c) { return std::tolower(c); });

		return Text(data);
	}

	Text ToText(const std::string& val)
	{
		return Text(val);
	}

	Text ToText(const std::wstring& str)
	{
		return Text(str);
	}

	Text ToText(const char* str)
	{
		return Text(str);
	}

	Text ToText(const bool val)
	{
		return Text(ToString(val));
	}

	Text ToText(const float val)
	{
		return Text(ToString(val));
	}

	Text ToText(const double val)
	{
		return Text(ToString(val));
	}

	Text ToText(const long double val)
	{
		return Text(ToString(val));
	}

	Text ToText(const int8_t val)
	{
		return Text(ToString(val));
	}

	Text ToText(const uint8_t val)
	{
		return Text(ToString(val));
	}

	Text ToText(const int16_t val)
	{
		return Text(ToString(val));
	}

	Text ToText(const uint16_t val)
	{
		return Text(ToString(val));
	}

	Text ToText(const int32_t val)
	{
		return Text(ToString(val));
	}

	Text ToText(const uint32_t val)
	{
		return Text(ToString(val));
	}

	Text ToText(const int64_t val)
	{
		return Text(ToString(val));
	}

	Text ToText(const uint64_t val)
	{
		return Text(ToString(val));
	}

	std::string ToUtf8(const Text& text)
	{
		return String::ToUtf8(text.text);
	}

	std::wstring ToUtf16(const Text& text)
	{
		return String::ToUtf16(text.text);
	}
}
