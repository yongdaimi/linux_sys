#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <string.h>

#define SERV_PORT 49130
#define MAXLINE 80


int main()
{
	int sockfd;
	struct sockaddr_in servaddr, cliaddr;	
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	int cliaddr_len;
	int n, i;	

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket");
		exit(1);		
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	
	if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("bind");
		exit(1);
	}

	printf("Accepting connections...\n");

	while (1) {
		cliaddr_len = sizeof(cliaddr);
		n = recvfrom(sockfd, buf, MAXLINE, 0, (struct sockaddr *)&cliaddr, &cliaddr_len);
		if (n == -1) {
			perror("recvfrom err");
		}
		// print source address's ip,port
		printf("Received from %s at PORT %d, recvlen is: %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), ntohs(cliaddr.sin_port), n);

		for (i = 0; i < n; i++)
			buf[i] = toupper(buf[i]);	
		n = sendto(sockfd, buf, n, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
		// printf("send length is: %d\n", n);
		if (n == -1) {
			perror("sendto err");
		}
	}

	close(sockfd);
	return 0;
}
