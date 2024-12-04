#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <string_view>
#include<optional>
enum WBlisted {
    whitelisted,
    blacklisted,

};
class Entity {
public:
    Entity(const std::string& name, const std::string& type,  const WBlisted& whiteblack);

    virtual void display() const;
    const std::string_view getWhiteBlack() const;
    const std::string& getName() const;
    const std::string& getType() const;
      std::optional<WBlisted>  updateWhiteBlack(std::string_view delta);
private:
    std::string name;
    std::string type;
    WBlisted whiteblack = blacklisted;
};


#endif