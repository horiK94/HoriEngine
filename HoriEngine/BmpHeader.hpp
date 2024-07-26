#pragma once
#include <cstdint>

namespace HoriEngine::Image
{
# pragma pack (push, 1)
	struct BMPHeader
	{
		std::uint16_t bfType;
		std::uint32_t bfSize;
		std::uint16_t bfReserved1;
		std::uint16_t bfReserved2;
		std::uint32_t bfOffBits;
		std::uint32_t biSize;
		std::int32_t  biWidth;
		std::int32_t  biHeight;
		std::uint16_t biPlanes;
		std::uint16_t biBitCount;
		std::uint32_t biCompression;
		std::uint32_t biSizeImage;
		std::int32_t  biXPelsPerMeter;
		std::int32_t  biYPelsPerMeter;
		std::uint32_t biClrUsed;
		std::uint32_t biClrImportant;

		[[nodiscard]]
		static constexpr BMPHeader Make(std::int32_t width, std::int32_t height, std::uint32_t size_bytes) noexcept
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
	};

	static_assert(sizeof(BMPHeader) == 54);

# pragma pack (pop)
}