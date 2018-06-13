#include "text.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

cocos2d::Scene * myText::createScene()
{
	return myText::create();
}

bool myText::init()
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
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(myText::menuCloseCallback, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		log("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		log("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");
	//sprite->setScale(0.4);
	if (sprite == nullptr)
	{
		log("'bj.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}

	auto mugangItem = MenuItemImage::create(
		"../image/mugang.png",
		"../image/mugang.png",
		CC_CALLBACK_1(myText::toText, this));

	if (mugangItem == nullptr ||
		mugangItem->getContentSize().width <= 0 ||
		mugangItem->getContentSize().height <= 0)
	{
		log("'mugangItem.png' and 'mugangItem.png'");
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


	return true;
	
}


void myText::menuCloseCallback(Ref* pSender)
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


void myText::toText(cocos2d::Ref * pSender)
{
	auto scene2 = HelloWorld::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));


}
