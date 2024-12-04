#include <iostream>
#include <vector>
#include "Entity.h"
#include "WhiteBlackList.h"
#include "FileManager.h"
#include <string_view>



int main() {
    std::vector<Entity> entities;
    std::string filename = "WhiteBlackList.txt";
    
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Entity\n";
        std::cout << "2. Update White-Black Status\n";
        std::cout << "3. Display Entities\n";
        std::cout << "4. Display Whitelist\n";
        std::cout << "5. display Blacklist\n";
        std::cout << "5. Save to File\n";
        std::cout << "6. Load from File\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string name;
            std::string type;
            WBlisted whiteblack;
            std::cout << "Enter Entity Name: ";
            std::cin >> name;
            std::cout << "Enter Type: ";
            std::cin >> type;
            entities.push_back(Entity(name, type, whiteblack));
            break;
        }
        case 2: {
            std::string name;
            std::string delta;
            std::cout << "Enter Entity Name: ";
            std::cin >> name;
            std::cout << "Enter Status (whitelisted or blacklisted): ";
            std::cin >> delta;
            for (Entity& entity : entities) {
                if (entity.getName() == name) {
                    entity.updateWhiteBlack(delta);
                    break;
                }
            }
            break;
        }
        case 3: {
            std::cout << "\nCurrent Products:\n";
            for (const Entity& entity : entities) {
                entity.display();
            }
            break;
        }
        case 4: {
            std::cout << "\nWhite Listed Entities:\n";
            for (const Entity& entity : entities) {
                if (entity.getWhiteBlack() == "whitelisted") {
                    entity.display();
                }
            }
            break;
        }
        case 5: {
            std::cout << "/nBlack Listed Entities\n";
            for (const Entity& entity : entities) {
                if (entity.getWhiteBlack() == 0) {
                    entity.display();
                }
            }
            break;
        }

        case 6: {
            FileManager::writeToFile(entities, filename);
            std::cout << "Data saved to file: " << filename << std::endl;
            break;
        }
        case 7: {
            FileManager::readFromFile(entities, filename);
            std::cout << "Data loaded from file: " << filename << std::endl;
            break;
        }
        case 0:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}