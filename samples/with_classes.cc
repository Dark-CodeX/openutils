#include "../heap-pair/heap-pair.hh"
#include <openutils/sstring/sstring.hh>
#include <iostream>

int main()
{
	using namespace openutils;

	std::cout << "NAME 1:\n";
	heap_pair<sstring, sstring> name1("Ram", "Krishna"); // // 1st implementation
	std::cout << "    First name = `" << name1.first() << "`\n";
	std::cout << "    Last name = `" << name1.second() << "`\n\n";


	heap_pair<sstring, sstring> name2 = heap_pair<sstring, sstring>::make_heap_pair("Tushar", "Chaurasia"); // 2nd implementation
	std::cout << "NAME 2:\n";
	std::cout << "    First name = `" << name2.first() << "`\n";
	std::cout << "    Last name = `" << name2.second() << "`" << std::endl;
	return 0;
}