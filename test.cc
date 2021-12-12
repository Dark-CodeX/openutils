#include "map/map.hh"
#include <iostream>
#include <openutils/sstring/sstring.hh>

int main(int argc, char const **argv)
{
    using namespace sstr;
    map_t<sstring, int> map;
    for (std::size_t i = 1; i < (std::size_t)argc; ++i)
        map.add(argv[i], i);
    for (map_t<sstring, int>::iter i = map.iterator(); i.c_loop() != false; i.next())
        std::cout << i->key << " " << i->value << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Length = " << map.length() << std::endl;
    std::cout << "Capacity = " << map.capacity() << std::endl;
    std::cout << "Max Depth = " << map.max_depth() << std::endl;
    std::cout << "HASH = " << std::hash<map_t<sstring, int>>()(map) << std::endl;
    std::cout << "Error Rate = " << map.error_rate(argc - 1) << "%" << std::endl;
    return 0;
}
