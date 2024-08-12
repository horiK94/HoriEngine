#include "ImageProcessing.hpp"

HoriEngine::Image HoriEngine::FlipVertical(const Image& image)
{
	int32_t width = image.width();
	int32_t height = image.height();
	Image result(width, height);

	for (int32_t hi = 0; hi < height; hi++)
	{
		for (int32_t wi = 0; wi < width; wi++)
		{
			result[hi][wi] = image[height - hi - 1][wi];
		}
	}

	return result;
}

HoriEngine::Image HoriEngine::FlipHorizontal(const Image& image)
{
	int32_t width = image.width();
	int32_t height = image.height();
	Image result(width, height);

	for (int32_t hi = 0; hi < height; hi++)
	{
		for (int32_t wi = 0; wi < width; wi++)
		{
			result[hi][wi] = image[hi][width - 1 - wi];
		}
	}

	return result;
}

HoriEngine::Image HoriEngine::Rotate90(const Image& image)
{
	int32_t width = image.width();
	int32_t height = image.height();
	Image result(height, width);

	for (int32_t hi = 0; hi < width; hi++)
	{
		for (int32_t wi = 0; wi < height; wi++)
		{
			result[hi][wi] = image[wi][height - 1 - hi];
		}
	}

	return result;
}

HoriEngine::Image HoriEngine::CreateNegativeImage(const Image& image)
{

	int32_t width = image.width();
	int32_t height = image.height();
	Image result(width, height);

	for (int32_t hi = 0; hi < height; hi++)
	{
		for (int32_t wi = 0; wi < width; wi++)
		{
			Color color = image[hi][wi];
			result[hi][wi] = Color(
				Color::MAX_VALUE - color.r,
				Color::MAX_VALUE - color.g,
				Color::MAX_VALUE - color.b,
				color.a);
		}
	}

	return result;
}

HoriEngine::Image HoriEngine::CreateMonochromaticImage(const Image& image)
{

	int32_t width = image.width();
	int32_t height = image.height();
	Image result(width, height);

	for (int32_t hi = 0; hi < height; hi++)
	{
		for (int32_t wi = 0; wi < width; wi++)
		{
			Color color = image[hi][wi];
			uint8_t gray = static_cast<uint8_t>(0.299 * color.r + 0.587 * color.g + 0.114 * color.b);
			result[hi][wi] = Color(gray, gray, gray, color.a);
		}
	}

	return result;
}

HoriEngine::Image HoriEngine::CreateSepiaImage(const Image& image)
{
	int32_t width = image.width();
	int32_t height = image.height();
	Image result(width, height);

	for (int32_t hi = 0; hi < height; hi++)
	{
		for (int32_t wi = 0; wi < width; wi++)
		{
			Color color = image[hi][wi];
			uint16_t baseR = color.r;
			uint16_t baseG = color.g;
			uint16_t baseB = color.b;

			uint16_t r = static_cast<uint16_t>(0.393 * baseR + 0.769 * baseG + 0.189 * baseB);
			uint16_t g = static_cast<uint16_t>(0.349 * baseR + 0.686 * baseG + 0.168 * baseB);
			uint16_t b = static_cast<uint16_t>(0.272 * baseR + 0.534 * baseG + 0.131 * baseB);

			r = std::min(r, static_cast<uint16_t>(Color::MAX_VALUE));
			g = std::min(g, static_cast<uint16_t>(Color::MAX_VALUE));
			b = std::min(b, static_cast<uint16_t>(Color::MAX_VALUE));

			result[hi][wi] = Color(r, g, b, color.a);
		}
	}

	return result;
}

