#include "Entity.h"
#include <iostream>
#include <algorithm> // for std::transform
#include <cctype>    // for std::tolower
#include <iterator>  // for std::back_inserter
#include <string>
#include <string_view>
#include <optional>



Entity::Entity(const std::string& name, const std::string& type, const WBlisted& whiteblack) : name(name), type(type), whiteblack(whiteblack) {}

void Entity::display() const {
    std::cout << "Entity: " << name << ", Type: " << type << ", Status: " << getWhiteBlack() << std::endl;
}

 std::optional<WBlisted> Entity::updateWhiteBlack(std::string_view delta) {
    
    std::string lower{};
    std::transform(delta.begin(), delta.end(), std::back_inserter(lower),
        [](char c)
        {
            return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        });
    if (lower == "whitelisted") whiteblack = whitelisted;
    if (lower == "blacklisted") whiteblack = blacklisted;
    return {};
}

const std::string& Entity::getName() const {
    return name;
}

const std::string& Entity::getType() const {
    return type;
}
  const std::string_view Entity::getWhiteBlack() const {
    switch (whiteblack) {
    case whitelisted: return "whitelisted";
    case blacklisted: return "blacklisted";
    default: return "???";
    }
    }


