#include <stdio.h>
#include "top.h"
#include "bottom.h"
#include "left.h"
#include "right.h"


int main()
{	
	printf("This is MAIN sub\n");
	top();
	bottom();
	left();
	right();

	printf("===========================\n");
	printf("var_left = %d\n", var_left);
	printf("var_right = %d\n", var_right);
	printf("var_top = %d\n", var_top);
	printf("var_bottom = %d\n", var_bottom);
	return 0;

	
}
