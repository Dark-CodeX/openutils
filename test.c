#include <stdio.h>
#include "vector/vector.h"

int main(int argc, char const **argv)
{
    VECTOR(v);
    for (SIZE_T i = 1; i < (SIZE_T)argc; i++)
        v.append(&v, (void *)argv[i]);
    for (SIZE_T i = 0; i < v.length(&v); i++)
        printf("v[%llu] = %s\n", i, (const char *)v.get(&v, i));
    printf("Length = %llu\n", v.length(&v));
    v.destructor(&v);
    return 0;
}