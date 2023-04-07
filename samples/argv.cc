#include "../sstring/sstring.hh"
#include <iostream>

int main()
{
    using namespace openutils;
    sstring x = "--add -desc \"Complete sstring library\" -date 7/4/2023 --log";
    vector_t<sstring> args = x.to_argv();
    std::cout << "argc = " << args.length() << "\n";
    for (std::size_t i = 0; i < args.length(); i++)
        std::cout << "argv[" << i << "]: `" << args[i] << "`\n";
    return 0;
}