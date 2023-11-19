#pragma once
#ifndef __XML_PARSER_H__
#define __XML_PARSER_H__

#include "../Libraries/pugixml-master/src/pugixml.hpp"

class XMLParser {
public:
	XMLParser(const char* fileName);
	void parseData();

protected:
	bool loadFile();

private:
	pugi::xml_document document;
	const char* fileName;
};

#endif // !__XML_PARSER_H__
