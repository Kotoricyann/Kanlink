#pragma once

#ifndef __BATTLEBATTLE_H__
#define __BATTLEBATTLE_H__

#include "cocos2d.h"




class BattleBattle : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void toText(cocos2d::Ref* pSender);
	void toMuGang(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(BattleBattle);
};

#endif // __BattleBattle_SCENE_H__
