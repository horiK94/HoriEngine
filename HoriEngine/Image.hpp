#pragma once
#include <cstdint>
#include <vector>
#include "Color.hpp"
#include "BmpFile.hpp"
#include "JpegFile.hpp"

namespace HoriEngine
{
	class Image
	{
	public:
		static constexpr std::int32_t MaxSize = 16384;

		using iterator = std::vector<Color>::iterator;
		using const_iterator = std::vector<Color>::const_iterator;

		[[nodiscard]]
		Image() = default;

		[[nodiscard]]
		explicit Image(const std::string& filePath)
		{
			//TODO: パスも指定できるようになると嬉しい
			if (filePath.ends_with(".bmp"))
			{
				*this = LoadBMP(filePath);
			}
			else if (filePath.ends_with(".jpg") || filePath.ends_with(".jpeg"))		//TODO: 大文字も対応しよう
			{
				*this = LoadJPEG(filePath);
			}
		}

		explicit Image(int32_t width, int32_t height, const Color& color = White)
			: m_pixels(width* height, color), m_width(width), m_height(height)
		{
		}

		void resize(int32_t width, int32_t height, const Color& color = White)
		{
			m_pixels.assign(width * height, color);
			m_width = width;
			m_height = height;
		}

		std::int32_t getWidth() const
		{
			return m_width;
		}

		std::int32_t getHeight() const
		{
			return m_height;
		}

		iterator begin()
		{
			return m_pixels.begin();
		}

		iterator end()
		{
			return m_pixels.end();
		}

		const_iterator begin() const
		{
			return m_pixels.begin();
		}

		const_iterator end() const
		{
			return m_pixels.end();
		}

		Color* data()
		{
			return m_pixels.data();
		}

		const Color* data() const
		{
			return m_pixels.data();
		}

		Color* operator[](std::int32_t y)
		{
			//ライブラリ開発者の場合、範囲外チェックを行う設計もあり(トレードオフ)
			return m_pixels.data() + y * m_width;		//return &m_pixels[y * m_width];と同じ. 左の方が呼び出すメンバ関数が少ない(デバッグ版だと範囲外チェックが行われる)が、左だと範囲外チェックはされないので自分でチェックする必要がある
		}

		const Color* operator[](std::int32_t y) const
		{
			return m_pixels.data() + y * m_width;
		}

		[[nodiscard]]
		explicit operator bool() const
		{
			return !m_pixels.empty();
		}

		[[nodiscard]]
		bool isEmpty() const
		{
			return m_pixels.empty();
		}

		bool save(const std::string& fileName)
		{
			return SaveBMP(fileName, *this);
		}

	private:
		std::vector<Color> m_pixels;		//データは左上から記録
		std::int32_t m_width = 0;
		std::int32_t m_height = 0;
	};
}