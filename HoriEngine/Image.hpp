#pragma once
#include <cstdint>
#include <vector>
#include "Color.hpp"

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
		explicit Image(const std::string& filePath);
		[[nodiscard]]
		explicit Image(int32_t width, int32_t height, const Color& color = White);

		void resize(int32_t width, int32_t height, const Color& color = White);

		std::int32_t width() const;
		std::int32_t height() const;

		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const;

		Color* data();
		const Color* data() const;

		Color* operator[](std::int32_t y);
		const Color* operator[](std::int32_t y) const;

		[[nodiscard]]
		explicit operator bool() const;

		[[nodiscard]]
		bool isEmpty() const;

		bool save(const std::string& fileName);

	private:
		std::vector<Color> m_pixels;		//データは左上から記録
		std::int32_t m_width = 0;
		std::int32_t m_height = 0;
	};
}