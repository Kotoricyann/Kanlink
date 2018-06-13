#pragma once
/****************************************************************************
Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __BATTLESELECT_SCENE_H__
#define __BATTLESELECT_SCENE_H__

#include "cocos2d.h"
#include"BattleMain.h"

//extern short BattlePlace;
#define SHIP1_POS 400, 1000
#define SHIP2_POS 1200, 1000
#define SHIP3_POS 2000, 1000
#define SHIP4_POS 700, 400
#define SHIP5_POS 1500, 400
#define SHIP6_POS 2300, 400



class BattleSelect : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void toText(cocos2d::Ref* pSender);
	void selectOrder(cocos2d::Ref* pSender, cocos2d::Node *sixship,int i);
	static short order[6];
	static short orderNum;
	// implement the "static create()" method manually
	CREATE_FUNC(BattleSelect);
};

#endif // __BATTLESELECT_SCENE_H__
