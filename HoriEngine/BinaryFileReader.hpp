#pragma once
#include <iosfwd>
#include <fstream>

namespace HoriEngine
{
	class BinaryFileReader
	{
	public:
		/// @brief デフォルトコンストラクタ
		[[nodiscard]]
		BinaryFileReader() = default;

		/// @brief コンストラクタ
		/// @param filename 
		[[nodiscard]] explicit BinaryFileReader(const std::string& filename);

		/// @brief ファイルを開けているか
		/// @return 
		[[nodiscard]] bool isOpen() const;

		/// @brief ファイルを開けているか
		[[nodiscard]] explicit operator bool() const;

		/// @brief ファイルサイズ
		/// @return 
		[[nodiscard]]
		std::int64_t size() const;

		/// @brief 読み取り
		/// @param buffer 
		/// @param size 
		void read(void* buffer, size_t size);

		/// @brief 読み取り位置
		/// @return 
		[[nodiscard]]
		std::int64_t pos();

		/// @brief 閉じる
		void close();

	private:
		/// @brief ファイル
		std::ifstream file;
		/// @brief ファイルサイズ
		std::int64_t fileSize = 0;
	};
}
