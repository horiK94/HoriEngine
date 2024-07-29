#pragma once
#include <string>
namespace HoriEngine
{
	class Image;
	/// @brief JPEGファイルの読み込み
	/// @param fileName 
	Image LoadJPEG(const std::string& fileName);
	//TODO: いつかやる
	//bool SaveJPEG(const std::string& fileName, const Image& image);
}
