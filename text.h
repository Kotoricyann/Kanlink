#pragma once

#ifndef __MYTEXT_SCENE_H__
#define __MYTEXT_H__

#include "cocos2d.h"

class myText : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void toText(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(myText);
};

#endif // __MYTEXT_SCENE_H__
