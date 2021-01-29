// Rafal Sulowski 
//
// Gra polega na niszczeniu przeszdod poruszajacych sie w strone gracza
// Glownym celem gry jest osiagniecie maksymalnego wyniku zniszczonych meteorytow.
// Poruszanie sie do goru lub do dolu strzalkami, strzal lasera spacja
// (czestotliwosc strzalow co 1 sek, celowe utrudnienie rozgrywki)

// Statek gracza to obiekt klasy Tstatek_matka dziedziczy on publicznie po klasie Tobiekt
// Meteoryt to obiekt klasy Tstatek_obcy ktory tez dziedziczy publicznei po klasie Tobiekt
// Laser to obiekt klasy Tlaser
// Napisy sa obiektami klasy Tnapisy



#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tobiekt.h"

using namespace sf;
using namespace std;
////////////////////////////////////////



///ZMENNE GLOBALNE:
int y_gracza;			// wspolrzedna y -owa aktualna gracza
int x_gracza;			// wspolrzedna x -owa aktualna gracza
int y_strzal;			// wspolrzedna y -owa gracza w momecie strzalu
int zycia = 3;			// liczba zyc gracza
int zniszczenia = 0;	// liczba zniszconych przeszkod przez gracza
int klatki = 0;			// liczy klatki programu
string nick;			// nick gracza potrzebny do zapisu wyniku
ofstream zapis("wyniki.txt", ios::app);



///FUNKCJE GLOBALNE:
//funkcja majaca stwierdzic czy gracz trafil laserem
bool trafienie(Tstatek_obcy&, Tlaser&);
//sprawdza czy przeszkoda przeleciala mape bez zniszczenia
void skucha(Tstatek_obcy&, Tnapisy&);
//odlicza (rozpoczecie gry)
bool odliczanie(Tnapisy&);
//zapisuje wynik do pliku
void zapis_wynik();



