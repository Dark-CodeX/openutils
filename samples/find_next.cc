#include <iostream>
#include "../sstring/sstring.hh"

int main()
{
    using namespace openutils;
    sstring testString("Fear leads to anger; anger leads to hatred; hatred leads to conflict; conflict leads to suffering."); // -Master Yoda, in Star Wars Episode I: The Phantom Menace

    std::size_t i = testString.find("leads");
    while(true)
    {
        std::cout << "FOUND \"leads\" at: " << i << ", i.e., `" << testString.c_str() + i << "`" << "\n";
        i = testString.find_next(i + 1, "leads");
        if(i == testString.nerr) break;
    }

    return 0;
}
