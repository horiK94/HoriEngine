#include "BmpHeader.hpp"

#include "BmpFile.hpp"

namespace HoriEngine
{
	constexpr BMPHeader BMPHeader::Make(std::int32_t width, std::int32_t height, std::uint32_t size_bytes) noexcept
	{
		return
		{
			.bfType = 0x4d42,
			.bfSize = static_cast<std::uint32_t>(sizeof(BMPHeader) + size_bytes),
			.bfReserved1 = 0,
			.bfReserved2 = 0,
			.bfOffBits = sizeof(BMPHeader),
			.biSize = 40,
			.biWidth = width,
			.biHeight = -height,
			.biPlanes = 1,
			.biBitCount = 24,
			.biCompression = 0,
			.biSizeImage = size_bytes,
			.biXPelsPerMeter = 0,
			.biYPelsPerMeter = 0,
			.biClrUsed = 0,
			.biClrImportant = 0
		};
	}

}
