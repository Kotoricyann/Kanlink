#include "text.h"
#include "Hp_Icon.h"
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
int playerShipHPTag[6] = { 11,12,13,14,15,16 };
int enemyShipHPTag[6] = { 21,22,23,24,25,26 };


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

	auto chuji = Sprite::create("./image/Battle/50.png");
	
	chuji->setPosition(visibleSize.width / 2, visibleSize.height/ 2);
	chuji->setColor(Color3B(0,0,0));
	chuji->setScale(1.2);
	this->addChild(chuji, 11);

	chuji->runAction(DelayTime::create(1.0f));

	auto tintBy = TintTo::create(0.5f, 255.0f, 255.0f,255.0f);
	auto tintBy2 = TintBy::create(0.5f, -255.0f, -255.0f, -255.0f);
	auto sc = ScaleBy::create(0.3f, 1.3f);
	auto chujiout = Spawn::create(Sequence::create(sc,sc->reverse(), nullptr), tintBy,nullptr);
	chuji->runAction(Sequence::create(chujiout,FadeOut::create(1.0f),nullptr));

	auto door1 = Sprite::create("./image/Battle/358.png");
	auto door2 = Sprite::create("./image/Battle/355.png");

	door1->setAnchorPoint(ccp(1, 0.5));
	door2->setAnchorPoint(ccp(0, 0.5));

	door1->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	door2->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	door1->setScale(visibleSize.height / door1->getContentSize().height);
	door2->setScale(visibleSize.height / door2->getContentSize().height);

	door1->setOpacity(200);
	door2->setOpacity(200);

	this->addChild(door1, 10);
	this->addChild(door2, 10);

	auto delayhalf = DelayTime::create(0.5);

	auto door1Move = MoveBy::create(1, Vec2(-visibleSize.width / 2, 0));
	auto door2Move = MoveBy::create(1, Vec2(visibleSize.width / 2, 0));
	
	door1->runAction(Sequence::create(delayhalf,door1Move,nullptr) );
	door2->runAction(Sequence::create(delayhalf->clone(), door2Move,nullptr));

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


	

	Hp_Icon *playerShipsHP[6];
	ProgressTimer* tmp;
	for (size_t i = 0; i < Chinjufu::fleetNum; i++)
	{
		playerShipsHP[i] = Hp_Icon::create();
		playerShipsHP[i]->setPosition(playerShipOut[i]->getContentSize().width*1.8-12,(playerShipOut[i]->getPosition().y)*1.8-145);
		tmp = (ProgressTimer*)playerShipsHP[i]->getChildByTag(HP_BAR);
		tmp->setPercentage(100);
		this->addChild(playerShipsHP[i], 0, playerShipHPTag[i]);


	}
	Hp_Icon *enemyShipsHP[6];
	for (size_t i = 0; i < Chinjufu::fleetNum; i++)
	{
		enemyShipsHP[i] = Hp_Icon::create();
		enemyShipsHP[i]->setPosition(visibleSize.width- enemyShipOut[i]->getContentSize().width*1.8 + 12, (enemyShipOut[i]->getPosition().y)*1.8 - 100);
		tmp = (ProgressTimer*)enemyShipsHP[i]->getChildByTag(HP_BAR);
		tmp->setPercentage(100);
		this->addChild(enemyShipsHP[i], 0, enemyShipHPTag[i]);


	}







	this->scheduleUpdate();
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
void BattleBattle::scheduleBlood(Node * shuaxin,float xueliang) {
	auto progress = (ProgressTimer *)shuaxin->getChildByTag(HP_BAR);
	progress->setPercentage(xueliang*100);  //这里是百分制显示
	if (progress->getPercentage() < 0) {
		cout << "scheduleBlooderror" << endl;
	}
}

float BattleBattle::flag = 1;
void BattleBattle::update(float dt)
{
	auto * text = (ProgressTimer *)this->getChildByTag(12);
	//auto tc = (ProgressTimer *)text->getChildByTag(100);
	float num = (flag++) / 1000;
	scheduleBlood(text, num);
	//ProgressTimer * progress = (ProgressTimer *)text->;
	//text->setPercentage(50);  //这里是百分制显示
}
