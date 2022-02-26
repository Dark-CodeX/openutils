#include "../vector/vector.hh"
#include <iostream>

int main(void)
{
    openutils::vector_t<openutils::vector_t<const char *>> v, v2;
    v.add({"a", "b", "c"});
    v.add({"d", "e", "f"});
    v.add({"g", "h", "i"});
    for (auto x = v.iterator(); x.c_loop(); x.next())
    {
        std::cout << "[";
        for (auto y = (*x).iterator(); y.c_loop(); y.next())
            std::cout << *y << (y.is_last() ? ", " : "]");
        std::cout << std::endl;
    }
    return 0;
}