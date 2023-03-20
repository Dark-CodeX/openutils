#include "../array/array.hh"
#include <openutils/sstring/sstring.hh>
#include <iostream>

int main(void)
{
    openutils::array_t<openutils::sstring, 5> arr;
    arr.add(openutils::sstring::get_random(5));
    arr.add(openutils::sstring::get_random(5));
    arr.add(openutils::sstring::get_random(5));
    arr.add(openutils::sstring::get_random(5));
    arr.add(openutils::sstring::get_random(5));
    for (int i = 0; i < arr.length(); i++)
        std::cout << arr[i] << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    arr.sort([](auto a, auto b)
             { return a < b; });
    for (int i = 0; i < arr.length(); i++)
        std::cout
            << arr[i] << std::endl;
}