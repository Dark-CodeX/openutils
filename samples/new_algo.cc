#include <iostream>
#include "../sstring/sstring.hh"

int main()
{
	using namespace openutils;
	sstring testString("Fear leads to anger; anger leads to hatred; hatred leads to conflict; conflict leads to suffering."); // -Master Yoda, in Star Wars Episode I: The Phantom Menace

	std::cout << "FIND_NEXT:\n";

	std::size_t i = testString.find("leads");
	while (true)
	{
		std::cout << "FOUND \"leads\" at: " << i << ", i.e., `" << testString.c_str() + i << "`\n";
		i = testString.find_next(i + 1, "leads");
		if (i == testString.nerr())
			break;
	}

	std::cout << "\n\n";

	std::cout << "REPLACE:\nBEFORE: `" << testString << "`\n";
	std::cout << sstring::to_sstring(testString.replace("leads", "puls from").compare("Fear puls from to anger; anger puls from to hatred; hatred puls from to conflict; conflict puls from to suffering.")) << "\n";
	std::cout << "AFTER: `" << testString << "`\n\n\n";

	std::cout << "REMOVE:\nBEFORE: `" << testString << "`\n";
	std::cout << sstring::to_sstring(testString.remove("puls from").compare("Fear  to anger; anger  to hatred; hatred  to conflict; conflict  to suffering.")) << "\n";
	std::cout << "AFTER: `" << testString << "`\n";

	return 0;
}
