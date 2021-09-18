#include "sstring/sstring.h"

int main(int argc, char const **argv)
{
    SSTRING(a);
    a.set_array(&a, argv, ' ', 1, argc, argc);
    char *sdx = a.soundex(&a);
    a.print(&a, true, "\nEntropy = %Lf\nLength = %llu\nSoundex = %s\n", a.entropy(&a), a.length(&a), sdx);
    free(sdx);
    a.destructor(&a);
    return 0;
}
