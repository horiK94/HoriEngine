#include "File.hpp"
#include <filesystem>
namespace HoriEngine
{
	void CreateDirectoryHierarchy(const String::Text& pathText)
	{
		std::filesystem::path path = pathText.text;

		if (path.is_absolute())
		{
			//絶対パス指定なので、相対パスに変換
			path = std::filesystem::relative(path);
		}

		std::filesystem::path createDirectoryPath = path.remove_filename();
		std::filesystem::create_directories(createDirectoryPath);
	}
}
