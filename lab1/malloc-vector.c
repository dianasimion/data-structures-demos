#include "stdlib.h"
#include "utils.h"
#include <stdio.h>

int main()
{
	int *a;

	// there are more ways of setting the size of the memory "boxes" of the
	// malloced memory

	// a = malloc(5 * sizeof(int));
	a = malloc(5 * sizeof(*a));	   // this is more generic
	DIE(a == NULL, "malloc a failed"); // always check if the malloc failed

	// print addres of a
	printf("address of a: %p\n", &a);
	// print the content a (= the starting address of the malloced memory)
	printf("address of a: %p\n", a);

	// populate
	for (int i = 0; i < 5; i++) {
		a[i] = i * 100;
	}

	// print addresses of the elements
	for (int i = 0; i < 5; i++) {
		printf("address of a[%d]: %p\n", i, a + i);
		printf("address of a[%d]: %p\n\n", i, &a[i]);
	}

	// print the values of the elements
	for (int i = 0; i < 5; i++) {
		printf("value of a[%d]: %d\n", i, a[i]);
		printf("value of a[%d]: %d\n\n", i, *(a + i));
	}

	free(a);

	return 0;
}
