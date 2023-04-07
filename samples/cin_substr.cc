#include "../sstring/sstring.hh"
#include <iostream>

int main(void)
{
	using namespace openutils;
	sstring x;
	x.in();
	std::cout << "`" << x << "`\n\nLEN = " << x.length() << "\n\n";

			//   0123456789
	sstring y = "HelloWorld";
	sstring sub = y.substr(4, 2);
	std::cout << sstring::to_sstring(sub == "oW") << "\n";
	std::cout << "`" << sub << "`\n";

	return 0;
}