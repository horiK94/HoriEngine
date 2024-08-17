#include "Unicode.hpp"

namespace HoriEngine::String
{
	std::string ToUtf8(const String32& str)
	{
		//UTF-32 -> UTF-8
		std::string utf8;

		for (char32_t ch : str)
		{
			unsigned int codePoint = ch;
			if (codePoint <= 0x007f)
			{
				// 1バイト文字
				utf8.push_back(codePoint);
				continue;
			}

			if (codePoint <= 0x07FF)
			{
				// 2バイト文字
				utf8.push_back((codePoint >> 6) | 0b11000000);
				utf8.push_back((codePoint & 0b111111) | 0b10000000);
				continue;
			}

			if (codePoint <= 0xFFFF)
			{
				// 3バイト文字
				utf8.push_back((codePoint >> 12) | 0b11100000);
				utf8.push_back(((codePoint >> 6) & 0b111111) | 0b10000000);
				utf8.push_back((codePoint & 0b111111) | 0b10000000);
				continue;
			}

			// 4バイト文字
			utf8.push_back((codePoint >> 18) | 0b11110000);
			utf8.push_back(((codePoint >> 12) & 0b111111) | 0b10000000);
			utf8.push_back(((codePoint >> 6) & 0b111111) | 0b10000000);
			utf8.push_back((codePoint & 0b111111) | 0b10000000);
		}

		return utf8;
	}

	std::wstring ToUtf16(const String32& str)
	{
		std::wstring utf16;

		//UTF-32 -> UTF-16
		for (char32_t ch : str)
		{
			unsigned int codePoint = ch;

			if (codePoint < 0x10000)
			{
				// 第0面のときは 16ビットの符号なし整数として表現して終了
				utf16.push_back((wchar_t)codePoint);
				continue;
			}

			// サロゲートペアに変換
			unsigned int surrogate = codePoint - 0x10000;
			wchar_t high = static_cast<wchar_t>((surrogate >> 10) | 0b1101100000000000);
			wchar_t low = static_cast<wchar_t>((surrogate & 0b1111111111) | 0b1101110000000000);

			utf16.push_back(high);
			utf16.push_back(low);
		}

		return utf16;
	}

	String32 ToString(const std::string& val)
	{
		return String32(val.begin(), val.end());
	}

	String32 ToString(const std::wstring& str)
	{
		return String32(str.begin(), str.end());
	}

	String32 ToString(const char* str)
	{
		std::string s = str;
		return String32(ToString(s));
	}

	String32 ToString(const char32_t* str)
	{
		return String32(str);
	}

	String32 ToUtf32(const std::string& str)
	{
		return String32(str.begin(), str.end());
	}

	String32 ToString(const bool val)
	{
		return val ? U"true" : U"false";
	}

	String32 ToString(const float val)
	{
		std::string utf8 = std::to_string(val);
		return String32(utf8.begin(), utf8.end());
	}

	String32 ToString(const double val)
	{
		std::string utf8 = std::to_string(val);
		return String32(utf8.begin(), utf8.end());
	}

	String32 ToString(const long double val)
	{
		std::string utf8 = std::to_string(val);
		return String32(utf8.begin(), utf8.end());
	}

	String32 ToString(const int8_t val)
	{
		std::string utf8 = std::to_string(val);
		return String32(utf8.begin(), utf8.end());
	}

	String32 ToString(const uint8_t val)
	{
		std::string utf8 = std::to_string(val);
		return String32(utf8.begin(), utf8.end());
	}

	String32 ToString(const int16_t val)
	{
		std::string utf8 = std::to_string(val);
		return String32(utf8.begin(), utf8.end());
	}

	String32 ToString(const uint16_t val)
	{
		std::string utf8 = std::to_string(val);
		return String32(utf8.begin(), utf8.end());
	}

	String32 ToString(const int32_t val)
	{
		std::string utf8 = std::to_string(val);
		return String32(utf8.begin(), utf8.end());
	}

	String32 ToString(const uint32_t val)
	{
		std::string utf8 = std::to_string(val);
		return String32(utf8.begin(), utf8.end());
	}

	String32 ToString(const int64_t val)
	{
		std::string utf8 = std::to_string(val);
		return String32(utf8.begin(), utf8.end());
	}

	String32 ToString(const uint64_t val)
	{
		std::string utf8 = std::to_string(val);
		return String32(utf8.begin(), utf8.end());
	}
}