int main()
{
	srand(time(NULL));


	///TWORZENIE OBIEKTOW:
	//stworzenie i ustawnienie najwazniejszych parametrow okna
	RenderWindow okno{ VideoMode{800, 450}, "Rafal Sulowski" };
	okno.setPosition(Vector2i{ 400, 0 });
	okno.setFramerateLimit(60);

	//stworzenie obiektow klas majacych udzial w rozgrywce
	Tstatek_matka gracz(50, 200, 30, 25);
	vector <Tstatek_obcy> flota;
	Tlaser laser(0, 0, 0);

	//tworzenie interwejsu urzytkownika
	Tnapisy tekst("\\Projekt na Informatyke\\font.ttf", 300, 180, "", 50);
	Tnapisy napisy_zycia("font.ttf", 10, 10, "Liczba zyc: ", 16);
	Tnapisy napisy_zy("font.ttf", 130, 10, "3 / 3", 16);
	Tnapisy napisy_zniszczenia("font.ttf", 600, 10, "Zniszczen: ", 16);
	Tnapisy napisy_znisz("font.ttf", 720, 10, to_string(zniszczenia), 18);
	Tnapisy napisy_combo("font.ttf", 300, 180, "", 50);


	//border oddzielajcy przestrzen gry od informacji
	RectangleShape border;
	border.setPosition(0, 48);
	border.setFillColor(Color::Yellow);
	border.setSize(Vector2f(800, 2));


	///PETLA GLOWNA PROGRAMU:
	Clock czas;
	Event zd;
	while (okno.isOpen())
	{
		//pobranie wspolzednych polozenia gracza
		y_gracza = gracz.poz_y();
		x_gracza = gracz.poz_x();
		

	///PETLA OBSLUGUJACA ZDARZENIA (TAKIE JAK NACISNIECIE SPACJI ITP.):
		while (okno.pollEvent(zd))
		{
			if (zd.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				okno.close();
			if (zd.type == Event::Resized)
				okno.setSize(Vector2u(800, 450));
			if (Keyboard::isKeyPressed(Keyboard::Space) && laser.cool_down == 0)
			{
				laser.czas_zycia = 10;
				laser.cool_down = 60;
				y_strzal = y_gracza;
			}

		}
		okno.clear(Color::Black);


	///WPROWADZENIE DO GRY:
		if (!odliczanie(tekst))
			klatki++;


	///OBSLUGA PRZESZKOD:
		//tworzy nowe przeszkody
		if (klatki == 90 && odliczanie(tekst) == false)
		{
			flota.push_back(Tstatek_obcy(801, 70 + rand() % (380 + 1 - 70), 30, 20));
			klatki = 0;
		}
		//przemiezcza i rysuje wszystkie przeszkody
		for (int i = 0; i < flota.size(); i++)
		{
			flota[i].przemiesc(2);
			okno.draw(flota[i]);
		}


	///OBSLUGA LASERA:
		//rysuje laser jezeli nacinieto spacje
		if (laser.czas_zycia > 0)
		{
			okno.draw(Tlaser(x_gracza, y_strzal));
			laser.czas_zycia--;
		}
		if (!laser.cool_down == 0)
			laser.cool_down--;


	///OBSLUGA KOLIZJI (LASER - PRZESZKODA):
		for (int i = 0; i < flota.size(); i++)
			if (trafienie(flota[i], laser))
			{
				flota.erase(flota.begin() + i);
				zniszczenia++;
				napisy_znisz.set_string(to_string(zniszczenia));
			}



	///OBSLUGA TRACENIA ZYCIA:
		for (int i = 0; i < flota.size(); i++)
			skucha(flota[i], napisy_zy);
		//konczy rozgrywke gdy stracono 3 zycia
		if (zycia == 0)
		{
			Time pomiar = czas.getElapsedTime();

			cout << "Koniec gry, twoj wynik zniszczen to: " << zniszczenia << endl;
			cout << "Czas gry: " << pomiar.asSeconds() << endl;

			okno.close();
		}


	///OBSLUGA GRACZA:
		gracz.przemiesc(3.f);
		okno.draw(gracz);

	///RYSOWANIE INTERFEJSU:
		okno.draw(tekst);
		okno.draw(napisy_zycia);
		okno.draw(napisy_zy);
		okno.draw(napisy_zniszczenia);
		okno.draw(napisy_znisz);
		okno.draw(napisy_combo);
		//rysowanie borderu:
		okno.draw(border);

	///WYWOLANIE WSZYSTKICH METOD DRAW NA EKRAN:
		okno.display();
	}

	zapis_wynik();
}



///DEFINICJE FUNKCJI GLOBALNYCH:
bool trafienie(Tstatek_obcy& wrog, Tlaser& laser)
{
	if ((y_strzal >= wrog.poz_y() - 10) && (y_strzal <= wrog.poz_y() + 10))
		return true;
	else
		return false;
}

void skucha(Tstatek_obcy& wrog, Tnapisy& napis_zycia)
{
	if (wrog.poz_x() - 15 == 0)
	{
		zycia--;

		if (zycia == 2)
			napis_zycia.set_string("2 / 3");
		else if (zycia == 1)
			napis_zycia.set_string("1 / 3");
	}
}

bool odliczanie(Tnapisy& tekst)
{
	static int odliczanie = 0;

	if (odliczanie < 240)
	{
		if (odliczanie < 60)
			tekst.set_string("3");

		if (odliczanie >= 60 && odliczanie < 120)
			tekst.set_string("2");

		if (odliczanie >= 120 && odliczanie < 180)
			tekst.set_string("1");

		if (odliczanie >= 180 && odliczanie < 240)
			tekst.set_string("GO");

		odliczanie++;
		return true;
	}
	else if (odliczanie >= 240)
	{
		tekst.set_string("");
		return false;
	}
}

void zapis_wynik()
{
	cout << "Podaj nick:" << endl;
	cin >> nick;
	zapis << "Nick: \"" << nick << "\" wynik zniszczen: " << zniszczenia << endl;
}

