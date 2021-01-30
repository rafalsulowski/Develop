#include "Tryg.h"

void printFunctionForm_trygonometric(char type, char *name, int arg)
{
    printf("-%c -> Trygonometric function\nFunction form: ", type);
    printf("%s ( %dx )", name, arg);
}

Point *Solution_trygonometric(Point *tab, int n, int type, double arg)
{
    switch (type)
    {
    case 1:
    {
        for (int i = 0; i < n; i++)
        {
            (tab + i)->y = sin((tab + i)->x * arg);
            //printf("Dla arg = %g\t(tab + %d) -> y = %g\n", (tab + i)->x, i, (tab + i)->y);
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < n; i++)
        {
            (tab + i)->y = cos((tab + i)->x * arg);
            //printf("Dla arg = %g\t(tab + %d) -> y = %g\n", (tab + i)->x, i, (tab + i)->y);
        }
        break;
    }
    case 3:
    {
        for (int i = 0; i < n; i++)
        {
            (tab + i)->y = tan((tab + i)->x * arg);
            //printf("Dla arg = %g\t(tab + %d) -> y = %g\n", (tab + i)->x, i, (tab + i)->y);
        }
        break;
    }
    case 4:
    {
        for (int i = 0; i < n; i++)
        {
            (tab + i)->y = 1 / (tan((tab + i)->x * arg));
            //printf("Dla arg = %g\t(tab + %d) -> y = %g\n", (tab + i)->x, i, (tab + i)->y);
        }
        break;
    }
    case 5:
    {
        for (int i = 0; i < n; i++)
        {
            (tab + i)->y = sinh((tab + i)->x * arg);
            //printf("Dla arg = %g\t(tab + %d) -> y = %g\n", (tab + i)->x, i, (tab + i)->y);
        }
        break;
    }
    case 6:
    {
        for (int i = 0; i < n; i++)
        {
            (tab + i)->y = cosh((tab + i)->x * arg);
            //printf("Dla arg = %g\t(tab + %d) -> y = %g\n", (tab + i)->x, i, (tab + i)->y);
        }
        break;
    }
    case 7:
    {
        for (int i = 0; i < n; i++)
        {
            (tab + i)->y = tanh((tab + i)->x * arg);
            //printf("Dla arg = %g\t(tab + %d) -> y = %g\n", (tab + i)->x, i, (tab + i)->y);
        }
        break;
    }
    case 8:
    {
        for (int i = 0; i < n; i++)
        {
            (tab + i)->y = 1 / (tanh((tab + i)->x * arg));
            //printf("Dla arg = %g\t(tab + %d) -> y = %g\n", (tab + i)->x, i, (tab + i)->y);
        }
        break;
    }
    default:
        break;
    }

    return tab;
}
