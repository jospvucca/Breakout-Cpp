#pragma once
#ifndef __XML_PARSER_H__
#define __XML_PARSER_H__

#include "../Libraries/pugixml-master/src/pugixml.hpp"
#include "ParseData.h"

class XMLParser final {
public:
	XMLParser(const std::string fileName);
	ParseData parseData();

protected:
	bool loadFile();
	LevelData parseLevelData(const pugi::xml_node& root);
	std::vector<BrickData> parseBrickTypes(const pugi::xml_node& root);
	BrickData parseBrickData(const pugi::xml_node& brickType);
	BrickPositioning parsePositionData(const pugi::xml_node& root);

private:
	pugi::xml_document document;
	const std::string fileName;
};

#endif // !__XML_PARSER_H__
