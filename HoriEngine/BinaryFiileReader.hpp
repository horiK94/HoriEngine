#pragma once

#include <fstream>
#include <iosfwd>
#include <string>
#include "Unicode.hpp"
#include "Debug.hpp"

using namespace HoriEngine::String;
using namespace HoriEngine::Debug;

namespace HoriEngine::File
{
	class BinaryFileReader
	{
	public:
		/// @brief デフォルトコンストラクタ
		[[nodiscard]]
		BinaryFileReader() = default;

		/// @brief コンストラクタ
		/// @param filename 
		[[nodiscard]]
		explicit BinaryFileReader(const std::string& filename)
		{
			file.open(filename, std::ios::binary);

			if (file.is_open())
			{
				file.seekg(0, std::ios::end);
				fileSize = file.tellg();
				file.seekg(0, std::ios::beg);
			}
			else
			{
				OutputDebug(U"ファイルを開けませんでした : " + ToString(filename));
			}
		}

		/// @brief ファイルを開けているか
		/// @return 
		[[nodiscard]]
		bool isOpen() const
		{
			return file.is_open();
		}

		/// @brief ファイルを開けているか
		[[nodiscard]]
		explicit operator bool() const
		{
			return isOpen();
		}

		/// @brief ファイルサイズ
		/// @return 
		[[nodiscard]]
		std::int64_t size() const
		{
			return fileSize;
		}

		/// @brief 読み取り
		/// @param buffer 
		/// @param size 
		void read(void* buffer, size_t size)
		{
			file.read(static_cast<char*>(buffer), size);
		}

		/// @brief 読み取り位置
		/// @return 
		[[nodiscard]]
		std::int64_t pos()
		{
			return file.tellg();
		}

		/// @brief 閉じる
		void close()
		{
			file.close();
			fileSize = 0;
		}

	private:
		/// @brief ファイル
		std::ifstream file;
		/// @brief ファイルサイズ
		std::int64_t fileSize = 0;
	};
}
