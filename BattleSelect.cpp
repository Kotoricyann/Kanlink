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
#include "Kanclass.h"
#include "BattleBattle.h"
#include "BattleSelect.h"
#include "SimpleAudioEngine.h"
#include "text.h"
#include <iostream>
#include <windows.h>

USING_NS_CC;
using namespace std;

short BattleSelect::order[6];
short BattleSelect::orderNum = 0;

string BP[4] = { "Ò»ºÅº£Óò","¶þºÅ","ÈýºÅ","ËÄºÅ" };


Scene* BattleSelect::createScene()
{
	return BattleSelect::create();
}

//Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in BattleSelectScene.cpp\n");
}

// on "init" you need to initialize your instance
bool BattleSelect::init()
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
	log(BattleMain::BattlePlace);
	cout<<BP[BattleMain::BattlePlace]<<"111111111111111111111111111111111111111111111111"<<endl;
	cout << "11111" << endl;
	auto label = Label::createWithSystemFont("Please select attack order:", "Î¢ÈíÑÅºÚ", 44);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	// add "BattleSelect" splash screen"
	auto sprite = Sprite::create("./image/545.png");
	sprite->setScale(1500/sprite->getContentSize().width);
	if (sprite == nullptr)
	{
		problemLoading("'bj.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}

	for (int i=0; i < 6; i++)
	{
		Chinjufu::fleet[i].setShip("001", "poi", 1,100, 100, 50, 30,1,0,"n");
	}
	Chinjufu::fleetNum = 6;

	auto sixShip = Node::create();
	sixShip->setPosition(0, 0);
	sixShip->setScale(0.6);

	
	Chinjufu::fleet[0].HP=10;
	Chinjufu::fleet[0].checkWeak();


	auto ship1 = MenuItemImage::create(
		"./image/Ship/" + Chinjufu::fleet[0].id + Chinjufu::fleet[0].state +".png",
		"./image/Ship/" + Chinjufu::fleet[0].id + Chinjufu::fleet[0].state + ".png",
		CC_CALLBACK_1(BattleSelect::selectOrder,this,sixShip,1));
	
	/*auto ship2 = MenuItemImage::create(
		"./image/Ship/" + Chinjufu::fleet[1].id + Chinjufu::fleet[1].state + ".png",
		"./image/Ship/" + Chinjufu::fleet[1].id + Chinjufu::fleet[1].state + ".png",
		CC_CALLBACK_1(BattleSelect::selectOrder, this, sixShip, 2));

	auto ship3 = MenuItemImage::create(
		"./image/Ship/" + Chinjufu::fleet[2].id + Chinjufu::fleet[2].state + ".png",
		"./image/Ship/" + Chinjufu::fleet[2].id + Chinjufu::fleet[2].state + ".png",
		CC_CALLBACK_1(BattleSelect::selectOrder, this, sixShip, 3));

	auto ship4 = MenuItemImage::create(
		"./image/Ship/" + Chinjufu::fleet[3].id + Chinjufu::fleet[3].state + ".png",
		"./image/Ship/" + Chinjufu::fleet[4].id + Chinjufu::fleet[3].state + ".png",
		CC_CALLBACK_1(BattleSelect::selectOrder, this, sixShip, 4));

	auto ship5 = MenuItemImage::create(
		"./image/Ship/" + Chinjufu::fleet[4].id + Chinjufu::fleet[4].state + ".png",
		"./image/Ship/" + Chinjufu::fleet[4].id + Chinjufu::fleet[4].state + ".png",
		CC_CALLBACK_1(BattleSelect::selectOrder, this, sixShip, 5));

	auto ship6 = MenuItemImage::create(
		"./image/Ship/" + Chinjufu::fleet[5].id + Chinjufu::fleet[5].state + ".png",
		"./image/Ship/" + Chinjufu::fleet[5].id + Chinjufu::fleet[5].state + ".png",
		CC_CALLBACK_1(BattleSelect::selectOrder, this, sixShip, 6));
	
	auto ship2 = Sprite::create("./image/Ship/" + Chinjufu::fleet[1].id + "n.png");
	auto ship3 = Sprite::create("./image/Ship/" + Chinjufu::fleet[2].id + "n.png");
	auto ship4 = Sprite::create("./image/Ship/" + Chinjufu::fleet[3].id + "n.png");
	auto ship5 = Sprite::create("./image/Ship/" + Chinjufu::fleet[4].id + "n.png");
	auto ship6 = Sprite::create("./image/Ship/" + Chinjufu::fleet[5].id + "n.png");*/

	MenuItemImage *ships[6];
	Menu *menus[6];

	for (int i = 0; i < Chinjufu::fleetNum; i++)
	{
		ships[i] = MenuItemImage::create(
			"./image/Ship/" + Chinjufu::fleet[i].id + Chinjufu::fleet[i].state + ".png",
			"./image/Ship/" + Chinjufu::fleet[i].id + Chinjufu::fleet[i].state + ".png",
			CC_CALLBACK_1(BattleSelect::selectOrder, this, sixShip, i + 1));
		menus[i] = Menu::create(ships[i], NULL);
		menus[i]->setPosition(0, 0);
	}



	auto m1 = Menu::create(ship1, NULL);
	m1->setPosition(0, 0);



	switch (Chinjufu::fleetNum) {
	case 6:
		ships[5]->setPosition(SHIP6_POS);
		sixShip->addChild(menus[5]);
		
	case 5:
		ships[4]->setPosition(SHIP5_POS);
		sixShip->addChild(menus[4]);

	case 4:
		ships[3]->setPosition(SHIP4_POS);
		sixShip->addChild(menus[3]);

	case 3:
		ships[2]->setPosition(SHIP3_POS);
		sixShip->addChild(menus[2]);
	case 2:
		ships[1]->setPosition(SHIP2_POS);
		sixShip->addChild(menus[1]);
	case 1:
		ships[0]->setPosition(SHIP1_POS);
		sixShip->addChild(menus[0]); break;
	default: break;
	}

	this->addChild(sixShip);





	return true;
}


void BattleSelect::menuCloseCallback(Ref* pSender)
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


void BattleSelect::toText(cocos2d::Ref * pSender)
{
	auto scene2 = myText::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));


}

void BattleSelect::selectOrder(cocos2d::Ref * pSender, cocos2d::Node * sixship, int i)
{
	string bianhao[6] = { "1","2","3","4","5","6" };
	
	for (int j = 0; j < BattleSelect::orderNum; j++)
	{
		if (BattleSelect::order[j] == i)return;
	}


	BattleSelect::order[BattleSelect::orderNum++] = i;
	
	auto bianLabel = Label::createWithSystemFont(bianhao[BattleSelect::orderNum -1], "Î¢ÈíÑÅºÚ", 100);

	switch (i) {
	case 1:bianLabel->setPosition(SHIP1_POS); break;
	case 2:bianLabel->setPosition(SHIP2_POS); break;
	case 3:bianLabel->setPosition(SHIP3_POS); break;
	case 4:bianLabel->setPosition(SHIP4_POS); break;
	case 5:bianLabel->setPosition(SHIP5_POS); break;
	case 6:bianLabel->setPosition(SHIP6_POS); break;
	}
	sixship->addChild(bianLabel, 4);
	
	if (BattleSelect::orderNum == 6)
	{
		Sleep(2);
		auto scene2 = BattleBattle::createScene();

		Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));

	}
	auto delay = DelayTime::create(0.25f);
}
