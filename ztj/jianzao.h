#pragma once
#ifndef __JIANZAO_SCENE_H__
#define __JIANZAO_SCENE_H__

#include "cocos2d.h"
#include "iostream"
using namespace std;

class JianZao : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	static string build;

	virtual bool init();

	// a selector callback
	void tostart(cocos2d::Ref* pSender);
	void shownum(int number, cocos2d::Sprite* shi, cocos2d::Sprite* bai);
	void toreset(cocos2d::Ref * pSender, int number,cocos2d::Sprite* shi1, cocos2d::Sprite* bai1);
	void tomax(cocos2d::Ref * pSender, int number,cocos2d::Sprite* shi1, cocos2d::Sprite* bai1);
	void todecshi(cocos2d::Ref * pSender, int number, cocos2d::Sprite* shi, cocos2d::Sprite* bai);
	void todecbai(cocos2d::Ref * pSender, int number, cocos2d::Sprite* shi, cocos2d::Sprite* bai);
	void toaddshi(cocos2d::Ref * pSender, int number, cocos2d::Sprite* shi, cocos2d::Sprite* bai);
	void toaddbai(cocos2d::Ref * pSender, int number, cocos2d::Sprite* shi, cocos2d::Sprite* bai);
	void toMuGang(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(JianZao);
};

#endif // __JIANZAO_SCENE_H__
