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
			BITMAPFILEHEADER  fileHeader;
			ifs.read(reinterpret_cast<char*>(&fileHeader), sizeof(BITMAPFILEHEADER));

			if(fileHeader.bfType == 'B' | ('M' << 8)		//CPU がリトルエンディアン
				|| fileHeader.bfType == ('B' << 8) | 'M')	//CPU がビッグエンディアン
			{
				OutputDebug(U"file is BMP");
			}
			else
			{
				OutputDebug(U"file is not BMP");
			}

			ifs.seekg(14, std::ios_base::beg);		//情報ヘッダの位置まで移動

			std::vector<char> infoHeader(4);
			ifs.read(infoHeader.data(), infoHeader.size());		//read()を呼ぶとヘッダの位置が進むので後で戻す必要がある

			bool isWindowsBitMap = infoHeader[0] == 40;		//40ならWindowsビットマップ

			BITMAPINFOHEADER winInfoHeader;
			BITMAPCOREHEADER os2InfoHeader;

			ifs.seekg(14, std::ios_base::beg);		//情報ヘッダの位置までもう1度移動

			if (isWindowsBitMap)
			{
				OutputDebug(U"WindowsBitMap");
				ifs.read(reinterpret_cast<char*>(&winInfoHeader), sizeof(BITMAPINFOHEADER));

				OutputDebug(U"width: " + ToString(winInfoHeader.biWidth));
				OutputDebug(U"height: " + ToString(winInfoHeader.biHeight));

			}
			else
			{
				OutputDebug(U"OS/2 BitMap");
				ifs.read(reinterpret_cast<char*>(&os2InfoHeader), sizeof(BITMAPCOREHEADER));
			}


		}
	};

}
