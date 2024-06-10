#include <Windows.h>
#include "Unicode.hpp"
#include "Debug.hpp"
#include <fstream>
using namespace HoriEngine::Debug;
using namespace HoriEngine::String;

namespace HoriEngine::FileIO
{

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
	OpenConsole();

	OutputDebug(U"a");
	OutputDebug(U"®");
	OutputDebug(U"あ");
	OutputDebug(U"𩹽");


	//std::ofstream ofs("test.txt");
	std::ifstream ifs("test.txt", std::ios_base::binary);		//バイナリモードで開く
	//std::ifstream ifs("sample_image.bmp", std::ios_base::binary);		//バイナリモードで開く
	if (ifs)
	{
		//最初は0にseek(読み取り位置)がある
		ifs.seekg(0, std::ios_base::end);		//読み取り位置を終端まで行く. 2バイトのテキストならseek(読み取り位置)は2になる
		std::size_t size = ifs.tellg();		//ファイルの先頭から何倍と進んだか = サイズ取得
		OutputDebug(U"file Opened: " + ToString(size));
	}
	else
	{
		OutputDebug(U"file not Opened");
	}

	CloseConsole();

	return 0;
}