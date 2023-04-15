#include "../sstring/sstring.hh"
#include <cassert>
#include <iostream>

int main()
{
    using namespace openutils;
    sstring x = "tushar tushar tushar";
    x.rfind("tushar");
    return 0;
}
