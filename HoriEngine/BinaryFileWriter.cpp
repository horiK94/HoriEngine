#include "BinaryFileWriter.hpp"
#include "Debug.hpp"
#include "Unicode.hpp"

namespace HoriEngine
{
	BinaryFileWriter::BinaryFileWriter(const std::string& filename)
	{
		file.open(filename, std::ios::binary);

		if (!file.is_open())
		{
			Debug::OutputDebug(U"ファイルを開けませんでした : " + String::FromUtf8(filename));
		}
	}

	bool BinaryFileWriter::isOpen() const
	{
		return file.is_open();
	}

	BinaryFileWriter::operator bool() const
	{
		return isOpen();
	}

	void BinaryFileWriter::write(const void* buffer, size_t size)
	{
		file.write(static_cast<const char*>(buffer), size);
	}

	void BinaryFileWriter::close()
	{
		file.close();
	}
}
