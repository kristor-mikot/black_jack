#pragma once
#include"Gamer.h"
#include"Karta.h"
#include <time.h>
#include<windows.h>
int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int resh;
	string resh2;
	cout << "\nДобро пожаловать в казино What?,сколько денег у вас с собой?";
	cin >> resh;
	cout << "\nОтлично,у меня с собой как раз столько же,может сыграем в black jack?";
	cin >> resh2;
	Gamer gamer1("Valera", resh);
	Gamer gamer2("Vasili", resh);
	if (resh2 == "да")
	{
		while (true)
		{
			cout << "\nСколько хотите поставить?";
			cin >> resh;
			if (gamer1.get_money() - resh >= 0)
			{
				cout << "\nОтлично,играем";
				cout << "У вас счёт: " << gamer1.summa_kart(gamer1.get_karti()) << "\nХотите взять ещё карту?";
				cin >> resh2;
				if (resh2 == "да")
				{
					while (true)
					{
						gamer1.dobav_kart();
						cout << "\nНовый счёт: " << gamer1.summa_kart(gamer1.get_karti());
						if (gamer1.summa_kart(gamer1.get_karti()) > 21)
							break;
						cout << "\nХотите взять ещё одну карту?";
						cin >> resh2;
						if (resh2 == "нет")
							break;
						
					}
				}
				cout << "Мой счёт: " << gamer2.summa_kart(gamer2.get_karti()) << "\nХочу ли я взять ещё одну карту?";
				cin >> resh2;
				if (resh2 == "да")
				{
					while (true)
					{
						gamer2.dobav_kart();
						cout << "\nНовый счёт: " << gamer2.summa_kart(gamer2.get_karti());
						if (gamer2.summa_kart(gamer2.get_karti()) > 21)
							break;
						cout << "\nМожет взять ещё карту?";
						cin >> resh2;
						if (resh2 == "нет")
							break;
					}
				}
				if ((gamer1.summa_kart(gamer1.get_karti()) > gamer2.summa_kart(gamer2.get_karti())) && gamer1.summa_kart(gamer1.get_karti()) <= 21)
				{
					cout << "\nВы выиграли";
					gamer1.plus_money(resh);
					gamer2.minus_money(resh);
					if (gamer2.get_money() <= 0)
					{
						cout << "\nУ меня деньги закончились,но игра была хорошая\nНу,я пошёл";
						Sleep(5000);
						break;
					}
				}
				else if ((gamer1.summa_kart(gamer1.get_karti()) < gamer2.summa_kart(gamer2.get_karti())) && gamer2.summa_kart(gamer1.get_karti()) <= 21)
				{
					cout << "\nЯ победил в этот раз";
					gamer1.minus_money(resh);
					gamer2.plus_money(resh);
					if (gamer1.get_money() <= 0)
					{
						cout << "\nУ вас деньги закончились,но игра была хорошая\nНу,я пошёл";
						Sleep(5000);
						break;
					}
				}
				else if((gamer1.summa_kart(gamer1.get_karti()) == gamer2.summa_kart(gamer2.get_karti())) && gamer2.summa_kart(gamer1.get_karti()) <= 21)
				{
					cout << "\nНичья,неплохо";
					gamer1.minus_money(resh);
					gamer2.minus_money(resh);
					if (gamer1.get_money() <= 0 )
					{
						cout << "\nДеньги у меня закончились,но игра была хорошая\nНу,я пошёл";
						Sleep(5000);
						break;
					}
					else if(gamer2.get_money() <= 0)
					{
						cout << "\nДеньги у вас закончились,но игра была хорошая\nНу,я пошёл";
						Sleep(5000);
						break;
					}
				}
				else if ((gamer1.summa_kart(gamer1.get_karti()) <=21)  && gamer2.summa_kart(gamer1.get_karti()) > 21)
				{
					cout << "\nВы выиграли";
					gamer1.plus_money(resh);
					gamer2.minus_money(resh);
					if (gamer2.get_money() <= 0)
					{
						cout << "\nУ меня деньги закончились,но игра была хорошая\nНу,я пошёл";
						Sleep(5000);
						break;
					}
				}
				else if ((gamer1.summa_kart(gamer1.get_karti()) > 21) && gamer2.summa_kart(gamer1.get_karti()) <= 21)
				{
					cout << "\nЯ победил в этот раз";
					gamer1.minus_money(resh);
					gamer2.plus_money(resh);
					if (gamer1.get_money() <= 0)
					{
						cout << "\nУ вас деньги закончились,но игра была хорошая\nНу,я пошёл";
						Sleep(5000);
						break;
					}
				}
			}
			else
			{
				cout << "\nУ вас недостаточно средств,пожалуйста введите другое число";
				cout << "\nВаше количество денег: " << gamer1.get_money();
			}
		}
	}
	else
	{
		cout << "\nКак хотите,я пошел";
	}
}