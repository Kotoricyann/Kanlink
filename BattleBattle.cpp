#include "text.h"
#include"mugang.h"
#include "Kanclass.h"
#include "BattleBattle.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

//cocos2d::Vec2 playerShipsPos[6] = { { 0,100 },
//									{ 0,200 },
//									{ 0,300 },
//									{ 0,400 },
//									{ 0,500 },
//									{ 0,600 } };

int playerShipsPos[6] = {
	100,
	200,
	300,
	400,
	500,
	600
};

int playerShipsPosHeight=100;

cocos2d::Vec2 enemyShipsPos[6] = {  { 100,100 },
									{ 100,200 },
									{ 100,300 },
									{ 100,400 },
									{ 100,500 },
									{ 100,600 } };

cocos2d::Scene * BattleBattle::createScene()
{
	return BattleBattle::create();
}

bool BattleBattle::init()
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

	// add a label shows "Hello World"
	// create and initialize a label

	

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("./image/Battle/BattleBG.jpg");
	sprite->setScale(1500/sprite->getContentSize().width);
	
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

	auto playerShips = Node::create();
	playerShips->setScale(1.8);

	Sprite *playerShipOut[6];
	Sprite *ships[6];
	for (int i = 0; i < Chinjufu::fleetNum; i++)
	{
		playerShipOut[i] = Sprite::create("./image/Battle/506.png");
		ships[i] = Sprite::create("./image/Ship/" + Chinjufu::fleet[i].id + Chinjufu::fleet[i].state + "c.png");
		playerShipOut[i]->addChild(ships[i], 1);
		ships[i]->setPosition(ships[i]->getContentSize().width / 2-1.75, ships[i]->getContentSize().height / 2+2.25);
		playerShipOut[i]->setPosition(playerShipOut[i]->getContentSize().width /2 ,playerShipsPosHeight+(5-i)*(playerShipOut[i]->getContentSize().height+5));
		
		playerShips->addChild(playerShipOut[i]);
	}

	this->addChild(playerShips,1);


	auto enemyShips = Node::create();
	enemyShips->setScale(1.8);
	enemyShips->setAnchorPoint(ccp(1, 0));
	enemyShips->setPosition(visibleSize.width, 0);
	Sprite *enemyShipOut[6];
	Sprite *shipsEnemy[6];
	for (int i = 0; i < Chinjufu::fleetNum; i++)
	{
		
		enemyShipOut[i] = Sprite::create("./image/Battle/510.png");
		shipsEnemy[i] = Sprite::create("./image/Ship/" + Chinjufu::fleet[i].id + Chinjufu::fleet[i].state + "c.png");
		
		
		
		enemyShipOut[i]->setAnchorPoint(ccp(1, 0));
		enemyShipOut[i]->addChild(shipsEnemy[i], 1);
		shipsEnemy[i]->setPosition(shipsEnemy[i]->getContentSize().width / 2 + 11.75, shipsEnemy[i]->getContentSize().height / 2 + 2.25);
		enemyShipOut[i]->setPosition(0, playerShipsPosHeight + (5 - i)*(enemyShipOut[i]->getContentSize().height + 5));

		enemyShips->addChild(enemyShipOut[i],-1);
	}

	this->addChild(enemyShips, 1);





	return true;

}


void BattleBattle::menuCloseCallback(Ref* pSender)
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


void BattleBattle::toText(cocos2d::Ref * pSender)
{
	auto scene2 = myText::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));


}

void BattleBattle::toMuGang(cocos2d::Ref * pSender)
{
	auto scene2 = MuGang::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));

}
