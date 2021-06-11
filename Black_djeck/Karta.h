#pragma once
#include <iostream>
#include <string.h>
#include"Header.h"
using namespace std;
class Karta
{
private: 
	int chis;
	int mast;
	int value;
public:
	Karta(int num,int _mast)
	{
		chis = num;
		mast = _mast;
		value=set_value();
	}
	Karta()
	{
		chis = 2;
		mast = 1;
		value = 0;
	}
	int set_value();
	int get_value();
	void text();
	/*void set_karta();*/
	void set_chis(int _chis);
	void set_mast(int _mast);
	int get_chis();
	int get_mast();
};

