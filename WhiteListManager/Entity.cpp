#include "Entity.h"
#include <iostream>



Entity::Entity(const std::string& name, const std::string& type, const bool& whiteblack) : name(name), type(type), whiteblack(whiteblack) {}

void Entity::display() const {
    std::cout << "Entity: " << name << ", Type: " << type << ", Status: "<< whiteblack << std::endl;
}

void Entity::updateWhiteBlack(bool delta) {
    whiteblack = delta;
}

const std::string& Entity::getName() const {
    return name;
}

const std::string& Entity::getType() const {
    return type;
}
const  bool& Entity::getWhiteBlack() const{
    return whiteblack;
}

