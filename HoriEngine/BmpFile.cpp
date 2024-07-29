#pragma once
#include "Image.hpp"
#include "BmpHeader.hpp"
#include "BinaryFileReader.hpp"
#include "BinaryFileWriter.hpp"
#include "Math.hpp"

namespace HoriEngine
{
	const int32_t colorChannelCount = 3;
	const int32_t colorSupportBit = 24;

	/// @brief BMPファイルの読み込み
	/// @param fileName 
	Image LoadBMP(const std::string& fileName)
	{
		BinaryFileReader reader(fileName);
		if (!reader)
		{
			OutputDebug(U"file not Opened");
			return {};
		}

		BMPHeader header;
		reader.read(&header, sizeof(BMPHeader));

		if (header.bfType != 0x4d42)
		{
			OutputDebug(U"file is not BMP");
			return {};
		}

		if (header.biSize != 40)
		{
			OutputDebug(U"OS/2は非サポート");
			return {};
		}

		if (header.biCompression)
		{
			OutputDebug(U"圧縮されたBMPは非サポート");
			return {};
		}

		const bool isTopDown = header.biHeight < 0;
		const int32_t width = header.biWidth;
		const int32_t height = isTopDown ? -header.biHeight : header.biHeight;

		if (!Math::InRange(width, 1, Image::MaxSize))
		{
			OutputDebug(U"widthのサイズが不正です");
			return {};
		}

		if (!Math::InRange(height, 1, Image::MaxSize))
		{
			OutputDebug(U"heightのサイズが不正です");
			return {};
		}

		if (header.biBitCount != colorSupportBit)
		{
			OutputDebug(U"24bit以外のBMPは非サポート");
			return {};
		}

		//以下、サポートしているBMPファイル
		Image result{ width , height };

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
					result[i][j] = color;
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
					std::uint32_t startByteIndex = j * 3;

					//BGRBGR...の順番で記録されている
					Color color = Color(line[startByteIndex + 2], line[startByteIndex + 1], line[startByteIndex]);
					result[height - 1 - i][j] = color;
				}
			}
		}

		return result;
	}

	//TODO: 4の倍数ではないものにも対応する
	bool SaveBMP(const std::string& fileName, const Image& image)
	{
		//bfSizeはファイル全体のbyteサイズ
		uint32_t filePixel = image.getWidth() * image.getHeight();
		uint32_t fileByteSize = colorChannelCount * filePixel;
		BMPHeader header = BMPHeader::Make(image.getWidth(), image.getHeight(), fileByteSize);

		BinaryFileWriter writer(fileName);
		if (!writer.isOpen())
		{
			return false;
		}

		writer.write(&header, sizeof(BMPHeader));

		std::vector<std::uint8_t> line(fileByteSize);

		for (size_t i = 0; const auto& color : image)
		{
			line[i * 3] = color.b;
			line[i * 3 + 1] = color.g;
			line[i * 3 + 2] = color.r;

			i++;
		}

		writer.write(line.data(), fileByteSize);
		return true;
	}
}
