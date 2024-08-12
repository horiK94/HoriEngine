#pragma once
#include <string>
#include "Debug.hpp"
#include "Unicode.hpp"
#include <filesystem>
#include "vector"

namespace HoriEngine
{
	void CreateDirectoryHierarchy(const std::string& pathText)
	{
		std::filesystem::path path = pathText;

		if (path.is_absolute())
		{
			//絶対パス指定なので、相対パスに変換
			path = std::filesystem::relative(path);
		}

		std::filesystem::path createDirectoryPath = path.remove_filename();
		std::filesystem::create_directories(createDirectoryPath);
	}
}