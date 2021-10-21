#include "sstring/sstring.h"

int main(int argc, char const **argv)
{
    sstring x = new_sstring(0, NULL);
    x.set_array(&x, argv, ' ', 0, argc, argc);
    for (iter_sstring i = x.iterator(x.begin(), x.end(&x)); i.c_loop(&i) != false; i.advance(&i, +1))
        printf("%d", x.char_get(&x, i.cur));
    printf("\n");
    x.destructor(&x);
    return 0;
}