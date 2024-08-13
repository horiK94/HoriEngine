#include "File.hpp"
#include <filesystem>

namespace HoriEngine
{
	void CreateDirectoryHierarchy(const std::string& pathText)
	{
		std::filesystem::path path = pathText;

		if (path.is_absolute())
		{
			//��΃p�X�w��Ȃ̂ŁA���΃p�X�ɕϊ�
			path = std::filesystem::relative(path);
		}

		std::filesystem::path createDirectoryPath = path.remove_filename();
		std::filesystem::create_directories(createDirectoryPath);
	}
}