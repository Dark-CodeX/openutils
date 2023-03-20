#include "../vector/vector.h"
#include <stdio.h>

int compare(const void *ptr1, const void *ptr2)
{
	return (*((int *)ptr1)) > (*((int *)ptr2));
}

int main(void)
{
	vector(vec, int);
	for (int i = 10; i >= 0; i--)
		vector_add(vec, i);
	for (size_t i = 0; i < vector_length(vec); i++)
		printf("%d ", vector_get(vec, i));
	puts("\n");
	vector_sort(vec, compare);
	for (size_t i = 0; i < vector_length(vec); i++)
		printf("%d ", vector_get(vec, i));
	puts("\n");
	vector_destructor(vec);
	return EXIT_SUCCESS;
}