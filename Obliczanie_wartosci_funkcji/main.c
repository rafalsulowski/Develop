/*
Program który w pliku wynikowym zapisuje argument i wartośc funkcji tego argumentu
Do pragram uruchamia się danymi argumentami wejscia, jezeli wszysteki arg sa poprawne
program zapisze do pliku argumenty i wartosci funkcji dla tych argumentow.
Uruchamianie programu:
prog.exe -w 1 2 3 -f 1.0 -t 5.67 -n 300 -o output
Pierwszy argument -w lub -t informują program z jaką funkcją pracuje:
A) wielomianowa: funkcja stała, liniowa, kwadratowa, wielomianowa stopnia >= 3
B) trygonometryczna: funkcja sin (x), cos (x), tg (x), ctg (x), sinh (x), cosh (x), tgh (x), ctgh (x) (wszystkie domyślnie
dla argumentu x, można zmienić argument podając (w nawiasach nowy arg) sin(2x), sin(3x))
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#include "Point.h"
#include "Polymain.h"
#include "Tryg.h"

//maksymalna liczba wspolczynnikkow funkcji wielomianowej
#define MAX_FACTOR 10 //mozna zwiekszyć
//maksymalna rzad wielkosci argumentu w funkcji trygonometrycznej
#define MAX_SIZE 10 //mozna zwiekszyć


int main(int argc, char **argv)
{
    char type_function = argc > 1 ? argv[1][1] : '\0'; //typ funkcji wielomianowa / trygonometryczna
    int i = 2;
    double *Factors = (double *)malloc(sizeof(double) * MAX_FACTOR); //wspolczynniki funkcji wielomianowej
    int Function_degree = 0;                                         //stopien wielomianu

    double arg_tryg = 1;        //arguemnt funkcji trygonometrycznej
    int type_tryg_function = 1; //typ funkcji trygonometrycznej (1 - sin, 2 - cos, ... 5 - sinh, 6 - cosh, ...)

    if (type_function == 'w')
    {
        if (!Factors)
        {
            fprintf(stderr, "Can't alloc memory for table of Factors!");
            exit(EXIT_FAILURE);
        }

        while (strcmp(argv[i], "-f"))
        {
            *(Factors + i - 2) = atof(argv[i]);
            i++;
        }
        Function_degree = i;
    }
    else if (type_function == 't')
    {
        char *buf = (char *)malloc(sizeof(char) * (MAX_SIZE + 1));

        if (!strcmp("sin", argv[2]))
            type_tryg_function = 1;
        else if (!strcmp("cos", argv[2]))
            type_tryg_function = 2;
        else if (!strcmp("tg", argv[2]))
            type_tryg_function = 3;
        else if (!strcmp("ctg", argv[2]))
            type_tryg_function = 4;
        else if (!strcmp("sinh", argv[2]))
            type_tryg_function = 5;
        else if (!strcmp("cosh", argv[2]))
            type_tryg_function = 6;
        else if (!strcmp("tgh", argv[2]))
            type_tryg_function = 7;
        else if (!strcmp("ctgh", argv[2]))
            type_tryg_function = 8;
        else
        {
            fprintf(stderr, "Incorrect function!");
            exit(1);
        }

        if (argv[3][0] == 'x')
            arg_tryg = 1;
        else
        {
            int k = 0;
            while (argv[3][k++] != 'x')
                ;

            k--;
            strncpy(buf, argv[3], k);
            arg_tryg = atof(buf);
        }

        i = 4;
    }
    else
    {
        fprintf(stderr, "Incorrect type of function!");
        exit(EXIT_FAILURE);
    }

    double FromX = atof(argv[i + 1]); //poczatek przedizialu
    double ToX = atof(argv[i + 3]);   //koniec przedzialu
    int n = atoi(argv[i + 5]);        //liczba argumentow do obliczenia
    char *output = argv[i + 7];       //nazwa pliku wyjsciowego

    //wypisanie instrukcji programu
    printf("\nYou are running program with following argument:\n");

    if (type_function == 'w')
        printFunctionForm_Polymain(Factors, Function_degree - 1, type_function);
    else if (type_function == 't')
        printFunctionForm_trygonometric(type_function, argv[2], arg_tryg);

    printf("\n-f -> FromX = %g\n-t -> ToX = %g\n-n -> n = %d\n-o -> Solution will be saved in \"%s\" output file\n",
           FromX, ToX, n, output);

    Point *points = (Point *)malloc(sizeof(Point) * (n)); //miejsce na argumenty i wartosci
    double epsilon = (ToX - FromX) / (n - 1);             //przyrost argumentow

    //przyporzatkowanie argumentow
    for (int i = 0; i < n; i++)
        (points + i)->x = FromX + i * epsilon;

    //przyporzatkowanie wartosci od danych argumentow (f. wielomianowa)
    if (type_function == 'w')
        points = Solution_polymain(Factors, Function_degree, n, points);

    //przyporzatkowanie wartosci od danych argumentow (f. trygonometryczna)
    else if (type_function == 't')
        points = Solution_trygonometric(points, n, type_tryg_function, arg_tryg);

    //wypisanie od pliku odpowiedzi
    Write_solution_to_file(output, points, n);

    printf("\n\nThe progarm exit normally - SUCCES\n");
    return 0;
}