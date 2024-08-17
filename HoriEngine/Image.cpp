#include "Image.hpp"
#include "BmpFile.hpp"
#include "JpegFile.hpp"
#include "PngFile.hpp"
#include "Debug.hpp"
#include "File.hpp"

namespace HoriEngine
{
	Image::Image(const std::string& filePath)
	{
		if (filePath.ends_with(".bmp"))
		{
			*this = LoadBMP(filePath);
		}
		else if (filePath.ends_with(".jpg") || filePath.ends_with(".jpeg"))		//TODO: 大文字も対応しよう
		{
			*this = LoadJPEG(filePath);
		}
		else if (filePath.ends_with(".png"))
		{
			*this = LoadPNG(filePath);
		}
		else
		{
			Debug::OutputDebug(U"対応していないファイル形式です");
		}
	}

	Image::Image(int32_t width, int32_t height, const Color& color)
		: m_pixels(width* height, color), m_width(width), m_height(height)
	{
	}

	void Image::resize(int32_t width, int32_t height, const Color& color)
	{
		m_pixels.assign(width * height, color);
		m_width = width;
		m_height = height;
	}

	std::int32_t Image::width() const
	{
		return m_width;
	}

	std::int32_t Image::height() const
	{
		return m_height;
	}

	Image::iterator Image::begin()
	{
		return m_pixels.begin();
	}

	Image::iterator Image::end()
	{
		return m_pixels.end();
	}

	Image::const_iterator Image::begin() const
	{
		return m_pixels.begin();
	}

	Image::const_iterator Image::end() const
	{
		return m_pixels.end();
	}

	Color* Image::data()
	{
		return m_pixels.data();
	}

	const Color* Image::data() const
	{
		return m_pixels.data();
	}

	Color* Image::operator[](std::int32_t y)
	{
		//ライブラリ開発者の場合、範囲外チェックを行う設計もあり(トレードオフ)
		return m_pixels.data() + y * m_width;
		//return &m_pixels[y * m_width];と同じ. 左の方が呼び出すメンバ関数が少ない(デバッグ版だと範囲外チェックが行われる)が、左だと範囲外チェックはされないので自分でチェックする必要がある
	}

	const Color* Image::operator[](std::int32_t y) const
	{
		return m_pixels.data() + y * m_width;
	}

	Image::operator bool() const
	{
		return !m_pixels.empty();
	}

	bool Image::isEmpty() const
	{
		return m_pixels.empty();
	}

	bool Image::save(const std::string& filePath) const
	{
		if (filePath.find("/") != std::string::npos)
		{
			CreateDirectoryHierarchy(filePath);
		}

		if (filePath.ends_with(".bmp"))
		{
			return SaveBMP(filePath, *this);
		}
		if (filePath.ends_with(".png"))
		{
			return SavePNG(filePath, *this);
		}

		Debug::OutputDebug(U"対応していないファイル形式です");
		return false;
	}
}
