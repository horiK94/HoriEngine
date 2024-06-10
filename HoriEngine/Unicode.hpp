#pragma once
#include <string>

namespace HoriEngine::String
{
	std::wstring ToUtf16(const std::u32string& str)
	{
		std::wstring utf16;

		//UTF-32 -> UTF-16
		for (char32_t ch : str)
		{
			UINT32 codePoint = ch;

			if (codePoint < 0x10000)
			{
				// 第0面のときは 16ビットの符号なし整数として表現して終了
				utf16.push_back((wchar_t)codePoint);
				continue;
			}

			// サロゲートペアに変換
			UINT32 surrogate = codePoint - 0x10000;
			wchar_t high = static_cast<wchar_t>((surrogate >> 10) | 0b1101100000000000);
			wchar_t low = static_cast<wchar_t>((surrogate & 0b1111111111) | 0b1101110000000000);

			utf16.push_back(high);
			utf16.push_back(low);
		}

		return utf16;
	}

	std::u32string ToString(const std::size_t n)
	{
		std::string utf8 = std::to_string(n);
		return std::u32string(utf8.begin(), utf8.end());
	}

	std::u32string ToString(const int val)
	{
		std::string utf8 = std::to_string(val);
		return std::u32string(utf8.begin(), utf8.end());
	}

	std::u32string ToString(const unsigned int val)
	{
		std::string utf8 = std::to_string(val);
		return std::u32string(utf8.begin(), utf8.end());
	}

	std::u32string ToString(const long val)
	{
		std::string utf8 = std::to_string(val);
		return std::u32string(utf8.begin(), utf8.end());
	}

	std::u32string ToString(const unsigned long val)
	{
		std::string utf8 = std::to_string(val);
		return std::u32string(utf8.begin(), utf8.end());
	}

	std::u32string ToString(const long long val)
	{
		std::string utf8 = std::to_string(val);
		return std::u32string(utf8.begin(), utf8.end());
	}

	std::u32string ToString(const float val)
	{
		std::string utf8 = std::to_string(val);
		return std::u32string(utf8.begin(), utf8.end());
	}

	std::u32string ToString(const double val)
	{
		std::string utf8 = std::to_string(val);
		return std::u32string(utf8.begin(), utf8.end());
	}

	std::u32string ToString(const long double val)
	{
		std::string utf8 = std::to_string(val);
		return std::u32string(utf8.begin(), utf8.end());
	}

	//std::u32string ToString(const unsigned long long val)
	//{
	//	std::string utf8 = std::to_string(val);
	//	return std::u32string(utf8.begin(), utf8.end());
	//}

	std::string ToUtf8(const std::u32string& str)
	{
		//UTF-32 -> UTF-8
		std::string utf8;

		for (char32_t ch : str)
		{
			UINT32 codePoint = ch;
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
}
