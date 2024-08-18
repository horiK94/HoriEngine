#include <Windows.h>
#include <iostream>
#include "Unicode.hpp"
#include "Debug.hpp"

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
		//::getchar();	//何かキーを押すまで待つ
		::FreeConsole();		//Allocしたものを閉じる
	}

	//// @brief デバッグ出力
	void OutputDebug(const String32& str)
	{
		std::cout << String::ToUtf8(str) << '\n';
	}
}
