#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <string.h>
#include <arpa/inet.h>

int ids[8000];
char* buffer_client[8000];
fd_set actual_fds, write_fds, read_fds;
int max_fd;

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}
void    send_message(int author, char* msg)
{
    for(int fd = 3; fd <= max_fd; fd++)
    {
        if (FD_ISSET(fd, &write_fds) && fd != author)
            send(fd, msg, strlen(msg), 0);
    }
}
void    handle_message(int fd, char** buffer)
{
    char* msg = NULL;
    char* mess;
    while (extract_message(buffer, &msg))
    {
        mess = malloc(sizeof(char) * (strlen(msg) +32));
        sprintf(mess, "client: %d: %s", ids[fd], msg);
        send_message(fd, mess);
        free(mess);
        free(msg);
        msg = NULL;
    }
}
int main(int ac, char** av) 
{
	
    if (ac != 2)
    {
        write(2, "Wrong number of arguments", strlen("Wrong number of arguments"));
        return (1);
    }
    
    int count = 0;
    int sockfd, connfd;
	struct sockaddr_in servaddr; 
    socklen_t len;
    char msg[1024];

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully binded..\n");
	if (listen(sockfd, 10) != 0) {
		printf("cannot listen\n"); 
		exit(0); 
	}


    max_fd = sockfd;
    FD_ZERO(&actual_fds);
    FD_SET(sockfd, &actual_fds);
    while (1)
    {
        read_fds = write_fds = actual_fds;
        if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) < 0)
            continue ;
        for (int fd = 3; fd <= max_fd; fd++)
        {
           if (FD_ISSET(fd, &read_fds))
           {
                if (fd == sockfd)
                {
                    connfd = accept(sockfd, (struct sockaddr *)&servaddr, &len);
                    if (connfd < 0) 
                        continue;
                    ids[connfd] = count++;
                    buffer_client[connfd] = NULL;
                    sprintf(msg, "server: client %d just arrived\n", ids[connfd]);
                    send_message(connfd, msg);
                    FD_SET(connfd, &actual_fds);
                    if (max_fd < connfd)
                        max_fd = connfd;
                }
                else
                {
                    char buffer[4097];
                    int bytes = recv(fd, buffer, 4096, 0);
                    if (bytes <= 0)
                    {
                        sprintf(msg, "server: client %d just left\n", ids[fd]);
                        send_message(fd, msg);
                        free(buffer_client[fd]);
                        buffer_client[fd] = NULL;
                        FD_CLR(fd, &actual_fds);
                        close(fd);
                    }
                    else
                    {
                        buffer[bytes] = '\0';
                        buffer_client[fd] = str_join(buffer_client[fd], buffer);
                        if (strstr(buffer_client[fd], "\n") == NULL)
                            continue ;
                        handle_message(fd, &buffer_client[fd]);
                    }
                }
           }
        }
         
    }
	
}