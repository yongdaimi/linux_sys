


int main()
{
	int listenfd;
	struct sockaddr_in servaddr;	


	listenfd = socket(AF_INET, SOCK_STREAM, 0);	
	if (listenfd < 0) {
		perror("socket");
		exit(0);
	}	

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family

	return 0;
}
