#include <Windows.h>

namespace HoriEngine
{
	void Main();
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
	HoriEngine::Main();
	return 0;
}