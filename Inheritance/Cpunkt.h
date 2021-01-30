#include <iostream>
using namespace std;

class Cpunkt
{
    double x,y;
    string nazwa;

public:
    Cpunkt(double iks = 0.0, double igrek = 0.0, string nazwa_punktu = "A");
    ~Cpunkt();
    void wypisz_punkt();
    void zmien_wspolrzedne();

};


class Ckolo :public Cpunkt
{
    double r;
    string nazwa;

public:
    Ckolo(double iks = 0.0, double igrek = 0.0, double pr = 3.0, string nazwa_punktu = "S", string nazwa_kola = "KOLO")
    :Cpunkt(iks, igrek, nazwa_punktu)
    {
        r = pr;
        nazwa = nazwa_kola;
    }

    ~Ckolo();
    void wypisz_kolo();
    void zmien_promien();

};
