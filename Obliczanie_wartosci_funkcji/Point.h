#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Polymain.h"

typedef struct PKT
{
    double x;
    double y;
} Point;

void Write_solution_to_file(char *, Point *, int);

#endif