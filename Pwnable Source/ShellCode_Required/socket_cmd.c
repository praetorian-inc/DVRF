#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Pwnable Socket Program
// By b1ack0wl
// Stack Overflow
 
int main(int argc, char **argv[])
{
if (argc <2){

printf("Usage: %s port_number - by b1ack0wl\n", argv[0]);
exit(1);

}
 
    char str[200] = "\0";
    char endstr[100] = "\0";
    int listen_fd, comm_fd;
    int retval = 0;
 
    struct sockaddr_in servaddr;
 
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
 
    bzero( &servaddr, sizeof(servaddr));
 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));
	printf("Binding to port %d\n", atoi(argv[1]));
 
    retval = bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if (retval == -1){
	printf("Error Binding to port %d\n", atoi(argv[1]) );
	 exit(1);}


    listen(listen_fd, 2);
 
    comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
 
    while(1)
    {
 
        bzero(str, 200);
	write(comm_fd, "Send me a string:",17);
        read(comm_fd,str,200);
	if (!strcasecmp(str, "exit")){
	write(comm_fd, "Exiting...");
	exit(0);
	}
	snprintf(endstr, sizeof(endstr), "echo %s", str);
	system(endstr);
	bzero(endstr, 100);
	snprintf(endstr, sizeof(endstr), "You sent me %s", str);
 	
        write(comm_fd, endstr, strlen(endstr)+1);
 
    }
}
