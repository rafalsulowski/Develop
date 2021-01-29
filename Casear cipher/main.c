#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *movingShift(char *s, int shifts)
{
    int len = (int)strlen(s);
    char *str = (char *)malloc(sizeof(char) * (1 + len));
    strcpy(str, s);

    for (int i = 0; i < len; i++)
        str[i] += (shifts + i);

    return str;
}

char *demovingShift(char *s, int shifts)
{
    int len = (int)strlen(s);
    char *str = (char *)malloc(sizeof(char) * (1 + len));
    strcpy(str, s);

    for (int i = 0; i < len; i++)
    {
        str[i] -= (i + shifts);
    }

    return str;
}

int main(void)
{
    char *u = "Ala ma 2 koty i 3 psy!";
    printf("%s\n", u);

    char *v = movingShift(u, 1);
    printf("%s\n", v);

    v = demovingShift(v, 1);
    printf("%s", v);

    return 0;
}