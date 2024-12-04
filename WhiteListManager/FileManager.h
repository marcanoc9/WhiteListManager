#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "Entity.h"
#include <string_view>
class FileManager {
public:
    static void writeToFile(const std::vector<Entity>& entities, const std::string& filename);
    static void readFromFile(std::vector<Entity>& entities, const std::string& filename);
};

#endif