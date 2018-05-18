#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define SERV_PORT 8000
#define MAX_LINE 80

int main()
{
	int sockfd;
	struct sockaddr_in servaddr;
	char buf[MAX_LINE];
	int n;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);	
	
	while(fgets(buf, MAX_LINE, stdin) != NULL) {
		n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
		if (n < 0) {
			perror("sendto");
			exit(1);
		}
		n = recvfrom(sockfd, buf, MAX_LINE, 0, NULL, 0);
		if (n < 0) {
			perror("recvfrom");
			exit(2);
		}
		write(STDOUT_FILENO, buf, n);
	}
	close(sockfd);
	return 0;
}
