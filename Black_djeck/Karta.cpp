#include "Karta.h"

//void Karta::set_karta()
//{
//	srand(time(0));
//	chis = (rand() % 9)+2;
//	mast = (rand() % 3)+1;
//	if (mast == "1")
//	{
//		mast = "Kresti";
//	}
//	else if (mast == "2")
//	{
//		mast = "Bubi";
//	}
//	else if (mast == "3")
//	{
//		mast = "Heart";
//	}
//	else
//	{
//		mast = "Piki";
//	}
//}

int Karta::set_value()
{
	if (chis >= 2 && chis <= 10)
	{
		return chis;
	}
	else if (chis == 14)
		return 11;
	else
		return 10;
}

int Karta::get_value()
{
	return value;
}

void Karta::text()
{
	if (chis == 2)
		cout << "\ntwo ";
	else if (chis == 3)
		cout << "\nThree ";
	else if (chis == 4)
		cout << "\nFour ";
	else if (chis == 5)
		cout << "\nFive ";
	else if (chis == 6)
		cout << "\nSix ";
	else if (chis == 7)
		cout << "\nSeven ";
	else if (chis == 8)
		cout << "\nEignt ";
	else if (chis == 9)
		cout << "\nNine";
	else if (chis == 10)
		cout << "\nTen";
	else if (chis == 11)
		cout << "\nValet";
	else if (chis == 12)
		cout << "\nDama";
	else if (chis == 13)
		cout << "\nKing";
	else if (chis == 14)
		cout << "\nTuz";
	if (mast == 1)
		cout << "Heart ";
	else if (mast == 2)
		cout << "Bubi ";
	else if (mast == 3)
		cout << "Kresti ";
	else if (mast == 4)
		cout << "Piki ";
}



void Karta::set_chis(int _chis)
{
	chis = _chis;
}

void Karta::set_mast(int _mast)
{
	mast = _mast;
}

int Karta::get_chis()
{
	return chis;
}

int Karta::get_mast()
{
	return mast;
}
