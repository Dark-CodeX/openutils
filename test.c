#include "sstring/sstring.h"

int main(int argc, char const *argv[])
{
    sstring a;
    init_sstr(&a); // we need to pass it's refernce as it accepts only pointers to our string { aka __string__ }
    a.set_array(&a, argv, ' ', 1, argc, argc);
    a.print(&a, true, "");
    printf("Entropy = %Lf\n", a.entropy(&a));
    printf("Length = %llu\n", a.length(&a));
    a.destructor(&a);
    return 0;
}
