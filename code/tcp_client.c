#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define SERV_PORT 49128
#define MAXLINE 80

int main(int argc, char *argv[])
{
	
	int sockfd, n;
	struct sockaddr_in servaddr;
	char *str;
	char buf[MAXLINE];

	if (argc != 2) {
		fputs("usage: ./client message\n", stderr);
		exit(1);
	}
	str = argv[1];

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(1);
	}
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);	
	
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	
	write(sockfd, str, strlen(str));
	n = read(sockfd, buf, MAXLINE);
	printf("Response from server:\n");
	write(STDOUT_FILENO, buf, n);
	close(sockfd);
	return 0;
}
