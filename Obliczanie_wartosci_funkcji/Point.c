#include "Point.h"

void Write_solution_to_file(char *file_name, Point *tab, int n)
{
    FILE *out = fopen(file_name, "w");
    if (!out)
    {
        fprintf(stderr, "Cannot open a file to save solution!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
        fprintf(out, "%g %g\n", (tab + i)->x, (tab + i)->y);
}
