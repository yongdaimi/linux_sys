#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>


#define SOCK_PORT 49128
#define MAXLINE 80

int main()
{
	int sockfd, connfd;	
	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddr_len;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	int i, n;	

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(1);
	}
	
	/*Construct sockaddr_in struct*/
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SOCK_PORT);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("connect");
		exit(1);
	}

	if (listen(sockfd, 128) < 0) {
		perror("listen");
		exit(1);
	}
	
	while (1) {
		cliaddr_len = sizeof(cliaddr);
		connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
		n = read(connfd, buf, MAXLINE);
		printf("received from %s at PORT %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
			ntohs(cliaddr.sin_port));
		for (i = 0; i < n; i++)
			buf[i] = toupper(buf[i]);
		write(connfd, buf, n);
		close(connfd);
	}
	
	close(sockfd);
	return 0;
}



