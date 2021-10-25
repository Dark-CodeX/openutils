#include "../sstring/sstring.h"

int main(int argc, char const **argv)
{
    SSTRING(a);
    a.set_array(&a, argv, ' ', 1, argc, argc);
    a.print(&a, true, "\nEntropy = %Lf\nLength = %llu\nPositional Average = %Lf\nPositional Modulus = %llu\n", a.entropy(&a), a.end(&a), a.positional_average(&a), a.positional_modulus(&a));
    a.destructor(&a);
    return 0;
}
