#include "../sstring/sstring.h"

int main(int argc, char const **argv)
{
    SSTRING(a);
    a.set_array(&a, argv, ' ', 1, argc, argc);
    a.print(&a, true, "\nEntropy = %f\nLength = %zu\nHash = %zu", a.entropy(&a), a.end(&a), a.hash(&a));
    a.destructor(&a);
    return 0;
}
