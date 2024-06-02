#include <Windows.h>
#include <iostream>
#include  <vector>

namespace HoriEngine::String
{
	std::wstring ToUtf16(const std::u32string& str)
	{
		std::vector<wchar_t> utf16;

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

		std::wstring result(utf16.data(), utf16.size());
		return result;
	}

	std::string ToUtf8(const std::u32string& str)
	{
		//UTF-32 -> UTF-8
		std::vector<char> utf8;

		for (char32_t ch : str)
		{
			UINT32 codePoint = ch;
			if (codePoint <= 0x007f)
			{
				// 1バイト文字
				utf8.push_back(codePoint);
				continue;
			}

			if(codePoint <= 0x07FF)
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

		std::string result(utf8.begin(), utf8.end());
		return result;
	}
}

namespace HoriEngine::Debug
{
	/// @brief コンソールを開く
	void OpenConsole()
	{
		::AllocConsole();
		SetConsoleOutputCP(CP_UTF8);

		FILE* file = nullptr;
		::freopen_s(&file, "CONIN$", "r", stdin);
		::freopen_s(&file, "CONOUT$", "w", stdout);
		::freopen_s(&file, "CONOUT$", "w", stderr);
	}

	//// @brief コンソールを閉じる
	void CloseConsole()
	{
		getchar();
		::FreeConsole();		//Allocしたものを閉じる
	}

	/// @brief UTF-8 -> UTF-16
	///	チェック用. 削除予定
	std::string utf8_encode(const std::wstring& wstr)
	{
		if (wstr.empty()) return std::string();
		int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
		std::string strTo(size_needed, 0);
		WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
		return strTo;
	}

	//// @brief デバッグ出力
	void OutputDebug(const std::u32string& str)
	{
		std::wstring s = String::ToUtf16(str);
		std::cout << utf8_encode(s) << '\n';
		std::cout << String::ToUtf8(str) << '\n';
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
	HoriEngine::Debug::OpenConsole();

	HoriEngine::Debug::OutputDebug(U"a");
	HoriEngine::Debug::OutputDebug(U"®");
	HoriEngine::Debug::OutputDebug(U"あ");
	HoriEngine::Debug::OutputDebug(U"𩹽");

	HoriEngine::Debug::CloseConsole();

	return 0;
}