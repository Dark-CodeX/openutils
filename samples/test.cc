#include "../vector/vector.hh"
#include <iostream>
#include <openutils/sstring/sstring.hh>
#include <cassert>

int main()
{
    using namespace openutils;
    sstring x = "HelloHello";
    vector_t<char> vec(x.begin(), x.begin() + 5);
    for (char i : vec)
        std::cout << i << "\n";
    std::cout << vec.length() << "\n";
    std::cout << vec.capacity() << std::endl;
    return EXIT_SUCCESS;
}