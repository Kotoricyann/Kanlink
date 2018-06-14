#include "HelloWorldScene.h"
#include "jianzao.h"
#include "SimpleAudioEngine.h"
#include "mugang.h"
#include "shanguang.h"
#include "Kanclass.h"
#include "stdlib.h"
#include "iostream"
#include "string.h"
using namespace std;
string JianZao::build;
USING_NS_CC;

int steelnum = 30;
int oilnum = 30;
int alumnum = 30;
int ammonum = 30;
int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
Ship quzhu[20], xunyang[20], zhanjian[20], hangmu[20];
int flag[10] = { 0 };
Scene* JianZao::createScene()
{
	return JianZao::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in jianzao.cpp\n");
}

// on "init" you need to initialize your instance
bool JianZao::init()
{
	//////////////////////////////
	// 1. super init first
	p1 = 0;
	p2 = 0;
	p3 = 0;
	p4 = 0;
	steelnum = 30;
	oilnum = 30;
	alumnum = 30;
	ammonum = 30;
	for (int i = 0;i < 10;i++)
	{
		flag[i] = 0;
	}
	char cid[20];
	char cname[100];
	int type;//舰船种类：驱逐、巡洋舰、战列舰、航母:1,2,3,4
	int HP_MAX;//最大血量
	int atk;//攻击力
	int ac;//护甲
	int lv;//等级
	int exp;//当前经验值
	FILE *fp = NULL; /* 需要注意 */
	fp = fopen("ShipProperty.csv", "r");
	if (NULL == fp)
	{
		return -1; /* 要返回错误代码 */
	}
	char buf[200];
	while (feof(fp) == NULL)
	{

		fscanf(fp, "%s%s%d%d%d%d", &cid, &cname, &type, &HP_MAX, &atk, &ac);
		string id(&cid[0], &cid[strlen(cid)]);
		string name(&cname[0], &cname[strlen(cname)]);
		cout << id;
		cout << name;
		switch (type)
		{
		case 1:quzhu[p1++].setShip(id, name, type,HP_MAX, HP_MAX, atk, ac, 1, 0,"n");break;
		case 2:xunyang[p2++].setShip(id, name, type, HP_MAX, HP_MAX, atk, ac, 1, 0, "n");break;
		case 3:zhanjian[p3++].setShip(id, name, type, HP_MAX, HP_MAX, atk, ac, 1, 0, "n");break;
		case 4:hangmu[p4++].setShip(id, name, type, HP_MAX, HP_MAX, atk, ac, 1, 0, "n");break;
		}
	}
	



	fclose(fp);

	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto myNode = Node::create();
	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object


	/////////////////////////////
	// 3. add your codes below...
	Sprite *background = Sprite::create("./image/background.png", Rect(0, 0, visibleSize.width, visibleSize.height));
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
	myNode->addChild(label, 1);
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
	myNode->addChild(sprite, 0);
	}
	*/
	auto baidi = Sprite::create("./factory/baidi.png");
	if (baidi == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		baidi->setScale(1.9);
		baidi->setPosition(Vec2(origin.x + visibleSize.width - baidi->getContentSize().width + 230 , origin.y + baidi->getContentSize().height));
		// add the sprite as a child to this layer
		myNode->addChild(baidi, 1);
	}

	auto mugangItem = MenuItemImage::create(
		"../image/mugang.png",
		"../image/mugang.png",
		CC_CALLBACK_1(JianZao::toMuGang, this));

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
	auto ge1 = Sprite::create("./factory/0.png");
	if (ge1 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		ge1->setScale(2.3);
		ge1->setPosition(Vec2(origin.x + 595, origin.y + 560));

		// add the sprite as a child to this layer
		myNode->addChild(ge1, 2);
	}

	auto ge2 = Sprite::create("./factory/0.png");
	if (ge2 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		ge2->setScale(2.3);
		ge2->setPosition(Vec2(origin.x + 595, origin.y + 240));

		// add the sprite as a child to this layer
		myNode->addChild(ge2, 2);
	}

	auto ge3 = Sprite::create("./factory/0.png");
	if (ge3 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		ge3->setScale(2.3);
		ge3->setPosition(Vec2(origin.x + 1145, origin.y + 560));

		// add the sprite as a child to this layer
		myNode->addChild(ge3, 2);
	}


	auto ge4 = Sprite::create("./factory/0.png");
	if (ge4 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		ge4->setScale(2.3);
		ge4->setPosition(Vec2(origin.x + 1145, origin.y + 240));

		// add the sprite as a child to this layer
		myNode->addChild(ge4, 2);
	}

	auto shi1 = Sprite::create("./factory/3.png");
	if (shi1 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		shi1->setScale(2.3);
		shi1->setPosition(Vec2(origin.x + 555, origin.y + 560));

		// add the sprite as a child to this layer
		myNode->addChild(shi1, 2);
	}

	auto shi2 = Sprite::create("./factory/3.png");
	if (shi2 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		shi2->setScale(2.3);
		shi2->setPosition(Vec2(origin.x + 555, origin.y + 240));

		// add the sprite as a child to this layer
		myNode->addChild(shi2, 2);
	}

	auto shi3 = Sprite::create("./factory/3.png");
	if (shi3 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		shi3->setScale(2.3);
		shi3->setPosition(Vec2(origin.x + 1105, origin.y + 560));

		// add the sprite as a child to this layer
		myNode->addChild(shi3, 2);
	}


	auto shi4 = Sprite::create("./factory/3.png");
	if (shi4 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		shi4->setScale(2.3);
		shi4->setPosition(Vec2(origin.x + 1105, origin.y + 240));

		// add the sprite as a child to this layer
		myNode->addChild(shi4, 2);
	}

	auto bai1 = Sprite::create("./factory/0.png");
	if (bai1 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		bai1->setScale(2.3);
		bai1->setPosition(Vec2(origin.x + 515, origin.y + 560));

		// add the sprite as a child to this layer
		myNode->addChild(bai1, 2);
	}

	auto bai2 = Sprite::create("./factory/0.png");
	if (bai2 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		bai2->setScale(2.3);
		bai2->setPosition(Vec2(origin.x + 515, origin.y + 240));

		// add the sprite as a child to this layer
		myNode->addChild(bai2, 2);
	}

	auto bai3 = Sprite::create("./factory/0.png");
	if (bai3 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		bai3->setScale(2.3);
		bai3->setPosition(Vec2(origin.x + 1065, origin.y + 560));

		// add the sprite as a child to this layer
		myNode->addChild(bai3, 2);
	}


	auto bai4 = Sprite::create("./factory/0.png");
	if (bai4 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		bai4->setScale(2.3);
		bai4->setPosition(Vec2(origin.x + 1065, origin.y + 240));

		// add the sprite as a child to this layer
		myNode->addChild(bai4, 2);
	}

	auto kacao1 = Sprite::create("./factory/302.png");
	if (kacao1 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		kacao1->setScale(2.5);
		kacao1->setPosition(Vec2(origin.x + 680, origin.y + 586));

		// add the sprite as a child to this layer
		myNode->addChild(kacao1, 1);
	}

	auto kacao2 = Sprite::create("./factory/302.png");
	if (kacao2 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		kacao2->setScale(2.5);
		kacao2->setPosition(Vec2(origin.x + 680, origin.y + 265));

		// add the sprite as a child to this layer
		myNode->addChild(kacao2, 1);
	}

	auto kacao3 = Sprite::create("./factory/302.png");
	if (kacao3 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		kacao3->setScale(2.5);
		kacao3->setPosition(Vec2(origin.x + 1230, origin.y + 586));

		// add the sprite as a child to this layer
		myNode->addChild(kacao3, 1);
	}


	auto kacao4 = Sprite::create("./factory/302.png");
	if (kacao4 == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		kacao4->setScale(2.5);
		kacao4->setPosition(Vec2(origin.x + 1230, origin.y + 265));

		// add the sprite as a child to this layer
		myNode->addChild(kacao4, 1);
	}

	auto start = MenuItemImage::create(
		"./factory/565.png",
		"./factory/570.png",
		CC_CALLBACK_1(JianZao::tostart, this)
	);
	if (start == nullptr ||
		start->getContentSize().width <= 0 ||
		start->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - start->getContentSize().width/2-20 ;
		float y = origin.y + start->getContentSize().height * 3 / 2;
		start->setPosition(Vec2(x, y));
	}
	auto menu = Menu::create(start, NULL);
	menu->setPosition(Vec2::ZERO);
	myNode->addChild(menu, 1);

	auto reset1 = MenuItemImage::create(
		"./factory/304.png",
		"./factory/304.png",
		CC_CALLBACK_1(JianZao::toreset, this,1,shi1,bai1)
	);
	if (reset1 == nullptr ||
		reset1->getContentSize().width <= 0 ||
		reset1->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 815;
		float y = origin.y + 550;
		reset1->setScale(2.5);
		reset1->setPosition(Vec2(x, y));
	}
	auto m_reset1 = Menu::create(reset1, NULL);
	m_reset1->setPosition(Vec2::ZERO);
	myNode->addChild(m_reset1, 1);

	auto reset2 = MenuItemImage::create(
		"./factory/304.png",
		"./factory/304.png",
		CC_CALLBACK_1(JianZao::toreset, this,2, shi2, bai2)
	);
	if (reset2 == nullptr ||
		reset2->getContentSize().width <= 0 ||
		reset2->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 815;
		float y = origin.y + 235;
		reset2->setScale(2.5);
		reset2->setPosition(Vec2(x, y));
	}
	auto m_reset2 = Menu::create(reset2, NULL);
	m_reset2->setPosition(Vec2::ZERO);
	myNode->addChild(m_reset2, 1);

	auto reset3 = MenuItemImage::create(
		"./factory/304.png",
		"./factory/304.png",
		CC_CALLBACK_1(JianZao::toreset, this,3, shi3, bai3)
	);
	if (reset3 == nullptr ||
		reset3->getContentSize().width <= 0 ||
		reset3->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 1365;
		float y = origin.y + 550;
		reset3->setScale(2.5);
		reset3->setPosition(Vec2(x, y));
	}
	auto m_reset3 = Menu::create(reset3, NULL);
	m_reset3->setPosition(Vec2::ZERO);
	myNode->addChild(m_reset3, 1);

	auto reset4 = MenuItemImage::create(
		"./factory/304.png",
		"./factory/304.png",
		CC_CALLBACK_1(JianZao::toreset, this,4, shi4, bai4)
	);
	if (reset4 == nullptr ||
		reset4->getContentSize().width <= 0 ||
		reset4->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 1365;
		float y = origin.y + 235;
		reset4->setScale(2.5);
		reset4->setPosition(Vec2(x, y));
	}
	auto m_reset4 = Menu::create(reset4, NULL);
	m_reset4->setPosition(Vec2::ZERO);
	myNode->addChild(m_reset4, 1);

	auto max1 = MenuItemImage::create(
		"./factory/308.png",
		"./factory/308.png",
		CC_CALLBACK_1(JianZao::tomax, this,1,shi1,bai1)
	);
	if (max1 == nullptr ||
		max1->getContentSize().width <= 0 ||
		max1->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 815;
		float y = origin.y + 490;
		max1->setScale(2.5);
		max1->setPosition(Vec2(x, y));
	}
	auto m_max1 = Menu::create(max1, NULL);
	m_max1->setPosition(Vec2::ZERO);
	myNode->addChild(m_max1, 1);

	auto max2 = MenuItemImage::create(
		"./factory/308.png",
		"./factory/308.png",
		CC_CALLBACK_1(JianZao::tomax, this,2, shi2, bai2)
	);
	if (max2 == nullptr ||
		max2->getContentSize().width <= 0 ||
		max2->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 815;
		float y = origin.y + 175;
		max2->setScale(2.5);
		max2->setPosition(Vec2(x, y));
	}
	auto m_max2 = Menu::create(max2, NULL);
	m_max2->setPosition(Vec2::ZERO);
	myNode->addChild(m_max2, 1);

	auto max3 = MenuItemImage::create(
		"./factory/308.png",
		"./factory/308.png",
		CC_CALLBACK_1(JianZao::tomax, this,3, shi3, bai3)
	);
	if (max3 == nullptr ||
		max3->getContentSize().width <= 0 ||
		max3->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 1365;
		float y = origin.y + 490;
		max3->setScale(2.5);
		max3->setPosition(Vec2(x, y));
	}
	auto m_max3 = Menu::create(max3, NULL);
	m_max3->setPosition(Vec2::ZERO);
	myNode->addChild(m_max3, 1);

	auto max4 = MenuItemImage::create(
		"./factory/308.png",
		"./factory/308.png",
		CC_CALLBACK_1(JianZao::tomax, this,4, shi4, bai4)
	);
	if (max4 == nullptr ||
		max4->getContentSize().width <= 0 ||
		max4->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 1365;
		float y = origin.y + 175;
		max4->setScale(2.5);
		max4->setPosition(Vec2(x, y));
	}
	auto m_max4 = Menu::create(max4, NULL);
	m_max4->setPosition(Vec2::ZERO);
	myNode->addChild(m_max4, 1);

	auto dec_11 = MenuItemImage::create(
		"./factory/311.png",
		"./factory/313.png",
		CC_CALLBACK_1(JianZao::todecshi, this,1,shi1,bai1)
	);
	if (dec_11 == nullptr ||
		dec_11->getContentSize().width <= 0 ||
		dec_11->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 735;
		float y = origin.y + 685;
		dec_11->setScale(2.5);
		dec_11->setPosition(Vec2(x, y));
	}
	auto m_dec_11 = Menu::create(dec_11, NULL);
	m_dec_11->setPosition(Vec2::ZERO);
	myNode->addChild(m_dec_11, 1);

	auto dec_12 = MenuItemImage::create(
		"./factory/311.png",
		"./factory/313.png",
		CC_CALLBACK_1(JianZao::todecshi, this, 2, shi2, bai2)
	);
	if (dec_12 == nullptr ||
		dec_12->getContentSize().width <= 0 ||
		dec_12->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 735;
		float y = origin.y + 365;
		dec_12->setScale(2.5);
		dec_12->setPosition(Vec2(x, y));
	}
	auto m_dec_12 = Menu::create(dec_12, NULL);
	m_dec_12->setPosition(Vec2::ZERO);
	myNode->addChild(m_dec_12, 1);

	auto dec_13 = MenuItemImage::create(
		"./factory/311.png",
		"./factory/313.png",
		CC_CALLBACK_1(JianZao::todecshi, this, 3, shi3, bai3)
	);
	if (dec_13 == nullptr ||
		dec_13->getContentSize().width <= 0 ||
		dec_13->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 1285;
		float y = origin.y + 685;
		dec_13->setScale(2.5);
		dec_13->setPosition(Vec2(x, y));
	}
	auto m_dec_13 = Menu::create(dec_13, NULL);
	m_dec_13->setPosition(Vec2::ZERO);
	myNode->addChild(m_dec_13, 1);

	auto dec_14 = MenuItemImage::create(
		"./factory/311.png",
		"./factory/313.png",
		CC_CALLBACK_1(JianZao::todecshi, this, 4, shi4, bai4)
	);
	if (dec_14 == nullptr ||
		dec_14->getContentSize().width <= 0 ||
		dec_14->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 1285;
		float y = origin.y + 365;
		dec_14->setScale(2.5);
		dec_14->setPosition(Vec2(x, y));
	}
	auto m_dec_14 = Menu::create(dec_14, NULL);
	m_dec_14->setPosition(Vec2::ZERO);
	myNode->addChild(m_dec_14, 1);

	auto dec_21 = MenuItemImage::create(
		"./factory/311.png",
		"./factory/313.png",
		CC_CALLBACK_1(JianZao::todecbai, this,1,shi1,bai1)
	);
	if (dec_21 == nullptr ||
		dec_21->getContentSize().width <= 0 ||
		dec_21->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 735;
		float y = origin.y + 620;
		dec_21->setScale(2.5);
		dec_21->setPosition(Vec2(x, y));
	}
	auto m_dec_21 = Menu::create(dec_21, NULL);
	m_dec_21->setPosition(Vec2::ZERO);
	myNode->addChild(m_dec_21, 1);

	auto dec_22 = MenuItemImage::create(
		"./factory/311.png",
		"./factory/313.png",
		CC_CALLBACK_1(JianZao::todecbai, this, 2, shi2, bai2)
	);
	if (dec_22 == nullptr ||
		dec_22->getContentSize().width <= 0 ||
		dec_22->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 735;
		float y = origin.y +300;
		dec_22->setScale(2.5);
		dec_22->setPosition(Vec2(x, y));
	}
	auto m_dec_22 = Menu::create(dec_22, NULL);
	m_dec_22->setPosition(Vec2::ZERO);
	myNode->addChild(m_dec_22, 1);

	auto dec_23 = MenuItemImage::create(
		"./factory/311.png",
		"./factory/313.png",
		CC_CALLBACK_1(JianZao::todecbai, this, 3, shi3, bai3)
	);
	if (dec_23 == nullptr ||
		dec_23->getContentSize().width <= 0 ||
		dec_23->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 1285;
		float y = origin.y + 620;
		dec_23->setScale(2.5);
		dec_23->setPosition(Vec2(x, y));
	}
	auto m_dec_23 = Menu::create(dec_23, NULL);
	m_dec_23->setPosition(Vec2::ZERO);
	myNode->addChild(m_dec_23, 1);

	auto dec_24 = MenuItemImage::create(
		"./factory/311.png",
		"./factory/313.png",
		CC_CALLBACK_1(JianZao::todecbai, this, 4, shi4, bai4)
	);
	if (dec_24 == nullptr ||
		dec_24->getContentSize().width <= 0 ||
		dec_24->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 1285;
		float y = origin.y + 300;
		dec_24->setScale(2.5);
		dec_24->setPosition(Vec2(x, y));
	}
	auto m_dec_24 = Menu::create(dec_24, NULL);
	m_dec_24->setPosition(Vec2::ZERO);
	myNode->addChild(m_dec_24, 1);


	auto add_11 = MenuItemImage::create(
		"./factory/316.png",
		"./factory/318.png",
		CC_CALLBACK_1(JianZao::toaddshi, this,1,shi1,bai1)
	);
	if (add_11 == nullptr ||
		add_11->getContentSize().width <= 0 ||
		add_11->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 885;
		float y = origin.y + 685;
		add_11->setScale(2.5);
		add_11->setPosition(Vec2(x, y));
	}
	auto m_add_11 = Menu::create(add_11, NULL);
	m_add_11->setPosition(Vec2::ZERO);
	myNode->addChild(m_add_11, 1);

	auto add_12 = MenuItemImage::create(
		"./factory/316.png",
		"./factory/318.png",
		CC_CALLBACK_1(JianZao::toaddshi, this, 2, shi2, bai2)
	);
	if (add_12 == nullptr ||
		add_12->getContentSize().width <= 0 ||
		add_12->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 885;
		float y = origin.y + 365;
		add_12->setScale(2.5);
		add_12->setPosition(Vec2(x, y));
	}
	auto m_add_12 = Menu::create(add_12, NULL);
	m_add_12->setPosition(Vec2::ZERO);
	myNode->addChild(m_add_12, 1);

	auto add_13 = MenuItemImage::create(
		"./factory/316.png",
		"./factory/318.png",
		CC_CALLBACK_1(JianZao::toaddshi, this, 3, shi3, bai3)
	);
	if (add_13 == nullptr ||
		add_13->getContentSize().width <= 0 ||
		add_13->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 1435;
		float y = origin.y + 685;
		add_13->setScale(2.5);
		add_13->setPosition(Vec2(x, y));
	}
	auto m_add_13 = Menu::create(add_13, NULL);
	m_add_13->setPosition(Vec2::ZERO);
	myNode->addChild(m_add_13, 1);

	auto add_14 = MenuItemImage::create(
		"./factory/316.png",
		"./factory/318.png",
		CC_CALLBACK_1(JianZao::toaddshi, this, 4, shi4, bai4)
	);
	if (add_14 == nullptr ||
		add_14->getContentSize().width <= 0 ||
		add_14->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 1435;
		float y = origin.y + 365;
		add_14->setScale(2.5);
		add_14->setPosition(Vec2(x, y));
	}
	auto m_add_14 = Menu::create(add_14, NULL);
	m_add_14->setPosition(Vec2::ZERO);
	myNode->addChild(m_add_14, 1);

	auto add_21 = MenuItemImage::create(
		"./factory/316.png",
		"./factory/318.png",
		CC_CALLBACK_1(JianZao::toaddbai, this,1,shi1,bai1)
	);
	if (add_21 == nullptr ||
		add_21->getContentSize().width <= 0 ||
		add_21->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 885;
		float y = origin.y + 620;
		add_21->setScale(2.5);
		add_21->setPosition(Vec2(x, y));
	}
	auto m_add_21 = Menu::create(add_21, NULL);
	m_add_21->setPosition(Vec2::ZERO);
	myNode->addChild(m_add_21, 1);

	auto add_22 = MenuItemImage::create(
		"./factory/316.png",
		"./factory/318.png",
		CC_CALLBACK_1(JianZao::toaddbai, this, 2, shi2, bai2)
	);
	if (add_22 == nullptr ||
		add_22->getContentSize().width <= 0 ||
		add_22->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 885;
		float y = origin.y + 300;
		add_22->setScale(2.5);
		add_22->setPosition(Vec2(x, y));
	}
	auto m_add_22 = Menu::create(add_22, NULL);
	m_add_22->setPosition(Vec2::ZERO);
	myNode->addChild(m_add_22, 1);

	auto add_23 = MenuItemImage::create(
		"./factory/316.png",
		"./factory/318.png",
		CC_CALLBACK_1(JianZao::toaddbai, this, 3, shi3, bai3)
	);
	if (add_23 == nullptr ||
		add_23->getContentSize().width <= 0 ||
		add_23->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 1435;
		float y = origin.y + 620;
		add_23->setScale(2.5);
		add_23->setPosition(Vec2(x, y));
	}
	auto m_add_23 = Menu::create(add_23, NULL);
	m_add_23->setPosition(Vec2::ZERO);
	myNode->addChild(m_add_23, 1);

	auto add_24 = MenuItemImage::create(
		"./factory/316.png",
		"./factory/318.png",
		CC_CALLBACK_1(JianZao::toaddbai, this, 4, shi4, bai4)
	);
	if (add_24 == nullptr ||
		add_24->getContentSize().width <= 0 ||
		add_24->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + 1435;
		float y = origin.y + 300;
		add_24->setScale(2.5);
		add_24->setPosition(Vec2(x, y));
	}
	auto m_add_24 = Menu::create(add_24, NULL);
	m_add_24->setPosition(Vec2::ZERO);
	myNode->addChild(m_add_24, 1);

	auto oil = Sprite::create("./factory/oil.png");
	if (oil == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		oil->setScale(1.3);
		oil->setPosition(Vec2(origin.x + 510, origin.y + 706));

		// add the sprite as a child to this layer
		myNode->addChild(oil, 1);
	}

	auto ammo = Sprite::create("./factory/ammo.png");
	if (ammo == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		ammo->setScale(1.3);
		ammo->setPosition(Vec2(origin.x + 520, origin.y +385));

		// add the sprite as a child to this layer
		myNode->addChild(ammo, 1);
	}

	auto steel = Sprite::create("./factory/steel.png");
	if (steel == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		steel->setScale(1.3);
		steel->setPosition(Vec2(origin.x + 1060, origin.y + 706));

		// add the sprite as a child to this layer
		myNode->addChild(steel, 1);
	}


	auto alum = Sprite::create("./factory/alum.png");
	if (alum == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		alum->setScale(1.3);
		alum->setPosition(Vec2(origin.x + 1060, origin.y + 385));

		// add the sprite as a child to this layer
		myNode->addChild(alum, 1);
	}

	myNode->setPosition(500, 0);
	this->addChild(myNode);
	auto moveby = MoveBy::create(1, Vec2(-500, 0));
	auto move_ease_in = EaseBackOut::create(moveby->clone());
	myNode->runAction(move_ease_in);
	return true;
}

