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

#include "cardshow.h"
#include "SimpleAudioEngine.h"
#include "jianzao.h"
#include "iostream"
using namespace std;
USING_NS_CC;

Scene* CardShow::createScene()
{
	return CardShow::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool CardShow::init()
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



	// create menu, it's an autorelease object


	/////////////////////////////
	// 3. add your codes below...
	auto background = Sprite::create("./factory/511.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	background->setScale(1.875);
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
	string filepath = "./image/Ship/" + JianZao::build + "n.png";
	auto ship = Sprite::create(filepath);
	if (ship == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		ship->setScale(1.8);
		ship->setPosition(Vec2(origin.x + visibleSize.width / 2 ,  origin.y+100 ));

		// add the sprite as a child to this layer
		this->addChild(ship, 1);
	}

	auto get = Sprite::create("./factory/376.png");
	if (get == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		get->setScale(1.8);
		get->setPosition(Vec2(origin.x + visibleSize.width -160, visibleSize.height + origin.y-100));

		// add the sprite as a child to this layer
		this->addChild(get, 1);
	}

	auto tuiItem = MenuItemImage::create(
		"./factory/41.png",
		"./factory/41.png",
		CC_CALLBACK_1(CardShow::totui, this));

	if (tuiItem == nullptr ||
		tuiItem->getContentSize().width <= 0 ||
		tuiItem->getContentSize().height <= 0)
	{
		problemLoading("'tuiItem.png' and 'tuiItem.png'");
	}
	else
	{
		float x =  visibleSize.width-tuiItem->getContentSize().width ;
		float y = origin.y + tuiItem->getContentSize().height ;
		tuiItem->setPosition(Vec2(x, y));
		tuiItem->setScale(1.5);
	}

	auto menu1 = Menu::create(tuiItem, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 1);

	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCSprite *spriteBlink1 = CCSprite::create("./factory/209.png");
	spriteBlink1->setPosition(ccp(size.width / 2.0f + 150, size.height / 2.0f + 330));
	this->addChild(spriteBlink1, 1);

	CCActionInterval *blinkAction1 = CCBlink::create(10, 20);
	CCAction *action1 = CCRepeatForever::create(dynamic_cast<CCActionInterval *>(CCSequence::create(blinkAction1, NULL)));
	spriteBlink1->runAction(action1);

	CCSprite *spriteBlink2 = CCSprite::create("./factory/222.png");
	spriteBlink2->setPosition(ccp(size.width / 2.0f - 250, size.height / 2.0f - 140));
	this->addChild(spriteBlink2, 1);

	CCActionInterval *blinkAction2 = CCBlink::create(10, 20);
	CCAction *action2 = CCRepeatForever::create(dynamic_cast<CCActionInterval *>(CCSequence::create(blinkAction2, NULL)));
	spriteBlink2->runAction(action2);

	CCSprite *spriteBlink3 = CCSprite::create("./factory/222.png");
	spriteBlink3->setScale(0.6);
	spriteBlink3->setPosition(ccp(size.width / 2.0f + 265, size.height / 2.0f - 270));
	this->addChild(spriteBlink3, 1);

	CCActionInterval *blinkAction3 = CCBlink::create(10, 20);
	CCAction *action3 = CCRepeatForever::create(dynamic_cast<CCActionInterval *>(CCSequence::create(blinkAction3, NULL)));
	spriteBlink3->runAction(action3);

	CCSprite *spriteBlink4 = CCSprite::create("./factory/214.png");
	spriteBlink4->setPosition(ccp(size.width / 2.0f + 680, size.height / 2.0f + 400));
	this->addChild(spriteBlink4, 1);

	CCActionInterval *blinkAction4 = CCBlink::create(10, 20);
	CCAction *action4 = CCRepeatForever::create(dynamic_cast<CCActionInterval *>(CCSequence::create(blinkAction4, NULL)));
	spriteBlink4->runAction(action4);



	auto chilun = Sprite::create("./factory/38.png");
	chilun->setPosition(Vec2(visibleSize.width -chilun->getContentSize().width, chilun->getContentSize().height));
	chilun->setScale(1.5);
	this->addChild(chilun, 1);
	auto rotate = RotateBy::create(2.0, 360);
	CCAction *chilunf = CCRepeatForever::create(dynamic_cast<CCActionInterval *>(CCSequence::create(rotate, NULL)));
	chilun->runAction(chilunf);




	return true;
}


void CardShow::totui(cocos2d::Ref * pSender)
{
	auto scene2 = JianZao::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));

}