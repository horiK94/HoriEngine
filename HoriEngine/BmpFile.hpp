#pragma once
#include <cstdio>
#include <fstream>
#include <iostream>
#include <locale>
#include "BinaryFiileReader.hpp"
#include "BinaryFileWriter.hpp"
#include "Image.hpp"
#include "Math.hpp"

using namespace HoriEngine::Debug;
using namespace HoriEngine::String;
using namespace HoriEngine::File;
using namespace HoriEngine::Math;

namespace HoriEngine::Image
{
	class BmpFile
	{
	public:
		BMPHeader header;
		Image image;

		const int32_t colorChannelCount = 3;
		const int32_t colorSupportBit = 24;

		[[nodiscard]]
		explicit operator bool() const
		{
			return !image.isEmpty();
		}

		BmpFile() = default;

		BmpFile(const std::string& fileName)
		{
			Load(fileName);
		}

		/// @brief BMPファイルの読み込み
		/// @param fileName 
		void Load(const std::string& fileName)
		{
			BinaryFileReader reader(fileName);
			if (!reader)
			{
				OutputDebug(U"file not Opened");
				return;
			}

			reader.read(&header, sizeof(BMPHeader));

			if (header.bfType != 0x4d42)
			{
				OutputDebug(U"file is not BMP");
				return;
			}

			if (header.biSize != 40)
			{
				OutputDebug(U"OS/2は非サポート");
				return;
			}

			if (header.biCompression)
			{
				OutputDebug(U"圧縮されたBMPは非サポート");
				return;
			}

			const bool isTopDown = header.biHeight < 0;
			const int32_t width = header.biWidth;
			const int32_t height = isTopDown ? -header.biHeight : header.biHeight;

			if (!Math::InRange(width, 1, Image::MaxSize))
			{
				OutputDebug(U"widthのサイズが不正です");
				return;
			}

			if (!Math::InRange(height, 1, Image::MaxSize))
			{
				OutputDebug(U"heightのサイズが不正です");
				return;
			}

			if (header.biBitCount != colorSupportBit)
			{
				OutputDebug(U"24bit以外のBMPは非サポート");
				return;
			}

			//以下、サポートしているBMPファイル

			Image result;
			result.pixels.resize(width * height);
			result.width = width;
			result.height = height;

			//1pixel当たりのサイズは3byte
			std::uint32_t bytesPerLine = (width * colorChannelCount);
			if (bytesPerLine % 4 != 0)
			{
				bytesPerLine += 4 - (bytesPerLine % 4);
			}

			std::vector<std::vector<std::uint8_t>> lines(height);
			for (int i = 0; i < height; i++)
			{
				std::vector<std::uint8_t> line(bytesPerLine);
				reader.read(line.data(), bytesPerLine);
				lines[i] = line;
			}

			std::vector<Color> colors(width * height);

			//画像読み込み
			if (isTopDown)
			{
				//左上から右下に記録されている
				for (int i = 0; i < height; i++)
				{
					std::vector<std::uint8_t> line = lines[i];
					for (int j = 0; j < width; j++)
					{
						std::uint32_t colorIndex = i * width + j;
						std::uint32_t startByteIndex = j * 3;

						//BGRBGR...の順番で記録されている
						Color color = Color(line[startByteIndex + 2], line[startByteIndex + 1], line[startByteIndex]);
						colors[colorIndex] = color;
					}
				}
			}
			else
			{
				//左下から右上に記録されている
				for (int i = 0; i < height; i++)
				{
					std::vector<std::uint8_t> line = lines[i];
					for (int j = 0; j < width; j++)
					{
						std::uint32_t colorIndex = (height - 1 - i) * width + j;
						std::uint32_t startByteIndex = j * 3;

						//BGRBGR...の順番で記録されている
						Color color = Color(line[startByteIndex + 2], line[startByteIndex + 1], line[startByteIndex]);
						colors[colorIndex] = color;
					}
				}
			}

			result.pixels = colors;
			image = result;
		}

		bool Write(const std::string& fileName)
		{
			//bfSizeはファイル全体のbyteサイズ
			uint32_t filePixel = image.width * image.height;
			uint32_t fileByteSize = colorChannelCount * filePixel;
			BMPHeader header = BMPHeader::Make(image.width, image.height, fileByteSize);

			BinaryFileWriter writer(fileName);
			if (!writer.isOpen())
			{
				return false;
			}

			writer.write(&header, sizeof(BMPHeader));

			std::vector<std::uint8_t> line(fileByteSize);
			for (int i = 0; i < filePixel; i++)
			{
				Color color = image.pixels[i];
				line[i * 3] = color.b;
				line[i * 3 + 1] = color.g;
				line[i * 3 + 2] = color.r;
			}

			writer.write(line.data(), fileByteSize);

			return true;
		}
	};
}
