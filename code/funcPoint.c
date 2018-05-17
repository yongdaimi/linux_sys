#include <stdio.h>


int max(int a, int b)
{
	return a>b?a:b;
}


int main()
{
	int x, y, maxval;
	int (*pmax)(int , int) = max;
	printf("Input two numbers: \n");
	scanf("%d %d", &x, &y);
	maxval = (*pmax)(x, y);
	printf("Max value is: %d\n", maxval);
	return 0;
}
