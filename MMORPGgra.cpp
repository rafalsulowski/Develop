// MMORPGgra.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>



class OBIEKT
{
protected:

	double hp;
	double power;

public:

	OBIEKT(double hp = 100, double power = 10)
	{
		this->hp = hp;
		this->power = power;

		cout << "konstruktor objektu" << endl;
	}
	~OBIEKT()
	{
		cout << "+++" << endl;
	}

};

class MOB :public OBIEKT
{
protected:

	int lvl_MOB;
	int pp_MOB;

public:

	MOB(double hp = 100, double power = 10, int lvl_MOB = 1, int pp_MOB = 1) :OBIEKT(hp, power)
	{
		this->hp = hp;
		this->power = power;
		this->lvl_MOB = lvl_MOB;
		this->pp_MOB = pp_MOB;

		cout << "konstruktor Moba" << endl;
	}

	int attack()
	{
		int x{}, n;

		n = 10 + (lvl_MOB * pp_MOB);
		x = 10 + rand() % (n + 1 - 0);

		cout << "Mob zaatakowal za " << x << endl;

		return x;
	}

	void lvl_up_MOB()
	{
		cout << "MOB wbija " << lvl_MOB << " level" << endl;
		lvl_MOB++;
		pp_MOB += 2;
	}

};

class GRACZ :public MOB
{
	int lvl_GR;
	int pp_GR;
	int kl_wyp; //klasa wypsazenia od 1 do 5

public:

	GRACZ(int lvl_GR = 1, int pp_GR = 1, int kl_wyp = 0) : MOB(hp, power, lvl_MOB, pp_MOB)
	{
		this->lvl_GR = lvl_GR;
		this->pp_GR = pp_GR;
		this->kl_wyp = kl_wyp;
	}

	void lvl_up_GR()
	{
		cout << "Gracz wbija " << lvl_GR << " level" << endl;
		lvl_GR++;
		pp_GR += 4;
		kl_wyp += 0.25;

	}
	int attack()
	{
		int x{}, n;

		n = 15 + (lvl_MOB * pp_MOB);
		x = 15 + rand() % (n + 1 - 0);

		cout << "Gracz zaatakowal za " << x << endl;
		this->hp -= x;

		return x;
	}

	void unik()
	{
		int x, wyp, n; //wyp - wyposarzenie zwiekszajace szanse na unik

		x = 100 % (1 + wyp);
		n = 0 + rand() % (100 + 1);

		if (x >= n)
			cout << "Unik!!!" << endl;
		else
			this->hp -= MOB::attack();

	}

	double amo_usz()     //amortyzacja uszkodzen- zmniejszenie uszkodzen
	{
		double x, wyp;

		if (kl_wyp == 0)
			this->hp -= MOB::attack();
		else if (kl_wyp == 1)
		{
			x = MOB::attack() * 0, 9;
			this->hp -= x;
		}
		else if (kl_wyp == 2)
		{
			x = MOB::attack() * 0, 8;
			this->hp -= x;
		}
		else if (kl_wyp == 3)
		{
			x = MOB::attack() * 0, 7;
			this->hp -= x;
		}
		else if (kl_wyp == 4)
		{
			x = MOB::attack() * 0, 6;
			this->hp -= x;
		}
		else if (kl_wyp == 5)
		{
			x = MOB::attack() * 0, 5;
			this->hp -= x;
		}
	}


	void koniec_gry()
	{
		if (lvl_GR > 16)
			cout << "Brawo przeszedles gre!" << endl;
	}

	double stan_zdrowia()
	{
		cout << "Gracz ma: " << this->hp << " punktow zycia" << endl;

	}



};


int main()
{
	srand(time(NULL));

	OBIEKT ob1;
	MOB mob1;
	GRACZ gr1;

	mob1.attack();
	gr1.stan_zdrowia();

	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
