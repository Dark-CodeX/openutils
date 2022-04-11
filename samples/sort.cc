#include "../vector/vector.hh"
#include <iostream>
#include <cassert>

int main(void)
{
    openutils::vector_t<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    openutils::vector_t<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (openutils::vector_t<int>::iter i = vec.iterator(); i.c_loop(); i.next())
        std::cout << (*i) << " ";
    vec.sort();
    std::cout << std::endl;
    for (openutils::vector_t<int>::iter i = vec.iterator(); i.c_loop(); i.next())
        std::cout << (*i) << " ";
    std::cout << std::endl;
    assert(vec == vec2);
    return EXIT_SUCCESS;
}