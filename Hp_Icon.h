//
//  Hp_Icon.hpp
//  helloworld
//
//  Created by 张智昊 on 05/06/2018.
//
//

#ifndef Hp_Icon_hpp
#define Hp_Icon_hpp
#include "cocos2d.h"

#define HP_BAR 100

class Hp_Icon : public cocos2d::Node{
public:
    Hp_Icon();
    ~Hp_Icon();
    virtual bool init() override;
    CREATE_FUNC(Hp_Icon);
};

#endif /* Hp_Icon_hpp */
