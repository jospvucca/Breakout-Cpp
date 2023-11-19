#pragma once
#ifndef __XML_PARSER_H__
#define __XML_PARSER_H__

#include "../Libraries/pugixml-master/src/pugixml.hpp"

class XMLParser {
public:
	XMLParser(const std::string fileName);
	void parseData();

protected:
	bool loadFile();
	void parseLevelData(const pugi::xml_node& root);
	void parseBrickTypes(const pugi::xml_node& root);
	void parseBrickData(const pugi::xml_node& brickType);
	void parsePositionData(const pugi::xml_node& root);

private:
	pugi::xml_document document;
	const std::string fileName;
};

#endif // !__XML_PARSER_H__
