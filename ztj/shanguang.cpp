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

#include "shanguang.h"
#include "SimpleAudioEngine.h"
#include "cardshow.h"

USING_NS_CC;

Scene* ShanGuang::createScene()
{
	return ShanGuang::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool ShanGuang::init()
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
	auto background = Sprite::create("./factory/504.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	background->setScale(1.875);
	this->addChild(background, -1);



	auto light = Sprite::create("./factory/487.png");
	light->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	light->setScale(0.01);
	this->addChild(light, 1);
	auto scale = ScaleTo::create(1.0f, 7.0f, 7.0f);
	auto rotate = RotateBy::create(1.0, 180);
	auto mySpawn = Spawn::createWithTwoActions(scale, rotate);
	CCAction *lightf = CCRepeatForever::create(dynamic_cast<CCActionInterval *>(CCSequence::create(mySpawn, NULL)));
	light->runAction(lightf);
	//light->runAction(Spawn::create(, );

	auto kabei = MenuItemImage::create(
		"./factory/kabei.png",
		"./factory/kabei.png",
		CC_CALLBACK_1(ShanGuang::toshow, this)
	);
	if (kabei == nullptr ||
		kabei->getContentSize().width <= 0 ||
		kabei->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		kabei->setOpacity(200);
		kabei->setScale(0.1);
		kabei->setPosition(Vec2(0 , -500));
		kabei->runAction(Spawn::create(ScaleTo::create(1.0f, 1.8f, 1.8f), JumpTo::create(1.0f, Vec2(0, 0), 200, 1), NULL));
	}
	auto mkabei = Menu::create(kabei, NULL);
	this->addChild(mkabei, 1);


	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCSprite *spriteBlink1 = CCSprite::create("./factory/37.png");
	spriteBlink1->setPosition(ccp(size.width / 2.0f+150, size.height / 2.0f+230));
	this->addChild(spriteBlink1, 1);

	CCActionInterval *blinkAction1 = CCBlink::create(10, 20);
	CCAction *action1 = CCRepeatForever::create(dynamic_cast<CCActionInterval *>(CCSequence::create(blinkAction1, NULL)));  
	spriteBlink1->runAction(action1);

	CCSprite *spriteBlink2 = CCSprite::create("./factory/399.png");
	spriteBlink2->setPosition(ccp(size.width / 2.0f - 270, size.height / 2.0f - 120));
	this->addChild(spriteBlink2, 1);

	CCActionInterval *blinkAction2 = CCBlink::create(10, 20);
	CCAction *action2 = CCRepeatForever::create(dynamic_cast<CCActionInterval *>(CCSequence::create(blinkAction2, NULL)));  
	spriteBlink2->runAction(action2);

	CCSprite *spriteBlink3 = CCSprite::create("./factory/214.png");
	spriteBlink3->setPosition(ccp(size.width / 2.0f + 300, size.height / 2.0f - 270));
	this->addChild(spriteBlink3, 1);

	CCActionInterval *blinkAction3 = CCBlink::create(10, 20);
	CCAction *action3 = CCRepeatForever::create(dynamic_cast<CCActionInterval *>(CCSequence::create(blinkAction3, NULL)));  
	spriteBlink3->runAction(action3);

	//auto scene2 = CardShow::createScene();
	////auto delay = DelayTime::create(2.0f);
	////this->runAction(delay);
	//this->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));
	//this->addChild(scene2);
	//Director::getInstance()->pushScene(scene2);
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

	return true;
}


void ShanGuang::toshow(cocos2d::Ref * pSender)
{
	auto scene2 = CardShow::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));

}
