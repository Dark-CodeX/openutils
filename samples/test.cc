#include "../optional/optional.hh"
#include <openutils/sstring/sstring.hh>
#include <iostream>

openutils::optional_t<openutils::sstring> test(const openutils::sstring &input)
{
	if (input.length() != 0)
		return input.soundex();
	return openutils::optnull;
}

int main()
{
	openutils::optional_t<openutils::sstring> y = test(openutils::sstring::get_input());
	if (y)
		std::cout << y.get() << std::endl;
	else
	{
		std::cerr << "err: value was (null)" << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
