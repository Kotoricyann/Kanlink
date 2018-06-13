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
#include "text.h"
#include "mugang.h"
#include "BattleSelect.h"
#include "BattleMain.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

short BattleMain::BattlePlace = 0;


Scene* BattleMain::createScene()
{
	return BattleMain::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool BattleMain::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	

	/////////////////////////////
	// 3. add your codes below...
	auto *background = Sprite::create("../image/background.png", Rect(0, 0, visibleSize.width, visibleSize.height));
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background, 0);

	// add a label shows "Hello World"
	// create and initialize a label
	/*
	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
	problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width/2,
	origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);
	}

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");
	if (sprite == nullptr)
	{
	problemLoading("'HelloWorld.png'");
	}
	else
	{
	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);
	}
	*/
	auto mugangItem = MenuItemImage::create(
		"../image/mugang.png",
		"../image/mugang.png",
		CC_CALLBACK_1(BattleMain::toMuGang, this));

	if (mugangItem == nullptr ||
		mugangItem->getContentSize().width <= 0 ||
		mugangItem->getContentSize().height <= 0)
	{
		problemLoading("'mugangItem.png' and 'mugangItem.png'");
	}
	else
	{
		float x = mugangItem->getContentSize().width / 2;
		float y = visibleSize.height - mugangItem->getContentSize().height / 2;
		mugangItem->setPosition(Vec2(x, y));
	}
	
	auto menu1 = Menu::create(mugangItem, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 1);

	// create menu, it's an autorelease object
	auto baidi = Sprite::create("./image/221.png");
	baidi->setScale(1.9);
	if (baidi == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		baidi->setPosition(Vec2(origin.x + visibleSize.width - baidi->getContentSize().width + 90+500, origin.y + baidi->getContentSize().height));

		// add the sprite as a child to this layer
		this->addChild(baidi, 1);
	}

	auto firstMap = MenuItemImage::create(
		"./image/591.png",
		"./image/591.png",
		CC_CALLBACK_1(BattleMain::toBattle, this ,1)
	);
	firstMap->setScale(1.8);
	if (firstMap == nullptr ||
		firstMap->getContentSize().width <= 0 ||
		firstMap->getContentSize().height <= 0)
	{
		problemLoading("'591.png' and '591.png'");
	}
	else
	{
		float x = origin.x + 600+500;
		float y = origin.y + 600;
		firstMap->setPosition(Vec2(x, y));
	}

	auto menu_firstMap = Menu::create(firstMap, NULL);
	menu_firstMap->setPosition(Vec2::ZERO);
	auto node_fm = Node::create();
	node_fm->addChild(menu_firstMap, 2);
	this->addChild(node_fm, 2);


	auto listener_fm = EventListenerTouchOneByOne::create();
	listener_fm->onTouchBegan = [=](Touch* touch, Event* event) {
		auto out = Sprite::create("./image/362.png");
		if (out == nullptr)
		{
			problemLoading("'out.png'");
		}
		else
		{
			// position the sprite on the center of the screen
			out->setScale(1.8);
			out->setPosition(Vec2(600,600));

			// add the sprite as a child to this layer
			
			this->addChild(out, 3);
		}
		return true; // if you are consuming it
	};

	listener_fm->onTouchEnded = [=](Touch *touch, Event *event){
		this->removeChildByName("out");
	};


	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener_fm, this);


	//origin.x + visibleSize.width - baidi->getContentSize().width + 70 , origin.y + baidi->getContentSize().height
	auto moveby = MoveBy::create(1,Vec2(-500, 0));
	auto move_ease_in = EaseBackOut::create(moveby->clone());
	baidi->runAction(move_ease_in);
	firstMap->runAction(move_ease_in->clone());
	return true;
}


void BattleMain::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}


void BattleMain::toText(cocos2d::Ref * pSender)
{
	auto scene2 = myText::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));


}

void BattleMain::toMuGang(cocos2d::Ref * pSender)
{
	auto scene2 = MuGang::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));

}

void BattleMain::toBattle(cocos2d::Ref * pSender, short no)
{
	BattleMain::BattlePlace = no;
	auto scene2 = BattleSelect::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));

}