void JianZao::tostart(cocos2d::Ref * pSender)
{
	int ship,position;
	string shipid;
	if (steelnum > 150 && ammonum > 150)
	{
		flag[7] = 1;
		flag[8] = 1;
	}
	if (oilnum>80)
	{
		flag[4] = 1;
		flag[5] = 1;
		flag[6] = 1;
	}
	if (alumnum>200&&steelnum>150)
	{
		flag[9] = 1;
	}
	
		flag[0] = 1;
		flag[1] = 1;
		flag[2] = 1;
		flag[3] = 1;
	
	do
	{
		position = rand() % 10;
	} while (flag[position] != 1);
	switch (position)
	{
	case 0:	
	case 1:
	case 2:
	case 3:
		ship = rand() % p1;
		shipid = quzhu[ship].id;
		if (shipid == "002") {
			ship = rand() % p1;
			shipid = quzhu[ship].id;
		}
		if (shipid == "002") {
			ship = rand() % p1;
			shipid = quzhu[ship].id;
		}
		Chinjufu::ship[Chinjufu::shipNum] = quzhu[ship];
		break;
	case 4:
	case 5:
	case 6:
		ship = rand() % p2;
		shipid = xunyang[ship].id;
		Chinjufu::ship[Chinjufu::shipNum] = xunyang[ship];
		break;
	case 7:
	case 8:
		ship = rand() % p3;
		shipid = zhanjian[ship].id;
		Chinjufu::ship[Chinjufu::shipNum] = zhanjian[ship];
		break;
	case 9:
		ship = rand() % p4;
		shipid = hangmu[ship].id;
		Chinjufu::ship[Chinjufu::shipNum] = hangmu[ship];
	default:
		break;
	}
	Chinjufu::shipNum++;
	JianZao::build = shipid;
	auto sg = ShanGuang::createScene();
	Director::getInstance()->replaceScene(sg);
}
void JianZao::shownum(int number, cocos2d::Sprite* shi, cocos2d::Sprite* bai)
{
	int b, s;
	char bb,ss;
	b = number / 100;
	s = number % 100;
	s = s / 10;
	bb = b + '0';
	ss = s + '0';
	char sfile[50] = "./factory/0.png";
	char bfile[50] = "./factory/0.png";
	sfile[10] = ss;
	bfile[10] = bb;
	Texture2D* ling = Director::getInstance()->getTextureCache()->addImage(bfile);
	Texture2D* san = Director::getInstance()->getTextureCache()->addImage(sfile);
	bai->setTexture(ling);
	shi->setTexture(san);
}

