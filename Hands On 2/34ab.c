/*
============================================================================
Name : 34ab.c
Author : Parv Gatecha (MT2024108)
Description : Write a program to communicate between two machines using socket.
Date: 18 Sept, 2024.
============================================================================
*/

/*
    1. socket() -> create an endpoint for the communication
        sockfetfd = socket(AF_INET, SOCK_STREAM, 0);
    2. bind() -> bind a name to a socket
        bindStatus = bind(socketfd, &socketaddr, sizeof(socketfd));
    3. listen() -> listen for connections on a socket
        listenStatus = listen(socketfd, 2); // backlog -> 2
    4. accept() -> accept a connection on a socket
        connectionfd = accept(socketfd, &socketaddr, sizeof(socketaddr), 0);
    5. Start communicating -> `write` to and `read` from connectionfd
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
void main()
{
    int socktd = socket(AF_INET, SOCK_STREAM, 0);
    if (socktd == -1)
    {
        perror("Erroe when creating socket");
        _exit(0);
    }
    printf("Socket created\n");

    // assigning server info
    struct sockaddr_in address;
    address.sin_addr.s_addr = htonl(INADDR_ANY); // host to network short
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    // make connection to the server
    int connectionS = connect(socktd, (struct sockaddr *)&address, sizeof(address));

    if (connectionS == -1)
    {
        perror("Error while establishing Connection\n");
        _exit(0);
    }

    printf("Connection with server established\n");

    char buf[100];
    // read fron server
    read(socktd, buf, 100);
    printf("Data from server: %s\n", buf);

    printf("Write massage for server: \n");
    scanf("%[^\n]", buf);

    write(socktd, buf, sizeof(buf));
    printf("Data sent to server\n");

    // closing socket
    close(socktd);
}

/*
============================================================================
Command line: cc 34ab.c && ./a.out
Output: 
Socket created
Connection with server established
Data from server: 5
Write massage for server: 
5
Data sent to server
============================================================================
*/