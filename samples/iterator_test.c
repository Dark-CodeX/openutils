#include "../sstring/sstring.h"

int main(int argc, char const **argv)
{
    sstring x = new_sstring(0, NULL);
    x.set_array(&x, argv, ' ', 0, argc, argc);
    printf("TOP_TO_BOTTOM:\n");
    for (iter_sstring i = x.iterator(x.begin(), x.end(&x)); i.c_loop(&i) != false; i.advance(&i, +1))
        printf("%c", x.char_get(&x, i.cur));
    printf("\n");
    printf("BOTTOM_TO_TOP\n");
    for (iter_sstring i = x.iterator(x.end(&x), x.begin()); i.c_loop(&i) != false; i.advance(&i, -1))
        printf("%c", x.char_get(&x, i.cur));
    printf("\n");
    x.destructor(&x);
    return 0;
}