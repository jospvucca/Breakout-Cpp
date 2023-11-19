#include "XMLParser.h"
#include "XMLTags.h"
#include <iostream>

XMLParser::XMLParser(const char* fileName) : fileName(fileName)
{
	std::cout << "---> XMLParser::ctor(" + std::string(fileName) + ")." << std::endl;
}

bool XMLParser::loadFile() {
	return document.load_file(fileName) == pugi::xml_parse_status::status_ok;
}

void XMLParser::parseData() {
	if (!loadFile()) {
		std::cout << "---> XMLParser::parseData ---! File could not be loaded with name: " + std::string(fileName) + "..." << std::endl;
	}

	std::cout << "---> XMLParser::parseData ---> File successfully loaded." << std::endl;

	//Access XML data
	pugi::xml_node root = document.child(XMLTags::ROOT);
	for (pugi::xml_node tool = root.child(XMLTags::TOOL); tool; tool = tool.next_sibling(XMLTags::TOOL)) {
		std::cout << "Tool name: " << tool.attribute(XMLTags::NAME).value() << std::endl;
	}
}