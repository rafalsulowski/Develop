
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

long parse_int(const char *number)
{
    char *str = (char *)malloc(sizeof(char) * 12);
    for (int i = 0; i < 12; i++)
        str[i] = '\0';

    char c;
    long quantity = 0;
    char *numbers[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven",
                         "eight", "nine", "?", "eleven", "twelve", "thirteen", "fourteen",
                         "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *dozens[9] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *hun = "hundred";
    char *tho = "thousand";

    long temp = 0, sum = 0;

    int i = 0, k = 0;
    while (true)
    {
        c = number[i++];

        if (isalpha(c))
        {
            str[k] = c;
            k++;
            continue;
        }
        else if (isspace(c) || c == '-' || c == '\0')
        {
            str[k] = '\0';

            if (!strcmp(str, "and"))
            {
                strcpy(str, "");
                k = 0;
                continue;
            }

            if (!strcmp(str, tho)) //1000
            {
                sum = 0;
                quantity += temp * 1000;
                temp = 0;

                strcpy(str, "");
                k = 0;
                continue;
            }

            if (!strcmp(str, hun)) //100
            {
                temp *= 100;
                sum = temp;

                strcpy(str, "");
                k = 0;
                continue;
            }

            for (int j = 0; j < 9; j++) //dozens 10, 20, 30, ...
            {
                if (!strcmp(str, dozens[j]))
                {
                    temp += (j + 1) * 10;
                    break;
                }
            }

            for (int j = 0; j < 20; j++) //number 1-9 and 11-19
            {
                if (!strcmp(str, numbers[j]))
                {
                    temp += j;
                    break;
                }
            }

            strcpy(str, "");
            k = 0;

            if (c == '\0')
                break;
        }
        else
            break;
    }

    quantity += temp;
    return quantity;
}

int main(void)
{
    printf("Sol: %ld", parse_int("thirty-five thousand"));

    return 0;
}