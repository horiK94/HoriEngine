#pragma once

#include <Windows.h>
#include <iostream>
#include "Unicode.hpp"
#include "Debug.hpp"

namespace HoriEngine::Debug
{
	/// @brief �R���\�[�����J��
	void OpenConsole()
	{
		::AllocConsole();
		::SetConsoleOutputCP(CP_UTF8);

		FILE* file = nullptr;
		::freopen_s(&file, "CONIN$", "r", stdin);
		::freopen_s(&file, "CONOUT$", "w", stdout);
		::freopen_s(&file, "CONOUT$", "w", stderr);
	}

	//// @brief �R���\�[�������
	void CloseConsole()
	{
		getchar();
		::FreeConsole();		//Alloc�������̂����
	}

	//// @brief �f�o�b�O�o��
	void OutputDebug(const String32& str)
	{
		std::cout << String::ToUtf8(str) << '\n';
	}
}
