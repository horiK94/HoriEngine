#pragma once
#include "Text.hpp"
namespace HoriEngine
{
	class Image;
	/// @brief BMPファイルの読み込み
	/// @param fileName 
	Image LoadBMP(const String::Text& fileName);

	bool SaveBMP(const String::Text& fileName, const Image& image);
}
