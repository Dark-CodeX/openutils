#include "../vector/vector.hh"
#include <iostream>

int main(void)
{
    vector_t<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (vector_t<int>::iter i = v.iterator(); i.c_loop(); i.next())
        std::cout << *i << std::endl;
    return 0;
}