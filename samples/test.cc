#include "../heap-pair/heap-pair.hh"
#include <iostream>

int main()
{
	using namespace openutils;
	heap_pair<char *, int> pair; // for default ctor

	heap_pair<char *, int> pair_2("OPENUTILS", 100);
	std::cout << "Value of FIRST = `" << pair_2.first() << "`\n";
	std::cout << "Value of SECOND = `" << pair_2.second() << "`\n";
	return 0;
}