#include <Windows.h>
#include "Unicode.hpp"
#include "Debug.hpp"
#include "Color.hpp"
#include "BmpFile.hpp"
#include "BinaryFileWriter.hpp"
#include "BinaryFiileReader.hpp"

using namespace HoriEngine::Debug;
using namespace HoriEngine::String;
using namespace HoriEngine::Image;
using namespace HoriEngine::File;
using namespace HoriEngine;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
	OpenConsole();

	BmpFile bmp("sample_image.bmp");
	bmp.SaveBmp("sample_image_copy.bmp");

	BinaryFileWriter writer("sample_image_copy.txt");
	writer.write("A", 1);


	CloseConsole();

	return 0;
}