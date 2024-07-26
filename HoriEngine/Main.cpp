#include <Windows.h>
#include "Unicode.hpp"
#include "Debug.hpp"
#include "Color.hpp"
#include "BmpFile.hpp"
#include "BinaryFileWriter.hpp"
#include "BinaryFiileReader.hpp"
#include "ImageConverter.hpp"

using namespace HoriEngine::Debug;
using namespace HoriEngine::String;
using namespace HoriEngine::Image;
using namespace HoriEngine::File;
using namespace HoriEngine;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
	OpenConsole();

	BmpFile bmp("sample_image_copy.bmp");
	bmp.Write("sample_image_copy2.bmp");

	//BmpFile grayBmp;
	//grayBmp.image = ConvertToGray(bmp.image);
	//grayBmp.Write("sample_image_gray.bmp");

	BmpFile sepiaBmp;
	sepiaBmp.image = ConvertSepia(bmp.image);
	sepiaBmp.Write("sample_image_sepia.bmp");

	OutputDebug(U"Finished!");

	CloseConsole();

	return 0;
}