#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERV_PORT 8000
#define MAX_LINE 80

int main(int argc, char *argv[])
{	
	int sockfd;
	int n;
	struct sockaddr_in servaddr;
	char buf[MAX_LINE];	
	char *str;	

	if (argc != 2) {
		fputs("usage: ./client message\n", stderr);
		exit(1);
	}
	
	str = argv[1];
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);

	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	write(sockfd, str, strlen(str));
	
	n = read(sockfd, buf, MAX_LINE);
	printf("Response from server: \n");
	write(STDOUT_FILENO, buf, n);
	printf("\n");
	close(sockfd);
	return 0;
}
