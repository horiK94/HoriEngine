#pragma once
#include <cstdint>
#include <vector>
#include "Color.hpp"
#include "BmpHeader.hpp"


namespace HoriEngine::Image
{
	class Image
	{
	public:
		static constexpr std::int32_t MaxSize = 16384;

		std::vector<Color> pixels
;		//�f�[�^�͍��ォ��L�^
		std::int32_t width = 0;
		std::int32_t height = 0;

		[[nodiscard]]
		explicit operator bool() const
		{
			return !pixels.empty();
		}

		[[nodiscard]]
		bool isEmpty() const
		{
			return pixels.empty();
		}
	};
}