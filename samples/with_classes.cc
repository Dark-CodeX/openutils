#include "../heap-pair/heap-pair.hh"
#include <openutils/sstring/sstring.hh>
#include <iostream>

int main()
{
	using namespace openutils;

	heap_pair<sstring, sstring> name("Tushar", "Chaurasia");
	std::cout << "First name = `" << name.first() << "`\n";
	std::cout << "Last name = `" << name.second() << "`\n";
	return 0;
}