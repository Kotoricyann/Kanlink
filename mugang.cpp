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
#include "BattleMain.h"
#include "mugang.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MuGang::createScene()
{
    return MuGang::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MuGang::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MuGang::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
	auto *background = Sprite::create("../image/background.png", Rect(0, 0, visibleSize.width, visibleSize.height));
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background,0);

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
		CC_CALLBACK_1(MuGang::toMuGang, this));

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

	// create menu, it's an autorelease object
	auto menu1 = Menu::create(mugangItem, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 1);
	
	auto cj = MenuItemImage::create(
		"./image/button/chuji.png",
		"./image/button/chuji.png",
		CC_CALLBACK_1(MuGang::toChuJi, this));
	if (cj == nullptr ||
		cj->getContentSize().width <= 0 ||
		cj->getContentSize().height <= 0)
	{
		problemLoading("'chuji.png' and 'chuji.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		float x = origin.x + 250;
		float y = origin.y + 325;

		cj->setPosition(Vec2(x,y));

		// add the sprite as a child to this layer
		
	}

	auto menu_cj = Menu::create(cj, NULL);
	menu_cj->setPosition(Vec2::ZERO);
	this->addChild(menu_cj, 1);


	auto bc = MenuItemImage::create(
		"./image/button/133.png",
		"./image/button/140.png",
		CC_CALLBACK_1(MuGang::toChuJi, this)
	);
	bc->setScale(1.75);
	if (bc == nullptr ||
		bc->getContentSize().width <= 0 ||
		bc->getContentSize().height <= 0)
	{
		problemLoading("'bc.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		bc->setPosition(Vec2(origin.x + 305, origin.y + 585));

		// add the sprite as a child to this layer
		
	}

	auto menu_bc = Menu::create(bc, NULL);
	menu_bc->setPosition(Vec2::ZERO);
	this->addChild(menu_bc, 1);

	
	auto gc = MenuItemImage::create(
		"./image/button/94.png",
		"./image/button/101.png",
		CC_CALLBACK_1(MuGang::toChuJi, this)
	);
	gc->setScale(1.75);
	if (gc == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		gc->setPosition(Vec2(origin.x + 525, origin.y + 370));

		// add the sprite as a child to this layer
		
	}
	auto menu_gc = Menu::create(gc, NULL);
	menu_gc->setPosition(Vec2::ZERO);
	this->addChild(menu_gc, 1);


	auto jn = Sprite::create("../image/jianniang/common/Yura.png");
	if (jn == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		jn->setPosition(Vec2(origin.x + 1100, origin.y + 150));
		jn->setScale(1.5);
		// add the sprite as a child to this layer
		this->addChild(jn, 1);
	}
    return true;
}


void MuGang::menuCloseCallback(Ref* pSender)
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

void MuGang::toChuJi(cocos2d::Ref * pSender)
{
	auto cj = BattleMain::createScene();
	Director::getInstance()->replaceScene(cj);
}
void MuGang::toText(cocos2d::Ref * pSender)
{
	auto scene2 = myText::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));
}
void MuGang::toMuGang(cocos2d::Ref * pSender)
{
	auto scene2 = MuGang::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));

}

