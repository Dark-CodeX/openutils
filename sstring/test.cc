#include "sstring.hh"
#include <iostream>

using namespace sstr;

int main(void)
{
    sstring x;
    x.open("sstring/sstring.h");
    split_t s;
    s = x.split("\n");
    for (std::size_t i = 0; i < s.length(); i++)
        std::cout << '`' << s[i] << '`' << std::endl;
    return 0;
}