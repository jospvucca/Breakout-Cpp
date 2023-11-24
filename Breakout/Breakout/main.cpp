// Breakout.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "XMLParser.h"
#include "XMLFiles.h"
#include "LevelFactory.h"
#include <iostream>

int main()
{
    std::cout << "File name: " + std::string(XMLFiles::LEVEL_ONE) << std::endl;

    int levelCounter = 1;

    XMLParser xmlParser(XMLFiles::LEVEL_ONE);
    ParseData levelConfigData = xmlParser.parseData();
    LevelConfig config = LevelConfig(levelCounter, levelConfigData.level.rowCount, levelConfigData.level.columnCount,
        levelConfigData.level.rowSpacing, levelConfigData.level.columnSpacing, levelConfigData.level.backgroundTexture, levelConfigData.positions.brickPositions);

    std::unique_ptr<Level> currentLevel = LevelFactory::createLevelFromConfig(1, config);
    
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
