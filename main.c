#include "string/string.h"

#pragma GCC optimize("O2")

int main(int argc, char const *argv[])
{
    string a;
    init_str(&a); // we need to pass it's refernce as it accepts only pointers to our string { aka __string__ }

    a.set(&a, "Hello");

    a.print(&a, true);

    // Do not free 'a' because it is not stored in heap memory and it is not a pointer.
    // It is freed automatically when `int main(int argc, char const *argv[])` returns 0;
    return 0;
}