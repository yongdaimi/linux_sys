#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>


#define MAXLINE 80
#define SERV_PORT 49130

static const char *SERV_ADDR = "127.0.0.1";

int main()
{
	
	int sockfd;
	char buf[MAXLINE];
	struct sockaddr_in servaddr;
	int n, i;	

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, SERV_ADDR, &servaddr.sin_addr);	
	servaddr.sin_port = htons(SERV_PORT);	

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket");
		exit(1);
	}

	while (fgets(buf, MAXLINE, stdin) != NULL) {
		n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
		if (n == -1) {
			perror("sendto err");
		}
		
		n = recvfrom(sockfd, buf, MAXLINE, 0, NULL, 0);
		if (n == -1) {
			perror("recvfrom err");
		}
		
		//printf("recv len is: %d\n", n);
		write(STDOUT_FILENO, buf, n);
	}

	close(sockfd);
	return 0;
}