void JianZao::toreset(cocos2d::Ref * pSender,int number, cocos2d::Sprite* shi, cocos2d::Sprite* bai)
{
	Texture2D* ling = Director::getInstance()->getTextureCache()->addImage("./factory/0.png");
	Texture2D* san = Director::getInstance()->getTextureCache()->addImage("./factory/3.png");
	bai->setTexture(ling);
	shi->setTexture(san);
	switch (number)
	{
	case 3:steelnum = 30;break;
	case 1:oilnum = 30;break;
	case 4:alumnum = 30;break;
	case 2:ammonum = 30;break;
	}
}

void JianZao::tomax(cocos2d::Ref * pSender,int number, cocos2d::Sprite* shi, cocos2d::Sprite* bai)
{
	Texture2D* ling = Director::getInstance()->getTextureCache()->addImage("./factory/9.png");
	Texture2D* san = Director::getInstance()->getTextureCache()->addImage("./factory/9.png");
	bai->setTexture(ling);
	shi->setTexture(san);
	switch (number)
	{
	case 3:steelnum = 990;break;
	case 1:oilnum = 990;break;
	case 4:alumnum = 990;break;
	case 2:ammonum = 990;break;
	}
}

void JianZao::todecshi(cocos2d::Ref * pSender, int number, cocos2d::Sprite* shi, cocos2d::Sprite* bai)
{
	int zhi;
	switch (number)
	{
	case 3:if (steelnum != 30)
			{
			steelnum -= 10;			
			}
		   zhi = steelnum;
		    break;
	case 1:if (oilnum != 30)
			{
			oilnum -= 10;
			}
		   zhi = oilnum;
			break;
	case 4:if (alumnum != 30)
			{
				alumnum -= 10;
			}
		   zhi = alumnum;
		   break;
	case 2:if (ammonum != 30)
			{
				ammonum -= 10;
			}
		   zhi = ammonum;
		   break;
	}
	shownum(zhi, shi, bai);
}

