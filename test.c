#include "sstring/sstring.h"

int main(int argc, char const *argv[])
{
    SSTRING(a);
    a.set_array(&a, argv, ' ', 1, argc, argc);
    a.print(&a, true, "\nEntropy = %Lf\nLength = %llu", a.entropy(&a), a.length(&a));
    a.destructor(&a);
    return 0;
}
