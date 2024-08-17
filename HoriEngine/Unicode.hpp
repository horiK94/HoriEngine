#pragma once

#include "TypeDefine.hpp"
#include <string>
#include <cstdint>

namespace HoriEngine::String
{
	std::string ToUtf8(const String32& str);
	std::wstring ToUtf16(const String32& str);

	String32 ToString(const std::string& val);
	String32 ToString(const std::wstring& str);

	String32 ToString(const char* str);
	String32 ToString(const char32_t* str);

	String32 ToString(const bool val);

	String32 ToString(const float val);
	String32 ToString(const double val);
	String32 ToString(const long double val);

	String32 ToString(const int8_t val);
	String32 ToString(const uint8_t val);
	String32 ToString(const int16_t val);
	String32 ToString(const uint16_t val);
	String32 ToString(const int32_t val);
	String32 ToString(const uint32_t val);
	String32 ToString(const int64_t val);
	String32 ToString(const uint64_t val);
}
