#include "../vector/vector.hh"
#include <iostream>

int main()
{
    openutils::vector_t<int> vec = {5, 11, 24, -21, -2, 1};
    vec.sort([](auto t1, auto t2)
             { return t1 < t2; });
    for (int i : vec)
        std::cout << i << "\n";
    return EXIT_SUCCESS;
}