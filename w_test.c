#include "sstring/w_sstring.h"

#pragma GCC optimize("O2")

int main(int argc, char const *argv[])
{
    w_sstring a;
    init_w_sstr(&a); // we need to pass it's refernce as it accepts only pointers to our string { aka __string__ }
    srand((unsigned int)(time(NULL) * getpid() * getpid() + getpid()));
    a.set_random(&a, 100);
    a.print(&a, true, "");
    a.to_binary(&a);
    a.print(&a, true, "");
    a.from_binary(&a);
    a.print(&a, true, "");
    printf("Entropy = %Lf\n", a.entropy(&a));
    printf("Length = %lu\n", a.length(&a));
    a.destructor(&a);
    return 0;
}
