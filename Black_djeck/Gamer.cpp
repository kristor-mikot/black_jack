#include "Gamer.h"

int Gamer::proverka()
{
	for (int i = 0;i < razm-1;i++)
	{
		if ((karti[razm - 1].get_chis() == karti[i].get_chis()) && (karti[razm - 1].get_mast() == karti[i].get_mast()))
		{
			karti[razm - 1] = Karta((rand() % 12) + 2, (rand() % 3) + 1);
			return 1;
		}
	}
	return 0;
}

void Gamer::dobav_kart()
{
	Karta* temp_karti = new Karta[razm];
	for (int i = 0;i < razm;i++)
	{
		temp_karti[i] = karti[i];
	}
	razm++;
	delete[]karti;
	karti = new Karta[razm];
	for (int i = 0;i < razm - 1;i++)
	{
		karti[i] = temp_karti[i];
	}
	karti[razm - 1] = Karta((rand() % 12) + 2, (rand() % 3) + 1);
	while (true)
	{
		int temp = proverka();
		if (temp == 0)
			break;
	}
}

void Gamer::set_name(string _name)
{
	name = _name;
}

void Gamer::set_money(int _money)
{
	money = _money;
}
void Gamer::minus_money(int kolvo)
{
	money = money-kolvo;
}
void Gamer::plus_money(int kolvo)
{
	money = money +kolvo;
}

string Gamer::get_name()
{
	return name;
}

int Gamer::get_money()
{
	return money;
}

Karta* Gamer::get_karti()
{
	return karti;
}

int Gamer::summa_kart(Karta* karti)
{
	int summ = 0;
	for (int i = 0;i < razm;i++)
	{
		summ = summ+karti[i].get_value();
	}
	return summ;
}

void Gamer::vivod()
{
	for (int i = 0;i < razm;i++)
	{
		cout << endl;
		karti[i].text();
	}
	cout << endl;
}

void Gamer::set_karti()
{
	karti[0] = Karta((rand() % 12) + 2, (rand() % 3) + 1);
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
