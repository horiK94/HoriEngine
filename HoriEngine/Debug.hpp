﻿#pragma once

#include <Windows.h>
#include <iostream>
#include "Unicode.hpp"

namespace HoriEngine::Debug
{
	/// @brief コンソールを開く
	inline void OpenConsole()
	{
		::AllocConsole();
		::SetConsoleOutputCP(CP_UTF8);

		FILE* file = nullptr;
		::freopen_s(&file, "CONIN$", "r", stdin);
		::freopen_s(&file, "CONOUT$", "w", stdout);
		::freopen_s(&file, "CONOUT$", "w", stderr);
	}

	//// @brief コンソールを閉じる
	inline void CloseConsole()
	{
		getchar();
		::FreeConsole();		//Allocしたものを閉じる
	}

	//// @brief デバッグ出力
	inline void OutputDebug(const std::u32string& str)
	{
		std::cout << String::ToUtf8(str) << '\n';
	}
}
