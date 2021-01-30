#include <iostream>
#include "Cpunkt.h"
using namespace std;

Ckolo::~Ckolo()
{
    cout << endl;
}
//
void Ckolo::wypisz_kolo()
{
    Cpunkt::wypisz_punkt();
    cout << "Promien: " << r << endl << "Nazwa kola: " << nazwa << endl;

}
//
void Ckolo::zmien_promien()
{
    int nr;

    cout << "Podaj nowy promien: " << endl;
    cin >> nr;
    r = nr;
}
