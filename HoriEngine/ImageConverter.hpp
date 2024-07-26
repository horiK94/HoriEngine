#pragma once
#include "Image.hpp"
#include "Math.hpp"
#include "Debug.hpp"
#include "Unicode.hpp"

using namespace HoriEngine;

namespace HoriEngine::Image
{
	Image ConvertToGray(const Image& image)
	{
		Image grayImage;
		grayImage.width = image.width;
		grayImage.height = image.height;
		grayImage.pixels = std::vector<Color>(image.width * image.height);

		for (int32_t i = 0; i < image.pixels.size(); i++)
		{
			Color color = image.pixels[i];
			uint16_t gray = static_cast<uint16_t>(color.r * 0.21 + color.g * 0.72 + color.b * 0.07);
			grayImage.pixels[i] = Color(gray, gray, gray);
		}
		return grayImage;
	}

	Image ConvertSepia(const Image& image)
	{
		Image sepiaImage;
		sepiaImage.width = image.width;
		sepiaImage.height = image.height;
		sepiaImage.pixels = std::vector<Color>(image.width * image.height);

		for (int32_t i = 0; i < image.pixels.size(); i++)
		{
			Color color = image.pixels[i];
			uint16_t r = static_cast<uint16_t>(color.r * 0.393 + color.g * 0.769 + color.b * 0.189);
			r = Math::Clamp(r, 0, 255);
			uint16_t g = static_cast<uint16_t>(color.r * 0.349 + color.g * 0.686 + color.b * 0.168);
			g = Math::Clamp(g, 0, 255);
			uint16_t b = static_cast<uint16_t>(color.r * 0.272 + color.g * 0.534 + color.b * 0.131);
			b = Math::Clamp(b, 0, 255);
			sepiaImage.pixels[i] = Color(r, g, b);
		}
		return sepiaImage;
	}
}