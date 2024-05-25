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
	/// @brief �R���\�[�����J��
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
		::FreeConsole();		//Alloc�������̂����
	}

	//void OutputDebug(std::string str)		//ShiftJIS�@-> UTF-8(�ݒ�ŕύX)
	//{
	//	//OutputDebugStringA��OS�̃f�t�H���g�����G���R�[�f�B���O���ݒ肳���
	//	::OutputDebugStringA("Hello World");		//�}���`�o�C�g������. (���ɂ�邪�A���{�ꂾ�ƃf�t�H���g)SHIFT-JIS
	//	::OutputDebugStringW(L"Hello World");		//���C�h������(UTF-16)
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
	//�E�B���h�E���ǂ��\�����邩�̕��@. �\�����@���Q�l�ɂ��Ă��������ŕς��鏈���������Ă����邱�Ƃ��ł���. 10: SW_SHOWDEFAULT �Ńf�t�H���g�̕\�����@�ɂȂ�. �]��Ȃ���OK
	//�Ăяo�����̕ς��� 
	std::cout << nCmdShow << '\n';

	std::cout << sizeof("����") << '\n';		//2byte * 2 + NULL����1byte = 5byte
	std::cout << sizeof(u8"����") << '\n';		//���{��3byte * 2 + NULL����1byte = 7byte
	std::cout << sizeof(u"����") << '\n';		//���{��3byte * 2 + NULL����1byte = 7byte
	std::cout << sizeof(U"����") << '\n';		//���{��3byte * 2 + NULL����1byte = 7byte

	HoriEngine::Debug::OutputDebug(U"Hello, World");

	HoriEngine::Debug::CloseConsole();

	return 0;
}