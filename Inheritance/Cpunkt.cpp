#include <iostream>
#include "Cpunkt.h"
using namespace std;

Cpunkt::Cpunkt(double iks, double igrek, string nazwa_punktu)
{
    x = iks;
    y = igrek;
    nazwa = nazwa_punktu;
}
//
Cpunkt::~Cpunkt()
{
    cout << endl;
}
//
void Cpunkt::wypisz_punkt()
{
    cout << "Punkt o nazwie: " << nazwa << endl << "X: " << x << " Y: " << y << endl;
}
//
void Cpunkt::zmien_wspolrzedne()
{
    double nx,ny;

    cout << "Podaj nowe wspolrzedne: " << endl;
    cout << "x: ";      cin >> nx;
    cout << "y: ";      cin >> ny;

    x = nx;
    y = ny;
}

