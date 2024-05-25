#include <Windows.h>
#include <iostream>

namespace HoriEngine::String
{
	std::wstring ToUtf16(const std::u32string& str)
	{
		//UTF-32 -> UTF-16
		return L"";
	}

	std::string ToUtf8(const std::u32string& str)
	{
		//UTF-32 -> UTF-16
		return "";
	}
}

namespace HoriEngine::Debug
{
	/// @brief コンソールを開く
	void OpenConsole()
	{
		::AllocConsole();

		FILE* file = nullptr;
		::freopen_s(&file, "CONIN$", "r", stdin);
		::freopen_s(&file, "CONOUT$", "w", stdout);
		::freopen_s(&file, "CONOUT$", "w", stderr);

		//::Sleep(10000);
	}

	void CloseConsole()
	{
		getchar();
		::FreeConsole();		//Allocしたものを閉じる
	}

	//void OutputDebug(std::string str)		//ShiftJIS　-> UTF-8(設定で変更)
	//{
	//	//OutputDebugStringAはOSのデフォルト文字エンコーディングが設定される
	//	::OutputDebugStringA("Hello World");		//マルチバイト文字列. (環境によるが、日本語だとデフォルト)SHIFT-JIS
	//	::OutputDebugStringW(L"Hello World");		//ワイド文字列(UTF-16)
	//	u8"Hello World";	//UTF-8
	//	u"Hello World";		//UTF-16
	//	U"Hello World";		//UTF-32
	//}

	void OutputDebug(const std::u32string& str)
	{
		::OutputDebugStringW(String::ToUtf16(str).c_str());
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

	std::cout << sizeof("あい") << '\n';		//2byte * 2 + NULL文字1byte = 5byte
	std::cout << sizeof(u8"あい") << '\n';		//日本語3byte * 2 + NULL文字1byte = 7byte
	std::cout << sizeof(u"あい") << '\n';		//日本語3byte * 2 + NULL文字1byte = 7byte
	std::cout << sizeof(U"あい") << '\n';		//日本語3byte * 2 + NULL文字1byte = 7byte

	HoriEngine::Debug::OutputDebug(U"Hello, World");

	HoriEngine::Debug::CloseConsole();

	return 0;
}