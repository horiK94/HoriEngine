#include "Image.hpp"
#include "JpegFile.hpp"
#include "BinaryFileReader.hpp"

#define STB_IMAGE_STATIC
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace HoriEngine
{
	Image LoadJPEG(const std::string& fileName)
	{
		BinaryFileReader reader(fileName);

		std::vector<unsigned char> buffer(reader.size());
		reader.read(buffer.data(), buffer.size());
		int32_t width = 0;
		int32_t height = 0;
		int32_t channels = 0;
		unsigned char* pixels = stbi_load_from_memory(buffer.data(), buffer.size(), &width, &height, &channels, 3);

		Image image{ width, height };

		for (int64_t i = 0; auto & pixel : image)
		{
			pixel.r = pixels[i * 3 + 0];
			pixel.g = pixels[i * 3 + 1];
			pixel.b = pixels[i * 3 + 2];
			i++;
		}

		stbi_image_free(pixels);
		return image;
	}
}
