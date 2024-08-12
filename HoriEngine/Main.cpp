#include "Debug.hpp"
#include "Image.hpp"
#include "ImageProcessing.hpp"
#include <Windows.h>

using namespace HoriEngine::String;
using namespace HoriEngine;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
	Debug::OpenConsole();

	{
		HoriEngine::Image baseImage("./Images/yuenchi_family.png");
		FlipVertical(baseImage).save("./Images/yuenchi_flip_vertical.bmp");
		FlipHorizontal(baseImage).save("./Images/yuenchi_flip_horizontal.bmp");

		auto rotate = baseImage;
		for (int i = 1; i < 4; i++)
		{
			rotate =  Rotate90(rotate);
			rotate.save("./Images/yuenchi_rotate_" + String::ToUtf8(ToString(i * 90)) + ".bmp");
		}

		CreateNegativeImage(baseImage).save("./Images/yuenchi_negative.bmp");
		CreateMonochromaticImage(baseImage).save("./Images/yuenchi_monochromatic.bmp");
		CreateSepiaImage(baseImage).save("./hoge/yuenchi_sepia.bmp");
	}

	Debug::OutputDebug(U"Finished!");

	Debug::CloseConsole();

	return 0;
}