#include "XMLParser.h"
#include "XMLTags.h"
#include <iostream>
#include <sstream>
#include <filesystem>
#include <string>
#include <algorithm>

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

ParseData XMLParser::parseData() {
	if (!loadFile()) {
		std::cout << "---> XMLParser::parseData ---! File could not be loaded with name: " + fileName + "..." << std::endl;
	}

	std::cout << "---> XMLParser::parseData ---> File successfully loaded." << std::endl;

    // Access XML data
    pugi::xml_node root = document.child(XMLTags::ROOT);


    //TODO - create objects with the help of structs from these methods below
    ParseData parseData = ParseData();

    parseData.level = parseLevelData(root);
    parseData.bricks = parseBrickTypes(root);
    parseData.positions = parsePositionData(root);

    return parseData;
    //return { parseLevelData(root), parseBrickTypes(root), parsePositionData(root) };
}

LevelData XMLParser::parseLevelData(const pugi::xml_node& root) {
    std::cout << "---> Parsing Level data from root: " + std::string(root.name()) << std::endl;

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

    //TODO - I would prefer to use Builder pattern here
    LevelData levelData = LevelData();
    levelData.rowCount = rowCount;
    levelData.columnCount = columnCount;
    levelData.rowSpacing = rowSpacing;
    levelData.columnSpacing = columnSpacing;
    levelData.backgroundTexture = backgroundTexture;

    //return levelData;
    return {rowCount, columnCount, rowSpacing, columnSpacing, backgroundTexture};
}

std::vector<BrickData> XMLParser::parseBrickTypes(const pugi::xml_node& root) {
    std::cout << "---> Parsing Level data from root: " + std::string(root.name()) << std::endl; //TODO change description

    pugi::xml_node brickTypesNode = root.child(XMLTags::BRICK_TYPES);

    std::vector<BrickData> brickData = std::vector<BrickData>();
    for (pugi::xml_node brickType = brickTypesNode.child(XMLTags::BRICK_TYPE); brickType; brickType = brickType.next_sibling(XMLTags::BRICK_TYPE)) {
        brickData.emplace_back(parseBrickData(brickType));
    }

    return brickData;
}

BrickData XMLParser::parseBrickData(const pugi::xml_node& brickType) {
    std::cout << "---> Parsing Level data from root: " + std::string(brickType.name()) << std::endl; //TODO change description

    std::string id = brickType.attribute(XMLTags::ID).as_string();
    std::string texture = brickType.attribute(XMLTags::TEXTURE).as_string();
    int hitpoints = brickType.attribute(XMLTags::HIT_POINTS).as_int();
    std::string hitSound = brickType.attribute(XMLTags::HIT_SOUND).as_string();
    std::string breakSound = brickType.attribute(XMLTags::BREAK_SOUND).as_string();
    int breakScore = brickType.attribute(XMLTags::BREAK_SCORE).as_int();

    std::cout << "Brick Type:" << std::endl;
    std::cout << "Id: " << id << std::endl;
    std::cout << "Texture: " << texture << std::endl;
    std::cout << "HitPoints: " << hitpoints << std::endl;
    std::cout << "HitSound: " << hitSound << std::endl;
    std::cout << "BreakSound: " << breakSound << std::endl;
    std::cout << "BreakScore: " << breakScore << std::endl;

    BrickData brickData = BrickData();
    brickData.id = id;
    brickData.texture = texture;
    brickData.hitpoints = hitpoints;
    brickData.hitSound = hitSound;
    brickData.breakSound = breakSound;
    brickData.breakScore = breakScore;

    //return brickData;
    return { id, texture, hitpoints, hitSound, breakSound, breakScore };
}

BrickPositioning XMLParser::parsePositionData(const pugi::xml_node& root) {
    std::cout << "---> Parsing Level data from root: " + std::string(root.name()) << std::endl; //TODO change description

    std::string bricksData = root.child_value(XMLTags::BRICK_PLACEMENT);
    std::cout << "Bricks Data: " << bricksData << std::endl;

    std::vector<std::vector<char>> brickPositions = std::vector<std::vector<char>>();
 
    //Remove spaces
    bricksData.erase(std::remove(bricksData.begin(), bricksData.end(), ' '), bricksData.end());

    std::istringstream iss(bricksData);
    std::string line;
    while (std::getline(iss, line)) {
        std::vector<char> inlinePositions(line.begin(), line.end());
        brickPositions.emplace_back(inlinePositions);   //Posibly push_back instead of emplace
    }

    BrickPositioning brickPositioning = BrickPositioning();
    brickPositioning.brickPositions = brickPositions;

    //return brickPositioning;
    return { brickPositions };
}