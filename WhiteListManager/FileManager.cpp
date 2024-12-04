#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <string_view>

void FileManager::writeToFile(const std::vector<Entity>& entities, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    for (const Entity& entity : entities) {
        file << entity.getName() << " " << entity.getType() << " " << entity.getWhiteBlack() << "\n";
    }
    file.close();
}

void FileManager::readFromFile(std::vector<Entity>& entities, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for reading." << std::endl;
        return;
    }

    std::string name;
    std::string type;
    WBlisted whiteblack;
    while (file >> name >> type) {
        entities.push_back(Entity(name, type, whiteblack));
    }
    file.close();
}