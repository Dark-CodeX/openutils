#include <openutils/sstring/sstring.h>
#include "../vector/vector.h"

int main(int argc, char const **argv)
{
	vector(vec, sstring);
	for (size_t i = 0; i < (size_t)argc; i++)
	{
		vector_add(vec, new_sstring(1, NULL));
		vec.src[i].set(&vec.src[i], argv[i]);
		vec.src[i].print(&vec.src[i], true, "\t\tLength = %llu, Entropy = %Lf", vec.src[i].length(&vec.src[i]), vec.src[i].entropy(&vec.src[i]));
		vec.src[i].destructor(&vec.src[i]);
		
	}
	vector_destructor(vec);
	return 0;
}