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
 
    char str[500] = "\0";
    char endstr[50] = "\0";
    int listen_fd, comm_fd;
    int retval = 0;
    int option = 1;
 
    struct sockaddr_in servaddr;
 
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
 
    bzero( &servaddr, sizeof(servaddr));
 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));
	printf("Binding to port %i\n", atoi(argv[1]));
 
    retval = bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if (retval == -1){
	printf("Error Binding to port %i\n", atoi(argv[1]));
	 exit(1);}

   if(setsockopt(listen_fd, SOL_SOCKET,SO_REUSEADDR, (char*)&option, sizeof(option)) < 0){
	printf("Setsockopt failed :(\n");
	close(listen_fd);
	exit(2);
}


    listen(listen_fd, 2);
 
    comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
 
        bzero(str, 500);
	write(comm_fd, "Send Me Bytes:",14);
        read(comm_fd,str,500);
	sprintf(endstr, "nom nom nom, you sent me %s", str);
 	printf("Sent back - %s",str);
        write(comm_fd, endstr, strlen(endstr)+1);
	shutdown(comm_fd, SHUT_RDWR);
	shutdown(listen_fd, SHUT_RDWR);
	close(comm_fd);
	close(listen_fd);
return 0x42;
}
