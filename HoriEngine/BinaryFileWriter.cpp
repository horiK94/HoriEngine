#include "BinaryFileWriter.hpp"
#include "Debug.hpp"

namespace HoriEngine
{
	BinaryFileWriter::BinaryFileWriter(const String::Text& filename)
	{
		file.open(filename.ToUtf8(), std::ios::binary);

		if (!file.is_open())
		{
			Debug::OutputDebug(U"ファイルを開けませんでした : " + filename);
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
