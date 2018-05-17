#include <sys/stat.h>


int main()
{
	
	chmod("empty.txt", S_IRUSR | S_IWUSR | S_IXUSR);
	return 0;
}
