#include "../array/array.hh"
#include <iostream>

int main()
{
    openutils::array_t<int, 6> a1 = {1, -43, -2, 100, 14, 0};
    a1.sort([](auto x, auto y)
            { return x < y; });
    for (auto i : a1)
        std::cout << i << "\n";
    return 0;
}