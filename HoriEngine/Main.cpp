#include "Debug.hpp"
#include "Image.hpp"
#include "Window.hpp"

namespace HoriEngine
{
	void Main()
	{
		Debug::OpenConsole();

		Window window;
		if (not window.init())	// !window.init()�Ɠ���
		{
			Debug::OutputDebug(U"init failed...");
			return;
		}
		while (window.update())
		{
		}

		Debug::OutputDebug(U"Finished!");

		Debug::CloseConsole();
	}
}
