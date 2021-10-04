#include <stdio.h>
#include "vector/vector.h"

int main(int argc, char const **argv)
{
    vector(x, char *);
    for (SIZE_T i = 1; i < (SIZE_T)argc; i++)
        vector_add(x, (char *)argv[i]);
    for (SIZE_T i = 0; i < x.length; i++)
        printf("'%s'\n", vector_get(x, i));
    vector_destructor(x);
    return 0;
}