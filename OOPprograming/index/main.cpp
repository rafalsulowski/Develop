#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;

class GRACZ;

class MOB
{
public:

    int hp;         //100
    int sila;       //10-20
    int obrona;     //1-10

    MOB(int hps = 100, int silas = 20, int obronas = 1) :hp(hps), sila(silas), obrona(obronas)
    {
    }
    ~MOB();

    int MOBattak(MOB mob);
    void MOBobrona(MOB& mob, GRACZ gracz);

friend class GRACZ;

};

class GRACZ
{
public:

    int hp;         //100
    int sila;       //15-25
    int obrona;     //1-10

    GRACZ(int hps = 100, int silas = 20, int obronas = 1) :hp(hps), sila(silas), obrona(obronas)
    {
    }
    ~GRACZ()
    {
    }

    int GRACZattak(GRACZ gracz);
    void GRACZobrona(MOB mob, GRACZ& gracz);

friend class MOB;

};


int MOB::MOBattak(MOB mob)
{
    int x,n;

    n = mob.sila + 10;
    x = 1 + rand() % (n + 1 - 1);

    cout << "Mob atakuje za: " << x << endl;

    return x;
}

int GRACZ::GRACZattak(GRACZ gracz)
{
    int x,n;

    n = gracz.sila + 10;
    x = 1 + rand() % (n + 1 - 1);

    cout << "Gracz atakuje za: " << x << endl;

    return x;
}
void MOB::MOBobrona(MOB& mob, GRACZ gracz)
{
    int x,n;

    n = mob.obrona + 10;
    x = 1 + rand() % (n + 1 - 1);



    n = GRACZ::GRACZattak(gracz) - x;
    cout << "Mob broni sie za: " << x << endl;

    if(n < 0)
        cout << "Mob obronil sie, nie otrzymuje obrazen, jego stan zdrowia wynosi: " << mob.hp << endl;
    else
    {
        mob.hp -= n;
        cout << "Teraz zdrowie moba wynosi: " << mob.hp << endl;
    }

}
void GRACZ::GRACZobrona(MOB mob, GRACZ& gracz)
{
    int x,x2,n;

    n = gracz.obrona + 10;
    x = 1 + rand() % (n + 1 - 1);


    n = MOBattak(mob) - x;
    cout << "Gracz broni sie za: " << x << endl;

    if(n < 0)
        cout << "Gracz obronil sie, nie otrzymuje obrazen, jego stan zdrowia wynosi: " << gracz.hp << endl;
    else
    {
        gracz.hp -= n;
        cout << "Teraz zdrowie gracza wynosi: " << gracz.hp << endl;
    }

}




int main()
{
    srand(time(NULL));

    MOB mob(10,20,1);
    GRACZ gracz(150,20,1);

    int i{0};
    int licz_zab{0}, licz_ciosy{0};


    while(gracz.hp > 0)
    {
        if(i %2 == 0)
        {
            GRACZobrona(mob, gracz);

            system("pause");
            system("cls");
            licz_ciosy++;
        }
        else
        {
            MOBobrona(mob,gracz);

            system("pause");
            system("cls");
        }

        if(mob.hp <= 0)
        {
            cout << "Mob zostal zabity!" << endl;
            licz_zab++;
            Sleep(1000);
        }

        i++;
    }

    cout << "Gracz zabil: " << licz_zab << " mobow" << endl;
    cout << "Wytrwal: " << licz_ciosy << " ciosow" << endl;







    return 0;
}








