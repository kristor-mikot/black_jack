#pragma once
#include <iostream>
#include <string.h>
#include"Karta.h"
using namespace std;
class Gamer
{
private:
	string name;
	int money;
	Karta *karti=new Karta[razm];
	int proverka();
public:
	Gamer(string _name, int _money) :name{ _name }, money{ _money }
	{
		karti[0]=Karta((rand()%12)+2, (rand() % 3) + 1);
		karti[1] = Karta((rand() % 12) + 2, (rand() % 3) + 1);
		while (true)
		{
			if ((karti[1].get_chis() == karti[0].get_chis()) && (karti[1].get_mast() == karti[0].get_mast()))
			{
				karti[1] = Karta((rand() % 12) + 2, (rand() % 3) + 1);
			}
			else
			{
				break;
			}
		}
		
	}
	Gamer(string _name) :Gamer(_name,1000){}
	void dobav_kart();
	void set_name(string _name);
	void set_money(int money);
	void minus_money(int kolvo);
	void plus_money(int kolvo);
	string get_name();
	int get_money();
	Karta *get_karti();
	int summa_kart(Karta *karti);
	void vivod();
	void set_karti();
	int razm = 2;
};

