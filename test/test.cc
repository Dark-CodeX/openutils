#include <openutils/sstring/sstring.hh>
#include <iostream>

constexpr static inline bool is_between(double value, double lower_bound, double upper_bound)
{
    return (value >= lower_bound && value <= upper_bound);
}

int main(int argc, const char **argv)
{
    if (argc == 1)
    {
        std::cerr << "err: no password passed" << std::endl;
        return EXIT_FAILURE;
    }
    openutils::sstring x = argv[1];
    double pass_strength = x.password_entropy();
    if (is_between(pass_strength, 0, 28))
        std::cout << "Very Weak Password" << std::endl;
    else if (is_between(pass_strength, 29, 35))
        std::cout << "Weak Password" << std::endl;
    else if (is_between(pass_strength, 36, 59))
        std::cout << "Medium Password" << std::endl;
    else if (is_between(pass_strength, 60, 127))
        std::cout << "Strong Password" << std::endl;
    else
        std::cout << "Very Strong Password" << std::endl;
    return EXIT_SUCCESS;
}