#pragma once
#include <cstdio>
#include <fstream>
#include <iostream>
#include <locale>

using namespace HoriEngine::Debug;
using namespace HoriEngine::String;

namespace HoriEngine::Image
{
	class BmpFile
	{
	public:
		BmpFile(std::string fileName)
		{
			std::ifstream ifs(fileName, std::ios_base::binary);		//バイナリモードで開く
			if (!ifs)
			{
				OutputDebug(U"file not Opened");
				return;
			}

			//最初は0にseek(読み取り位置)がある
			ifs.seekg(0, std::ios_base::end);		//読み取り位置を終端まで行く. 2バイトのテキストならseek(読み取り位置)は2になる
			std::size_t size = ifs.tellg();		//ファイルの先頭から何倍と進んだか = サイズ取得
			OutputDebug(U"file Opened: " + ToString(size));

			ifs.seekg(0, std::ios_base::beg);
			std::vector<char> buffer(2);
			ifs.read(buffer.data(), buffer.size());

			if(buffer[0] == 0x42 && buffer[1] == 0x4D)
			{
				OutputDebug(U"file is BMP");
			}
			else
			{
				OutputDebug(U"file is not BMP");
			}
		}
	};

}
