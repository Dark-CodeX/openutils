#include "map/map.hh"
#include <iostream>
#include <sstring/sstring.hh>

int main(int argc, char const** argv)
{
    using namespace sstr;
    map_t<sstring, int> map;
    for (std::size_t i = 1; i < argc; ++i)
        map.add(argv[i], i);
    for (map_t<sstring, int>::iter i = map.iterator(); i.c_loop(); i.next())
        std::cout << i->key << " " << i->value << std::endl;
    std::cout << "Length = " << map.length() << std::endl;
    std::cout << "Capacity = " << map.capacity() << std::endl;
    std::cout << "Error Rate = " << map.error_rate(argc - 1) << "%" << std::endl;
    return 0;
}