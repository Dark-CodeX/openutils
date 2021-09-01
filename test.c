#include "sstring/sstring.h"

#pragma GCC optimize("O2")

int main(int argc, char const *argv[])
{
    sstring a;
    init_str(&a); // we need to pass it's refernce as it accepts only pointers to our string { aka __string__ }
    a.set_array(&a, argv, ' ', 1, argc, argc);
    printf("Entropy = %Lf\n", a.entropy(&a));
    a.print(&a, true, "");
    a.destructor(&a);
    return 0;
}
