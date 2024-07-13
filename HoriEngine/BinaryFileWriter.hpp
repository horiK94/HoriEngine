#pragma once
#include <fstream>
#include <iosfwd>
#include <string>
#include "Debug.hpp"

using namespace HoriEngine::Debug;

namespace HoriEngine::File
{
	class BinaryFileWriter
	{
	public:
		/// @brief デフォルトコンストラクタ
		[[nodiscard]]
		BinaryFileWriter() = default;

		/// @brief コンストラクタ
		/// @param filename 
		[[nodiscard]]
		explicit BinaryFileWriter(const std::string& filename)
		{
			file.open(filename, std::ios::binary);

			if (!file.is_open())
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

		/// @brief 書き込み
		/// @param buffer 
		/// @param size 
		void write(const void* buffer, size_t size)
		{
			file.write(static_cast<const char*>(buffer), size);
		}

		/// @brief 閉じる
		void close()
		{
			file.close();
		}

	private:
		/// @brief ファイル
		std::ofstream file;
	};
}