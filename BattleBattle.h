#pragma once

#ifndef __BATTLEBATTLE_H__
#define __BATTLEBATTLE_H__

#include "cocos2d.h"
#include"Hp_Icon.h"





class BattleBattle : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	static float flag;
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void toText(cocos2d::Ref* pSender);
	void toMuGang(cocos2d::Ref* pSender);
	void scheduleBlood(Node * shuaxin, float xueliang);
	void update(float dt);
	// implement the "static create()" method manually
	CREATE_FUNC(BattleBattle);
};

#endif // __BattleBattle_SCENE_H__
