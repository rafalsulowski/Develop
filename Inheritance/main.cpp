#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "Cpunkt.h"
using namespace std;


int main()
{
    Cpunkt punkt(2,4,"A");

    punkt.wypisz_punkt();

    Sleep(1500);
    system("cls");

    punkt.zmien_wspolrzedne();

    system("cls");

    punkt.wypisz_punkt();

    //Kolo//

    Ckolo kolo(1,3,4,"S","Kolo");
    kolo.wypisz_kolo();
    kolo.zmien_promien();
    kolo.wypisz_kolo();

    kolo.zmien_wspolrzedne();
    kolo.wypisz_kolo();

    return 0;
}
