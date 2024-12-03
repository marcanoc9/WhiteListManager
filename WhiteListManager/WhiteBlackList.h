/* #ifndef WHITEBLACKLIST_H
#define WHITEBLACKLIST_H

#include "Entity.h"

class WhiteBlackList : public Entity {
public:
    bool whiteblack;
    
    WhiteBlackList(const std::string& name, const std::string& type, const bool& whiteblack);
    void display() const override;
    virtual void updateWhiteBlack(bool beta);
    
  
};

#endif
*/
