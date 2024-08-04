#include "BinaryFileReader.hpp"
#include "TypeDefine.hpp"
#include <string>
#include "Debug.hpp"


namespace HoriEngine
{
	BinaryFileReader::BinaryFileReader(const std::string& filename)
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
			HoriEngine::Debug::OutputDebug(U"ファイルを開けませんでした : " + HoriEngine::String::FromUtf8(filename));
		}
	}

	bool BinaryFileReader::isOpen() const
	{
		return file.is_open();
	}

	BinaryFileReader::operator bool() const
	{
		return isOpen();
	}

	std::int64_t BinaryFileReader::size() const
	{
		return fileSize;
	}

	void BinaryFileReader::read(void* buffer, size_t size)
	{
		file.read(static_cast<char*>(buffer), size);
	}

	std::int64_t BinaryFileReader::pos()
	{
		return file.tellg();
	}

	void BinaryFileReader::close()
	{
		file.close();
		fileSize = 0;
	}
}
