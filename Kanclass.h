#pragma once
#include <iostream>
#include<time.h>
using namespace std;
class Ship {
public:
	bool exist;//这个格子有没有信息
	int no;//镇守府内编号
	string id;//舰船编号（总编号）
	string name;//船名
	int type;//舰船种类：驱逐、巡洋舰、战列舰、航母:1,2,3,4
	bool ruin;//是否被摧毁
	short weak;//是否中破
	bool canRuin;//是否能被摧毁
	bool fleetflag;//是否在舰队里
	string state;//目前状态-n/s
	int HP;//当前血量
	int HP_MAX;//最大血量
	int atk;//攻击力
	int ac;//护甲
	int lv;//等级
	int exp;//当前经验值

	Ship();
	Ship(string _id, string _name, int _type, int _HP_MAX, int _atk, int _ac);
	void setShip(string _id, string _name, int _type,int _HP, int _HP_MAX, int _atk, int _ac, int _lv,  int _exp,string _state );
	void checkWeak();
	

};



class Chinjufu {
public:
	static char name[100];//镇守府名称
	static Ship ship[100];//船
	static short shipNum;//舰船总数
	static Ship fleet[6];//队伍内舰娘
	static short fleetNum;//队伍内舰娘总数
	static int steel;//刚
	static int oil;//油
	static int alum;//铝
	static int ammo;//弹
	static clock_t lastVisit;//上次访问时间，用来增加资源


	Chinjufu();
	static void replaceResourse();//更新资源量；

	//void duqushuju();//本地读取数据；

};