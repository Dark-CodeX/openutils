#include <stdio.h>
#include "vector/vector.h"

int main(int argc, char const **argv)
{
    vector(x, char *);
    for (size_t i = 1; i < (size_t)argc; i++)
        vector_add(x, (char *)argv[i]);
    for (size_t i = 0; i < x.length; i++)
        printf("'%s'\n", vector_get(x, i));
    vector_destructor(x);
    return 0;
}