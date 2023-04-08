#include "../returns/object.hh"
#include <iostream>
#include <openutils/sstring/sstring.hh>

int main()
{
	using namespace openutils;

	object_t x;
	x.set_value(2311);
	std::cout << "value: `" << x.get_value<int>() << "`\n";


		sstring mystr = sstring::open_file("./test.cc");
		x.change_value(mystr);
	std::cout << "value: `" << x.get_value<sstring>() << "`\n";
	return 0;
}