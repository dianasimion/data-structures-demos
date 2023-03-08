#include <stdio.h>

int main()
{
	// size --> depends on the arhitecture
	// all pointers have the same size
	printf("sizeof(char):\t %ld\n", sizeof(char));
	printf("sizeof(int):\t %ld\n", sizeof(int));
	printf("sizeof(float):\t %ld\n", sizeof(float));
	printf("sizeof(int*):\t %ld\n", sizeof(int *));
	printf("sizeof(iny**):\t %ld\n", sizeof(int **));
	printf("sizeof(int***):\t %ld\n", sizeof(int ***));
	printf("sizeof(void*):\t %ld\n\n", sizeof(void *));

	// pointer example
	int y = 10;
	int *x = &y;

	// change the value of b
	*x = 3;

	// print addresses and values
	printf("&x\t %p (address of x)\n", &x);
	printf("&y\t %p (address of y)\n", &y);
	printf("x\t %p (content of x)\n", x);
	printf("*x\t %d (value at the address contained by x)\n\n", *x);

	// double pointer example
	int c = 2;
	int *b = &c;
	int **a = &b;

	printf("&a:\t %p\n\n", &a);
	printf("a:\t %p\n", a);
	printf("&b:\t %p\n\n", &b);

	printf("*a:\t %p\n", *a);
	printf("b:\t %p\n", b);
	printf("&c:\t %p\n\n", &c);

	printf("**a:\t %d\n", **a);
	printf("*b:\t %d\n", *b);
	printf("c:\t %d\n", c);

	return 0;
}
