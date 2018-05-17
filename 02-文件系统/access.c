#include <unistd.h>
#include <stdio.h>

int main()
{
	
	if (access("test.txt", F_OK|X_OK) < 0) {
		printf("FILE Not Exists or No Execute permission\n");
	} else {
		printf("FILE Exists\n");
	}
	
	return 0;
}
