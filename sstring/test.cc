#include "sstring.hh"
#include <iostream>
#include <string>

using namespace sstr;

int main(void)
{
    sstring x = to_sstring(42);
    x.open("sstring/sstring.h");
    split_t s = x.split("\n");
    for (std::size_t i = 0; i < s.length(); i++)
        std::cout << '`' << s[i] << '`' << std::endl;
    return 0;
}