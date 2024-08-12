#pragma once
#include "Image.hpp"
#include <cstdint>
namespace HoriEngine
{
	//// @brief 画像の上下反転
	Image FlipVertical(const Image& image);

	///// @brief 画像の左右反転
	Image FlipHorizontal(const Image& image);

	///// @brief 画像の回転
	Image Rotate90(const Image& image);

	///// @brief 画像のネガポジ変換
	Image CreateNegativeImage(const Image& image);
	///// @brief 画像のモノクロ化
	Image CreateMonochromaticImage(const Image& image);
	///// @brief 画像のセピア化
	Image CreateSepiaImage(const Image& image);
}
