#include "../sstring/sstring.h"
#include <openutils/vector/vector.h>

int main(void)
{
	SSTRING(x);
	x.open(&x, "/home/tushar/Desktop/m.txt");
	split_t data = x.split(&x, "\n");
	vector(vec, long double);

	SSTRING(input);
	printf("ENTER:\n");
	input.in(&input);

	for (size_t i = 0; i < data.len; i++)
		vector_add(vec, input.percentage_matched(&input, data.data[i]));

	long double __d = 0;
	size_t index = 0;
	for (size_t i = 0; i < vec.length; i++)
	{
		if (__d < vec.src[i])
		{
			__d = vec.src[i];
			index = i;
		}
	}
	printf("Best Match:\n%s\nAt:%zu\n", data.data[index], index);
	free_split(&data);
	vector_destructor(vec);
	input.destructor(&input);
	x.destructor(&x);
	return 0;
}