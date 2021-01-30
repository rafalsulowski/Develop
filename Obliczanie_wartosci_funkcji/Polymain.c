#include "Polymain.h"

Point *Solution_polymain(double *Factors, int degree, int n, Point *tab)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < degree; i++)
        {
            (tab + j)->y += *(Factors + i) * pow((tab + j)->x, (degree - i - 1));
        }
        //printf("Dla arg = %g\t(tab + %d) -> y = %g\n", (tab + j)->x, j, (tab + j)->y);
    }

    return tab;
}

void printFunctionForm_Polymain(double *tab, int Function_degree, char type)
{

    printf("-%c -> Polymain function\nFunction form: ", type);

    int k = 0;
    for (int i = Function_degree; i >= 0; i--)
    {
        if (i == 0)
            printf("%+g ", *(tab + k));
        else if (i == Function_degree)
            printf("%gx^%d ", *(tab + k), i);
        else
            printf("%+gx^%d ", *(tab + k), i);

        k++;
    }
}