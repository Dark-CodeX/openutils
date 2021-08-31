#include "sstring/sstring.h"

#pragma GCC optimize("O2")

int main(int argc, char const *argv[])
{
    string a;
    init_str(&a); // we need to pass it's refernce as it accepts only pointers to our string { aka __string__ }
    for (size_t i = 1; i < argc; i++)
    {
        a.append(&a, argv[i]);
        if (i < argc - 1)
            a.append(&a, " ");
    };
    printf("Entropy = %Lf\n", a.entropy(&a));
    a.print(&a, true, "");
    a.destructor(&a);
    return 0;
}
