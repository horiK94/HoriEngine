#include "Color.hpp"
#include "Debug.hpp"
#include "Image.hpp"
#include "Unicode.hpp"
#include <Windows.h>

using namespace HoriEngine::Debug;
using namespace HoriEngine::String;
using namespace HoriEngine;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
	OpenConsole();

	{
		HoriEngine::Image image("sample_image.bmp");
		image.save("sample_image_copy.bmp");
	}

	{
		HoriEngine::Image image("ryo_san.jpg");
		Color& color1 = image[0][1];
		image.save("ryo_san_copy.bmp");
	}

	OutputDebug(U"Finished!");

	CloseConsole();

	return 0;
}