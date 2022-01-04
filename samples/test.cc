#include "returns/optional.hh"
#include "returns/default.hh"
#include <openutils/sstring/sstring.hh>
#include <iostream>

openutils::optional_t<openutils::sstring> test(openutils::sstring x)
{
    if (x.end() != 0)
        return x.soundex();
    return openutils::optnull;
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
    openutils::sstring &x = openutils::default_t();
    int &z = openutils::default_t();
    std::cout << "Default value of sstring = `" << x << "`, with length = " << x.end() << std::endl;
    std::cout << "Default value of int = " << z << std::endl;
    return 0;
}