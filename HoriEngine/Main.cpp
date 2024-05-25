#include <Windows.h>
#include <iostream>

namespace HoriEngine::Debug
{
	/// @brief コンソールを開く
	void OpenConsole()
	{
		//::OutputDebugStringW(L"Hello, World\n");
		::AllocConsole();

		FILE* file = nullptr;
		::freopen_s(&file, "CONIN$", "r", stdin);
		::freopen_s(&file, "CONOUT$", "w", stdout);
		::freopen_s(&file, "CONOUT$", "w", stderr);

		//::Sleep(10000);
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
	HoriEngine::Debug::OpenConsole();

	std::cout << "Hello, World" << '\n';
	std::cout << lpCmdLine << '\n';
	//ウィンドウをどう表示するかの方法. 表示方法を参考にしてこっち側で変える処理を書いてあげることもできる. 10: SW_SHOWDEFAULT でデフォルトの表示方法になる. 従わなくてOK
	//呼び出し側の変え方 
	std::cout << nCmdShow << '\n';

	getchar();
	::FreeConsole();		//Allocしたものを閉じる

	return 0;
}