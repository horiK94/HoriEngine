#pragma once
#include <string>
namespace HoriEngine
{
	class Image;
	/// @brief BMPファイルの読み込み
	/// @param fileName 
	Image LoadBMP(const std::string& fileName);

	bool SaveBMP(const std::string& fileName, const Image& image);
}
