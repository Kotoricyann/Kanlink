#pragma once
#include <iostream>
#include<time.h>
using namespace std;
class Ship {
public:
	bool exist;//���������û����Ϣ
	int no;//���ظ��ڱ��
	string id;//������ţ��ܱ�ţ�
	string name;//����
	int type;//�������ࣺ����Ѳ�󽢡�ս�н�����ĸ:1,2,3,4
	bool ruin;//�Ƿ񱻴ݻ�
	short weak;//�Ƿ�����
	bool canRuin;//�Ƿ��ܱ��ݻ�
	bool fleetflag;//�Ƿ��ڽ�����
	string state;//Ŀǰ״̬-n/s
	int HP;//��ǰѪ��
	int HP_MAX;//���Ѫ��
	int atk;//������
	int ac;//����
	int lv;//�ȼ�
	int exp;//��ǰ����ֵ

	Ship();
	Ship(string _id, string _name, int _type, int _HP_MAX, int _atk, int _ac);
	void setShip(string _id, string _name, int _type,int _HP, int _HP_MAX, int _atk, int _ac, int _lv,  int _exp,string _state );
	void checkWeak();
	

};



class Chinjufu {
public:
	static char name[100];//���ظ�����
	static Ship ship[100];//��
	static short shipNum;//��������
	static Ship fleet[6];//�����ڽ���
	static short fleetNum;//�����ڽ�������
	static int steel;//��
	static int oil;//��
	static int alum;//��
	static int ammo;//��
	static clock_t lastVisit;//�ϴη���ʱ�䣬����������Դ


	Chinjufu();
	static void replaceResourse();//������Դ����

	//void duqushuju();//���ض�ȡ���ݣ�

};