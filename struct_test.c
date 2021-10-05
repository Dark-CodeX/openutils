#include <sstring/sstring.h>
#include "vector/vector.h"

int main(int argc, char const **argv)
{
    sstring str[argc];
    vector(vec, sstring);
    for (SIZE_T i = 0; i < (SIZE_T)argc; i++)
        init_sstr(&str[i]);

    for (SIZE_T i = 0; i < (SIZE_T)argc; i++)
        vector_add(vec, str[i]);

    for (SIZE_T i = 0; i < (SIZE_T)argc; i++)
    {
        vec.src[i].set(&vec.src[i], argv[i]);
        vec.src[i].print(&vec.src[i], true, "\t\tLength = %llu, Entropy = %Lf", vec.src[i].length(&vec.src[i]), vec.src[i].entropy(&vec.src[i]));
    }
    for (SIZE_T i = 0; i < (SIZE_T)argc; i++)
        vec.src[i].destructor(&vec.src[i]);
    vector_destructor(vec);
    return 0;
}