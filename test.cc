#include "returns/optional.hh"
#include "returns/default.hh"
#include <openutils/sstring/sstring.hh>
#include <iostream>

optional_t<sstr::sstring> test(sstr::sstring x)
{
    if (x.end() != 0)
        return x.soundex();
    return optnull;
}

int main(void)
{
    auto y = test("Hello");
    if (y)
        std::cout << y.get() << std::endl;
    else
    {
        std::cerr << "value was null" << std::endl;
        return -1;
    }
    sstr::sstring &x = default_t();
    int &z = default_t();
    std::cout << "Default value of sstring = `" << x << "`, with length = " << x.end() << std::endl;
    std::cout << "Default value of int = " << z << std::endl;
    return 0;
}