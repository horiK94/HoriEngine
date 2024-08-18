#pragma once
#include "TypeDefine.hpp"
#include "Unicode.hpp"

namespace HoriEngine::String
{
	struct Text
	{
		String32 text;

		Text() = default;
		explicit Text(const char* text) : text(String::ToString(text)) {}
		explicit Text(const char32_t* text) : text(String::ToString(text)) {}
		explicit Text(const std::string& text) : text(String::ToString(text)) {}
		explicit Text(const std::wstring& text) : text(String::ToString(text)) {}
		explicit Text(const String32& t) : text(t) {}

		std::string ToUtf8();
		std::string ToUtf8() const;
		std::wstring ToUtf16();
		std::wstring ToUtf16() const;

		Text& operator=(const std::string& s);

		operator const String32& () const { return text; }
		operator String32& () { return text; }

		Text ToLower();
	};

	inline Text operator +(const Text& lhs, const Text& rhs)
	{
		return Text(lhs.text + rhs.text);
	}

	inline Text operator +(const String32& lhs, const Text& rhs)
	{
		return Text(lhs + rhs.text);
	}

	inline Text operator +(const Text& lhs, const String32& rhs)
	{
		return Text(lhs.text + rhs);
	}

	inline std::ostream& operator<<(std::ostream& stream, const Text& t)
	{
		stream << String::ToUtf8(t.text);
		return stream;
	}

	Text ToText(const std::string& val);
	Text ToText(const std::wstring& str);
	Text ToText(const char* str);

	Text ToText(const bool val);

	Text ToText(const float val);
	Text ToText(const double val);
	Text ToText(const long double val);

	Text ToText(const int8_t val);
	Text ToText(const uint8_t val);
	Text ToText(const int16_t val);
	Text ToText(const uint16_t val);
	Text ToText(const int32_t val);
	Text ToText(const uint32_t val);
	Text ToText(const int64_t val);
	Text ToText(const uint64_t val);

	std::string ToUtf8(const Text& str);
	std::wstring ToUtf16(const Text& str);
}
