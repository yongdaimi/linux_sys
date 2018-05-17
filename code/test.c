#include <stdio.h>


int func()
{
	static int n = 0;
	n++;
	printf("function is called %d times.\n", n);
	return n;
}

int main()
{
	int i, n = 0;
	for (i = 1; i<=5; i++) {
		func();
	}
	printf("n=%d\n", n);
	return 0;
}

