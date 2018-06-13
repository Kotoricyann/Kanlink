#include "Kanclass.h"


Chinjufu::Chinjufu() {
	
	

}
//静态成员定义
char Chinjufu::name[100];//镇守府名称
Ship Chinjufu::ship[100];//船
short Chinjufu::shipNum;//舰船总数
Ship Chinjufu::fleet[6];//队伍内舰娘
clock_t Chinjufu::lastVisit = clock();
int Chinjufu::alum = 200;
int Chinjufu::ammo = 200;
int Chinjufu::oil = 200;
int Chinjufu::steel= 200;
short Chinjufu::fleetNum = 0;

void Chinjufu::replaceResourse()
{
	clock_t now;
	now = clock();
	int interval = now - Chinjufu::lastVisit;
	steel = steel + interval / 1000;
	Chinjufu::oil += interval / 1000;
	Chinjufu::alum += interval / 1000;
	Chinjufu::ammo += interval / 1000;
	Chinjufu::lastVisit = now;
}

Ship::Ship()
{
	exist = 0;
	weak = 0;
	ruin = 0;
	state = "n";

}


void Ship::checkWeak()
{
	if (HP < HP_MAX / 2) {
		weak = 1;
		state = "s";
	}
	else {
		weak = 0;
		state = "n";
	}
	if (HP < HP_MAX / 4) weak = 2;
}

Ship::Ship(string _id, string _name, int _type, int _HP_MAX, int _atk, int _ac)
{
	id = _id;
	name = _name;
	type = _type;
	HP_MAX = _HP_MAX;
	atk = _atk;
	ac = _ac;
	lv = 1;
	exp = 0;
	exist = 1;
	weak = 0;
	ruin = 0;
	canRuin = 0;
}

void Ship::setShip(string _id, string _name, int _type, int _HP, int _HP_MAX, int _atk, int _ac, int _lv, int _exp, string _state)
{
	id = _id;
	name = _name;
	type = _type;
	HP = _HP;
	HP_MAX = _HP_MAX;
	atk = _atk;
	ac = _ac;
	lv = _lv;
	exp = _exp;
	exist = 1;
	weak = 0;
	ruin = 0;
	canRuin = 0;
}

