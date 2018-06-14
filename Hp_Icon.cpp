//
//  Hp_Icon.cpp
//  helloworld
//
//  Created by 张智昊 on 05/06/2018.
//  Edited by 吕芳锐
//

#include "Hp_Icon.h"
USING_NS_CC;
Hp_Icon::Hp_Icon()
{
    
}

Hp_Icon::~Hp_Icon(){
    
}

bool Hp_Icon::init(){
    if(!Node::init())
        return false;


    /*Sprite *bgSprite = Sprite::create("./image/Battle/HP_none.jpg");
    bgSprite->setPosition(Vec2(0, 140));
    bgSprite->setScale(4);
    this->addChild(bgSprite, 1, 1);*/
    
    Sprite *hpSprite = Sprite::create("./image/Battle/497.png");
	hpSprite->setColor(Color3B(255, 0, 0));

    auto progressTimer = ProgressTimer::create(hpSprite);
    
    progressTimer->setType(ProgressTimer::Type::BAR);
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //从左到右
    progressTimer->setMidpoint(Point(0.5, 0));
    progressTimer->setBarChangeRate(Point(0, 1));
    /*
    progressTimer->setMidpoint(Point(0, 0.5));
    progressTimer->setBarChangeRate(Point(1, 0));*/
    
    progressTimer->setPosition(Vec2(0, 140));
    progressTimer->setScale(1.8);
    progressTimer->setTag(HP_BAR);
    this->addChild(progressTimer, 2);
    
    return true;
}

