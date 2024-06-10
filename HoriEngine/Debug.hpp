#pragma once

#include <Windows.h>
#include <iostream>
#include "Unicode.hpp"

namespace HoriEngine::Debug
{
	/// @brief コンソールを開く
	void OpenConsole()
	{
		::AllocConsole();
		::SetConsoleOutputCP(CP_UTF8);

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
		//std::wstring s = String::ToUtf16(str);
		//std::cout << utf8_encode(s) << '\n';
		std::cout << String::ToUtf8(str) << '\n';
	}
}
