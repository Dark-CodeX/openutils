#include "../sstring/sstring.hh"
#include <iostream>

int main(void)
{
    using namespace openutils;

    sstring x = "Hello, World";

    std::cout << "BEFORE:\n";
    for (auto i : x)
        std::cout << i;
    std::cout << "\n";

    std::cout << "AFTER:\n";
    for (auto &i : x)
        i = 'T';

    std::cout << x << "\n";

    return 0;
}