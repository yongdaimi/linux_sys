#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERV_PORT 8000
#define MAX_LINE 80


int main()
{

	int sockfd;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddr_len;
	int n, i;		
	char buf[MAX_LINE];
	char str[INET_ADDRSTRLEN];
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	
	int ret;	
	ret = bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	printf("current ret is: %d\n", ret);
	printf("Accepting connections...\n");
	
	
	while(1) {
		cliaddr_len = sizeof(cliaddr);
		n = recvfrom(sockfd, buf, MAX_LINE, 0, (struct sockaddr *)&cliaddr, &cliaddr_len);
		if (n < 0) {
			perror("recvfrom error");
			exit(0);
		}
		printf("received from %s at PORT %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), ntohs(cliaddr.sin_port));
		for (i = 0; i < n; i++) {
			buf[i] = toupper(buf[i]);
		}
		n = sendto(sockfd, buf, n, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
		if (n < 0) {
			perror("sendto error");
			exit(1);
		}
	}
	return 0;
}
