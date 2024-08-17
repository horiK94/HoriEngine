#include "Image.hpp"
#include "PngFile.hpp"
#include "BinaryFileReader.hpp"

#define STB_IMAGE_STATIC
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define __STDC_LIB_EXT1__
#include "BinaryFileWriter.hpp"
#include "stb_image_write.h"

namespace HoriEngine
{
	Image LoadPNG(const std::string& fileName)
	{
		BinaryFileReader reader(fileName);

		std::vector<unsigned char> buffer(reader.size());
		reader.read(buffer.data(), buffer.size());
		int32_t width = 0;
		int32_t height = 0;
		int32_t channels = 0;
		unsigned char* pixels = stbi_load_from_memory(buffer.data(), buffer.size(), &width, &height, &channels, 4);

		Image image{ width, height };

		for (int64_t i = 0; auto & pixel : image)
		{
			pixel.r = pixels[i * 4 + 0];
			pixel.g = pixels[i * 4 + 1];
			pixel.b = pixels[i * 4 + 2];
			pixel.a = pixels[i * 4 + 3];
			i++;
		}

		stbi_image_free(pixels);
		return image;
	}

	bool SavePNG(const std::string& fileName, const Image& image)
	{
		std::vector<unsigned char> pixels(image.width() * image.height() * 4);
		int64_t i = 0;
		for (const auto& pixel : image)
		{
			pixels[i * 4 + 0] = pixel.r;
			pixels[i * 4 + 1] = pixel.g;
			pixels[i * 4 + 2] = pixel.b;
			pixels[i * 4 + 3] = pixel.a;
			i++;
		}

		int len;
		unsigned char* pngBuffer = stbi_write_png_to_mem(pixels.data(), image.width() * 4, image.width(), image.height(), 4, &len);

		BinaryFileWriter writer(fileName);
		writer.write(pngBuffer, len);

		//return stbi_write_png(fileName.c_str(), image.width(), image.height(), 4, pixels.data(), image.width() * 4) != 0;
		return true;
	}
}
