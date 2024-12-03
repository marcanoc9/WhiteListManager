#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
public:
    Entity(const std::string& name, const std::string& type, const bool& whiteblack);

    virtual void display() const;
    const bool& getWhiteBlack() const;
    const std::string& getName() const;
    const std::string& getType() const;
   virtual void updateWhiteBlack(bool delta);
private:
    std::string name;
    std::string type;
    bool whiteblack;
};


#endif