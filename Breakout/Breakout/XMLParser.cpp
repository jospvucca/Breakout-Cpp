#include "XMLParser.h"
#include "XMLTags.h"
#include <iostream>
#include <filesystem>

XMLParser::XMLParser(const std::string fileName) : fileName(fileName)
{
	std::cout << "---> XMLParser::ctor(" + fileName + ")." << std::endl;
}

bool XMLParser::loadFile() {

	pugi::xml_parse_result result = document.load_file(fileName.c_str());

	if (result.status != pugi::xml_parse_status::status_ok) {
		std::cout << "---> XMLParser::loadFile ---! Error loading file " << fileName << ": " << result.description() << std::endl;
		return false;
	}

	return true;
}

void XMLParser::parseData() {
	if (!loadFile()) {
		std::cout << "---> XMLParser::parseData ---! File could not be loaded with name: " + fileName + "..." << std::endl;
	}

	std::cout << "---> XMLParser::parseData ---> File successfully loaded." << std::endl;

    // Access XML data
    pugi::xml_node root = document.child(XMLTags::ROOT);

    parseLevelData(root);
    parseBrickTypes(root);
    parsePositionData(root);
}

void XMLParser::parseLevelData(const pugi::xml_node& root) {
    int rowCount = root.attribute(XMLTags::ROW_COUNT).as_int();
    int columnCount = root.attribute(XMLTags::COLUMN_COUNT).as_int();
    int rowSpacing = root.attribute(XMLTags::ROW_SPACING).as_int();
    int columnSpacing = root.attribute(XMLTags::COLUMN_SPACING).as_int();
    std::string backgroundTexture = root.attribute(XMLTags::BACKGROUND_TEXTURE).as_string();

    std::cout << "Level Data:" << std::endl;
    std::cout << "RowCount: " << rowCount << std::endl;
    std::cout << "ColumnCount: " << columnCount << std::endl;
    std::cout << "RowSpacing: " << rowSpacing << std::endl;
    std::cout << "ColumnSpacing: " << columnSpacing << std::endl;
    std::cout << "BackgroundTexture: " << backgroundTexture << std::endl;
}

void XMLParser::parseBrickTypes(const pugi::xml_node& root) {
    pugi::xml_node brickTypesNode = root.child(XMLTags::BRICK_TYPES);

    for (pugi::xml_node brickType = brickTypesNode.child(XMLTags::BRICK_TYPE); brickType; brickType = brickType.next_sibling(XMLTags::BRICK_TYPE)) {
        parseBrickData(brickType);
    }
}

void XMLParser::parseBrickData(const pugi::xml_node& brickType) {
    std::string id = brickType.attribute(XMLTags::ID).as_string();
    std::string texture = brickType.attribute(XMLTags::TEXTURE).as_string();
    int hitPoints = brickType.attribute(XMLTags::HIT_POINTS).as_int();
    std::string hitSound = brickType.attribute(XMLTags::HIT_SOUND).as_string();
    std::string breakSound = brickType.attribute(XMLTags::BREAK_SOUND).as_string();
    int breakScore = brickType.attribute(XMLTags::BREAK_SCORE).as_int();

    std::cout << "Brick Type:" << std::endl;
    std::cout << "Id: " << id << std::endl;
    std::cout << "Texture: " << texture << std::endl;
    std::cout << "HitPoints: " << hitPoints << std::endl;
    std::cout << "HitSound: " << hitSound << std::endl;
    std::cout << "BreakSound: " << breakSound << std::endl;
    std::cout << "BreakScore: " << breakScore << std::endl;
}

void XMLParser::parsePositionData(const pugi::xml_node& root) {
    std::string bricksData = root.child_value(XMLTags::BRICK_PLACEMENT);
    std::cout << "Bricks Data: " << bricksData << std::endl;
}