void JianZao::todecbai(cocos2d::Ref * pSender, int number, cocos2d::Sprite* shi, cocos2d::Sprite* bai)
{
	int zhi;
	switch (number)
	{
	case 3:if (steelnum >=130 )
	{
		steelnum -= 100;
	}
		   zhi = steelnum;
		   break;
	case 1:if (oilnum >=130)
	{
		oilnum -= 100;
	}
		   zhi = oilnum;
		   break;
	case 4:if (alumnum >=130)
	{
		alumnum -= 100;
	}
		   zhi = alumnum;
		   break;
	case 2:if (ammonum >=130)
	{
		ammonum -= 100;
	}
		   zhi = ammonum;
		   break;
	}
	shownum(zhi, shi, bai);
}

void JianZao::toaddshi(cocos2d::Ref * pSender, int number, cocos2d::Sprite* shi, cocos2d::Sprite* bai)
{
	int zhi;
	switch (number)
	{
	case 3:if (steelnum != 990)
	{
		steelnum += 10;
	}
		   zhi = steelnum;
		   break;
	case 1:if (oilnum != 990)
	{
		oilnum += 10;
	}
		   zhi = oilnum;
		   break;
	case 4:if (alumnum != 990)
	{
		alumnum += 10;
	}
		   zhi = alumnum;
		   break;
	case 2:if (ammonum != 990)
	{
		ammonum += 10;
	}
		   zhi = ammonum;
		   break;
	}
	shownum(zhi, shi, bai);
}

void JianZao::toaddbai(cocos2d::Ref * pSender, int number, cocos2d::Sprite* shi, cocos2d::Sprite* bai)
{
	int zhi;
	switch (number)
	{
	case 3:if (steelnum <= 890)
	{
		steelnum += 100;
	}
		   zhi = steelnum;
		   break;
	case 1:if (oilnum <= 890)
	{
		oilnum += 100;
	}
		   zhi = oilnum;
		   break;
	case 4:if (alumnum <= 890)
	{
		alumnum += 100;
	}
		   zhi = alumnum;
		   break;
	case 2:if (ammonum <= 890)
	{
		ammonum += 100;
	}
		   zhi = ammonum;
		   break;
	}
	shownum(zhi, shi, bai);
}


void JianZao::toMuGang(cocos2d::Ref * pSender)
{
	auto scene2 = MuGang::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene2, Color3B(0, 255, 255)));

}