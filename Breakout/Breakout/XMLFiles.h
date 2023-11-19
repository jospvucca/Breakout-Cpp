#pragma once
#ifndef __XML_FILES_H__
#define __XML_FILES_H__

#include <filesystem>

namespace XMLFiles {
	const static std::string LEVEL_ONE = (std::filesystem::current_path() / "Resources/Input/Level1.xml").string();
	const static std::string LEVEL_TWO = (std::filesystem::current_path() / "Resources/Input/Level2.xml").string();
	const static std::string LEVEL_THREE = (std::filesystem::current_path() / "Resources/Input/Level3.xml").string();
}

#endif // !__XML_FILES_H__
