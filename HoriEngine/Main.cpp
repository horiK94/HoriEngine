#include "Color.hpp"
#include "Debug.hpp"
#include "Image.hpp"
#include "Unicode.hpp"
#include <Windows.h>

#include "Math.hpp"

using namespace HoriEngine::String;
using namespace HoriEngine;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
	Debug::OpenConsole();

	{
		HoriEngine::Image image("sample_image.bmp");
		image.save("sample_image_copy.bmp");
	}

	{
		HoriEngine::Image image("ryo_san.jpg");
		image.save("ryo_san_copy.bmp");
	}

	{
		HoriEngine::Image image(104, 104);
		image.save("white_104.bmp");
	}

	{
		HoriEngine::Image image(102, 102);
		image.save("white_102.bmp");
	}

	{
		HoriEngine::Image image("yuenchi_family.png");
		image.save("yuenchi_family_copy.bmp");
	}

	Debug::OutputDebug(U"Finished!");

	Debug::CloseConsole();

	return 0;
}