#pragma once
#include "TypeDefine.hpp"
#include "Text.hpp"

namespace HoriEngine::Debug
{
	void OpenConsole();
	void CloseConsole();
	void OutputDebug(const String::Text& str);
}
