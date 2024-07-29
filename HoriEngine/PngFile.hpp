#pragma once
#include <string>
namespace HoriEngine
{
	class Image;
	/// @brief PNGファイルの読み込み
	/// @param fileName 
	Image LoadPNG(const std::string& fileName);
	//TODO: いつかやる
	//bool SavePNG(const std::string& fileName, const Image& image);
}
