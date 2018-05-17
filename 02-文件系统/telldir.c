#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>



static void printFileType(int fileType)
{
	printf("current fileType is: %d\n", fileType);
	switch (fileType) {
		case DT_BLK:	printf("File-type: block device\n");	break;
		case DT_CHR:	printf("File-type: character device\n");break;
		case DT_DIR:	printf("File-type: directory\n");	break;
		case DT_FIFO:	printf("File-type: FIFO/pipe\n");	break;
		case DT_LNK: 	printf("File-type: symlink\n");		break;
		case DT_REG: 	printf("File-type: regular file\n");	break;
		case DT_SOCK:	printf("File-type: socket\n");		break;
		default:	printf("File-type: unknow?\n");		break;
	}
	
}


int main()
{
	
	const char *filePath = "ndk";
	DIR *directory = opendir(filePath);	
	struct dirent *p;	
	
	while ((p = readdir(directory)) != NULL) {
		char *name = p->d_name;		
		if ((strcmp(name, ".") == 0) || (strcmp(name, "..") == 0)) continue;		
		printf("File-ino: %ld\n", p->d_ino);
		printf("File-off: %ld\n", p->d_off);
		printf("File-reclen: %u\n", p->d_reclen);
		printFileType(p->d_type);
		printf("File-name: %s\n", name);

		printf("current DIR Point location at: %ld\n", telldir(directory));
		printf("------------------------------------------\n");
	}
	closedir(directory);		
	return 0;
}
