#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

void main()
{
    int clnsock_fd;

    char message[1024], buff[1024];
    struct sockaddr_in svraddr;

    socklen_t svraddrlen = sizeof(struct sockaddr_in);

    clnsock_fd = socket(AF_INET, SOCK_DGRAM, 0);

    svraddr.sin_family = AF_INET;

    svraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    svraddr.sin_port = htons(PORT);

    while (1)
    {
        printf("enter  your message for server: ");
        gets(message);

        sendto(clnsock_fd, message, sizeof(message), 0, (struct sockaddr *)&svraddr, svraddrlen);

        if (strcmp(message, "exit") == 0)
            break;

        recvfrom(clnsock_fd, buff, sizeof(buff), MSG_WAITALL, (struct svraddr *)&svraddr, &svraddrlen);

        if (strcmp(buff, "exit") == 0)
            break;
    }
}