#include <Windows.h>
#include <iostream>

namespace HoriEngine::Debug
{
	/// @brief �R���\�[�����J��
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
	//�E�B���h�E���ǂ��\�����邩�̕��@. �\�����@���Q�l�ɂ��Ă��������ŕς��鏈���������Ă����邱�Ƃ��ł���. 10: SW_SHOWDEFAULT �Ńf�t�H���g�̕\�����@�ɂȂ�. �]��Ȃ���OK
	//�Ăяo�����̕ς��� 
	std::cout << nCmdShow << '\n';

	getchar();
	::FreeConsole();		//Alloc�������̂����

	return 0;
}