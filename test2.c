#include "sstring/sstring.h"

int main(int argc, char const *argv[])
{
    SSTRING(x);
    SSTRING(y);
    x.open(&x, "/home/tushar/Desktop/m.txt");
    SIZE_T cnt = x.count_char(&x, '\n');
    long double plots[cnt];

    printf("Enter:\t");
    y.in(&y, false, 512);
    printf("\"%s\"", y.c_str(&y));
    char *r;
    for (SIZE_T i = 0; i < cnt; i++)
    {
        r = x.getline(&x, i);
        plots[i] = y.percentage_matched(&y, (const char *)r);
        free(r);
    }
    long double l = plots[0];
    SIZE_T z = 0;
    for (SIZE_T p = 1; p < cnt; p++) // get largest percentage in `plots`
    {
        if (l < plots[p])
        {
            l = plots[p];
            z = p;
        }
    }
    printf("Best Matched: %s\nAt: %lld\n", x.getline(&x, z), z);
    x.destructor(&x);
    y.destructor(&y);
    return 0;
}