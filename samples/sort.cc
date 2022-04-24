#include "../map/map.hh"
#include <openutils/sstring/sstring.hh>
#include <iostream>

int main(void)
{
	using namespace openutils;
	map_t<sstring, int> x = {{"Tushar", 2}, {"Chaurasia", 3}, {"Hello", 1}, {"Bye", 123}, {"TATA", 13}};
	for (map_t<sstring, int>::iter i = x.iterator(); i.c_loop(); i.next())
		std::cout << i->key << " :: " << i->value << "\n";

	std::cout << std::endl;

   x.sort_values([](node_t<sstring, int> a, node_t<sstring, int> b)
				 { return a.value < b.value; });

	for (map_t<sstring, int>::iter i = x.iterator(); i.c_loop(); i.next())
		std::cout << i->key << "  :: " << i->value << "\n";
	return EXIT_SUCCESS;
}